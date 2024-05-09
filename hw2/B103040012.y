%define parse.error verbose
%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"

const int UD_TYPE = -1;
const int INT_TYPE = 0;
const int CHAR_TYPE = 1;
const int FLOAT_TYPE = 2;
const int STRING_TYPE = 3;
const int IDENTITY_TYPE = 4;
const int ARRAY_TYPE = 5;

int yylex();
unsigned long _line = 1;
int var_declaration = 0;
int current_type = UD_TYPE;
int last_type = UD_TYPE;
int array_decl_rept = 0;

int type_to_num(const char* type)
{
    //"integer"|"double"|"string"|"float"|"real"|"single"|"byte"|"longint"|"word"|"longword"|"shortint"|"cardinal"|"object"|"array"
    if (strcmp(type, "integer") == 0)
        return INT_TYPE;
    if (strcmp(type, "float") == 0 
        || strcmp(type, "real") == 0 
        || strcmp(type, "single") == 0 
        || strcmp(type, "double") == 0)
        return FLOAT_TYPE;
    if (strcmp(type, "string") == 0)
        return STRING_TYPE;
    return INT_TYPE;
}

void yyerror(const char* message) {
    printf("\nLine %02lu: %s\nKeep processing: ", _line, message);
};
%}
%union {
    int 	intVal;
    char    charVal;
    float 	floatVal;
    char*   stringVal;
}
/* reserved words */
%token PROGRAM ARRAY IF THEN ELSE CASE OF END ASSIGN _BEGIN WHILE DO REPEAT UNTIL FOR TO DOWNTO BREAK CONTINUE
%token VAR LOGICALNOT NEWLINE WITH WRITE WRITELN READ
%token <floatVal> FLOAT
%token <intVal> INT
%token <stringVal> STRING ID RELATIONAL_OP ADD_OP MUL_OP TYPE BUILTIN_FUNCTION
%token COMMENT
%%

program : PROGRAM ID ';' { printf("Line %02lu: %s %s;", _line, "program", $2); } block;

block : var_decl_part statement_part;

var_decl_part : | VAR { printf("%s", "var"); var_declaration = 1; } var_decl var_decl_rept EOSE { var_declaration = 0; };

var_decl : ID_list ':' { printf(" : "); } type {}
         | ID_list error type;
var_decl_rept : | var_decl_rept EOSE var_decl;

type : simple_type | structured_type;

simple_type : scalar_type | subrange_type | type_identifier;

scalar_type : '(' { printf("("); } ID_list ')'{ printf(")"); };

subrange_type : const '.' '.' { printf(".."); } const;

const : INT { printf("%d", $1); } | FLOAT { printf("%f", $1); } | ID { printf("%s", $1); };

type_identifier : TYPE 
                { 
                    printf("%s", $1); 
                    while (!empty()) 
                    { 
                        char id[30]; 
                        strcpy(id, top()); 
                        if (array_decl_rept > 0)
                            insert(id, ARRAY_TYPE);
                        else
                            insert(id, type_to_num($1)); 
                        pop(); 
                    }
                    array_decl_rept = 0;
                };

structured_type : array_type;

array_type : ARRAY { printf("array"); } '[' { printf("["); } index_type index_type_rept ']' { printf("]"); } OF { printf(" of "); ++array_decl_rept; } type;
index_type : simple_type
index_type_rept : | index_type_rept ',' { printf(","); } simple_type

ID_list : ID 
        { 
            printf("%s", $1); 
            if (var_declaration) push($1);
        } ID_list_rept;
ID_list_rept : | ID_list_rept ',' ID 
             {
                printf(", %s", $3);
                if (var_declaration) push($3);
             };

statement_part : compound_statement;

expression : simple_expression 
           | simple_expression RELATIONAL_OP { printf(" %s ", $2); } simple_expression;

simple_expression : term 
                  | simple_expression ADD_OP { printf(" %s ", $2); } term
                  {
                    if (current_type == STRING_TYPE || last_type == STRING_TYPE)
                    {
                        char buf[50];
                        sprintf(buf, "String type cannot use '%s' operation.", $2);
                        yyerror(buf);
                    }
                  };

term : factor 
     | term MUL_OP { printf(" %s ", $2); } factor 
     {
        if (current_type == STRING_TYPE || last_type == STRING_TYPE)
        {
            char buf[50];
            sprintf(buf, "String type cannot use '%s' operation.", $2);
            yyerror(buf);
        }
     };

factor : variable 
       | '(' { printf(" ( "); } expression ')' { printf(" ) "); } 
       | LOGICALNOT { printf(" not "); } factor { if (current_type == STRING_TYPE) yyerror("String type cannot be NOT."); }
       | function_designator;

variable : entire_variable 
         | indexed_variable;

entire_variable : INT { printf("%d", $1); last_type = current_type; current_type = INT_TYPE; } 
                | FLOAT { printf("%f", $1); last_type = current_type; current_type = FLOAT_TYPE; } 
                | STRING { printf("%s", $1); last_type = current_type; current_type = STRING_TYPE; } 
                | ID 
                {
                    if (exists($1) == 0)
                    {
                        char buf[100];
                        sprintf(buf, "%s was not declared in this scope. Take it as integer type.", $1);
                        yyerror(buf);
                        last_type = current_type; 
                        current_type = INT_TYPE;
                    }
                    else
                    {
                        printf("%s", $1); 
                        last_type = current_type; 
                        current_type = lookup_type($1); 
                    }
                };

indexed_variable : variable '[' { printf("["); } expression ']' { printf("]"); };

function_designator : BUILTIN_FUNCTION { printf("%s", $1); } 
                    | BUILTIN_FUNCTION { printf("%s", $1); } '(' { printf("("); } actual_parameter actual_parameter_list ')' { printf(")"); };
actual_parameter_list : | actual_parameter_list ',' { printf(", "); } actual_parameter
actual_parameter : expression

END_OF_COMP: '.' { printf("."); };
EOSE : ';' { printf(";"); };
EOS : | EOSE | END_OF_COMP | error;

if_statement : IF { printf("if "); } expression THEN { printf(" then "); } statement else_statement;
else_statement : | ELSE { printf(" else \n"); } statement;

case_statement : CASE expression OF case_list_element case_list_rept END EOSE;
case_list_rept : | ';' { printf(";"); } case_list_rept;
case_list_element : | case_label_list ':' { printf(":"); } statement;
case_label_list : case_label case_label_rept;
case_label_rept : | case_label_rept ',' { printf(","); } case_label;
case_label : INT | STRING | ID { printf("%s", $1); };

statement : | structured_statement | assignment_statement | procedure_statement;

assignment_statement : variable ASSIGN { printf(" := "); } expression EOS | variable error expression EOS;

structured_statement : compound_statement | conditional_statement | reptive_statement | with_statement;

compound_statement : _BEGIN { printf("begin"); } statement rept_statement EOS END { printf("end"); } END_OF_COMP;

conditional_statement : if_statement | case_statement;

rept_statement : | rept_statement EOS statement;

reptive_statement : while_stat | rept_stat | for_stat;

while_stat : WHILE { printf(" while "); } expression DO { printf(" do "); } statement;

rept_stat : REPEAT { printf(" repeat "); } statement rept_rept_stat UNTIL { printf(" until "); } expression;

rept_rept_stat : | rept_rept_stat ';' { printf(";"); } statement;

for_stat : FOR { printf("for "); } ID { printf("%s", $3); } ASSIGN { printf(" := "); } for_list DO { printf(" do "); } statement;

for_list : expression TO { printf(" to "); } expression | expression DOWNTO { printf(" downto "); } expression;

with_statement : WITH { printf("with"); } variable variable_list_rept DO { printf("do"); } statement;

variable_list_rept : | variable_list_rept ',' { printf(", "); } variable;

procedure_statement : BUILTIN_FUNCTION { printf("%s", $1); } | BUILTIN_FUNCTION { printf("%s", $1); } '(' { printf("("); } actual_parameter actual_parameter_list ')' { printf(")"); };;

%%
int main() {
    yyparse();
    return 0;
}
