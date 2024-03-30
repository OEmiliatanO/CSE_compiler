%{
#include <stdio.h>
#include <ctype.h>

int line_num = 0;

%}

comment_begin "(*"
comment_inside1 [^*\n]*
comment_inside2 "*"+[^*)\n]*
comment_inside3 \n
comment_end "*"+")"

%s comment

%%
<INITIAL>{
    {comment_begin}      { yymore(); BEGIN(comment); }
}

<comment>{
    {comment_inside1}    { yymore(); } /* eat anything that's not a '*' */
    {comment_inside2}    { yymore(); } /* eat up '*'s not followed by '/'s */
    {comment_inside3}    { yymore(); ++line_num; }
    {comment_end}        { printf("%s is \"comment\"", yytext); BEGIN(INITIAL); }
}

%%


int main()
{
    yylex();
}
