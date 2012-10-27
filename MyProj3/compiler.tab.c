/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
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
         
       int memsize = 0;
       int numFloats = 0;
       int numStrings = 0;
     

/* Line 268 of yacc.c  */
#line 91 "compiler.tab.c"

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
     NEG = 266
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 42 "compiler.y"

  float fval;
  int ival;
  char* sval;
  int tval;
  int bval;



/* Line 293 of yacc.c  */
#line 148 "compiler.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 160 "compiler.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   91

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  24
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  9
/* YYNRULES -- Number of rules.  */
#define YYNRULES  29
/* YYNRULES -- Number of states.  */
#define YYNSTATES  50

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   266

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      20,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    19,     2,     2,     2,     2,    17,     2,
      22,    23,    13,    12,     2,    11,     2,    14,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    21,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    16,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    18,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    15
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     8,    11,    13,    15,    17,
      19,    21,    25,    30,    34,    36,    38,    40,    42,    44,
      46,    51,    56,    59,    63,    67,    71,    75,    78,    82
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      25,     0,    -1,    -1,    26,    27,    -1,    -1,    27,    28,
      -1,    20,    -1,    29,    -1,    30,    -1,    31,    -1,    32,
      -1,     7,     5,    20,    -1,     5,    21,    32,    20,    -1,
       6,    32,    20,    -1,     8,    -1,    10,    -1,     9,    -1,
       5,    -1,     3,    -1,     4,    -1,    32,    17,    17,    32,
      -1,    32,    18,    18,    32,    -1,    19,    32,    -1,    32,
      12,    32,    -1,    32,    11,    32,    -1,    32,    13,    32,
      -1,    32,    14,    32,    -1,    11,    32,    -1,    32,    16,
      32,    -1,    22,    32,    23,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    75,   158,   159,   162,   163,   164,   165,
     166,   169,   191,   224,   239,   248,   253,   263,   287,   290,
     299,   318,   334,   341,   369,   395,   421,   447,   463,   489
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_NUM", "FLOAT_NUM", "VARNAME",
  "PRINT", "TYPE", "EXIT", "STRING", "BOOL", "'-'", "'+'", "'*'", "'/'",
  "NEG", "'^'", "'&'", "'|'", "'!'", "'\\n'", "'='", "'('", "')'",
  "$accept", "file", "$@1", "program", "statement", "vardecl",
  "assignment", "print", "exp", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    45,    43,    42,    47,   266,    94,    38,   124,    33,
      10,    61,    40,    41
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    24,    26,    25,    27,    27,    28,    28,    28,    28,
      28,    29,    30,    31,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,    32,    32,    32,    32,    32
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     3,     4,     3,     1,     1,     1,     1,     1,     1,
       4,     4,     2,     3,     3,     3,     3,     2,     3,     3
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     4,     1,     3,    18,    19,    17,     0,     0,
      14,    16,    15,     0,     0,     6,     0,     5,     7,     8,
       9,    10,     0,    17,     0,     0,    27,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,    11,    29,
      24,    23,    25,    26,    28,     0,     0,    12,    20,    21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     4,    17,    18,    19,    20,    21
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -16
static const yytype_int8 yypact[] =
{
     -16,     4,   -16,   -16,    23,   -16,   -16,   -14,    43,    13,
     -16,   -16,   -16,    43,    43,   -16,    43,   -16,   -16,   -16,
     -16,    73,    43,   -16,    -1,   -11,   -15,   -16,    55,    43,
      43,    43,    43,    43,     3,    17,    63,   -16,   -16,   -16,
      42,    42,   -15,   -15,   -15,    43,    43,   -16,   -16,   -16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      24,    33,    34,    35,     3,    26,    27,    22,    28,    38,
      29,    30,    31,    32,    36,    33,    34,    35,    25,    37,
      45,    40,    41,    42,    43,    44,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    46,     0,    48,    49,     0,
       0,     0,    14,    15,     0,    16,     5,     6,    23,     0,
       0,    10,    11,    12,    13,    31,    32,     0,    33,    34,
      35,     0,    14,     0,     0,    16,    29,    30,    31,    32,
       0,    33,    34,    35,    29,    30,    31,    32,    39,    33,
      34,    35,     0,    47,    29,    30,    31,    32,     0,    33,
      34,    35
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-16))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       8,    16,    17,    18,     0,    13,    14,    21,    16,    20,
      11,    12,    13,    14,    22,    16,    17,    18,     5,    20,
      17,    29,    30,    31,    32,    33,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    18,    -1,    45,    46,    -1,
      -1,    -1,    19,    20,    -1,    22,     3,     4,     5,    -1,
      -1,     8,     9,    10,    11,    13,    14,    -1,    16,    17,
      18,    -1,    19,    -1,    -1,    22,    11,    12,    13,    14,
      -1,    16,    17,    18,    11,    12,    13,    14,    23,    16,
      17,    18,    -1,    20,    11,    12,    13,    14,    -1,    16,
      17,    18
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    26,     0,    27,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    19,    20,    22,    28,    29,    30,
      31,    32,    21,     5,    32,     5,    32,    32,    32,    11,
      12,    13,    14,    16,    17,    18,    32,    20,    20,    23,
      32,    32,    32,    32,    32,    17,    18,    20,    32,    32
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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

/* Line 1806 of yacc.c  */
#line 75 "compiler.y"
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
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 169 "compiler.y"
    {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, (yyvsp[(2) - (3)].sval));
    if(test == NULL){
        SymbolTableEntry *entry = NULL;
        entry = (SymbolTableEntry*)malloc(sizeof (SymbolTableEntry));
        entry->name = (yyvsp[(2) - (3)].sval);
        entry->type = (yyvsp[(1) - (3)].tval);
        entry->lineno = yylineno;
        entry->offset = memsize;
        memsize += 8;
        symbolTableAddEntry(&symbol_table, entry);
    }
    else{
	char *error;
	error = (char*)malloc(1000); //this specifies a large byte allocation for the string
	fprintf(stderr, "Redeclaration of variable: %s on line: %d\n", (yyvsp[(2) - (3)].sval), test->lineno); 
        yyerror("redeclaration of variable");
	free(error);
	exit(1);
    }
}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 191 "compiler.y"
    {
	SymbolTableEntry *test = symbolTableGetEntry(&symbol_table, (yyvsp[(1) - (4)].sval));
	char* error;
	error = (char*)malloc(1000); //again assigning space to variable
    if(test == NULL){
	fprintf(stderr, "Symbol: %s not initialized on line: %d\n", (yyvsp[(1) - (4)].sval), yylineno);
        yyerror("no such symbol in table");
	//printf("\t pop eax\t ;clearing symbol from stack\n\n");
	exit(1);
    }
    else if(test->type != (yyvsp[(3) - (4)].ival)){
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
}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 224 "compiler.y"
    {
	if((yyvsp[(2) - (3)].ival) == INTEGER || BOOLEAN){
		printf("\t push DWORD printf_int\t ;sets up and calls print(extern)\n"\
			"\t call printf\n"\
			"\t add esp, 8\t ;clean up the DWORD and int arg that was on the stack\n\n");
	}
	else if( (yyvsp[(2) - (3)].ival) == FLOAT){
		printf("\t push DWORD printf_float\t ;sets up calls and print\n"\
			"\t call printf\n"\
			"\t add esp, 12\t ;gotta clean up the stack else stuff gets weird\n\n");
	}
	free((yyvsp[(1) - (3)].sval));
}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 239 "compiler.y"
    {printf("\t section\t .data\t ;creating global variable stack pointer\n"\
       	     "\t variable_stack:\n\t times %d db 0\n\n"\
	     "\t section\t .text\t ;going back to code section\n"\
	     "\t leave\n"\
	     "\t ret\n", memsize);
	free((yyvsp[(1) - (1)].sval));
	YYACCEPT;
}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 248 "compiler.y"
    {
	printf("\t push %d\n", (yyvsp[(1) - (1)].bval));
	(yyval.ival) = BOOLEAN;
}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 253 "compiler.y"
    {
  printf("\t section\t .data\n"\
	 "\t msg%d db %s, 0\n"\
	 "\t section\t .text\n"\
	 "\t push msg%d\n"\
	 "\t call printf\n\n", numStrings, (yyvsp[(1) - (1)].sval), numStrings);
  numStrings++; //keep track of number of string written so each time we declare a new variable it has a unique name
  free((yyvsp[(1) - (1)].sval));
}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 263 "compiler.y"
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
		if(test->type == INTEGER || BOOLEAN){
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
}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 287 "compiler.y"
    {printf("\t push DWORD %d\t ;pushes integer onto mem stack\n\n", (yyvsp[(1) - (1)].ival));
	(yyval.ival) = INTEGER;
}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 290 "compiler.y"
    {printf("\t section .data\t ;defining temporary variable for floats\n"\
					"\t tempFloat%d: dq %lf\t ;need to have a different float variable for each float\n"\
					
					"\t section .text\n"\
                    "\t push DWORD [tempFloat%d + 4]\t ;push on the bottom part of the variable\n"
					"\t push DWORD [tempFloat%d] \n\n", numFloats, (yyvsp[(1) - (1)].fval), numFloats, numFloats);
	(yyval.ival) = FLOAT;
	numFloats += 1; //keeping track of number of floats so each variable has a different name
}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 299 "compiler.y"
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
		printf("\t pop ebx\n"\
			"\t pop eax\n"\
			"\t add eax, ebx\t ;adding together to see if sum is 0\n"\
			"\t push DWORD eax\t ;pushing argument on stack\n"\
			"\t call anded\t ;calling function to test the result of anding\n"\
			"\t add esp, 4\n"\
			"\t push DWORD eax\n\n");
	}
}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 318 "compiler.y"
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
		printf("\t pop ebx\n"\
			"\t pop eax\n"\
			"\t imul eax, ebx\t ;multiply together so that if a 0 and 1 came in the result is 0\n"\
			"\t push DWORD eax\t ;push result on stack\n\n");
	}
}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 334 "compiler.y"
    {
	printf("\t pop eax\n"\
		"\t push DWORD eax\n"\
		"\t call noted\t ;calling function to determine what value is returned after the not\n"\
		"\t add esp, 4\n"\
		"\t push DWORD eax\n\n");
}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 341 "compiler.y"
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
}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 369 "compiler.y"
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
}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 395 "compiler.y"
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
}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 421 "compiler.y"
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
}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 447 "compiler.y"
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
}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 463 "compiler.y"
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
}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 489 "compiler.y"
    { (yyval.ival) = (yyvsp[(2) - (3)].ival);

}
    break;



/* Line 1806 of yacc.c  */
#line 1937 "compiler.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 494 "compiler.y"


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
  



