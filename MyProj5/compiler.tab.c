/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 23 "compiler.y"

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
         
		 /* all of these tracking variables are used inside the assembly statements
		 * allow jumps and declarations of variables with unique names and such*/
       int memsize = 0;		//tracking memory offset
       int numFloats = 0;	//tracking floats
       int numStrings = 0;	//tracking strings
	   int jumps = 0;		//number of jumps so far so each one has a unique label
	   int numifs = 0; 		//tracking if statements
	   int numwhiles = 0; //tracking while statements
	   int numfors = 0;
	   int inner = 0; //counter for jumps inside for loop
	   int inc = 0; //counter for jumps to the incremental section of for loop
     

/* Line 189 of yacc.c  */
#line 100 "compiler.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     INT_NUM = 258,
     FLOAT_NUM = 259,
     VARNAME = 260,
     PRINT = 261,
     TYPE = 262,
     EXIT = 263,
     STRING = 264,
     BOOL = 265,
     IF = 266,
     READINT = 267,
     READFLOAT = 268,
     WHILE = 269,
     FOR = 270,
     DEFINE = 271,
     NEG = 272
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 50 "compiler.y"

  float fval;
  int ival;
  char* sval;
  int tval;
  int bval;



/* Line 214 of yacc.c  */
#line 163 "compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 175 "compiler.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   412

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  119

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   272

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,     2,     2,     2,    17,     2,
      33,    34,    27,    26,     2,    25,     2,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      20,    21,    22,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    30,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,    18,    24,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    16,    19,
      22,    25,    28,    31,    34,    37,    40,    43,    47,    50,
      53,    54,    57,    58,    61,    62,    63,    73,    74,    75,
      76,    89,    90,   100,   102,   104,   106,   108,   110,   112,
     116,   121,   126,   131,   135,   140,   145,   150,   153,   157,
     161,   165,   169,   172,   176,   180,   181
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      36,     0,    -1,    -1,    37,    38,    -1,    -1,    38,    39,
      -1,    31,    -1,    40,    32,    -1,    41,    32,    -1,    42,
      32,    -1,    43,    32,    -1,    46,    32,    -1,    49,    32,
      -1,    53,    32,    -1,    55,    32,    -1,    56,    32,    -1,
       7,     5,    -1,     5,    21,    55,    -1,     6,    55,    -1,
       6,    43,    -1,    -1,    12,    44,    -1,    -1,    13,    45,
      -1,    -1,    -1,    14,    47,    33,    55,    34,    48,    23,
      38,    24,    -1,    -1,    -1,    -1,    15,    33,    41,    50,
      55,    51,    41,    34,    52,    23,    38,    24,    -1,    -1,
      16,     5,    33,    55,    34,    54,    23,    38,    24,    -1,
       8,    -1,    10,    -1,     9,    -1,     5,    -1,     3,    -1,
       4,    -1,    55,    20,    55,    -1,    55,    20,    21,    55,
      -1,    55,    21,    21,    55,    -1,    55,    19,    21,    55,
      -1,    55,    22,    55,    -1,    55,    22,    21,    55,    -1,
      55,    17,    17,    55,    -1,    55,    18,    18,    55,    -1,
      19,    55,    -1,    55,    26,    55,    -1,    55,    25,    55,
      -1,    55,    27,    55,    -1,    55,    28,    55,    -1,    25,
      55,    -1,    55,    30,    55,    -1,    33,    55,    34,    -1,
      -1,    11,    33,    55,    34,    57,    23,    38,    24,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    93,   183,   184,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   199,   221,   254,   267,
     280,   280,   297,   297,   315,   315,   315,   330,   330,   330,
     330,   350,   350,   360,   369,   374,   384,   408,   411,   420,
     454,   487,   522,   555,   587,   624,   641,   657,   671,   699,
     725,   751,   777,   793,   819,   823,   823
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "FLOAT_NUM", "VARNAME",
  "PRINT", "TYPE", "EXIT", "STRING", "BOOL", "IF", "READINT", "READFLOAT",
  "WHILE", "FOR", "DEFINE", "'&'", "'|'", "'!'", "'<'", "'='", "'>'",
  "'{'", "'}'", "'-'", "'+'", "'*'", "'/'", "NEG", "'^'", "'\\n'", "';'",
  "'('", "')'", "$accept", "file", "$@1", "program", "statement",
  "vardecl", "assignment", "print", "read", "$@2", "$@3", "whileloop",
  "@4", "$@5", "forloop", "@6", "@7", "$@8", "proc", "$@9", "exp",
  "ifstate", "$@10", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,    38,   124,    33,
      60,    61,    62,   123,   125,    45,    43,    42,    47,   272,
      94,    10,    59,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    40,    41,    42,    42,
      44,    43,    45,    43,    47,    48,    46,    50,    51,    52,
      49,    54,    53,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    57,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     3,     2,     2,
       0,     2,     0,     2,     0,     0,     9,     0,     0,     0,
      12,     0,     9,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     4,     3,     4,     4,     4,     2,     3,     3,
       3,     3,     2,     3,     3,     0,     8
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     4,     1,     3,    37,    38,    36,     0,     0,
      33,    35,    34,     0,    20,    22,    24,     0,     0,     0,
       0,     6,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    19,    18,    16,     0,    21,
      23,     0,     0,     0,    47,    52,     0,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    14,    15,    17,     0,     0,
       0,    27,     0,    54,     0,     0,     0,     0,    39,     0,
       0,    43,    49,    48,    50,    51,    53,    55,     0,     0,
       0,    45,    46,    42,    40,    41,    44,     0,    25,    28,
      31,     4,     0,     0,     0,     0,     4,     0,     4,    56,
       0,    29,     0,    26,     0,    32,     4,     0,    30
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,    23,    24,    25,    26,    27,    39,
      40,    28,    41,   102,    29,    89,   103,   114,    30,   104,
      31,    32,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -73
static const yytype_int16 yypact[] =
{
     -73,     6,   -73,   -73,   203,   -73,   -73,   -13,    14,     4,
     -73,   -73,   -73,   -20,   -73,   -73,   -73,   -18,     5,   259,
     259,   -73,   259,   -73,   -16,   -12,   -11,    -4,    -1,     0,
       3,   340,     9,   259,   -73,   -73,   356,   -73,   259,   -73,
     -73,    12,    37,    13,   382,    18,   268,   -73,   -73,   -73,
     -73,   -73,   -73,   -73,    26,    32,    36,   221,    38,   240,
     259,   259,   259,   259,   259,   -73,   -73,   370,   286,   259,
     -13,   -73,   259,   -73,   259,   259,   259,   259,   -23,   259,
     259,   -23,    10,    10,    18,    18,    18,   -73,   304,   259,
     322,   382,   382,   -23,   -23,   -23,   -23,    35,   -73,   356,
     -73,   -73,    40,    37,    42,    79,   -73,    39,   -73,   -73,
     110,   -73,   141,   -73,    47,   -73,   -73,   172,   -73
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,   -73,   -72,   -73,   -73,   -41,   -73,    52,   -73,
     -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
      -8,   -73,   -73
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      36,    71,    60,    61,    62,    63,     3,    64,    33,    37,
      43,    44,    45,    38,    46,    42,    47,     5,     6,    34,
      48,    49,    10,    11,    12,    67,    14,    15,    50,   105,
      68,    51,    52,    19,   110,    53,   112,    62,    63,    20,
      64,    66,    70,    74,   117,    69,    72,    22,    64,    78,
      75,    81,    82,    83,    84,    85,    86,    76,   101,    79,
      35,    88,   107,   106,    90,   108,    91,    92,    93,    94,
     116,    95,    96,   111,     0,     0,     0,     0,     0,     0,
       0,    99,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,     0,     0,    19,     0,
       0,     0,     0,   109,    20,     0,     0,     0,     0,     0,
      21,     0,    22,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,     0,     0,    19,
       0,     0,     0,     0,   113,    20,     0,     0,     0,     0,
       0,    21,     0,    22,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     0,     0,
      19,     0,     0,     0,     0,   115,    20,     0,     0,     0,
       0,     0,    21,     0,    22,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,     0,
       0,    19,     0,     0,     0,     0,   118,    20,     0,     0,
       0,     0,     0,    21,     0,    22,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
       0,     0,    19,     0,     5,     6,    34,     0,    20,    10,
      11,    12,     0,     0,    21,     0,    22,     0,     0,     0,
      19,     0,    77,     5,     6,    34,    20,     0,    10,    11,
      12,     0,     0,     0,    22,     0,     0,     0,     0,    19,
       0,    80,     5,     6,    34,    20,     0,    10,    11,    12,
       0,     0,     0,    22,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    20,    54,    55,    56,    57,    58,
      59,     0,    22,    60,    61,    62,    63,     0,    64,     0,
       0,     0,    73,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,    62,    63,     0,    64,     0,     0,     0,
      87,    54,    55,    56,    57,    58,    59,     0,     0,    60,
      61,    62,    63,     0,    64,     0,     0,     0,    98,    54,
      55,    56,    57,    58,    59,     0,     0,    60,    61,    62,
      63,     0,    64,     0,     0,     0,   100,    54,    55,    56,
      57,    58,    59,     0,     0,    60,    61,    62,    63,     0,
      64,     0,    65,    54,    55,    56,    57,    58,    59,     0,
       0,    60,    61,    62,    63,     0,    64,    54,    55,     0,
      57,    58,    59,     0,     0,    60,    61,    62,    63,     0,
      64,    56,    57,    58,    59,     0,     0,    60,    61,    62,
      63,     0,    64
};

static const yytype_int8 yycheck[] =
{
       8,    42,    25,    26,    27,    28,     0,    30,    21,     5,
       5,    19,    20,    33,    22,    33,    32,     3,     4,     5,
      32,    32,     8,     9,    10,    33,    12,    13,    32,   101,
      38,    32,    32,    19,   106,    32,   108,    27,    28,    25,
      30,    32,     5,    17,   116,    33,    33,    33,    30,    57,
      18,    59,    60,    61,    62,    63,    64,    21,    23,    21,
       8,    69,   103,    23,    72,    23,    74,    75,    76,    77,
      23,    79,    80,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    89,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,    -1,
      31,    -1,    33,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,    -1,
      -1,    31,    -1,    33,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    -1,
      19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    -1,    31,    -1,    33,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    19,    -1,    -1,    -1,    -1,    24,    25,    -1,    -1,
      -1,    -1,    -1,    31,    -1,    33,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    -1,    19,    -1,     3,     4,     5,    -1,    25,     8,
       9,    10,    -1,    -1,    31,    -1,    33,    -1,    -1,    -1,
      19,    -1,    21,     3,     4,     5,    25,    -1,     8,     9,
      10,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    19,
      -1,    21,     3,     4,     5,    25,    -1,     8,     9,    10,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    19,    -1,
      -1,    -1,    -1,    -1,    25,    17,    18,    19,    20,    21,
      22,    -1,    33,    25,    26,    27,    28,    -1,    30,    -1,
      -1,    -1,    34,    17,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    -1,    -1,    -1,
      34,    17,    18,    19,    20,    21,    22,    -1,    -1,    25,
      26,    27,    28,    -1,    30,    -1,    -1,    -1,    34,    17,
      18,    19,    20,    21,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    30,    -1,    -1,    -1,    34,    17,    18,    19,
      20,    21,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    -1,    32,    17,    18,    19,    20,    21,    22,    -1,
      -1,    25,    26,    27,    28,    -1,    30,    17,    18,    -1,
      20,    21,    22,    -1,    -1,    25,    26,    27,    28,    -1,
      30,    19,    20,    21,    22,    -1,    -1,    25,    26,    27,
      28,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    36,    37,     0,    38,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    19,
      25,    31,    33,    39,    40,    41,    42,    43,    46,    49,
      53,    55,    56,    21,     5,    43,    55,     5,    33,    44,
      45,    47,    33,     5,    55,    55,    55,    32,    32,    32,
      32,    32,    32,    32,    17,    18,    19,    20,    21,    22,
      25,    26,    27,    28,    30,    32,    32,    55,    55,    33,
       5,    41,    33,    34,    17,    18,    21,    21,    55,    21,
      21,    55,    55,    55,    55,    55,    55,    34,    55,    50,
      55,    55,    55,    55,    55,    55,    55,    57,    34,    55,
      34,    23,    48,    51,    54,    38,    23,    41,    23,    24,
      38,    34,    38,    24,    52,    24,    23,    38,    24
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 93 "compiler.y"
    {printf("extern printf\n"\
		"extern scanf\n"\
         "printf_int:\n\t db \"%%d\", 10, 0\n"\
	     "printf_float:\n\t db\"%%f\", 10, 0\n"\
         
		 "readNumMsg: db \"Enter number: \", 0\n"\
		 "scanf_int: db \"%%d\", 0\n"\
		 "scanf_float: db \"%%lf\", 0\n"\
		 
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
       	 "\t ret\n\n"\

		"or_ed:\n"\
		"\t push ebp\n"\
		"\t mov ebp, esp\n"\
		"\t mov ecx, [ebp+8]\n"\
		"\t mov eax, [ebp+12]\n"\
		"\t add eax, ecx\t ;adding together because answer will only be 0 iff both operands were\n"\
		"\t cmp eax, 0\n"\
		"\t jnz true\n"\
		"\t mov eax, 0\n"\
		"\t jmp done\n"\
		"\t true:\n"\
		"\t mov eax, 1\n"\
		"\t done:\n"\
		"\t leave\n"\
		"\t ret\n\n"\

		"not_ed:\t ;declaration of function to determine the result of not'ing the boolean\n"\
		"\t push ebp\n"\
		"\t mov ebp, esp\n"\
		"\t mov eax, [ebp+8]\n"\
		"\t cmp eax, 0\t ;test if not a 0\n"\
		"\t jz not_false\t ;eax was not 0 so we need to not a 1\n"\
		"\t mov eax, 0\t ;not 1 = 0\n"\
		"\t jmp exit\n"\
		"\t not_false:\n"\
		"\t mov eax, 1\t ;eax was originally 0 so we need to not it to a 1\n"\
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
;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 199 "compiler.y"
    {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, (yyvsp[(2) - (2)].sval));
    if(test == NULL){
        SymbolTableEntry *entry = NULL;
        entry = (SymbolTableEntry*)malloc(sizeof (SymbolTableEntry));
        entry->name = (yyvsp[(2) - (2)].sval);
        entry->type = (yyvsp[(1) - (2)].tval);
        entry->lineno = yylineno;
        entry->offset = memsize;
        memsize += 8;
        symbolTableAddEntry(&symbol_table, entry);
    }
    else{
	char *error;
	error = (char*)malloc(1000); //this specifies a large byte allocation for the string
	fprintf(stderr, "Redeclaration of variable: %s on line: %d\n", (yyvsp[(2) - (2)].sval), test->lineno); 
        yyerror("redeclaration of variable");
	free(error);
	exit(1);
    }
;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 221 "compiler.y"
    {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, (yyvsp[(1) - (3)].sval));
	char* error;
	error = (char*)malloc(1000); //again assigning space to variable
    if(test == NULL){
	fprintf(stderr, "Symbol: %s not initialized on line: %d\n", (yyvsp[(1) - (3)].sval), yylineno);
        yyerror("no such symbol in table");
	//printf("\t pop eax\t ;clearing symbol from stack\n\n");
	exit(1);
    }
    else if(test->type != (yyvsp[(3) - (3)].ival)){
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
;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 254 "compiler.y"
    {
	if((yyvsp[(2) - (2)].ival) == INTEGER || (yyvsp[(2) - (2)].ival) == BOOLEAN){
		printf("\t push DWORD printf_int\t ;sets up and calls print(extern)\n"\
			"\t call printf\n"\
			"\t add esp, 8\t ;clean up the DWORD and int arg that was on the stack\n\n");
	}
	else if( (yyvsp[(2) - (2)].ival) == FLOAT){
		printf("\t push DWORD printf_float\t ;sets up calls and print\n"\
			"\t call printf\n"\
			"\t add esp, 12\t ;gotta clean up the stack else stuff gets weird\n\n");
	}
	free((yyvsp[(1) - (2)].sval));
;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 267 "compiler.y"
    {
	if((yyvsp[(2) - (2)].ival) == INTEGER){
	printf("\t push DWORD printf_int\n"\
			"\t call printf\n"\
			"\t add esp, 8\n\n");
	}
	if((yyvsp[(2) - (2)].ival) == FLOAT){
		printf("\t push DWORD printf_float\n"\
				"\t call printf\n"\
				"\t add esp, 12\n\n");
	}
;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 280 "compiler.y"
    {
		printf("\t push readNumMsg\t ;message to prompt user for input\n"\
				"\t call printf\n"\
				"\t add esp, 4\n");
		;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 284 "compiler.y"
    {
	
	if((yyvsp[(1) - (2)].ival)== INTEGER){
		printf("\t sub esp, 4\t ;making room for result from scanf\n"\
				"\t lea eax, [esp]\t ;putting the address of the free space into eax\n"\
				"\t push DWORD eax\n"\
				"\t push DWORD scanf_int\n"\
				"\t call scanf\n"\
				"\t add esp, 8\t ;removing the last two push instructions\n");
		(yyval.ival) = INTEGER;
	}
;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 297 "compiler.y"
    {
	printf("\t push readNumMsg\t ;message to prompt user for input\n"\
			"\t call printf\n"\
			"\t add esp, 4\n");
		;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 301 "compiler.y"
    {
		
	if((yyvsp[(1) - (2)].ival)== FLOAT){
		printf("\t sub esp, 8\n"\
				"\t push DWORD esp\n"\
				"\t push DWORD scanf_float\t ;pushing on the format argument for integers\n"\
				"\t call scanf\n"\
				"\t add esp, 8\n\n");
		
		numFloats++;
		(yyval.ival) = FLOAT;
	}
;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 315 "compiler.y"
    {(yyval.ival) = printf("\t whileloop%d:\n", numwhiles);;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 315 "compiler.y"
    {
	(yyvsp[(1) - (5)].ival) = numwhiles;
	
	printf("\t pop eax\n"\
			"\t cmp eax, 0\t ;testing if the exp evaluated to a false\n"\
			"\t je while_out%d\n", numwhiles);
	
	numwhiles++;
;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 324 "compiler.y"
    {
	int while_out = (yyvsp[(1) - (9)].ival); //just keeping track of what while statement we're on
	printf("\t jmp whileloop%d\n", (yyvsp[(1) - (9)].ival));
	printf("\t while_out%d:\n", while_out);
;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 330 "compiler.y"
    {(yyval.ival) = printf("\t forloop%d:\n", numfors);;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 330 "compiler.y"
    {(yyval.ival) = printf("\t jmp inner%d\t ;skip increment on first pass\n \t inc%d:\n", numfors, numfors);;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 330 "compiler.y"
    {
	(yyvsp[(1) - (8)].ival) = numfors;
	
	printf("\t jmp forloop%d\n"\
			"\t inner%d:\n"\
			"\t pop eax\n"\
			"\t cmp eax, 0\t ;testing if the exp evaluated to a false\n"\
			"\t je for_out%d\n", numfors, numfors, numfors);
	
	numfors++;
;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 341 "compiler.y"
    {
	int for_out = (yyvsp[(1) - (12)].ival); //just keeping track of what while statement we're on
	printf("\t jmp inc%d\t ;time to jump bakc and increment the variable counter\n", (yyvsp[(1) - (12)].ival));
	printf("\t for_out%d:\n", for_out);
	jumps++;
	inner++;
	inc++;
;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 350 "compiler.y"
    {

;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 353 "compiler.y"
    {

;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 360 "compiler.y"
    {printf("\t section\t .data\t ;creating global variable stack pointer\n"\
       	     "\t variable_stack:\n\t times %d db 0\n\n"\
			"\t section\t .text\t ;going back to code section\n"\
			"\t leave\n"\
			"\t ret\n", memsize);
	free((yyvsp[(1) - (1)].sval));
	YYACCEPT;
;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 369 "compiler.y"
    {
	printf("\t push %d\n", (yyvsp[(1) - (1)].bval));
	(yyval.ival) = BOOLEAN;
;}
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 374 "compiler.y"
    {
  printf("\t section\t .data\n"\
	 "\t msg%d db %s, 10, 0\n"\
	 "\t section\t .text\n"\
	 "\t push msg%d\n"\
	 "\t call printf\n\n", numStrings, (yyvsp[(1) - (1)].sval), numStrings);
  numStrings++; //keep track of number of string written so each time we declare a new variable it has a unique name
  free((yyvsp[(1) - (1)].sval));
;}
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 384 "compiler.y"
    {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, (yyvsp[(1) - (1)].sval));
	char *error;
    error = (char*)malloc(1000); //reserving space for the error message
	if(test == NULL){ //testing if symbol is in table
		fprintf(stderr, "Symbol: %s used on line: %d uninitialized\n", (yyvsp[(1) - (1)].sval), yylineno);
		yyerror("error: use of uninitialized variable");
		exit(1);
	}
	else{
		(yyval.ival) = test->type;
		if(test->type == INTEGER || test->type == BOOLEAN){
			printf("\t push DWORD [variable_stack + %d]\t ; pushing on variable value\n", test->offset);
		}
		else{
			(yyval.ival) = FLOAT;
			printf("\t fld QWORD [variable_stack + %d]\t ;push whatever float value into st(0)\n"\
				   "\t sub esp, 8\t ;basically make room for this float on the stack\n"\
				   "\t fstp QWORD [esp]\t ;push it onto the stack\n\n", test->offset);
		}
	}
	free(error);
	free((yyvsp[(1) - (1)].sval));
;}
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 408 "compiler.y"
    {printf("\t push DWORD %d\t ;pushes integer onto mem stack\n\n", (yyvsp[(1) - (1)].ival));
	(yyval.ival) = INTEGER;
;}
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 411 "compiler.y"
    {printf("\t section .data\t ;defining temporary variable for floats\n"\
					"\t tempFloat%d: dq %lf\t ;need to have a different float variable for each float\n"\
					
					"\t section .text\n"\
                    "\t push DWORD [tempFloat%d + 4]\t ;push on the bottom part of the variable\n"
					"\t push DWORD [tempFloat%d] \n\n", numFloats, (yyvsp[(1) - (1)].fval), numFloats, numFloats);
	(yyval.ival) = FLOAT;
	numFloats += 1; //keeping track of number of floats so each variable has a different name
;}
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 420 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){
		yyerror("type mismatch in expression with '<'");
		exit(1);
	}
	else if((yyvsp[(1) - (3)].ival) == INTEGER){
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t cmp eax, ecx\n"\
			"\t mov eax, 0\n"\
			"\t setl al\n"\
			"\t push eax\n\n");
	}
	else if((yyvsp[(1) - (3)].ival) == FLOAT){
		(yyval.ival) = BOOLEAN;
		printf("\t fld QWORD [esp]\n"\
			"\t fld QWORD [esp+8]\n"\
			"\t add esp, 16\n"\
			"\t fcompp\t ;compares st0 and st1 and pops twice\n"\
			"\t mov eax, 0\t ;zero it out\n"\
			"\t fstsw ax\t ;push the flags set into ax\n"\
			"\t and eax, 0x4100\t ;finding the flags of interest\n"\
			"\t cmp eax, 0x0100\t ;testing if the flag we want was set\n"\
			"\t sete al\t ;if it was set the lowest bit in al\n"\
			"\t cmp eax, 0\n"\
			"\t jz done%d\n"\
			"\t mov eax, 0\n"\
			"\t mov eax, 1\n"\
			"\t done%d:\n"\
			"\t push DWORD eax\n\n", jumps, jumps);
		jumps++;
	}
;}
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 454 "compiler.y"
    {
	if((yyvsp[(1) - (4)].ival) != (yyvsp[(4) - (4)].ival)){
		yyerror("type mismatch in expression with '<='");
		exit(1);
	}
	else if((yyvsp[(1) - (4)].ival) == INTEGER){
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t cmp eax, ecx\n"\
			"\t mov eax, 0\n"\
			"\t setbe al\n"\
			"\t push eax\n\n");
	}
	else if((yyvsp[(1) - (4)].ival) == FLOAT){
		(yyval.ival) = BOOLEAN;
		printf("\t fld QWORD [esp]\n"\
			"\t fld QWORD [esp+8]\n"\
			"\t add esp, 16\n"\
			"\t fcompp\n"\
			"\t mov eax, 0\n"\
			"\t fstsw ax\n"\
			"\t and eax, 0x4100\n"\
			"\t setnz al\n"\
			"\t cmp eax, 0\n"\
			"\t jz done%d\n"\
			"\t mov eax, 0\n"\
			"\t mov eax, 1\n"\
			"\t done%d:\n"\
			"\t push DWORD eax\n\n", jumps, jumps);
		jumps++;
	}
;}
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 487 "compiler.y"
    {
	if((yyvsp[(1) - (4)].ival) != (yyvsp[(4) - (4)].ival)){
		yyerror("type mismatch in expression with '<='");
		exit(1);
	}
	else if((yyvsp[(1) - (4)].ival) == INTEGER){
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t cmp eax, ecx\n"\
			"\t mov eax, 0\n"\
			"\t sete al\n"\
			"\t push eax\n\n");
	}
	else if((yyvsp[(1) - (4)].ival) == FLOAT){
		(yyval.ival) = BOOLEAN;
		printf("\t fld QWORD [esp]\n"\
			"\t fld QWORD [esp+8]\n"\
			"\t add esp, 16\n"\
			"\t fcompp\n"\
			"\t mov eax, 0\n"\
			"\t fstsw ax\n"\
			"\t and eax, 0x00004100\n"\
			"\t cmp eax, 0x00004000\t ;testing if the bit we want was set\n"\
			"\t sete al\t if it was set the lowest bit in al\n"\
			"\t and eax, 0x0001\t ;testing if the lowest bit has been set in al, if not it will be 0\n"\
			"\t cmp eax, 0\n"\
			"\t jz done%d\n"\
			"\t mov eax, 0\n"\
			"\t mov eax, 1\n"\
			"\t done%d:\n"\
			"\t push DWORD eax\n\n", jumps, jumps);
		jumps++;
	}
;}
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 522 "compiler.y"
    {
	if((yyvsp[(1) - (4)].ival) != (yyvsp[(4) - (4)].ival)){
		yyerror("type mismatch in expression with '<='");
		exit(1);
	}
	else if((yyvsp[(1) - (4)].ival) == INTEGER){
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t cmp eax, ecx\n"\
			"\t mov eax, 0\n"\
			"\t setne al\n"\
			"\t push eax\n\n");
	}
	else if((yyvsp[(1) - (4)].ival) == FLOAT){
		(yyval.ival) = BOOLEAN;
		printf("\t fld QWORD [esp]\n"\
			"\t fld QWORD [esp+8]\n"\
			"\t add esp, 16\n"\
			"\t fcompp\n"\
			"\t mov eax, 0\n"\
			"\t fstsw ax\n"\
			"\t and eax, 0x4100\t ;getting the bits we want with the mask\n"\
			"\t and eax, 0x4000\t ;seeing if the upper bit was set because if it was we know it was equal\n"\
			"\t setz al\t ;if the upper bit wasn't set it wasn't equal so we note that in al\n"\
			"\t cmp eax, 1\t ;if it is 1 then we know that our above check worked\n"\
			"\t je done%d\t ;just jump straight to being finished cause eax == 1 and that's true\n"\
			"\t mov eax, 0\t ;otherwise make eax 0 to signify the expression is false\n"\
			"\t done%d:\n"\
			"\t push DWORD eax\n\n", jumps, jumps);
		jumps++;
	}
;}
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 555 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){
		yyerror("type mismatch in expression with '<='");
		exit(1);
	}
	else if((yyvsp[(1) - (3)].ival) == INTEGER){
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t cmp eax, ecx\n"\
			"\t mov eax, 0\n"\
			"\t setg al\n"\
			"\t push eax\n\n");
	}
	else if((yyvsp[(1) - (3)].ival) == FLOAT){
		(yyval.ival) = BOOLEAN;
		printf("\t fld QWORD [esp]\n"\
			"\t fld QWORD [esp+8]\n"\
			"\t add esp, 16\n"\
			"\t fcompp\n"\
			"\t mov eax, 0\n"\
			"\t fstsw ax\n"\
			"\t and eax, 0x4100\n"\
			"\t setz al\t ;if al is 0 then we know it is greater than and thus set lowest bit in al\n"\
			"\t cmp eax, 1\n"\
			"\t je done%d\t ;if eax is 1, aka lowest bit in al is set, jump to done\n"\
			"\t mov eax, 0\t ;else exp was actually less than so set eax to 0 to mark false\n"\
			"\t done%d:\n"\
			"\t push DWORD eax\n\n", jumps, jumps);
		jumps++;
	}
;}
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 587 "compiler.y"
    {
	if((yyvsp[(1) - (4)].ival) != (yyvsp[(4) - (4)].ival)){
		yyerror("type mismatch in expression with '<='");
		exit(1);
	}
	else if((yyvsp[(1) - (4)].ival) == INTEGER){
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t cmp eax, ecx\n"\
			"\t mov eax, 0\n"\
			"\t setge al\n"\
			"\t push eax\n\n");
	}
	else if((yyvsp[(1) - (4)].ival) == FLOAT){
		(yyval.ival) = BOOLEAN;
		printf("\t fld QWORD [esp]\n"\
			"\t fld QWORD [esp+8]\n"\
			"\t add esp, 16\n"\
			"\t fcompp\n"\
			"\t mov eax, 0\n"\
			"\t fstsw ax\n"\
			"\t and eax, 0x4100\n"\
			"\t and eax, 0x0100\t ;basically was the lower bit set thus saying it was less than?\n"\
			"\t setnz al\t ;if its not zero mark it as so because we now need to return false\n"\
			"\t and eax, 0x0001\t ;basically making eax now just 1 if we set the lowest bit of al\n"\
			"\t cmp eax, 1\t ;test if eax is one and thus we need to return false\n"\
			"\t je jump%d\t ;if eax is one jump to the section where we can mark false\n"\
			"\t mov eax, 1\t ;eax was not one so we set it now to 1 to signify true\n"\
			"\t jmp done%d\t ;jump out to preserve the truth\n"\
			"\t jump%d:\n"\
			"\t mov eax, 0\t ;marking eax so it returns false\n"\
			"\t done%d:\n"\
			"\t push DWORD eax\n\n", jumps, jumps, jumps, jumps);
		jumps++;
	}
;}
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 624 "compiler.y"
    {
	if((yyvsp[(1) - (4)].ival) != (yyvsp[(4) - (4)].ival)){
		yyerror("type mismatch");
		exit(1);
	}
	else if((yyvsp[(1) - (4)].ival) != BOOLEAN){
		yyerror("Boolean operators only apply to boolean values");
		exit(1);
	}
	else{
		(yyval.ival) = BOOLEAN;
		printf("\t pop ecx\n"\
			"\t pop eax\n"\
			"\t imul eax, ecx\t ;multiply together because eax will be 1 iff both parameters were true\n"\
			"\t push DWORD eax\n\n");
	}
;}
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 641 "compiler.y"
    {
	if((yyvsp[(1) - (4)].ival) != (yyvsp[(4) - (4)].ival)){
		yyerror("type mismatch");
		exit(1);
	}
	else if((yyvsp[(1) - (4)].ival) != BOOLEAN){
		yyerror("Boolean operators only apply to boolean values");
		exit(1);
	}
	else{
		(yyval.ival) = BOOLEAN;
		printf("\t call or_ed\n"\
			"\t add esp, 8\n"\
			"\t push DWORD eax\t ;push result on stack\n\n");
	}
;}
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 657 "compiler.y"
    {
	if((yyvsp[(2) - (2)].ival) != BOOLEAN){
		yyerror("Boolean operators only apply to boolean values");
		exit(1);
	}
	else{
		(yyval.ival) = BOOLEAN;
		printf("\t pop eax\n"\
			"\t push DWORD eax\n"\
			"\t call not_ed\t ;calling function to determine what value is returned after the not\n"\
			"\t add esp, 4\n"\
			"\t push DWORD eax\n\n");
	}
;}
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 671 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if((yyvsp[(1) - (3)].ival) == INTEGER){
			(yyval.ival) = INTEGER;
			printf("\t pop eax\t ;adding two numbers\n"\
                      "\t pop ebx\n"\
                      "\t add eax, ebx\n"\
                      "\t push eax\n\n");
		}
		else{
			(yyval.ival) = FLOAT;
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
;}
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 699 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if((yyvsp[(1) - (3)].ival) == INTEGER){
			(yyval.ival) = INTEGER;
			printf("\t pop ebx\t ;subtracting two numbers\n"\
                      "\t pop eax\n"\
                      "\t sub eax, ebx\n"\
                      "\t push eax\n\n");
		}
		else{
			(yyval.ival) = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fsub\t ;subtracting st(0) from st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
;}
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 725 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if((yyvsp[(1) - (3)].ival) == INTEGER){
			(yyval.ival) = INTEGER;
			printf("\t pop eax\t ;performing multiplication\n"\
                      "\t pop ebx\n"\
                      "\t imul ebx\n"\
                      "\t push eax\n\n");
		}
		else{
			(yyval.ival) = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fmul\t ;subtracting st(0) from st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
;}
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 751 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) != (yyvsp[(3) - (3)].ival)){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if((yyvsp[(1) - (3)].ival) == INTEGER){
			(yyval.ival) = INTEGER;
			printf("\t pop ecx\n"\
                      "\t pop eax\n"\
                      "\t idiv ecx\n"\
                      "\t push eax\n\n");
		}
		else{
			(yyval.ival) = FLOAT;
			printf("\t fld QWORD [esp+8]\t ;pushing the float number onto float stack\n"\
					"\t fld QWORD [esp]\t ;pushing second number onto float stack\n"\
					"\t add esp, 8\t ;clearing that float from the stack\n"\
					"\t add esp, 8\t ;clearing second float from stack\n"\
					"\t fdiv\t ;subtracting st(0) from st(1)\n"\
					"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
					"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
		}
	}
;}
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 777 "compiler.y"
    {
	if((yyvsp[(2) - (2)].ival) == INTEGER){
		(yyval.ival) = INTEGER;
		printf("\t pop eax\n"\
               "\t neg eax\n"\
               "\t push DWORD eax\n\n");
	}
	else{
		(yyval.ival) = FLOAT;
		printf("\t fld QWORD [esp]\t ;pushing number onto float stack\n"\
				"\t add esp, 8\t ;clearing that float from the stack\n"\
				"\t fchs\t ;negating value in st(0)\n"\
				"\t sub esp, 8\t ;making room to push the solution onto the stack\n"\
				"\t fstp QWORD [esp]\t ;storing on the stack\n\n");
	}
;}
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 793 "compiler.y"
    {
	if((yyvsp[(1) - (3)].ival) == INTEGER && (yyvsp[(3) - (3)].ival) != INTEGER){
		fprintf(stderr, "Type mismatch on line: %d\n", yylineno);
		yyerror("type mismatch");
		exit(1);
	}
	else{
		if((yyvsp[(1) - (3)].ival) == INTEGER){
			(yyval.ival) = INTEGER;
			printf("\t call pow\n"\
                   "\t add esp, 8\n"\
                   "\t push eax\n\n");
		}
		else if ((yyvsp[(1) - (3)].ival) == FLOAT && (yyvsp[(3) - (3)].ival) == INTEGER){
			(yyval.ival) = FLOAT;
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
;}
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 819 "compiler.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival);

;}
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 823 "compiler.y"
    {
	(yyvsp[(1) - (4)].ival) = numifs;
	if((yyvsp[(3) - (4)].ival) != BOOLEAN){
		fprintf(stderr, "Error: boolean expression expected after '(' on line %d\n", yylineno);
		exit(1);
	}
	
	printf("\t pop eax\n"\
			"\t cmp eax, 0\t ;testing if the exp evaluated to a false\n"\
			"\t je if_out%d\n", numifs);
	
	numifs++;
;}
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 836 "compiler.y"
    {
	int if_out = (yyvsp[(1) - (8)].ival); //just keeping track of what if statement we're on
	printf("\t if_out%d:\n", if_out);
;}
    break;



/* Line 1464 of yacc.c  */
#line 2499 "compiler.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 841 "compiler.y"


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
  



