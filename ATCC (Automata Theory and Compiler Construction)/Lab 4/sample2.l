%option noyywrap
%{
int c=0,l=1,w=0;
%}
%%
[a-zA-Z0-9]* {w++;c+=yyleng;}
. {c++;}
\n {l++;c++;}
%%
void main(){
    yyin = fopen("input.txt", "r");
    yylex();
    printf("Lines: %d\nWords: %d\nCharacters: %d\n", l, w, c);
}