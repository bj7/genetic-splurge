/************
 * compiler.y 
 * This file has been modified by Josh Bernitt for the purpose of 
 * creating a compiler. Instead of being a pure interpretter,
 * this program outputs assembly language, which can then
 * be run in an assembler.
 *
 * From http://www.gnu.org/software/bison/manual/html_mono/bison.html
 * Compile and run with
 * 
 *   $ bison compiler.y                     # creates compiler.tab.c
 *   $ gcc -lm -o comp compiler.tab.c       # creates calc executable
 *   $ ./comp
 *
 ****************************************/


 /* Compiler for my own language  */
     

 /* === C prolog === */

     %{
       #include "uthash.h"
       #include "utstring.h"
       #include <stdio.h>
       #include <string.h>
       #include <stdlib.h>
       #include <math.h>
       #include "comp.h"
       int yylex (void);
       void yyerror (char const *);
       extern int yylineno;
         
       SymbolTableEntry* symbol_table = NULL;
         
       int memsize = 0;
       int numFloats = 0;
       int numStrings = 0;
     %}

%union {
  float fval;
  int ival;
  char* sval;
  int tval;
  int bval;
};

 /* === Bison declarations === */

%token <ival> INT_NUM
%token <fval> FLOAT_NUM
%token <sval> VARNAME
%token <sval> PRINT
%token <tval> TYPE
%token <sval> EXIT
%token <sval> STRING
%token <bval> BOOL

%type <ival> exp 
     
%left '-' '+' 
%left '*' '/'
%left NEG
%right '^'
%left '&' '|'  //honestly I have no idea if this is correct 
%right '!'

 /* === Bison Grammar === */

%%

file: 
{printf("extern printf\n"\
         "printf_int:\n\t db \"%%d\", 10, 0\n"\
	 "printf_float:\n\t db\"%%f\", 10, 0\n"\
         
       	 "global main\n"\
         "global pow\n"\
       	 "global powF\t ;pow function for floats\n"\
		 
       	 "section\t .text\n"\
         "pow:\t ;declaration of power function\n\t"\
         "push ebp\n\t"\
         "mov ebp, esp\n\t"\
         "mov ecx, [ebp+8]\n\t"\
         "mov ebx, [ebp+12]\n\t"\
         "mov eax, [ebp+12]\n"\
         "Loop:\n\t"\
         "dec ecx\n\t"\
         "cmp ecx, 0\n\t"\
         "jle J1\n\t"\
         "imul ebx\n\t"\
         "jmp Loop\n"\
         "J1:\n\t"\
         "leave\n\t"\
         "ret\n\n"\
		 
       	 "powF:\t ;declaration of floating point power function\n"\
       	 "\t push ebp\n"\
       	 "\t mov ebp, esp\n"\
       	 "\t mov ecx, [ebp+8]\t ;getting the number of repitions needed\n"\
       	 "\t sub esp, 8\t ;make room for float number\n"\
       	 "\t fld QWORD [ebp+12]\t ;push the float onto the float stack st(0)\n"\
       	 "\t fld QWORD [ebp+12]\t ;push on again so st(1) now holds the same value as st(0)\n"\
       	 "\t fstp QWORD [esp]\t ;put float number into space made available so it can be accessed later\n"\
       	 "Loop2:\n"\
       	 "\t dec ecx\n"\
       	 "\t cmp ecx, 0\n"\
       	 "\t jle J2\n"\
       	 "\t fld QWORD [esp]\t ;push the float onto the float stack so st(0) and st(1) are the same\n"\
       	 "fmul\t ;multiply st(0) by st(1)\n"\
       	 "\t jmp Loop2\n"\
       	 "J2:\n"\
       	 "\t leave\n"\
       	 "\t ret\n"\

	"anded:\t ;declaration of function to determine the result of anding two booleans\n"\
	"\t push ebp\n"\
	"\t mov ebp, esp\n"\
	"\t mov eax, [ebp+8]\n"\
	"\t cmp eax, 0\t ;compare sum to 0\n"\
	"\t jnz not_true\t ;answer was not 0, thus not true so jump out\n"\
	"\t mov eax, 0\t ;mov 0 to signify it was true\n"\
	"\t jmp done\t ;jump to escape because answer was 0\n"\
	"\t not_true:\n"\
	"\t mov eax, 1\t ;mov one to signify false\n"\
	"\t done:\n"\
	"\t leave\n"\
	"\t ret\n\n"

	"noted:\t ;declaration of function to determine the result of not'ing the boolean\n"\
	"\t push ebp\n"\
	"\t mov ebp, esp\n"\
	"\t mov eax, [ebp+8]\n"\
	"\t cmp eax, 0\t ;test if we not a 0\n"\
	"\t jnz not_false\t ;eax was not 0 so we need to not a 1\n"\
	"\t mov eax, 1\t ;not 0 = 1\n"\
	"\t jmp exit\n"\
	"\t not_false:\n"\
	"\t mov eax, 0\t ;eax was originally 1 so we need to not it to a 0\n"\
	"\t exit:\n"\
	"\t leave\n"\
	"\t ret\n\n"\
         
       	 "main:\n\t"\
         "push ebp\n\t"\
         "mov ebp, esp\n\t"\
         "mov eax, 0\n\t"\
         "mov ebx, 0\n\t"\
         "mov ecx, 0\n\t"\
         "mov edx, 0\n\n");
}
program
;

program: /*empty*/
| program statement
;

statement: '\n'
| vardecl
| assignment
| print
| exp
;

vardecl: TYPE VARNAME '\n' {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, $2);
    if(test == NULL){
        SymbolTableEntry *entry = NULL;
        entry = (SymbolTableEntry*)malloc(sizeof (SymbolTableEntry));
        entry->name = $2;
        entry->type = $1;
        entry->lineno = yylineno;
        entry->offset = memsize;
        memsize += 8;
        symbolTableAddEntry(&symbol_table, entry);
    }
    else{
	char *error;
	error = (char*)malloc(1000); //this specifies a large byte allocation for the string
	fprintf(stderr, "Redeclaration of variable: %s on line: %d\n", $2, test->lineno); 
        yyerror("redeclaration of variable");
	free(error);
	exit(1);
    }
};

assignment: VARNAME '=' exp '\n' {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, $1);
	char* error;
	error = (char*)malloc(1000); //again assigning space to variable
    if(test == NULL){
	fprintf(stderr, "Symbol: %s not initialized on line: %d\n", $1, yylineno);
        yyerror("no such symbol in table");
	//printf("\t pop eax\t ;clearing symbol from stack\n\n");
	exit(1);
    }
    else if(test->type != $3){
        yyerror("type mismatch");
	//printf("\t pop eax\t ;clearing symbol from stack\n\n");
	exit(1);
    }
    else if(test->type == BOOLEAN){
	printf("\t pop eax\n"\
		"\t mov [variable_stack + %d], eax\n\n", test->offset);
    }
	//success, add the variable to the variable stack
    else if(test->type == INTEGER){
        printf("\t pop eax\n"\
	       "\t mov [variable_stack + %d], eax\n\n", test->offset);
    }
	//code for floating point numbers
    else{
	printf("\t fld QWORD [esp]\t ;load float number from stack onto float stack (st0)\n"\
       	       "\t add esp, 8\t ;remove floating point number that was on the stack\n"\
	       "\t fstp QWORD [variable_stack + %d]\t ;load float into variable stack\n\n", test->offset);
	}
    free(error);
};

print: PRINT exp '\n' {
	if($2 == INTEGER || BOOLEAN){
		printf("\t push DWORD printf_int\t ;sets up and calls print(extern)\n"\
			"\t call printf\n"\
			"\t add esp, 8\t ;clean up the DWORD and int arg that was on the stack\n\n");
	}
	else if( $2 == FLOAT){
		printf("\t push DWORD printf_float\t ;sets up calls and print\n"\
			"\t call printf\n"\
			"\t add esp, 12\t ;gotta clean up the stack else stuff gets weird\n\n");
	}
	free($1);
}; 

exp:
EXIT {printf("\t section\t .data\t ;creating global variable stack pointer\n"\
       	     "\t variable_stack:\n\t times %d db 0\n\n"\
	     "\t section\t .text\t ;going back to code section\n"\
	     "\t leave\n"\
	     "\t ret\n", memsize);
	free($1);
	YYACCEPT;
}
|
BOOL {
	printf("\t push %d\n", $1);
	$$ = BOOLEAN;
}
|
STRING {
  printf("\t section\t .data\n"\
	 "\t msg%d db %s, 0\n"\
	 "\t section\t .text\n"\
	 "\t push msg%d\n"\
	 "\t call printf\n\n", numStrings, $1, numStrings);
  numStrings++; //keep track of number of string written so each time we declare a new variable it has a unique name
  free($1);
}
|
VARNAME {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, $1);
	char *error;
    error = (char*)malloc(1000); //reserving space for the error message
	if(test == NULL){ //testing if symbol is in table
		fprintf(stderr, "Symbol: %s used on line: %d uninitialized\n", $1, yylineno);
		yyerror("error: use of uninitialized variable");
		exit(1);
	}
	else{
		$$ = test->type;
		if(test->type == INTEGER || BOOLEAN){
			printf("\t push DWORD [variable_stack + %d]\t ; pushing on variable value\n", test->offset);
		}
		else{
			$$ = FLOAT;
			printf("\t fld QWORD [variable_stack + %d]\t ;push whatever float value into st(0)\n"\
				   "\t sub esp, 8\t ;basically make room for this float on the stack\n"\
				   "\t fstp QWORD [esp]\t ;push it onto the stack\n\n", test->offset);
		}
	}
	free(error);
	free($1);
}
| INT_NUM {printf("\t push DWORD %d\t ;pushes integer onto mem stack\n\n", $1);
	$$ = INTEGER;
}
| FLOAT_NUM {printf("\t section .data\t ;defining temporary variable for floats\n"\
					"\t tempFloat%d: dq %lf\t ;need to have a different float variable for each float\n"\
					
					"\t section .text\n"\
                    "\t push DWORD [tempFloat%d + 4]\t ;push on the bottom part of the variable\n"
					"\t push DWORD [tempFloat%d] \n\n", numFloats, $1, numFloats, numFloats);
	$$ = FLOAT;
	numFloats += 1; //keeping track of number of floats so each variable has a different name
}
| exp '&''&' exp {
	if($1 != $4){
		yyerror("type mismatch");
		exit(1);
	}
	else if($1 != BOOLEAN){
		yyerror("Boolean operators only apply to boolean values");
		exit(1);
	}
	else{
		printf("\t pop ebx\n"\
			"\t pop eax\n"\
			"\t add eax, ebx\t ;adding together to see if sum is 0\n"\
			"\t push DWORD eax\t ;pushing argument on stack\n"\
			"\t call anded\t ;calling function to test the result of anding\n"\
			"\t add esp, 4\n"\
			"\t push DWORD eax\n\n");
	}
}
| exp '|''|' exp {
	if($1 != $4){
		yyerror("type mismatch");
		exit(1);
	}
	else if($1 != BOOLEAN){
		yyerror("Boolean operators only apply to boolean values");
		exit(1);
	}
	else{
		printf("\t pop ebx\n"\
			"\t pop eax\n"\
			"\t imul eax, ebx\t ;multiply together so that if a 0 and 1 came in the result is 0\n"\
			"\t push DWORD eax\t ;push result on stack\n\n");
	}
}
| '!' exp {
	printf("\t pop eax\n"\
		"\t push DWORD eax\n"\
		"\t call noted\t ;calling function to determine what value is returned after the not\n"\
		"\t add esp, 4\n"\
		"\t push DWORD eax\n\n");
}
| exp '+' exp {
	if($1 != $3){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if($1 == INTEGER){
			$$ = INTEGER;
			printf("\t pop eax\t ;adding two numbers\n"\
                      "\t pop ebx\n"\
                      "\t add eax, ebx\n"\
                      "\t push eax\n\n");
		}
		else{
			$$ = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fadd\t ;adding  st(0) to st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
	
					  //need specifics for floats
}
| exp '-' exp {
	if($1 != $3){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if($1 == INTEGER){
			$$ = INTEGER;
			printf("\t pop ebx\t ;subtracting two numbers\n"\
                      "\t pop eax\n"\
                      "\t sub eax, ebx\n"\
                      "\t push eax\n\n");
		}
		else{
			$$ = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fsub\t ;subtracting st(0) from st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
}
| exp '*' exp {
	if($1 != $3){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if($1 == INTEGER){
			$$ = INTEGER;
			printf("\t pop eax\t ;performing multiplication\n"\
                      "\t pop ebx\n"\
                      "\t imul ebx\n"\
                      "\t push eax\n\n");
		}
		else{
			$$ = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fmul\t ;subtracting st(0) from st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
}
| exp '/' exp {
	if($1 != $3){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if($1 == INTEGER){
			$$ = INTEGER;
			printf("\t pop ecx\n"\
                      "\t pop eax\n"\
                      "\t idiv ecx\n"\
                      "\t push eax\n\n");
		}
		else{
			$$ = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fdiv\t ;subtracting st(0) from st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
}
| '-' exp %prec NEG {
	if($2 == INTEGER){
		$$ = INTEGER;
		printf("\t pop eax\n"\
               "\t neg eax\n"\
               "\t push DWORD eax\n\n");
	}
	else{
		$$ = FLOAT;
		printf("\t fld QWORD [esp]\t ;pushing number onto float stack\n"\
				"\t add esp, 8\t ;clearing that float from the stack\n"\
				"\t fchs\t ;negating value in st(0)\n"\
				"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
				"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
	}
}
| exp '^' exp {
	if($1 == INTEGER && $3 != INTEGER){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if($1 == INTEGER){
			$$ = INTEGER;
			printf("\t call pow\n"\
                   "\t add esp, 8\n"\
                   "\t push eax\n\n");
		}
		else if ($1 == FLOAT && $3 == INTEGER){
			$$ = FLOAT;
			printf("\t call powF\t ;calling floating point power. Args already on the stack\n"\
					"\t add esp, 12\t ;clearing that float from the stack along with the int exponent\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
		else{
			fprintf(stderr, "Cannot do fractional exponents\n");
			exit(1);
		}
	}    
}
| '(' exp ')' { $$ = $2;

}
; 

%%

 /* === C epilog === */
     
/* Called by yyparse on error.  */
void yyerror (char const *s){
    fprintf(stderr, "%s\n", s);
}
    
int yywrap(){
	return 1;
}
     
int main(void){
	yyparse();
}

SymbolTableEntry *symbolTableGetEntry(SymbolTableEntry **symbol_table, char* key){
    SymbolTableEntry *entry = NULL;
    HASH_FIND_STR(*symbol_table, key, entry);
    return entry;
}

void symbolTableAddEntry(SymbolTableEntry **symbol_table, SymbolTableEntry *entry){
    HASH_ADD_KEYPTR(hh, *symbol_table, entry->name, strlen(entry->name), entry);
}
  


