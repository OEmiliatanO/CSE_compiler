%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "y.tab.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

extern unsigned long _line;
unsigned long _pos = 1, _cppos = 1;

void inform(unsigned long l, unsigned long p, const char* token, const char* type, const char* complement);
void color(const char* c, char* s);
%}
reserved_word absolute|const|function|nil
type "integer"|"double"|"string"|"float"|"real"|"single"|"byte"|"longint"|"word"|"longword"|"shortint"|"cardinal"|"object"|"array"
builtin_function write|writeln|read

id [A-Za-z_][_[:alnum:]]{0,14}
unsigned [0-9]+
int [+-]?[0-9]+
float_without_exp {int}(\.{unsigned})?
float {float_without_exp}([eE]{int})?
/* float [+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)? */
string \'([^\'\r\n]|\'\'){0,30}\'
comment_begin "(*"
comment_content [^*\n]*|"*"+[^*)\n]*
comment_end "*"+")"
/*comments \(\*({comments}|.|\r?\n)?\*\)*/
/* flex cannot “balance” parentheses to an arbitrary degree: https://www.cs.virginia.edu/~cr4bd/flex-manual/Does-flex-support-recursive-pattern-definitions_003f.html */

comma \,
semicolon ;
colon :
round_bracket \(|\)
lrb \(
rrb \)
define :=
ge \>
le \<
eq \=
eqq \=\=
geq \>\=
leq \<\=
square_bracket \[|\]
lsb \[
rsb \]
plus \+
sub \-
mul \*
div \/
period \.
curly_bracket \{|\}
ne \<\>
bitand \&
bitor \|
bitnot \~
shiftr \>\>
shiftl \<\<
logicalnot not

symbols {eqq}|{curly_bracket}|{bitand}|{bitnot}|{shiftr}|{shiftl}
op_symbols {eq}|{eqq}|{bitand}|{bitor}|{bitnot}|{shiftr}|{shiftl}

relational_op {eq}|{ne}|{le}|{leq}|{geq}|{ge}|in
add_op {plus}|{sub}|or
mul_op {mul}|{div}|div|mod|and
sign [+-]

newline \r?\n
space [\t\ ]

id_over_len_limit [A-Za-z_][_[:alnum:]]{15,}
id_wrong_starting [0-9^#%$][_[:alnum:]^#%$]*
nonid {id_over_len_limit}|{id_wrong_starting}

string_dquote \"([^\'\r\n]|\'\')*\"
/* incompleted_string_dquote \"[^;\r\n\ ]*|[^;\r\n\ ]*\" */
/* incompleted_string \'[^)';\r\n\ ]*|[^(';\r\n\ ]*\' */
string_over_len_limit \'([^\'\r\n]|\'\'){31,}\'
string_non_terminated_quote \'[^\'\r\n]*
nonstring {string_over_len_limit}|{string_dquote}

float_without_frac_exp {int}\.
float_without_frac {float_without_frac_exp}([eE]{int})?
float_without_int_exp [+-]?\.{unsigned}
float_without_int {float_without_int_exp}([eE]{int})?
float_with_e_frac ({float_without_frac_exp}|{float_without_int_exp}|{float_without_exp})([eE]({float_without_frac_exp}|{float_without_int_exp}|{float_without_exp}))+
/* float_with_multi_frac {int}(\.{unsigned}?([eE]({float_without_frac_exp}|{float_without_int_exp}|{float_without_exp}))?){2,} */
nonfloat {float_without_frac}|{float_without_int}|{float_with_e_frac}

incompleted_comments "(*)"
noncomment {incompleted_comments}

%s COMMENT_STATE
%s NUMERIC_STATE
%%

<INITIAL>{
    {newline} {
        ++_line;
        printf("\nLine %02lu: ", _line);
    }

    {space} {
        _pos += yyleng;
    }

    {reserved_word} {
        /*
        char type[50] = "reserved word";
        color(KGRN, type);
        */

        /* inform(_line, _pos, yytext, type, ""); */
        _pos += yyleng;
    }

    "program" {
        return PROGRAM;
    }

    "for" {
        return FOR;
    }
    
    "if" {
        return IF;
    }

    "else" {
        return ELSE;
    }

    "then" {
        return THEN;
    }

    "do" {
        return DO;
    }

    "end" {
        return END;
    }

    "case" {
        return CASE;
    }

    "of" {
        return OF;
    }

    "to" {
        return TO;
    }

    "downto" {
        return DOWNTO;
    }

    "with" {
        return WITH;
    }

    ":=" {
        return ASSIGN;
    }

    "while" {
        return WHILE;
    }

    "var" {
        return VAR;
    }

    "repeat" {
        return REPEAT;
    }

    "until" {
        return UNTIL;
    }

    "begin" {
        return _BEGIN;
    }

    "break" {
        return BREAK;
    }

    "continue" {
        return CONTINUE;
    }

    "array" {
        return ARRAY;
    }

    {builtin_function} {
        yylval.stringVal = strdup(yytext);
        return BUILTIN_FUNCTION;
    }

    {logicalnot} {
        return LOGICALNOT;
    }

    {type} {
        yylval.stringVal = strdup(yytext);
        return TYPE;
    }

    {int} {
        _pos += yyleng;
        sscanf(yytext, "%d", &yylval.intVal);
        //printf("detect \"%s\"", yytext);
        BEGIN(NUMERIC_STATE);
        return INT;
    }
    
    {float} {
        _pos += yyleng;
        sscanf(yytext, "%f", &yylval.floatVal);
        BEGIN(NUMERIC_STATE);
        return FLOAT;
    }

    {symbols} {
        _pos += yyleng;
    }

    {comma} {
        return ',';
    }

    {colon} {
        return ':';
    }

    {semicolon} {
        return ';';
    }

    {period} {
        return '.';
    }

    {comment_begin} {
        _cppos = _pos;
        yymore();
        BEGIN(COMMENT_STATE);
    }

    {comment_end} {
        char type[50] = "incompleted comment";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The comment is incompleted.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {relational_op} {
        BEGIN(INITIAL);
        yylval.stringVal = strdup(yytext);
        return RELATIONAL_OP;
    }

    {add_op} {
        BEGIN(INITIAL);
        yylval.stringVal = strdup(yytext);
        return ADD_OP;
    }

    {mul_op} {
        BEGIN(INITIAL);
        yylval.stringVal = strdup(yytext);
        return MUL_OP;
    }

    {id} {
        _pos += yyleng;
        yylval.stringVal = strdup(yytext);
        //printf("detect \"%s\"", yytext);
        return ID;
    }

    {string} {
        yylval.stringVal = strdup(yytext);
        BEGIN(NUMERIC_STATE);
        return STRING;
    }

    {rrb} {
        return ')';
    }

    {lrb} {
        return '(';
    }

    {lsb} {
        return '[';
    }

    {rsb} {
        return ']';
    }

    {id_over_len_limit} {
        char type[50] = "invalid identity";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The length exceeds the maximum length.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {id_wrong_starting} {
        char type[50] = "invalid identity";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s Starts with the invalid character: %s%c%s.", _line, KRED, KWHT, KRED, yytext[0], KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {string_dquote} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s Using double quotation marks (\").", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    /*
    i found that gcc does not detect incomplete string: 
    for example, string like 
    ab" 
    will be determined as identity and non-terminated quote.

    {incompleted_string} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s Incompleted string.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }
    */

    {string_over_len_limit} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The length exceeds the maximum length.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    
    {string_non_terminated_quote} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s missing terminating ' character.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }
   
    {float_without_frac} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The fraction is missing.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }
    
    {float_without_int} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The integer is missing.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {float_with_e_frac} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The exponential part cannot have fraction.", _line, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {incompleted_comments} {
        char type[50] = "incompleted comment";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "\n%5lu | %sERROR:%s The comment is incompleted.", _line, KRED, KWHT);
    }
    
    . {
        char type[50] = "Error";
        color(KRED, type);

        inform(_line, _pos, yytext, type, "");
        _pos += yyleng;
    }
}

<COMMENT_STATE>{
    {comment_content} {
        yymore();
    }

    {newline} {
        ++_line;
        yymore();
    }

    {comment_end} {
        BEGIN(INITIAL);
    }
}

<NUMERIC_STATE>{
    {relational_op} {
        BEGIN(INITIAL);
        yylval.stringVal = strdup(yytext);
        return RELATIONAL_OP;
    }

    {add_op} {
        BEGIN(INITIAL);
        yylval.stringVal = strdup(yytext);
        return ADD_OP;
    }

    {mul_op} {
        BEGIN(INITIAL);
        yylval.stringVal = strdup(yytext);
        return MUL_OP;
    }
    
    . {
        yyless(0);
        BEGIN(INITIAL);
    }
}

%%

void color(const char* c, char* s)
{
    char buffer[300];
    sprintf(buffer, "%s%s%s", c, s, KWHT);
    memcpy(s, buffer, strlen(buffer) * sizeof(char));
}

void inform(unsigned long l, unsigned long p, const char* token, const char* type, const char* complement)
{
    printf("Line: %lu, 1st char: %lu, \"%s\" is a \"%s\". %s\n", l, p, token, type, complement);
}

int yywrap(){
    return 1;
}

/*
int main()
{
    yylex();
    show_symbol_table();
}
*/
