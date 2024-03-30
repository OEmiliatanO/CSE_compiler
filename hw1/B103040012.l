%{
#include <stdio.h>
#include <ctype.h>
#include "symbol_table.h"

unsigned long _line = 1, _pos = 1;

void inform(unsigned long l, unsigned long p, const char* token, const char* type);
%}
reserved_word absolute|and|begin|break|case|const|continue|do|else|end|for|function|if|mod|nil|not|object|of|or|program|then|to|var|while|array|integer|double|write|writeln|string|float|read|real|single|byte|longint|word|longword|shortint|cardinal

id [A-Za-z_][_[:alnum:]]{0,14}
int [+-]?[0-9]+
frac [0-9]+
float [+-]?{int}(\.{frac})?([eE]{int})?
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
symbols {comma}|{semicolon}|{colon}|{round_bracket}|{define}|{ge}|{le}|{eq}|{eqq}|{geq}|{leq}|{square_bracket}|{plus}|{sub}|{mul}|{div}|{period}|{curly_bracket}|{ne}|{bitand}|{bitnot}|{shiftr}|{shiftl}
newline \r?\n
space [\t\ ]

id_over_len_limit [A-Za-z_][_[:alnum:]]{15,}
id_wrong_starting [0-9\^#][_[:alnum:]]*
nonid {id_over_len_limit}|{id_wrong_starting}

string_dquote \"([^\'\r\n]|\'\')?\"
incompleted_string \'[^';\r\n\ ]*|[^';\r\n\ ]*\'
string_over_len_limit \'([^\'\r\n]|\'\'){31,}\'
string_with_wrong_quote \'([^\'\r\n]*\'[^\'\r\n]*)+\'
nonstring {incompleted_string}|{string_over_len_limit}|{string_with_wrong_quote}|{string_dquote}

float_without_frac [+-]?{int}(\.)+([eE]{int})?
float_without_int [+-]?(\.{frac})+([eE]{int})?
float_with_e_frac [+-]?{int}(\.{frac})?([eE][+-]?{int}?\.{frac})
nonfloat {float_without_frac}|{float_without_int}|{float_with_e_frac}

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
        inform(_line, _pos, yytext, "reserved word");
        _pos += yyleng;
    }

    {id} {
        inform(_line, _pos, yytext, "identity");
        _pos += yyleng;
        insert(yytext);
    }

    {int} {
        inform(_line, _pos, yytext, "integer");
        _pos += yyleng;
    }

    {float} {
        inform(_line, _pos, yytext, "float");
        _pos += yyleng;
    }

    {symbols} {
        inform(_line, _pos, yytext, "symbol");
        _pos += yyleng;
    }

    {comment_begin} {
        yymore();
        BEGIN(COMMENT_STATE);
    }

    {comment_end} {
        inform(_line, _pos, yytext, "non-comment");
        _pos += yyleng;
    }

    {string} {
        inform(_line, _pos, yytext, "string");
        _pos += yyleng;
    }

    {nonid} {
        inform(_line, _pos, yytext, "non-id");
        _pos += yyleng;
    }

    {nonstring} {
        inform(_line, _pos, yytext, "non-string");
        _pos += yyleng;
    }

    {nonfloat} {
        inform(_line, _pos, yytext, "non-float");
        _pos += yyleng;
    }

    {noncomment} {
        inform(_line, _pos, yytext, "non-comment");
        _pos += yyleng;
    }
    
    . {
        inform(_line, _pos, yytext, "error");
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
        inform(_line, _pos, yytext, "comment");
        BEGIN(INITIAL);
    }
}

%%

void inform(unsigned long l, unsigned long p, const char* token, const char* type)
{
    printf("Line: %lu, 1st char: %lu, \"%s\" is a \"%s\".\n", l, p, token, type);
}

int main()
{
    yylex();
    show_symbol_table();
}
