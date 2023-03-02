%{
    /*definition section */
    #include <stdio.h>
    #include "TableSymboles.h"
    #include "parser.tab.h"
    int yyerror(const char *s);
    int cptLigne;
    extern SYMTABLE *TS;
%}

%option noyywrap 

blank [ \t]+
MAJ [A-Z]
MIN [a-z]
DIGIT [0-9]
EOL [\n]
MODELS models
MAIN main

BOOL "true"|"false"
STRING \".*\"

%x comment 
%%
"#" return (KEY);
"program" return (PROGKEY);
"def" return (SECTDEFKEY);
"$" {BEGIN(comment); /*start comment state*/}
<comment>"$" {BEGIN(INITIAL); /*when finding a $ => go back to regular state*/}
<comment>\n {/* do nothing */}
<comment>. {/* do nothing */}


"end" return (ENDPROG);
"{" return (CURLYSTART);
"}" return (CURLYEND);
"(" return (PARENTESESTART);
")" return (PARENTESEEND);
"[" return (BRACKETSTART);
"]" return (BRACKETEND);
"+" return (PLUS);
"-" return (MINUS);
"*" return (MULT);
"%" return (DIV);
">" return (SUP);
">=" return (SUPEQ);
"<" return (INF);
"<=" return (INFEQ);
"==" return (EQ);
"!=" return (NEQ);
"&&" return (AND);
"||" return (OR);
"!" return(NOT);

";" return (END);

{MODELS} return (MODELS);
{MAIN} return (MAIN);
{blank}  { /* ignore whitespace */ }
{EOL} { cptLigne++; /* ignore lines */ };
"var" {
    yylval.type = VAR;
    return (KEYVAR);}
"const" {
    yylval.type = CONST;
    return (KEYCONST);}
"for" return (KEYFOR);
"while" return (KEYWHILE);
"do" return (KEYDO);
"if" return (KEYIF);
"then" return (KEYTHEN);
"else" return (KEYELSE);
":" return (TWODOTS);
"=" return (ASSIGN);
"," return (COMMA);

"array" {
    yylval.type = ARRAY;
    return (KEYARRAY);}


"return" return (RETURNKEY);

"str" {
    //declarative keyword : str

    yylval.type = STR;
    return (DECSTR);
    }

"int" {
    yylval.type = INT;
    return (DECINT);
}
"bool" {
    yylval.type = BOOL;
    //printf("found a %d", yylval.type);
    return (DECBOOL);
}

"real" {
    yylval.type = REAL;
    return (DECREAL);
}


{DIGIT}+ {
   // yylval.integer = atoi(yytext);
   yylval.value = strdup(yytext);
   //printf(yylval.value);
    return (TYPEINT);
}

{DIGIT}+("."{DIGIT}*) {
    //yylval.real = strtod(yytext, NULL);
    yylval.value = strdup(yytext);
    //printf(yylval.value);
    return (TYPEREAL);
    }
{BOOL} {
     yylval.value = strdup(yytext);
    //printf(yylval.value);
    return (TYPEBOOL);
}

{STRING} {
    yylval.value = strdup(yytext);
    //printf(yylval.value);
    return (TYPESTR);
    }

{MIN}({MIN}*{MAJ}*{DIGIT}*)* {
    yylval.id =  strdup(yytext);
    return (IDENTIFIER);
}



. {
    fprintf(stderr,"\tERREUR : a la ligne %d. Il s'agit de %s et comporte %d lettre(s)\n",cptLigne,yytext,yyleng);
}

%%
