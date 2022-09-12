<<<<<<< HEAD
%{
	#include "y.tab.h"
    int currLine = 1, currPos = 1; 
%}


DIGIT       [0-9]
ID          [a-zA-Z][a-zA-Z0-9_]*
COMMENT     ##.*
NID         [0-9_][a-zA-Z0-9_]*
NID2        [a-zA-Z][a-zA-Z0-9_]*[_]

%% 

"function"      { currPos += yyleng; return FUNCTION;     }
"beginparams"   { currPos += yyleng; return BEGIN_PARAMS; }
"endparams"     { currPos += yyleng; return END_PARAMS;   }
"beginlocals"   { currPos += yyleng; return BEGIN_LOCALS; }
"endlocals"     { currPos += yyleng; return END_LOCALS;   }
"integer"       { currPos += yyleng; return INTEGER;      }
"array"         { currPos += yyleng; return ARRAY;        }
"enum"          { currPos += yyleng; return ENUM;         }
"of"            { currPos += yyleng; return OF;           }
"if"            { currPos += yyleng; return IF;           }
"then"          { currPos += yyleng; return THEN;         }
"endif"         { currPos += yyleng; return ENDIF;        }
"else"          { currPos += yyleng; return ELSE;         }
"while"         { currPos += yyleng; return WHILE;        }
"do"            { currPos += yyleng; return DO;           }
"beginloop"     { currPos += yyleng; return BEGINLOOP;    }
"endloop"       { currPos += yyleng; return ENDLOOP;      }
"continue"      { currPos += yyleng; return CONTINUE;     }
"read"          { currPos += yyleng; return READ;         }
"write"         { currPos += yyleng; return WRITE;        }
"and"           { currPos += yyleng; return AND;          }
"or"            { currPos += yyleng; return OR;           }
"not"           { currPos += yyleng; return NOT;          }
"true"          { currPos += yyleng; return TRUE;         }
"false"         { currPos += yyleng; return FALSE;        }
"return"        { currPos += yyleng; return RETURN;       }
"beginbody"     { currPos += yyleng; return BEGINBODY;    }
"endbody"       { currPos += yyleng; return ENDBODY;      }

"-"             { currPos += yyleng; return SUB; }
"+"             { currPos += yyleng; return PLUS; }
"*"             { currPos += yyleng; return MULT;}
"/"             { currPos += yyleng; return DIV; }
"%"             { currPos += yyleng; return MOD; }

"=="            { currPos += yyleng; return EQ; }
"<>"            { currPos += yyleng; return NEQ;}
"<"             { currPos += yyleng; return LT; }
">"             { currPos += yyleng; return GT; }
"<="            { currPos += yyleng; return LTE;}
">="            { currPos += yyleng; return GTE;}

";"             { currPos += yyleng; return SEMICOLON;       }
":"             { currPos += yyleng; return COLON;           }
","             { currPos += yyleng; return COMMA;           }
"("             { currPos += yyleng; return L_PAREN;         }
")"             { currPos += yyleng; return R_PAREN;         }
"["             { currPos += yyleng; return L_SQUARE_BRACKET;}
"]"             { currPos += yyleng; return R_SQUARE_BRACKET;}
":="            { currPos += yyleng; return ASSIGN;          }

{DIGIT}+        { currPos += yyleng; yylval.ival = atoi( yytext) ; return NUMBER; }

{NID}           { printf("Error at line %d, column %d: identifier: \"%s\" must begin with a letter\n", currLine, currPos, yytext); exit(0);}
{NID2}          { printf("Error at line %d, column %d: identifier: \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); exit(0);}

{ID}            { currPos += yyleng; yylval.sval = yytext; return IDENT;}


[\ \t]+         { currPos += yyleng; }
"\n"            { currLine++; currPos = 1; }
{COMMENT}       { currLine++; currPos = 1; }


.               { printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0); }

%% 
/*
int main(int argC, char** argV)
{
    if(argC >= 2)
    {
        yyin = fopen(argV[1], "r");
        if(yyin == NULL) yyin = stdin;
    }
    else yyin = stdin;

    yylex();
    return 0;
}
*/
=======
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


>>>>>>> parent of dc9e677... Add files via upload
