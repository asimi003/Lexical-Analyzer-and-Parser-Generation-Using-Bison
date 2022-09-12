%{
   
   #include "y.tab.h"
   int pos = 1;
   int line = 1;

%}
DIGIT [0-9] 

%%

[\n\r] {pos = 1; line++;}
[ \t]+ {pos += yyleng;}
"##".*\n {pos += yyleng;}

"function" {pos += yyleng; return FUNCTION;}
"beginparams" {pos += yyleng; return BEGIN_PARAMS;}
"endparams" {pos += yyleng; return END_PARAMS;}
"beginlocals" {pos += yyleng; return BEGIN_LOCALS;}
"endlocals" {pos += yyleng; return END_LOCALS;}
"beginbody" { pos += yyleng; return BEGIN_BODY;}
"endbody" {pos += yyleng; return END_BODY;}
"integer" {pos += yyleng; return INTEGER;}
"array" {pos += yyleng; return ARRAY;}
"of" {pos += yyleng; return OF;} 
"if" {pos += yyleng; return IF;}
"then" {pos += yyleng; return THEN;}
"endif" {pos += yyleng; return ENDIF;}
"else" {pos += yyleng; return ELSE;}
"while"  {pos += yyleng; return WHILE;}
"do"    {pos += yyleng; return DO;}
"beginloop"  {pos += yyleng; return BEGIN_LOOP;}
"endloop"  {pos += yyleng; return END_LOOP;}
"continue"  {pos += yyleng; return CONTINUE;}
"break"  {pos += yyleng; return BREAK;}
"read"  {pos += yyleng; return READ;}
"write" {pos += yyleng; return WRITE;}
"not"  {pos += yyleng; return NOT;}
"true" {pos += yyleng; return TRUE;}
"false"  {pos += yyleng; return FALSE;}
"return"  {pos += yyleng; return RETURN;}

{DIGIT}+ {yylval.num = atoi(yytext); pos += yyleng; return NUMBER;}

[0-9_]+[A-Za-z0-9_]* {printf("There is an error at line %i, column %i: identifier \"%s\" must begin with a letter\n", line, pos, yytext), pos += yyleng; exit(0);}

[0-9A-Za-z_]+_ {printf("There is an error at line %i, column %i: identifier \"%s\" cannot end with an underscore\n", line, pos, yytext), pos += yyleng; exit(0);}

[A-Za-z]+[0-9A-Za-z_]* {yylval.id = yytext; pos += yyleng; return IDENT;}

"-"  {pos += yyleng; return SUB;}
"+"  {pos += yyleng; return ADD;}
"*"  {pos += yyleng; return MULT;}
"/"  {pos += yyleng; return DIV;}
"%"  {pos += yyleng; return MOD;}

"==" {pos += yyleng; return EQ;}
"<>" {pos += yyleng; return NEQ;}
"<"  {pos += yyleng; return LT;}
">"  {pos += yyleng; return GT;}
"<="  {pos += yyleng; return LTE;}
">="  {pos += yyleng; return GTE;}

";"  {pos += yyleng; return SEMICOLON;}
":"  {pos += yyleng; return COLON;}
","  {pos += yyleng; return COMMA;}
"(" {pos += yyleng; return L_PAREN;}
")"  {pos += yyleng; return R_PAREN;}
"["  {pos += yyleng; return L_SQUARE_BRACKET;}
"]"  {pos += yyleng; return R_SQUARE_BRACKET;}
":="  {pos += yyleng; return ASSIGN;}
. {printf("Error at line %i, column %i: unrecognized symbol \"%s\"\n", line, pos, yytext); pos += yyleng; exit(0);}
                        
%%

int main(int argc, char ** argv) { 
 if (argc == 2) { 
   yyin = fopen(argv[1], "r"); 

} else { yyin = stdin; } 

  yyparse();

}


