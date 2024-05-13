%define parse.error verbose
%{
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "parsing_type.h"
#include "expression_stack.h"

int yylex();
unsigned long _line = 1;
int var_declaration = 0;
int last_type = UD_TYPE;
int array_decl_rept = 0;
int dimension = 0;
char current_type[30];

const char * regular_type(const char* type)
{
    //"integer"|"double"|"string"|"float"|"real"|"single"|"byte"|"longint"|"word"|"longword"|"shortint"|"cardinal"|"object"
    if (strcmp(type, "integer") == 0 || strcmp(type, "i") == 0
        || strcmp(type, "byte") == 0
        || strcmp(type, "longint") == 0
        || strcmp(type, "word") == 0
        || strcmp(type, "shortint") == 0)
        return "i";
    if (strcmp(type, "float") == 0  || strcmp(type, "f") == 0
        || strcmp(type, "real") == 0 
        || strcmp(type, "single") == 0 
        || strcmp(type, "double") == 0)
        return "f";
    if (strcmp(type, "string") == 0 || strcmp(type, "s") == 0)
        return "s";
    if (strcmp(type, "char") == 0 || strcmp(type, "c") == 0)
        return "c";
    return type;
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
%token PROGRAM FUNCTION PROCEDURE ARRAY IF THEN ELSE CASE OF END ASSIGN _BEGIN WHILE DO REPEAT UNTIL FOR TO DOWNTO BREAK CONTINUE
%token VAR LOGICALNOT NEWLINE WITH WRITE WRITELN READ
%token <floatVal> FLOAT
%token <intVal> INT
%token <stringVal> STRING ID RELATIONAL_OP ADD_OP MUL_OP TYPE BUILTIN_FUNCTION
%token COMMENT
%token END_OF_FILE
%%

program : PROGRAM ID ';' { printf("Line %02lu: %s %s;", _line, "program", $2); } block 
        | error ID ';' { printf("%s;", $2); } block;

block : procedure_function_decl_part var_decl_part statement_part | error var_decl_part statement_part;
block_ : procedure_function_decl_part var_decl_part statement_part_ | error var_decl_part statement_part_;

procedure_function_decl_part: | procedure_function_decl_part procedure_or_function ';' { printf(";"); };
procedure_or_function: procedure_decl | function_decl;
procedure_decl: procedure_header block_;
procedure_header: procedure_header_common ';' { printf(";"); }
                | procedure_header_common
                '(' { printf("("); } formal_parameter_section_list ')' { printf(")"); } ';' { printf(";"); };
procedure_header_common: PROCEDURE { printf("procedure "); } ID
                        {
                            printf("%s", $3);
                            insert($3, "p");
                        };
formal_parameter_section_list: formal_parameter_section formal_parameter_section_rept;
formal_parameter_section_rept: | formal_parameter_section_rept ';' { printf(";"); } formal_parameter_section;
formal_parameter_section: parameter_group | VAR { printf("var "); } parameter_group;
parameter_group: ID_list ':' { printf(":"); } parameter_type { memset(current_type, 0, sizeof(current_type)); };
parameter_type: type_identifier | structured_type;
return_type: type_identifier | structured_type;
function_decl: function_header block_;
function_header: FUNCTION ID
                {
                    printf("function %s", $2);
                } ':' { printf(":"); } return_type
                {
                    char func_type[100] = "n";
                    strcat(func_type, current_type);
                    insert($2, func_type);
                    memset(current_type, 0, sizeof(current_type));
                }
                ';' { printf(";"); }
                | FUNCTION ID
                {
                    printf("function %s", $2);
                }
                '(' { printf("("); } formal_parameter_section_list ')' 
                { printf(")"); } ':' { printf(":"); } return_type
                {
                    char func_type[100] = "n";
                    strcat(func_type, current_type);
                    insert($2, func_type);
                    memset(current_type, 0, sizeof(current_type));
                }
                ';' { printf(";"); };

var_decl_part : | VAR { printf("%s", "var "); var_declaration = 1; } var_decl var_decl_rept EOSE { var_declaration = 0; };
var_decl : ID_list ':' { printf(" : "); } type
         {
            while (!empty()) 
            { 
                char id[30]; 
                strcpy(id, top()); 
                insert(id, current_type);
                pop(); 
            }
            memset(current_type, 0, sizeof(current_type));
         }
         | ID_list error type
         {
            while (!empty()) 
            {
                char id[30]; 
                strcpy(id, top()); 
                insert(id, current_type);
                pop(); 
            }
            memset(current_type, 0, sizeof(current_type));
         };
var_decl_rept : | var_decl_rept EOSE var_decl;

type : simple_type | structured_type;

simple_type : scalar_type | subrange_type | type_identifier;

scalar_type : '(' { printf("("); } ID_list ')'{ printf(")"); };

subrange_type : const '.' '.' { printf(".."); } const;

const : INT { printf("%d", $1); } | FLOAT { printf("%f", $1); } | ID { printf("%s", $1); };

type_identifier : TYPE 
                { 
                    printf("%s", $1);
                    strcat(current_type, regular_type($1));
                };

structured_type : array_type;

array_type : ARRAY 
            { 
                printf("array"); 
                dimension = 0;
                if (current_type[0] == 'a')
                    sscanf(current_type+1, "%d", &dimension);
                else
                    strcat(current_type, "a"); 
            }
           '[' 
            { 
                printf("[");
            } index_type index_type_rept 
            ']' 
            {
                printf("]"); 
                char buf[2];
                sprintf(buf, "%d", dimension);
                strcpy(current_type+1, buf);
                dimension = 0; 
            } OF { printf(" of "); } type;
index_type : simple_type { ++dimension; };
index_type_rept : | index_type_rept ',' { printf(","); ++dimension; } simple_type;

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

statement_part : first_compound_statement;
statement_part_ : compound_statement;

expression : simple_expression 
           | simple_expression RELATIONAL_OP { printf(" %s ", $2); } simple_expression 
           {
                node_t b = exp_top(); exp_pop();
                node_t a = exp_top(); exp_pop();
                if ((strcmp(a.type, "i") != 0 && strcmp(a.type, "f") != 0) 
                 || (strcmp(b.type, "i") != 0 && strcmp(b.type, "f") != 0))
                    if (!(strcmp(a.type, "s") == 0 && strcmp(b.type, "s") == 0)
                     || !(strcmp(a.type, "c") == 0 && strcmp(b.type, "c") == 0))
                    {
                        char buf[100];
                        sprintf(buf, "%s and %s type cannot use '%s' operation.", cpretty(a.type), cpretty(b.type), $2);
                        yyerror(buf);
                    }
                exp_push(KIND_NUM, "i");
           };

simple_expression : term 
                  | simple_expression ADD_OP { printf(" %s ", $2); } term
                  {
                    node_t b = exp_top(); exp_pop();
                    node_t a = exp_top(); exp_pop();
                    if ((strcmp(a.type, "i") != 0 && strcmp(a.type, "f") != 0)
                     || (strcmp(b.type, "i") != 0 && strcmp(b.type, "f") != 0))
                    {
                        char buf[100];
                        sprintf(buf, "%s and %s type cannot use '%s' operation.", cpretty(a.type), cpretty(b.type), $2);
                        yyerror(buf);
                        exp_push(KIND_NUM, "i");
                    }
                    else if (strcmp(a.type, "f") == 0 || strcmp(b.type, "f") == 0)
                        exp_push(KIND_NUM, "f");
                    else
                        exp_push(KIND_NUM, "i");
                  };

term : factor 
     | term MUL_OP { printf(" %s ", $2); } factor 
     {
        node_t b = exp_top(); exp_pop();
        node_t a = exp_top(); exp_pop();
        if ((strcmp(a.type, "i") != 0 && strcmp(a.type, "f") != 0)
         || (strcmp(b.type, "i") != 0 && strcmp(b.type, "f") != 0))
        {
            char buf[100];
            sprintf(buf, "%s and %s type cannot use '%s' operation.", cpretty(a.type), cpretty(b.type), $2);
            yyerror(buf);
        }
        else if (strcmp(a.type, "f") == 0 || strcmp(b.type, "f") == 0)
            exp_push(KIND_NUM, "f");
        else
            exp_push(KIND_NUM, "i");
     };

factor : variable 
       | '(' { printf(" ( "); } expression ')' { printf(" ) "); } 
       | LOGICALNOT { printf(" not "); } factor 
        { 
            node_t a = exp_top(); exp_pop();
            if (strcmp(a.type, "i") != 0)
            {
                char buf[100];
                sprintf(buf, "%s cannot be NOTed.", cpretty(a.type));
                yyerror(buf);
            }
            exp_push(KIND_NUM, a.type);
        }
       | function_designator;

variable : entire_variable 
         | indexed_variable;

entire_variable : INT { printf("%d", $1); exp_push(KIND_NUM, "i"); } 
                | FLOAT { printf("%f", $1); exp_push(KIND_NUM, "f"); } 
                | STRING { printf("%s", $1); exp_push(KIND_NUM, "s"); } 
                | ID 
                {
                    if (exists($1) == 0)
                    {
                        char buf[100];
                        sprintf(buf, "%s was not declared in this scope.", $1);
                        yyerror(buf);
                        exp_push(KIND_NUM, "i");
                    }
                    else
                    {
                        const char* _type = lookup_type($1);
                        printf("%s", $1);
                        if (_type[0] == 'n' && strlen(_type) > 1)
                            exp_push(KIND_NUM, _type+1);
                        else
                        {
                            exp_push(KIND_NUM, lookup_type($1));
                        }
                    }
                };

indexed_variable : variable '[' { printf("["); } expression ']' 
                 {
                    printf("]");

                    node_t index = exp_top(); exp_pop();
                    node_t array = exp_top(); exp_pop();

                    if (array.type[0] != 'a')
                        yyerror("Only array type can be indexed.");
                    else
                    {
                        sscanf(array.type+1, "%d", &dimension);
                        --dimension;
                        if (dimension == 0)
                            sprintf(array.type, "%c", array.type[strlen(array.type)-1]);
                        else
                            sprintf(array.type, "a%d%c", dimension, array.type[strlen(array.type)-1]);
                    }

                    if (strcmp(index.type, "i") != 0)
                        yyerror("The index of array is not integer.");

                    dimension = 0;
                    exp_push(KIND_NUM, array.type);
                 };

function_designator : BUILTIN_FUNCTION
                    {
                        printf("%s", $1);

                        if (strcmp($1, "concat") == 0)
                            exp_push(KIND_NUM, "s");
                        else
                            exp_push(KIND_NUM, "n");
                    }
                    | BUILTIN_FUNCTION { printf("%s", $1); } 
                    '(' { printf("("); } actual_parameter actual_parameter_list ')'
                    {
                        printf(")");

                        if (strcmp($1, "concat") == 0)
                            exp_push(KIND_NUM, "s");
                        else
                            exp_push(KIND_NUM, "n");
                    }
                    | ID { printf("%s", $1); } '(' { printf("("); } actual_parameter actual_parameter_list ')' 
                    {
                        printf(")");

                        if (exists($1) == 0)
                        {
                            char buf[100];
                            sprintf(buf, "function %s was not declared in this scope.", $1);
                            yyerror(buf);
                        }
                        else if (lookup_type($1)[0] != 'n')
                        {
                            char buf[100];
                            sprintf(buf, "%s type is not callable.", cpretty(lookup_type($1)));
                            yyerror(buf);
                        }
                        else
                        {
                            const char* _type = lookup_type($1);
                            if (strlen(_type) <= 1)
                                exp_push(KIND_NUM, "n");
                            else
                                exp_push(KIND_NUM, _type+1);
                        }
                    };
actual_parameter_list : | actual_parameter_list ',' { printf(", "); } actual_parameter
actual_parameter : expression

EOSE : ';' { printf(";"); };

if_statement : IF { printf("if "); } expression THEN { printf(" then "); } statement else;
else: | ELSE { printf(" else \n"); } statement;

case_statement : CASE expression OF case_list_element case_list_rept END;
case_list_rept : | EOSE case_list_rept;
case_list_element : | case_label_list ':' { printf(":"); } statement;
case_label_list : case_label case_label_rept;
case_label_rept : | case_label_rept ',' { printf(","); } case_label;
case_label : INT | STRING | ID { printf("%s", $1); };

statement : | structured_statement | assignment_statement | procedure_statement;

assignment_statement : variable ASSIGN { printf(" := "); } expression
                     {
                        node_t expr = exp_top(); exp_pop();
                        node_t var  = exp_top(); exp_pop();
                        if (var.type[0] != expr.type[0])
                        {
                            if (var.type[0] == 'i' && expr.type[0] == 'f')
                                yyerror("WARNING: narrowing conversion form float to int.");
                            else
                            {
                                char buf[100];
                                sprintf(buf, "cannot convert %s to %s.", cpretty(expr.type), cpretty(var.type));
                                yyerror(buf);
                            }
                        }
                     }
                     | variable error expression
                     {
                        node_t expr = exp_top(); exp_pop();
                        node_t var  = exp_top(); exp_pop();
                        if (var.type[0] != expr.type[0])
                        {
                            if (var.type[0] == 'i' && expr.type[0] == 'f')
                                yyerror("WARNING: narrowing conversion form float to int.");
                            else
                            {
                                char buf[100];
                                sprintf(buf, "cannot convert %s to %s.", cpretty(expr.type), cpretty(var.type));
                                yyerror(buf);
                            }
                        }
                     };

structured_statement : compound_statement | conditional_statement | reptive_statement | with_statement;

first_compound_statement : _BEGIN { printf("begin"); } statement rept_statement { } END { printf("end"); } '.' { printf("."); };
compound_statement : _BEGIN { printf("begin"); } statement rept_statement END { printf("end"); };

conditional_statement : if_statement | case_statement;

rept_statement : | rept_statement EOSE statement;

reptive_statement : while_stat | rept_stat | for_stat;

while_stat : WHILE { printf(" while "); } expression DO { printf(" do "); } statement;

rept_stat : REPEAT { printf(" repeat "); } statement rept_rept_stat UNTIL { printf(" until "); } expression;

rept_rept_stat : | rept_rept_stat EOSE statement;

for_stat : FOR { printf("for "); } ID { printf("%s", $3); } ASSIGN { printf(" := "); } for_list DO { printf(" do "); } statement;

for_list : expression TO { printf(" to "); } expression | expression DOWNTO { printf(" downto "); } expression;

with_statement : WITH { printf("with"); } variable_list DO { printf("do"); } statement;

variable_list: variable variable_list_rept;

variable_list_rept : | variable_list_rept ',' { printf(", "); } variable;

procedure_statement : BUILTIN_FUNCTION { printf("%s", $1); } | BUILTIN_FUNCTION { printf("%s", $1); } '(' { printf("("); } actual_parameter actual_parameter_list ')' { printf(")"); };;

%%
int main() {
    yyparse();
    printf("\n");
    show_symbol_table();
    return 0;
}
