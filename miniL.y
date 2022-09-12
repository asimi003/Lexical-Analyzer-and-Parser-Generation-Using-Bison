<<<<<<< HEAD
%{
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <set>
#include <map>

using std::string;
using std::set;
using std::map;

int yylex(void);
void yyerror( const char* msg );
int numTemps, numLabels = 0;
string newTemp();
string newLabel();
extern int currLine;
extern int currPos;
FILE* yyin;
bool hasMain = false;

map<string, string> varTemp;
map<string, int> arrSize;
set<string> definedFns;
set<string> KEYWORDS { "FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "INTEGER", "ARRAY", "ENUM", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE", "FALSE", "RETURN", "BEGINBODY", "ENDBODY", "SUB", "PLUS", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN" };
%}

%union{
    int ival;
    char* sval;
    struct S {
        char* code;
    } statement;
    struct E {
        char* place;
        char* code;
        bool isArr;
    } expression;
}

%error-verbose
%start start
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS INTEGER ARRAY ENUM OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN BEGINBODY ENDBODY SUB PLUS MULT DIV MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
/* sets the datatype for the token */
%token <sval> IDENT
%token <ival> NUMBER
%type <expression> function ident declarations declaration var_list var expressions expression identifiers
%type <expression> bool_expr relation_and_expr relation_expr relation_sub comp multiplicative_expr term
%type <statement> statement statements

/* set pemdas */
%right ASSIGN
%left OR
%left AND
%right NOT
%left LT LTE GT GTE EQ NEQ
%left PLUS SUB
%left MULT DIV MOD

%%

start: 
        functions
;
functions: /* ε */ 
    { 
        if( !hasMain ){
            printf( "No main function declared\n" );
        } 
    }
    | function functions { }
;

function: FUNCTION ident SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGINBODY statements ENDBODY 
    {
        string temp = "func ";
        string s = $2.place;
        temp.append( s ).append( "\n" );

        if( s == "main" ){
                hasMain = true;
        }

        string declares = $5.code;
        int nDecs = 0;
        while( declares.find(".") != string::npos ) {
            int pos = declares.find( "." );
            declares.replace( pos, 1, "=" );
            string part = ", $" + std::to_string( nDecs ) + "\n";
            nDecs++;
            declares.replace( declares.find( "\n", pos ), 1, part );
        }

        temp.append( declares ).append( $8.code );

        string statements = $11.code;
        if( statements.find( "continue" ) != string::npos ){
            printf( "ERROR: Continue outside loop in function %s\n", $2.place);
        }

        //add the states to string
        temp.append( statements ).append( "endfunc\n\n" );
        printf( temp.c_str() );
    }

declarations: /* ε */ { 
        $$.code = strdup( "" );
        $$.place = strdup( "" );
    }
    | declaration SEMICOLON declarations { 
        string temp;
        temp.append( $1.code ).append( $3.code );
        $$.code = strdup( temp.c_str() );
        $$.place = strdup( "" );
    };
;

declaration: identifiers COLON INTEGER { 
        int left = 0;
        int right = 0;
        string parse( $1.place );
        string temp;
        bool isDone = false;
        while( !isDone ){
            right = parse.find( "|", left ); //find other possible idents
            temp.append( ". " ); //add the `. k`
            if( right == string::npos ){ //only one ident 
                string ident = parse.substr( left, right );
                //check it isnt a keyword
                if( KEYWORDS.find( ident ) != KEYWORDS.end() ){
                    printf( "Identifier $s is a resevered keyword.\n", ident.c_str() );
                }
                //check it hasnt been defined as a function or a variable
                if( definedFns.find( ident ) != definedFns.end() || varTemp.find( ident ) != varTemp.end() ){
                    printf( "Identifier $s is already declared.\n", ident.c_str() );
                } else {
                    varTemp[ident] = ident;
                    arrSize[ident] = 1;
                }
                temp.append( ident );
                isDone = true;
            } else { //there are more idents on the same line
                string ident = parse.substr( left, right - left );

                if( KEYWORDS.find( ident ) != KEYWORDS.end() ){
                    printf( "Identifier $s is a resevered keyword.\n", ident.c_str() );
                }

                if( definedFns.find( ident ) != definedFns.end() || varTemp.find( ident ) != varTemp.end() ){
                    printf( "Identifier $s is already declared.\n", ident.c_str() );
                } else {
                    varTemp[ident] = ident;
                    arrSize[ident] = 1;
                }
                temp.append( ident );
                left = right + 1;
            }
            temp.append( "\n" );
        }
        $$.code = strdup( temp.c_str() );
        string s = "";
        $$.place = strdup( "" );
}
| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER { 
    //TODO not finished
    //printf( "declaration -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF NUMBER\n"); 
    int left = 0;
    int right = 0;
    string parse( $1.place );
    string temp;
    bool isDone = false;
    while( !isDone ){
        right = parse.find( "|", left );
        temp.append( ".[] ");
        if( right == string::npos ){ //only one ident 
            string ident = parse.substr( left, right );
            //check it isnt a keyword
            if( KEYWORDS.find( ident ) != KEYWORDS.end() ){
                printf( "Identifier $s is a resevered keyword.\n", ident.c_str() );
            }
            //check it hasnt been defined as a function or a variable
            if( definedFns.find( ident ) != definedFns.end() || varTemp.find( ident ) != varTemp.end() ){
                printf( "Identifier $s is already declared.\n", ident.c_str() );
            } else {
                varTemp[ident] = ident;
                arrSize[ident] = 1;
            }
            temp.append( ident );
            isDone = true;
        } else {

        }
    }
}
| identifiers COLON ENUM L_PAREN identifiers R_PAREN { 
    printf( "declaration -> identifiers COLON ENUM L_PAREN identifiers R_PAREN\n"); 
}
;

identifiers: ident { 
    // printf( "identifiers -> ident\n"); 
    $$.place = strdup( $1.place );
    $$.code = strdup( "" );
}
| ident COMMA identifiers { 
    //printf( "identifiers -> ident COMMA identifiers\n"); 
    string s;
    s.append( $1.place ).append( "|" ).append( $3.place );
    $$.place = strdup( s.c_str() );
    $$.code = strdup( "" );
}
;

ident: IDENT { 
    if( definedFns.find( $1 ) != definedFns.end() ){
        printf( "function %s is declared already.\n", $1 );
    } else {
        definedFns.insert( $1 );
    }
    $$.place = strdup( $1 );
    $$.code = strdup( "" );
    // printf( "ident -> IDENT %s\n", $1 ); 
}
;

statements: statement SEMICOLON { 
    //printf( "statements -> ε\n"); 
    $$.code = strdup( $1.code );
}
| statement SEMICOLON statements { 
    //printf( "statements -> statement SEMICOLON statements\n"); 
    string temp;
    temp.append( $1.code );
    temp.append( $3.code );
    $$.code = strdup( temp.c_str() );
}
;

statement: var ASSIGN expression { 
    //printf( "statement -> var ASSIGN expression\n"); 
    string temp;
    temp.append( $1.code ).append( $3.code );
    string middle = $3.place;
    if($1.isArr && $3.isArr ){
        temp += "[]= ";
    } else if ( $1.isArr ){
        temp += "[]= ";
    } else {
        temp += "= ";
    }
    temp.append( $1.place ).append( ", " ).append( middle ).append( "\n" );
    $$.code = strdup( temp.c_str() );
}
| IF bool_expr THEN statements ENDIF {
    if(DEBUG_OUTPUT) printf( "statement -> IF bool_expr THEN statements ENDIF\n"); 
    string ifStart = newLabel();
    string after = newLabel();
    string t;
    //?:= label, predicate	if predicate is true (1) goto label
    t.append( $2.code );
    //true block
    t.append( "?:=" ).append( ifStart ).append( ", " ).append( $2.place ).append( "\n" );
    //else //:= label
    t.append( ":= " ).append( after ).append( "\n" );
    //TODO come back too
}
| IF bool_expr THEN statements ELSE statements ENDIF {
    if(DEBUG_OUTPUT) printf( "statement -> IF bool_expr THEN statements ELSE statements ENDIF\n"); 
}
| WHILE bool_expr BEGINLOOP statements ENDLOOP {
    if(DEBUG_OUTPUT) printf( "statement -> WHILE bool_expr BEGINLOOP statements ENDLOOP\n"); 
}
| DO BEGINLOOP statements ENDLOOP WHILE bool_expr {
    if( DEBUG_OUTPUT) printf( "statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_expr\n"); 
}
| READ var_list {
    if( DEBUG_OUTPUT) printf( "statement -> READ var_list\n"); 
}
| WRITE var_list {
    if( DEBUG_OUTPUT) printf( "statement -> WRITE var_list\n"); 
}
| CONTINUE {
    if( DEBUG_OUTPUT) printf( "statement -> CONTINUE\n"); 
}
| RETURN expression {
    if( DEBUG_OUTPUT) printf( "statement -> RETURN expression\n"); 
    string temp;
    temp.append( $2.code ).append( "ret " ).append( $2.place ).append( "\n" );
    $$.code = strdup( temp.c_str() );
}
;

bool_expr: relation_and_expr { printf( "bool_expr -> relation_and_expr\n"); }
    | relation_and_expr OR bool_expr { printf( "bool_expr -> relation_and_expr OR bool_expr\n"); }
;

relation_and_expr: relation_expr { printf( "relation_and_expr -> relation_expr\n"); }
    | relation_expr AND relation_and_expr { printf( "bool_expr -> relation_expr AND relation_and_expr\n"); }
;

relation_expr: relation_sub { printf( "relation_expr -> relation_sub\n"); }
    | NOT relation_sub  { printf( "relation_expr _> NOT relation_sub\n"); }
;

relation_sub: expression comp expression { printf( "relation_sub -> expression comp expression\n"); }
    | TRUE                           { printf( "relation_sub -> TRUE\n"); }
    | FALSE                          { printf( "relation_sub -> FALSE\n"); }
    | L_PAREN bool_expr R_PAREN      { printf( "relation_sub -> L_PAREN bool_expr R_PAREN\n"); }
;

comp: EQ       { printf( "comp -> EQ\n"); }
    | NEQ  { printf( "comp -> NEQ\n"); }
    | LT   { printf( "comp -> LT\n"); }
    | GT   { printf( "comp -> GT\n"); }
    | LTE  { printf( "comp -> LTE"); }
    | GTE  { printf( "comp -> GTE\n"); }
;

var: ident { 
    if( DEBUG_OUTPUT ) { printf( "var -> ident\n" );} 
    string id = $1.place;
    //check undeclared vars check1
    if( definedFns.find( id) == definedFns.end() && varTemp.find( id ) == varTemp.end() ){ //was not found
        string s = "Using an undeclared variable " + $1.place;
        yyerror( s.c_str() );
    }
    else if( arrSize[id] > 1 ){ //check if array check6
        string s = "Identifier did not provide index for array identifer " + id;
        yyerror( s.c_str() );
    }
    $$.place = strdup( id.c_str() );
    $$.code = strdup( "" )
    $$.arr = false;
}
| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
    if(DEBUG_OUTPUT) printf( " var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n" ); 
    string id = $1.place;
    //check undeclared vars check1
    if( definedFns.find( id) == definedFns.end() && varTemp.find( id ) == varTemp.end() ){ //was not found
        string s = "Using an undeclared variable " + $1.place;
        yyerror( s.c_str() );
    }
    else if( arrSize.find( id ) == arrSize.end() ){ //check if array check6
        string s = "Identifier is not an array identifer " + id;
        yyerror( s.c_str() );
    }
    string t;
    t.append( $1.place ).append( ", " ).append( $3.place );
    $$.code = strdup( $3.code );
    $$.place = strdup( t.c_str() );
    $$.arr = true;
}
;

//only used in read write .[](<or>) dst/src
var_list: var {
    if(DEBUG_OUTPUT) printf( "var_list -> var\n" );
    string t;
    if( $1.arr ){
        t.append( ".[]| ");
    }
    else {
        t.append( ".| " );
    }
    t.append( $1.place ).append( "\n" );

    $$.code = strdup( t.c_str() );
    $$.place = strdup( "" );
}
| var COMMA var_list {
    if(DEBUG_OUTPUT) printf( "var_list -> var COMMA var_list\n" ); 
    string t;
    if( $1.arr ){
        t.append( ".[]| ");
    }
    else {
        t.append( ".| " );
    }
    t.append( $1.place ).append( "\n" ).append( $3.code );

    $$.code = strdup( t.c_str() );
    $$.place = strdup( "" );
}
;
expression: multiplicative_expr {
    if( DEBUG_OUTPUT ) printf( "expression -> multiplicative_expr\n"); 
    $$.code = strdup( $1.code );
    $$.place = strdup( $1.place );
}
| multiplicative_expr PLUS expression {
    if( DEBUG_OUTPUT) printf( "expression -> multiplicative_expr PLUS expression\n");
    string t;
    string dest = newTemp();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "+ " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
| multiplicative_expr SUB expression {
    if(DEBUG_OUTPUT) printf( "expression -> multiplicative_expr SUB expression\n");
    string t;
    string dest = newTemp();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "- " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
;

multiplicative_expr: term {
    if(DEBUG_OUTPUT) printf( "multiplicative_expr -> term\n"); 
    $$.code = strdup( $1.code );
    $$.place = strdup( $$.place );
}
| term MULT multiplicative_expr {
    if( DEBUG_OUTPUT) printf( "multiplicative_expr -> term MULT multiplicative_expr\n"); 
    string t;
    string dest = newTemp();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "* " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
| term DIV multiplicative_expr  {
    if( DEBUG_OUTPUT ) printf( "multiplicative_expr -> term DIV multiplicative_expr\n"); 
    string t;
    string dest = newTemp();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "/ " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
| term MOD multiplicative_expr  {
    if( DEBUG_OUTPUT ) printf( "multiplicative_expr -> term MOD multiplicative_expr\n");
    string t;
    string dest = newTemp();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "% " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
;

term: var { printf( "term -> var\n" ); }
| SUB var {
    if(DEBUG_OUTPUT) printf( "term -> SUB var\n" ); 
    string dst = newTemp();
    string t;

    t.append( $2.code ).append( ". " + dst + "\n");
    if( $2.arr ){
        t.append( "=[] " + dst + ", ").append( $2.place).append( "\n" );
    }
    else {
        t.append( "= " + dst + ", " ).append( $2.place ).append( "\n" );
    }
    t.append( "* ").append($$.place ).append( ", -1\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( $2.place );
    $$.arr = false;
}
| NUMBER {
    if(DEBUG_OUTPUT) printf( "term -> NUMBER\n" ); 
    $$.code = strdup( "" );
    $$.place = strdup( std::to_string( $1 ).c_str() );
}
| SUB NUMBER {
    if(DEBUG_OUTPUT) printf( "term -> SUB NUMBER\n" ); 
    string s = "-" + std::to_string( $2 );
    $$.code = strdup( "" );
    $$.place = strdup( s.c_str() );
}
| L_PAREN expression R_PAREN {
    if( DEBUG_OUTPUT) printf( "term -> L_PAREN expression R_PAREN\n" ); 
    $$.code = strdup( $2.code );
    $$.place = strdup( $2.place );
}
| SUB L_PAREN expression R_PAREN {
    if( DEBUG_OUTPUT ) printf( "term -> SUB L_PAREN expression R_PAREN\n" ); 
    string t;
    t.append( $3.code ).append( "* ").append($3.place).append( ", ").append( $3.place)
    t.append( ", -1\n" );

    $$.code( t.c_str() );
    $$.place( $3.place );
}
| ident L_PAREN expressions R_PAREN {
    if( DEBUG_OUTPUT) printf( "term -> ident L_PAREN expressions R_PAREN\n" ); 
    string t;
    //check undeclared fn
    if( definedFns.find( $1.place ) == definedFns.end() ) {
        string s = "Using an undeclared function " + $1.place;
        yyerror( s.c_str() );
    }

    string dst = newTemp();
    //. __temp__11
    //call fibonacci, __temp__11
    t.append( $3.code );
    t.append( ". " + dst + "\n" )
    t.append( "call " ).append($1.place ).append( ", " + dst + "\n" );

    $$.code = strdup( t.c_str );
}
| ident L_PAREN  R_PAREN { printf( "term -> ident L_PAREN R_PAREN\n" ); }
;

expressions: expression { printf( "expressions -> expression\n"); }
    | expression COMMA expressions { printf( "expression COMMA expressions\n"); }
;

%%

int main( int argc, char **argv ){
        if( argc > 1 ) {
                yyin = fopen( argv[1], "r" );
                if( yyin == NULL ) printf( "error opening file" );
        }
        yyparse();
        return 0;
}

string newTemp(){
    string temp = "_t" + to_string( numTemps );
    numTemps++;
}

string newLabel(){
    string temp = "_l" + to_string( numLabels );
    numLabels++;
}

void yyerror( const char* msg ){
    printf( "** line %d, position %d: %s\n", currLine, currPos, msg );
}


=======

nclude <stdio.h>
#include <set>
#include <map>
#include <stdlib.h>
#include <cstring>

using std::string;
using std::set;
using std::map;

int yylex(void);
void yyerror( const char* msg );
int numTemps, numLabels = 0;
string tem();
string lab();

extern int currLine;
extern int currPos;
FILE* yyin;
bool hasMain = false;

map<string, string> varTemp;
map<string, int> arrSize; 
set<string> definedFns

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

start: 
        functions
;
functions: /* ε */ 
    { 
        if( !hasMain ){
            printf( "No main function declared\n" );
        } 
    }
    | function functions { }
;

declarations: /* ε */ { 
        $$.code = strdup( "" );
        $$.place = strdup( "" );
    }
    | declaration SEMICOLON declarations { 
        string temp;
        temp.append( $1.code ).append( $3.code );
        $$.code = strdup( temp.c_str() );
        $$.place = strdup( "" );
    };
;

function: FUNCTION ident SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGINBODY statements ENDBODY 
    {
        string temp = "func ";
        string s = $2.place;
        temp.append( s ).append( "\n" );

        if( s == "main" ){
                hasMain = true;
        }

        temp.append( declares ).append( $8.code );

        string statements = $11.code;
        if( statements.find( "continue" ) != string::npos ){
            printf( "ERROR: Continue outside loop in function %s\n", $2.place);
        }

        temp.append( statements ).append( "endfunc\n\n" );
        printf( temp.c_str() );
    }

ident: IDENT { 
    if( definedFns.find( $1 ) != definedFns.end() ){
        printf( "function %s is declared already.\n", $1 );
    } else {
        definedFns.insert( $1 );
    }
    $$.place = strdup( $1 );
    $$.code = strdup( "" );
    // printf( "ident -> IDENT %s\n", $1 ); 
}
;

identifiers: ident { 
    // printf( "identifiers -> ident\n"); 
    $$.place = strdup( $1.place );
    $$.code = strdup( "" );
}
| ident COMMA identifiers { 
    //printf( "identifiers -> ident COMMA identifiers\n"); 
    string s;
    s.append( $1.place ).append( "|" ).append( $3.place );
    $$.place = strdup( s.c_str() );
    $$.code = strdup( "" );
}
;

statements: statement SEMICOLON { 
    //printf( "statements -> ε\n"); 
    $$.code = strdup( $1.code );
}
| statement SEMICOLON statements { 
    //printf( "statements -> statement SEMICOLON statements\n"); 
    string temp;
    temp.append( $1.code );
    temp.append( $3.code );
    $$.code = strdup( temp.c_str() );
}
;

bool_expr: rel { printf( "bool_expr -> rel\n"); }
    | rel OR bool_expr { printf( "bool_expr -> rel OR bool_expr\n"); }
;

rel: relex { printf( "rel -> relex\n"); }
    | relex AND rel { printf( "bool_expr -> relex AND rel\n"); }
;

relex: relsub { printf( "relex -> relsub\n"); }
    | NOT relsub  { printf( "relex _> NOT relsub\n"); }
;

relsub: expression comp expression { printf( "relsub -> expression comp expression\n"); }
    | TRUE                           { printf( "relsub -> TRUE\n"); }
    | FALSE                          { printf( "relsub -> FALSE\n"); }
    | L_PAREN bool_expr R_PAREN      { printf( "relsub -> L_PAREN bool_expr R_PAREN\n"); }
;

comp: EQ       { printf( "comp -> EQ\n"); }
    | NEQ  { printf( "comp -> NEQ\n"); }
    | GT   { printf( "comp -> GT\n"); }
    | LTE  { printf( "comp -> LTE"); }
    | LT   { printf( "comp -> LT\n"); 
    | GTE  { printf( "comp -> GTE\n"); }
;

var: ident { 
    if( DEBUG_OUTPUT ) { printf( "var -> ident\n" );} 
    string id = $1.place;
    //check undeclared vars check1
    if( definedFns.find( id) == definedFns.end() && varTemp.find( id ) == varTemp.end() ){ //was not found
        string s = "Using an undeclared variable " + $1.place;
        yyerror( s.c_str() );
    }
    else if( arrSize[id] > 1 ){ //check if array check6
        string s = "Identifier did not provide index for array identifer " + id;
        yyerror( s.c_str() );
    }
    $$.place = strdup( id.c_str() );
    $$.code = strdup( "" )
    $$.arr = false;
}
| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {
    if(DEBUG_OUTPUT) printf( " var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n" ); 
    string id = $1.place;
    //check undeclared vars check1
    if( definedFns.find( id) == definedFns.end() && varTemp.find( id ) == varTemp.end() ){ //was not found
        string s = "Using an undeclared variable " + $1.place;
        yyerror( s.c_str() );
    }
    else if( arrSize.find( id ) == arrSize.end() ){ //check if array check6
        string s = "Identifier is not an array identifer " + id;
        yyerror( s.c_str() );
    }
    string t;
    t.append( $1.place ).append( ", " ).append( $3.place );
    $$.code = strdup( $3.code );
    $$.place = strdup( t.c_str() );
    $$.arr = true;
}
;

var_list: var {
    if(DEBUG_OUTPUT) printf( "var_list -> var\n" );
    string t;
    if( $1.arr ){
        t.append( ".[]| ");
    }
    else {
        t.append( ".| " );
    }
    t.append( $1.place ).append( "\n" );

    $$.code = strdup( t.c_str() );
    $$.place = strdup( "" );
}
| var COMMA var_list {
    if(DEBUG_OUTPUT) printf( "var_list -> var COMMA var_list\n" ); 
    string t;
    if( $1.arr ){
        t.append( ".[]| ");
    }
    else {
        t.append( ".| " );
    }
    t.append( $1.place ).append( "\n" ).append( $3.code );

    $$.code = strdup( t.c_str() );
    $$.place = strdup( "" );
}
;
expression: mult {
    if( DEBUG_OUTPUT ) printf( "expression -> mult\n"); 
    $$.code = strdup( $1.code );
    $$.place = strdup( $1.place );
}
| mult SUB expression {
    if(DEBUG_OUTPUT) printf( "expression -> mult SUB expression\n");
    string t;
    string dest = tem();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "- " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
| mult PLUS expression {
    if( DEBUG_OUTPUT) printf( "expression -> mult PLUS expression\n");
    string t;
    string dest = tem();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "+ " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
;

term: x {printf("term -> x\n");} | number {printf("term -> number\n");} | L_PAREN expression R_PAREN {printf("term -> L_PAREN expression R_PAREN\n");} | id L_PAREN expression exp_loop R_PAREN {printf("term -> id L_PAREN expression exp_loop R_PAREN\n");} 

number: NUMBER {printf("number -> NUMBER %d\n", $1); }
exp_loop: COMMA expression exp_loop {printf("exp_loop -> COMMA expression exp_loop\n");} | %empty {printf("exp_loop -> epsilon\n");}

st_write: WRITE x  {printf("st_write -> WRITE x SEMICOLON\n");}

st_read: READ x  {printf("st_read -> READ x SEMICOLON\n");}

st_while: WHILE bool_exp BEGIN_LOOP statements END_LOOP {printf("st_while -> WHILE bool_exp BEGIN_LOOP statements END_LOOP\n");} 

st_if: IF bool_exp THEN statements ENDIF {printf("st_if -> IF bool_exp THEN statements ENDIF\n");} 

mult: term {
    if(DEBUG_OUTPUT) printf( "mult -> term\n"); 
    $$.code = strdup( $1.code );
    $$.place = strdup( $$.place );
}
}
| term MOD mult  {
    if( DEBUG_OUTPUT ) printf( "mult -> term MOD mult\n");
    string t;
    string dest = tem();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "% " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
| term MULT mult {
    if( DEBUG_OUTPUT) printf( "mult -> term MULT mult\n"); 
    string t;
    string dest = tem();

    t.append( $1.code ).append( $3.code );
    t.append( ". " + dst + "\n" );
    t.append( "* " + dst + ", " ).append( $1.place ).append( ", " ).append( $3.place ).append( "\n");

    $$.code = strdup( t.c_str() );
    $$.place = strdup( dst.c_str() );
}
;

term: var { printf( "term -> var\n" ); }
| SUB var {
    if(DEBUG_OUTPUT) printf( "term -> SUB var\n" ); 
    string dst = tem();
    string t;

    string dst = tem();
    //. __temp__11
    //call fibonacci, __temp__11
    t.append( $3.code );
    t.append( ". " + dst + "\n" )
    t.append( "call " ).append($1.place ).append( ", " + dst + "\n" );

    $$.code = strdup( t.c_str );
}
| ident L_PAREN  R_PAREN { printf( "term -> ident L_PAREN R_PAREN\n" ); }
;

exp: expression { printf( "exp -> expression\n"); }
    | expression COMMA exp { printf( "expression COMMA exp\n"); }
;
%%
int yyerror (const char* s) {
    extern int line;
    extern int  pos;
    printf("Error at line %d, column %d: unexpected symbol %s\n", line, pos, s); 
    exit(1);
}
		 

>>>>>>> parent of dc9e677... Add files via upload
