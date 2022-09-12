%{
   
    #include <stdio.h>
    #include <stdlib.h>
    
    extern FILE * yyin; 
    int yyerror(const char* s);
%}

%union 
{
    char* id;
    int num;
}

%error-verbose
%start P 

%token <num> NUMBER
%token <id> IDENT

%token FUNCTION 
%token BEGIN_PARAMS 
%token END_PARAMS 
%token BEGIN_LOCALS 
%token END_LOCALS 
%token BEGIN_BODY 
%token END_BODY 
%token INTEGER 
%token ARRAY 
%token OF 
%token IF 
%token THEN 
%token ENDIF 
%token ELSE 
%token WHILE 
%token DO 
%token IN 
%token BEGIN_LOOP 
%token END_LOOP  
%token BREAK 
%token CONTINUE 
%token READ 
%token WRITE 
%token TRUE 
%token FALSE 
%token RETURN
%token FOR 

%left AND
%left OR
%right NOT 
%left SUB
%left ADD
%left MULT
%left DIV
%left MOD
%left EQ
%left NEQ
%left LT
%left GT
%left LTE
%left GTE

%token SEMICOLON 
%token COLON 
%token COMMA 
%token L_PAREN 
%token R_PAREN 
%token L_SQUARE_BRACKET 
%token R_SQUARE_BRACKET

%left ASSIGN

%%

P: functions {printf("P -> functions\n");}

functions: fx functions {printf("functions -> fx functions\n");} | %empty {printf("functions -> epsilon\n");}

fx: FUNCTION id SEMICOLON BEGIN_PARAMS decs END_PARAMS BEGIN_LOCALS decs END_LOCALS BEGIN_BODY statements END_BODY {printf("fx -> FUNCTION id SEMICOLON BEGIN_PARAMS decs END_PARAMS BEGIN_LOCALS decs END_LOCALS BEGIN_BODY statements END_BODY\n");}

decs: dec SEMICOLON decs {printf("decs -> dec SEMICOLON decs\n");} | %empty {printf("decs -> epsilon\n");}

dec: ids COLON INTEGER {printf("dec -> ids COLON INTEGER\n");} | ids COLON ARRAY L_SQUARE_BRACKET number R_SQUARE_BRACKET OF INTEGER {printf("dec -> ids COLON ARRAY L_SQUARE_BRACKET number  R_SQUARE_BRACKET OF INTEGER\n");}

ids: id {printf("ids -> id\n");} | id COMMA ids {printf("ids -> id COMMA ids\n");}

id: IDENT {printf("id -> IDENT %s\n", $1);}

statements: statement SEMICOLON statements {printf("statements -> statement SEMICOLON statements\n");} | statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}

statement: st_return {printf("statement -> st_return\n");} | st_continue {printf("statement -> st_continue\n");}  | st_break  {printf("statement -> st_break\n");}|  st_write {printf("statement -> st_write\n");} | st_read {printf("statement -> st_read\n");} | st_while {printf("statement -> st_while\n");} | st_if {printf("statement -> st_if\n");} | st_var {printf("statement -> st_var\n");}  | st_do {printf("statement -> st_do\n");} | st_for {printf("statement -> st_for\n");}

st_break: BREAK {printf("st_break -> BREAK\n");}  
st_return: RETURN expression {printf("st_return -> RETURN expression\n");} 

st_continue: CONTINUE {printf("st_continue -> CONTINUE\n");}

st_write: WRITE x  {printf("st_write -> WRITE x SEMICOLON\n");}

st_read: READ x  {printf("st_read -> READ x SEMICOLON\n");}

st_while: WHILE bool_exp BEGIN_LOOP statements END_LOOP {printf("st_while -> WHILE bool_exp BEGIN_LOOP statements END_LOOP\n");} 

st_if: IF bool_exp THEN statements ENDIF {printf("st_if -> IF bool_exp THEN statements ENDIF\n");} 

st_do: DO BEGIN_LOOP statements END_LOOP {printf("st_do -> DO BEGIN_LOOP statements END_LOOP\n");} 

st_for: FOR x ASSIGN number SEMICOLON bool_exp SEMICOLON x ASSIGN expression BEGIN_LOOP statements END_LOOP {printf("st_for -> FOR x ASSIGN number  SEMICOLON bool_exp SEMICOLON x ASSIGN expression BEGIN_LOOP statements END_LOOP\n");}


bool_exp: relation_exps {printf("bool_exp -> relation_exps\n");} |  bool_exp OR relation_exps {printf("bool_exp -> bool_exp OR relation_exps\n");}

relation_exps: relation_exp {printf("relation_exps -> relation_exp\n");} | relation_exps AND relation_exp {printf("relation_exps -> relation_exps AND relation_exp\n");}

relation_exp: NOT exp_comp {printf("relation_exp -> NOT exp_comp\n");} | exp_comp  {printf("relation_exp -> exp_comp\n");} | TRUE  {printf("relation_exp -> TRUE\n");} | FALSE  {printf("relation_exp -> FALSE\n");} | L_PAREN bool_exp R_PAREN  {printf("relation_exp -> L_PAREN bool_exp R_PAREN\n");}

exp_comp: expression comp expression {printf("exp_comp -> expression comp expression\n");} 

comp: EQ {printf("comp -> EQ\n");} | NEQ {printf("comp -> NEQ\n");} | GT {printf("comp -> GT\n");} | LTE {printf("comp -> LTE\n");} | GTE {printf("comp -> GTE\n");}

st_var: x ASSIGN expression {printf("st_var -> x ASSIGN expression\n");} 

x: id {printf("x -> id\n");} | id L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("x -> id L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");} | id L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("x -> id L_SQUARE_BRACKET expression R_SQUARE_BRACKET L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}

expression: multiplicative_exp add_sub_exp {printf("expression -> multiplicative_exp add_sub_exp\n");}

multiplicative_exp: term {printf("multiplicative_exp -> term\n");} | term MULT multiplicative_exp {printf("multiplicative_exp -> term MULT multiplicative_exp\n");} | term DIV multiplicative_exp {printf("multiplicative_exp -> term DIV multiplicative_exp\n");} | term MOD multiplicative_exp {printf("multiplicative_exp -> term MOD multiplicative_exp\n");}

add_sub_exp: ADD expression {printf("add_sub_exp -> ADD expression\n");} | SUB expression {printf("add_sub_exp -> SUB expression\n");} |  %empty {printf("add_sub_exp -> epsilon\n");}

term: x {printf("term -> x\n");} | number {printf("term -> number\n");} | L_PAREN expression R_PAREN {printf("term -> L_PAREN expression R_PAREN\n");} | id L_PAREN expression exp_loop R_PAREN {printf("term -> id L_PAREN expression exp_loop R_PAREN\n");} 

number: NUMBER {printf("number -> NUMBER %d\n", $1); }
exp_loop: COMMA expression exp_loop {printf("exp_loop -> COMMA expression exp_loop\n");} | %empty {printf("exp_loop -> epsilon\n");}


%%
int yyerror (const char* s) {
    extern int line;
    extern int  pos;
    printf("Error at line %d, column %d: unexpected symbol %s\n", line, pos, s); 
    exit(1);
}
		 

