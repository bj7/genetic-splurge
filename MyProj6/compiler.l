%{
  #include "compiler.tab.h"
    #include "comp.h"
%}

%%

%option yylineno;

[ \t][ \n]*  {                                   /*eat white space*/
}

return {
	yylval.ival = PROC;
	return RETURN;
}

call {
	yylval.ival = PROC;
	return CALL;
}

define {
	yylval.ival = PROC;
	return DEFINE;
}

for {
	yylval.ival = INTEGER;
	return FOR;
}

while {
	yylval.ival = INTEGER;
	return WHILE;
}

readInt {
	yylval.ival = INTEGER;
	return READINT;
}

readFloat {
	yylval.ival = FLOAT;
	return READFLOAT;
}

if {
	yylval.ival = INTEGER;
	return IF;
}	
true {
	yylval.bval = TRUE;
	return BOOL;
}

false {
	yylval.bval = FALSE;
	return BOOL;
}

bool {
	yylval.tval = BOOLEAN;
	return TYPE;
}

\"[^"\n]*["\n"] {			/*quoted strings*/
	yylval.sval = strdup(yytext);
	return STRING;
}

exit {
	yylval.sval = strdup(yytext);
	return EXIT;
}

print {
    yylval.sval = strdup(yytext);                   /*match to print newline*/
    return PRINT;
}

int {
    yylval.tval = INTEGER;
    return TYPE;
}

float {
    yylval.tval = FLOAT;
    return TYPE;
}

[a-zA-Z][a-zA-Z0-9]* {                     /*match a variable name*/
  yylval.sval = strdup(yytext);
  return VARNAME;
}

[0-9]+ {                                   /*match an integer*/
  yylval.ival = atoi(yytext);
  return INT_NUM;
}

[0-9]+"."[0-9]+|"."[0-9]+ {              /*match a float*/
   yylval.fval = atof(yytext);
   return FLOAT_NUM;
}

. {
  return (int)(*yytext);                  /*match some operator*/
}

\n {
  return (int)(*yytext);
}

%%

