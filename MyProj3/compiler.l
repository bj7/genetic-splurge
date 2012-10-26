%{
  #include "compiler.tab.h"
    #include "comp.h"
%}

%%

%option yylineno;

[ \t]  {                                   /*eat white space*/
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

