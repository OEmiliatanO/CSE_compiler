%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/types.h>
#include <regex.h>
#include "symbol_table.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

unsigned long _line = 1, _pos = 1;

void inform(unsigned long l, unsigned long p, const char* token, const char* type, const char* complement);
void color(const char* c, char* s);
%}
reserved_word absolute|and|begin|break|case|const|continue|do|else|end|for|function|if|mod|nil|not|object|of|or|program|then|to|var|while|array|integer|double|write|writeln|string|float|read|real|single|byte|longint|word|longword|shortint|cardinal

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
define :=
ge \>
le \<
eq \=
eqq \=\=
geq \>\=
leq \<\=
square_bracket \[|\]
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
symbols {comma}|{semicolon}|{colon}|{round_bracket}|{define}|{ge}|{le}|{eq}|{eqq}|{geq}|{leq}|{square_bracket}|{sub}|{mul}|{div}|{period}|{curly_bracket}|{ne}|{bitand}|{bitnot}|{shiftr}|{shiftl}
newline \r?\n
space [\t\ ]

id_over_len_limit [A-Za-z_][_[:alnum:]]{15,}
id_wrong_starting [0-9^#%$][_[:alnum:]^#%$]*
nonid {id_over_len_limit}|{id_wrong_starting}

string_dquote \"([^\'\r\n]|\'\')*\"
incompleted_string_dquote \"[^;\r\n\ ]*|[^;\r\n\ ]*\"
incompleted_string \'[^';\r\n\ ]*|[^';\r\n\ ]*\'
string_over_len_limit \'([^\'\r\n]|\'\'){31,}\'
string_with_wrong_quote \'([^\'\r\n]*\'[^\'\r\n]*)+\'
nonstring {incompleted_string}|{string_over_len_limit}|{string_with_wrong_quote}|{string_dquote}

float_without_frac_exp {int}\.
float_without_frac {float_without_frac_exp}([eE]{int})?
float_without_int_exp [+-]?\.{unsigned}
float_without_int {float_without_int_exp}([eE]{int})?
float_with_e_frac ({float_without_frac_exp}|{float_without_int_exp}|{float_without_exp})([eE]({float_without_frac_exp}|{float_without_int_exp}|{float_without_exp}))+
float_with_multi_frac {int}(\.{unsigned}?([eE]({float_without_frac_exp}|{float_without_int_exp}|{float_without_exp}))?){2,}
nonfloat {float_without_frac}|{float_without_int}|{float_with_e_frac}|{float_with_multi_frac}

incompleted_comments "(*)"
noncomment {incompleted_comments}

%s COMMENT_STATE
%%

<INITIAL>{
    {newline} {
        ++_line;
        _pos = 1;
    }

    {space} {
        _pos += yyleng;
    }

    {reserved_word} {
        char type[50] = "reserved word";
        color(KGRN, type);

        inform(_line, _pos, yytext, type, "");
        _pos += yyleng;
    }

    {id} {
        char type[50] = "identity";
        color(KYEL, type);

        inform(_line, _pos, yytext, type, "");
        _pos += yyleng;
        insert(yytext);
    }

    ({int}[\+\-\*\/]{int}) {
        regex_t preg;
        regcomp(&preg, "[+-]?[0-9]+", REG_EXTENDED);
        char text[200], s[200];
        memcpy(text, yytext, (sizeof(char) * 200 > strlen(yytext) ? strlen(yytext) : sizeof(char) * 200));
        regmatch_t matchptr[1];
        int status = regexec(&preg, text, 1, matchptr, 0);
        size_t len_s = 0;
        if (status == 0)
        {
            len_s = matchptr[0].rm_eo - matchptr[0].rm_so;
            memcpy(s, text + matchptr[0].rm_so, len_s * sizeof(char));
        }
        s[len_s] = '\0';
        inform(_line, _pos, s, "integer", "");
        _pos += len_s;
        s[0] = text[matchptr[0].rm_eo];
        s[1] = '\0';
        inform(_line, _pos, s, "symbol", "");
        yyless(len_s+1);
        _pos += 1;
        regfree(&preg);

    }

    {int} {
        inform(_line, _pos, yytext, "integer", "");
        _pos += yyleng;
    }

    /* float [+-]?[0-9]+(\.[0-9]+)?([eE][+-]?[0-9]+)? */
    ({float}[\+\-\*\/]{float}) {
        regex_t preg;
        regcomp(&preg, "[+-]?[0-9]+(\\.[0-9]+)?([eE][+-]?[0-9]+)?", REG_EXTENDED);
        char text[200], s[200];
        memcpy(text, yytext, (sizeof(char) * 200 > strlen(yytext) ? strlen(yytext) : sizeof(char) * 200));
        regmatch_t matchptr[1];
        int status = regexec(&preg, text, 1, matchptr, 0);
        size_t len_s = 0;
        if (status == 0)
        {
            len_s = matchptr[0].rm_eo - matchptr[0].rm_so;
            memcpy(s, text + matchptr[0].rm_so, len_s * sizeof(char));
        }
        s[len_s] = '\0';
        inform(_line, _pos, s, "float", "");
        _pos += len_s;
        s[0] = text[matchptr[0].rm_eo];
        s[1] = '\0';
        inform(_line, _pos, s, "symbol", "");
        yyless(len_s+1);
        _pos += 1;
        regfree(&preg);
    }

    {float} {
        inform(_line, _pos, yytext, "float", "");
        _pos += yyleng;
    }

    {symbols} {
        inform(_line, _pos, yytext, "symbol", "");
        _pos += yyleng;
    }

    {comment_begin} {
        yymore();
        BEGIN(COMMENT_STATE);
    }

    {comment_end} {
        char type[50] = "incompleted comment";
        color(KRED, type);

        inform(_line, _pos, yytext, type, "");
        _pos += yyleng;
    }

    {string} {
        inform(_line, _pos, yytext, "string", "");
        _pos += yyleng;
    }

    {id_over_len_limit} {
        char type[50] = "invalid identity";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "The length exceeds the %smaximum length%s.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {id_wrong_starting} {
        char type[50] = "invalid identity";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "Starts with the invalid character: %s%c%s.", KRED, yytext[0], KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    /*
    {nonid} {
        inform(_line, _pos, yytext, "invalid identity");
        _pos += yyleng;
    }
    */

    {string_dquote} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "Using %sdouble quotation marks (\")%s.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {incompleted_string_dquote} {
        char type[50] = "invalid string";
        color(KRED, type);
        
        char complement[100];
        sprintf(complement, "%sIncompleted string%s with %sdouble quotation marks (\")%s.", KRED, KWHT, KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {incompleted_string} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "%sIncompleted string%s.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {string_over_len_limit} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "The length exceeds the %smaximum length%s.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {string_with_wrong_quote} {
        char type[50] = "invalid string";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "Cannot match the %ssingle quotation marks%s.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    /*
    {nonstring} {
        inform(_line, _pos, yytext, "non-string", "");
        _pos += yyleng;
    }
    */
   
    {float_without_frac} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "The %sfraction%s is missing.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }
    
    {float_without_int} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "The %sinteger%s is missing.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {float_with_e_frac} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "The %sexponential part%s cannot have fraction.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;
    }

    {float_with_multi_frac} {
        char type[50] = "invalid float type";
        color(KRED, type);

        char complement[100];
        sprintf(complement, "This float contains %smultiple fraction%s.", KRED, KWHT);

        inform(_line, _pos, yytext, type, complement);
        _pos += yyleng;

    }

    /*
    {nonfloat} {
        inform(_line, _pos, yytext, "non-float", "");
        _pos += yyleng;
    }
    */

    {noncomment} {
        char type[50] = "invalid comment";
        color(KRED, type);

        inform(_line, _pos, yytext, "invalid comment", "");
        _pos += yyleng;
    }
    
    . {
        char type[50] = "error";
        color(KRED, type);

        inform(_line, _pos, yytext, "error", "");
        _pos += yyleng;
    }
}

<COMMENT_STATE>{
    {comment_content} {
        _pos += yyleng;
        yymore();
    }

    {newline} {
        ++_line;
        _pos = 1;
        yymore();
    }

    {comment_end} {
        inform(_line, _pos, yytext, "comment", "");
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

int main()
{
    yylex();
    show_symbol_table();
}
