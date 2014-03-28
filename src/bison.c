/* A Bison parser, made by GNU Bison 2.4.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
   2009, 2010 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.3"

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


/*

    YABASIC ---  a simple Basic Interpreter
    written by Marc-Oliver Ihm 1995-2004
    homepage: www.yabasic.de

    BISON part
     
    This file is part of yabasic and may be copied only 
    under the terms of either the Artistic License or 
    the GNU General Public License (GPL), both of which 
    can be found at www.yabasic.de

*/


#ifndef YABASIC_INCLUDED
#include "yabasic.h"     /* definitions of yabasic */
#endif

#include <malloc.h>

#if HAVE_ALLOCA_H
#ifndef WINDOWS
#include <alloca.h>
#endif
#endif

void __yy_bcopy(char *,char *,int); /* prototype missing */

int tileol; /* true, read should go to eon of line */
int mylineno=1; /* line number; counts fresh in every new file */
int main_lineno=1; /* line number of main */
int function_type=ftNONE; /* contains function type while parsing function */
char *current_function=NULL; /* name of currently parsed function */
int exported=FALSE; /* true, if function is exported */
int yylex(void);
extern struct libfile_name *current_libfile; /*  defined in main.c: name of currently parsed file */
int missing_endif=0;
int missing_endif_line=0;
int missing_endsub=0;
int missing_endsub_line=0;
int missing_next=0;
int missing_next_line=0;
int missing_wend=0;
int missing_wend_line=0;
int missing_until=0;
int missing_until_line=0;
int missing_loop=0;
int missing_loop_line=0;
int in_loop=0;

void report_missing(int severity,char *text) {
  if (missing_loop || missing_endif || missing_next || missing_until || missing_wend) {
    error(severity,text);
    string[0]='\0';
    if (missing_endif)
      sprintf(string,"if statement starting at line %d has seen no 'endif' yet",missing_endif_line);
    else if (missing_next)
      sprintf(string,"for-loop starting at line %d has seen no 'next' yet",missing_next_line);
    else if (missing_wend)
      sprintf(string,"while-loop starting at line %d has seen no 'wend' yet",missing_wend_line);
    else if (missing_until)
      sprintf(string,"repeat-loop starting at line %d has seen no 'until' yet",missing_until_line);
    else if (missing_loop)
      sprintf(string,"do-loop starting at line %d has seen no 'loop' yet",missing_wend_line);
    if (string[0]) error(severity,string);
  }
}
     



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     tFNUM = 258,
     tSYMBOL = 259,
     tSTRSYM = 260,
     tDOCU = 261,
     tDIGITS = 262,
     tSTRING = 263,
     tFOR = 264,
     tTO = 265,
     tSTEP = 266,
     tNEXT = 267,
     tWHILE = 268,
     tWEND = 269,
     tREPEAT = 270,
     tUNTIL = 271,
     tIMPORT = 272,
     tGOTO = 273,
     tGOSUB = 274,
     tLABEL = 275,
     tON = 276,
     tSUB = 277,
     tENDSUB = 278,
     tLOCAL = 279,
     tSTATIC = 280,
     tEXPORT = 281,
     tERROR = 282,
     tEXECUTE = 283,
     tEXECUTE2 = 284,
     tCOMPILE = 285,
     tRUNTIME_CREATED_SUB = 286,
     tINTERRUPT = 287,
     tBREAK = 288,
     tCONTINUE = 289,
     tSWITCH = 290,
     tSEND = 291,
     tCASE = 292,
     tDEFAULT = 293,
     tLOOP = 294,
     tDO = 295,
     tSEP = 296,
     tEOPROG = 297,
     tIF = 298,
     tTHEN = 299,
     tELSE = 300,
     tELSIF = 301,
     tENDIF = 302,
     tUSING = 303,
     tPRINT = 304,
     tINPUT = 305,
     tLINE = 306,
     tRETURN = 307,
     tDIM = 308,
     tEND = 309,
     tEXIT = 310,
     tAT = 311,
     tSCREEN = 312,
     tSCREENSHOT = 313,
     tREVERSE = 314,
     tCOLOUR = 315,
     tAND = 316,
     tOR = 317,
     tNOT = 318,
     tEOR = 319,
     tNEQ = 320,
     tLEQ = 321,
     tGEQ = 322,
     tLTN = 323,
     tGTN = 324,
     tEQU = 325,
     tPOW = 326,
     tREAD = 327,
     tDATA = 328,
     tRESTORE = 329,
     tOPEN = 330,
     tCLOSE = 331,
     tSEEK = 332,
     tTELL = 333,
     tAS = 334,
     tREADING = 335,
     tWRITING = 336,
     tWAIT = 337,
     tBELL = 338,
     tLET = 339,
     tARDIM = 340,
     tARSIZE = 341,
     tBIND = 342,
     tWINDOW = 343,
     tDOT = 344,
     tCIRCLE = 345,
     tCLEAR = 346,
     tFILL = 347,
     tPRINTER = 348,
     tSETUP = 349,
     tBUTTON = 350,
     tALERT = 351,
     tMENU = 352,
     tCHECKBOX = 353,
     tRADIOBUTTON = 354,
     tTEXTCONTROL = 355,
     tLISTBOX = 356,
     tDROPBOX = 357,
     tADD = 358,
     tREMOVE = 359,
     tLOCALIZE = 360,
     tFILEPANEL = 361,
     tSLIDER = 362,
     tSTATUSBAR = 363,
     tLAYOUT = 364,
     tSET = 365,
     tTEXTEDIT = 366,
     tCOUNT = 367,
     tVIEW = 368,
     tBOXVIEW = 369,
     tTABVIEW = 370,
     tTEXTURL = 371,
     tBITMAP = 372,
     tCANVAS = 373,
     tOPTION = 374,
     tDROPZONE = 375,
     tCOLORCONTROL = 376,
     tTREEBOX = 377,
     tCOLUMNBOX = 378,
     tCOLUMN = 379,
     tSORT = 380,
     tTOOLTIP = 381,
     tCALENDAR = 382,
     tCLIPBOARD = 383,
     tCOPY = 384,
     tSUBMENU = 385,
     tSELECT = 386,
     tSCROLLBAR = 387,
     tEXPAND = 388,
     tCOLLAPSE = 389,
     tSPLITVIEW = 390,
     tSTACKVIEW = 391,
     tPOPUPMENU = 392,
     tSPINCONTROL = 393,
     tMSEND = 394,
     tNUMMESSAGE = 395,
     tTHREAD = 396,
     tSOUND = 397,
     tPLAY = 398,
     tSTOP = 399,
     tSHORTCUT = 400,
     tISCOMPUTERON = 401,
     tDRAW = 402,
     tTEXT = 403,
     tFLUSH = 404,
     tELLIPSE = 405,
     tSAVE = 406,
     tRECT = 407,
     tGETCHAR = 408,
     tPUTCHAR = 409,
     tNEW = 410,
     tCURVE = 411,
     tLAUNCH = 412,
     tATTRIBUTE = 413,
     tSIN = 414,
     tASIN = 415,
     tCOS = 416,
     tACOS = 417,
     tTAN = 418,
     tATAN = 419,
     tEXP = 420,
     tLOG = 421,
     tSQRT = 422,
     tSQR = 423,
     tMYEOF = 424,
     tABS = 425,
     tSIG = 426,
     tINT = 427,
     tFRAC = 428,
     tMOD = 429,
     tRAN = 430,
     tLEN = 431,
     tVAL = 432,
     tLEFT = 433,
     tRIGHT = 434,
     tMID = 435,
     tMIN = 436,
     tMAX = 437,
     tSTR = 438,
     tINKEY = 439,
     tCHR = 440,
     tASC = 441,
     tHEX = 442,
     tDEC = 443,
     tBIN = 444,
     tUPPER = 445,
     tLOWER = 446,
     tTRIM = 447,
     tLTRIM = 448,
     tRTRIM = 449,
     tINSTR = 450,
     tRINSTR = 451,
     tSYSTEM = 452,
     tSYSTEM2 = 453,
     tPEEK = 454,
     tPEEK2 = 455,
     tPOKE = 456,
     tDATE = 457,
     tTIME = 458,
     tTOKEN = 459,
     tTOKENALT = 460,
     tSPLIT = 461,
     tSPLITALT = 462,
     tGLOB = 463,
     tMESSAGE = 464,
     tIMAGE = 465,
     tSVG = 466,
     tTRANSLATE = 467,
     tGET = 468,
     tMOUSE = 469,
     tISMOUSEIN = 470,
     tKEYBOARD = 471,
     tPASTE = 472,
     tGETNUM = 473,
     UMINUS = 474
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


  double fnum;          /* double number */
  int inum;             /* integer number */
  int token;            /* token of command */
  int sep;              /* number of newlines */
  char *string;         /* quoted string */
  char *symbol;         /* general symbol */
  char *digits;         /* string of digits */
  char *docu;		/* embedded documentation */



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



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
#define YYFINAL  406
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   12857

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  229
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  109
/* YYNRULES -- Number of rules.  */
#define YYNRULES  586
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1925

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   474

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,   228,     2,     2,     2,     2,
     224,   225,   221,   220,   227,   219,     2,   222,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,   226,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   223
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,     9,    10,    16,    17,    19,
      22,    24,    27,    29,    32,    34,    36,    38,    40,    42,
      44,    46,    48,    50,    52,    53,    57,    58,    62,    64,
      66,    69,    72,    76,    80,    81,    87,    88,    94,    97,
      99,   102,   104,   107,   112,   117,   121,   126,   131,   132,
     136,   137,   142,   145,   148,   150,   153,   156,   158,   161,
     164,   167,   177,   188,   197,   208,   219,   232,   243,   247,
     253,   261,   272,   278,   282,   288,   294,   300,   306,   313,
     322,   333,   339,   341,   344,   347,   355,   363,   367,   371,
     376,   382,   390,   400,   407,   418,   424,   430,   438,   446,
     454,   466,   470,   476,   482,   494,   500,   508,   517,   521,
     534,   545,   551,   557,   563,   569,   577,   585,   595,   607,
     622,   639,   647,   655,   667,   673,   676,   684,   696,   702,
     710,   720,   725,   735,   743,   751,   761,   773,   777,   784,
     793,   797,   804,   814,   820,   826,   830,   841,   847,   857,
     869,   877,   881,   887,   893,   899,   907,   913,   919,   933,
     951,   957,   963,   968,   978,   982,   986,   999,  1011,  1027,
    1031,  1037,  1043,  1055,  1066,  1072,  1079,  1087,  1097,  1103,
    1109,  1117,  1127,  1138,  1148,  1160,  1173,  1183,  1193,  1208,
    1214,  1218,  1222,  1226,  1230,  1236,  1240,  1246,  1259,  1267,
    1277,  1288,  1294,  1305,  1317,  1327,  1333,  1340,  1343,  1346,
    1348,  1350,  1354,  1359,  1364,  1369,  1374,  1379,  1384,  1386,
    1388,  1391,  1393,  1396,  1400,  1411,  1420,  1429,  1438,  1442,
    1444,  1446,  1453,  1458,  1465,  1472,  1477,  1484,  1486,  1491,
    1493,  1495,  1497,  1499,  1503,  1507,  1514,  1521,  1530,  1537,
    1542,  1549,  1558,  1560,  1564,  1569,  1574,  1579,  1584,  1589,
    1594,  1599,  1604,  1606,  1610,  1612,  1616,  1621,  1628,  1635,
    1640,  1647,  1652,  1663,  1668,  1673,  1678,  1680,  1684,  1687,
    1692,  1697,  1703,  1707,  1713,  1719,  1723,  1730,  1739,  1743,
    1747,  1750,  1758,  1762,  1768,  1774,  1781,  1787,  1791,  1797,
    1801,  1805,  1806,  1811,  1812,  1817,  1820,  1824,  1828,  1832,
    1836,  1840,  1844,  1849,  1856,  1858,  1863,  1868,  1875,  1882,
    1884,  1886,  1890,  1894,  1898,  1902,  1906,  1909,  1913,  1917,
    1921,  1925,  1929,  1933,  1935,  1939,  1943,  1947,  1951,  1956,
    1961,  1966,  1971,  1976,  1981,  1988,  1993,  1998,  2005,  2010,
    2015,  2020,  2025,  2030,  2035,  2042,  2047,  2051,  2058,  2065,
    2070,  2075,  2080,  2085,  2092,  2099,  2108,  2115,  2124,  2129,
    2134,  2139,  2146,  2153,  2160,  2165,  2174,  2181,  2190,  2197,
    2202,  2207,  2214,  2221,  2230,  2240,  2250,  2259,  2262,  2265,
    2269,  2275,  2281,  2292,  2296,  2300,  2306,  2312,  2316,  2320,
    2324,  2328,  2332,  2338,  2344,  2352,  2360,  2368,  2374,  2382,
    2388,  2394,  2400,  2407,  2411,  2413,  2417,  2421,  2425,  2429,
    2437,  2445,  2451,  2457,  2467,  2473,  2475,  2478,  2481,  2483,
    2485,  2487,  2489,  2494,  2501,  2506,  2513,  2518,  2523,  2524,
    2527,  2528,  2530,  2534,  2536,  2538,  2539,  2540,  2541,  2553,
    2555,  2557,  2559,  2561,  2562,  2564,  2566,  2569,  2571,  2575,
    2577,  2579,  2584,  2589,  2591,  2595,  2597,  2599,  2604,  2609,
    2610,  2612,  2616,  2618,  2620,  2624,  2628,  2629,  2630,  2631,
    2632,  2647,  2649,  2651,  2652,  2655,  2656,  2658,  2659,  2667,
    2669,  2672,  2674,  2676,  2677,  2678,  2679,  2686,  2687,  2688,
    2693,  2694,  2699,  2701,  2703,  2704,  2705,  2714,  2716,  2718,
    2719,  2724,  2726,  2731,  2732,  2733,  2734,  2735,  2747,  2749,
    2751,  2752,  2758,  2759,  2762,  2763,  2764,  2765,  2773,  2774,
    2776,  2778,  2779,  2784,  2786,  2791,  2793,  2798,  2800,  2804,
    2806,  2811,  2813,  2818,  2820,  2822,  2826,  2830,  2831,  2834,
    2839,  2841,  2845,  2846,  2849,  2856,  2857,  2862,  2863,  2868,
    2869,  2876,  2877,  2887,  2888,  2892,  2893,  2895,  2896,  2899,
    2902,  2907,  2909,  2914,  2921,  2928,  2936,  2947,  2960,  2968,
    2979,  2992,  2995,  2997,  2999,  3003,  3005
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     230,     0,    -1,   231,    42,    -1,   234,    -1,    -1,    -1,
     231,   232,    41,   233,   234,    -1,    -1,   241,    -1,    84,
     241,    -1,   248,    -1,    84,   248,    -1,    17,    -1,    27,
     246,    -1,   279,    -1,   287,    -1,   303,    -1,   299,    -1,
     296,    -1,    33,    -1,    34,    -1,   266,    -1,   260,    -1,
     261,    -1,    -1,    24,   235,   273,    -1,    -1,    25,   236,
     275,    -1,   306,    -1,   312,    -1,    18,   258,    -1,    19,
     258,    -1,    21,    32,    33,    -1,    21,    32,    34,    -1,
      -1,    21,   249,    18,   237,   336,    -1,    -1,    21,   249,
      19,   238,   337,    -1,    20,   258,    -1,   243,    -1,    76,
     335,    -1,   244,    -1,    30,   246,    -1,    28,   224,   262,
     225,    -1,    29,   224,   262,   225,    -1,    49,   334,   325,
      -1,    49,   334,   325,   226,    -1,    49,   334,   325,   227,
      -1,    -1,    50,   239,   327,    -1,    -1,    51,    50,   240,
     327,    -1,    72,   322,    -1,    73,   324,    -1,    74,    -1,
      74,   258,    -1,    74,   246,    -1,    52,    -1,    52,   249,
      -1,    52,   246,    -1,    53,   259,    -1,    88,    75,   254,
     242,   254,   227,   246,   227,   246,    -1,    95,   254,   242,
     254,   227,   246,   227,   246,   227,   246,    -1,    97,   246,
     227,   246,   227,   246,   227,   246,    -1,    98,   254,   227,
     246,   227,   246,   227,   249,   227,   246,    -1,    99,   254,
     227,   246,   227,   246,   227,   249,   227,   246,    -1,   100,
     254,   242,   254,   227,   246,   227,   246,   227,   246,   227,
     246,    -1,   101,   254,   242,   254,   227,   246,   227,   249,
     227,   246,    -1,   101,    91,   246,    -1,   101,   103,   246,
     227,   246,    -1,   101,   103,   246,   227,   249,   227,   246,
      -1,   102,   254,   242,   254,   227,   246,   227,   246,   227,
     246,    -1,   102,   103,   246,   227,   246,    -1,   102,    91,
     246,    -1,   102,   104,   246,   227,   249,    -1,   101,   104,
     246,   227,   246,    -1,   101,   104,   246,   227,   249,    -1,
     101,   131,   246,   227,   249,    -1,    96,   246,   227,   246,
     227,   246,    -1,   148,   254,   227,   246,   227,   246,   227,
     246,    -1,   148,   254,   242,   254,   227,   246,   227,   246,
     227,   246,    -1,   148,   110,   246,   227,   246,    -1,   105,
      -1,   105,   246,    -1,   105,   144,    -1,   147,   148,   254,
     227,   246,   227,   246,    -1,   147,   152,   254,   242,   254,
     227,   246,    -1,   147,   149,   246,    -1,    88,    76,   246,
      -1,   109,   246,   227,   246,    -1,    88,   110,   246,   227,
     246,    -1,    88,   110,   246,   227,   246,   227,   246,    -1,
      88,   110,   246,   227,   246,   227,   249,   227,   249,    -1,
     145,   246,   227,   246,   227,   246,    -1,   111,   254,   242,
     254,   227,   246,   227,   249,   227,   246,    -1,   111,   103,
     246,   227,   246,    -1,   111,   110,   246,   227,   246,    -1,
     111,   110,   246,   227,   246,   227,   249,    -1,   111,   110,
     246,   227,   246,   227,   246,    -1,   111,    60,   246,   227,
     246,   227,   246,    -1,   111,    60,   246,   227,   246,   227,
     249,   227,   249,   227,   249,    -1,   111,    91,   246,    -1,
     147,   110,   246,   227,   246,    -1,   147,   110,   249,   227,
     246,    -1,   147,   110,   246,   227,   249,   227,   249,   227,
     249,   227,   246,    -1,   147,   110,   246,   227,   249,    -1,
     147,   110,   246,   227,   246,   227,   246,    -1,   113,   254,
     242,   254,   227,   246,   227,   246,    -1,   113,   104,   246,
      -1,   114,   254,   242,   254,   227,   246,   227,   246,   227,
     249,   227,   246,    -1,   115,   254,   242,   254,   227,   246,
     227,   246,   227,   246,    -1,   115,   110,   246,   227,   249,
      -1,   115,   103,   246,   227,   246,    -1,   115,   104,   246,
     227,   249,    -1,   147,    89,   254,   227,   246,    -1,   147,
      51,   254,   242,   254,   227,   246,    -1,   147,    90,   254,
     227,   249,   227,   246,    -1,   147,   150,   254,   227,   249,
     227,   249,   227,   246,    -1,   147,   156,   254,   227,   254,
     227,   254,   227,   254,   227,   246,    -1,   107,   254,   242,
     254,   227,   246,   227,   246,   227,   249,   227,   249,   227,
     246,    -1,   107,   254,   242,   254,   227,   246,   227,   246,
     227,   249,   227,   249,   227,   246,   227,   246,    -1,   107,
      20,   246,   227,   246,   227,   246,    -1,   107,   110,   246,
     227,   246,   227,   249,    -1,   107,    60,   246,   227,   246,
     227,   249,   227,   249,   227,   249,    -1,   107,   110,   246,
     227,   249,    -1,   157,   246,    -1,   119,   110,   246,   227,
     246,   227,   246,    -1,   119,    60,   246,   227,   246,   227,
     249,   227,   249,   227,   249,    -1,   119,   110,   246,   227,
     246,    -1,   119,   110,   246,   227,   246,   227,   249,    -1,
     119,   110,   246,   227,   246,   227,   249,   227,   249,    -1,
     117,   254,   227,   246,    -1,   117,   218,   254,   242,   254,
     227,   246,   227,   246,    -1,   117,   218,   249,   227,   246,
     227,   246,    -1,   117,   218,   246,   227,   246,   227,   246,
      -1,   147,   117,   254,   227,   246,   227,   246,   227,   246,
      -1,   147,   117,   254,   242,   254,   227,   246,   227,   246,
     227,   246,    -1,   117,   104,   246,    -1,    58,   254,   242,
     254,   227,   246,    -1,   118,   254,   242,   254,   227,   246,
     227,   246,    -1,   113,   120,   246,    -1,   121,   254,   227,
     246,   227,   246,    -1,   121,   110,   246,   227,   249,   227,
     249,   227,   249,    -1,   100,   110,   246,   227,   246,    -1,
     100,   110,   246,   227,   249,    -1,   100,    91,   246,    -1,
     122,   254,   242,   254,   227,   246,   227,   249,   227,   246,
      -1,   122,   103,   246,   227,   246,    -1,   122,   103,   246,
     227,   246,   227,   246,   227,   249,    -1,   122,   103,   246,
     227,   246,   227,   249,   227,   249,   227,   249,    -1,   122,
     103,   246,   227,   246,   227,   249,    -1,   122,    91,   246,
      -1,   122,   104,   246,   227,   246,    -1,   122,   131,   246,
     227,   249,    -1,   122,   104,   246,   227,   249,    -1,   122,
     104,   246,   227,   246,   227,   246,    -1,   122,   133,   246,
     227,   246,    -1,   122,   134,   246,   227,   246,    -1,    95,
     210,   254,   227,   246,   227,   246,   227,   246,   227,   246,
     227,   246,    -1,    98,   210,   254,   227,   246,   227,   246,
     227,   246,   227,   246,   227,   246,   227,   249,   227,   246,
      -1,    98,   110,   246,   227,   249,    -1,    99,   110,   246,
     227,   249,    -1,   126,   246,   227,   246,    -1,   126,    60,
     246,   227,   249,   227,   249,   227,   249,    -1,   101,   125,
     246,    -1,   122,   125,   246,    -1,   123,   254,   242,   254,
     227,   246,   227,   249,   227,   246,   227,   246,    -1,   123,
     103,   246,   227,   249,   227,   249,   227,   249,   227,   246,
      -1,   123,   124,   246,   227,   246,   227,   249,   227,   249,
     227,   249,   227,   249,   227,   246,    -1,   123,    91,   246,
      -1,   123,   104,   246,   227,   249,    -1,   123,   131,   246,
     227,   249,    -1,   123,    60,   246,   227,   246,   227,   249,
     227,   249,   227,   249,    -1,   127,   254,   227,   246,   227,
     246,   227,   246,   227,   246,    -1,   127,   110,   246,   227,
     246,    -1,   132,   246,   227,   249,   227,   246,    -1,   132,
     110,   246,   227,   246,   227,   249,    -1,   132,   110,   246,
     227,   246,   227,   249,   227,   249,    -1,   132,   110,   246,
     227,   246,    -1,   102,   131,   246,   227,   249,    -1,    97,
     110,   246,   227,   249,   227,   246,    -1,    97,   110,   246,
     227,   246,   227,   246,   227,   246,    -1,   130,   246,   227,
     246,   227,   246,   227,   246,   227,   246,    -1,   130,   110,
     246,   227,   246,   227,   249,   227,   246,    -1,   130,   110,
     246,   227,   246,   227,   246,   227,   246,   227,   246,    -1,
     108,   254,   242,   254,   227,   246,   227,   246,   227,   246,
     227,   246,    -1,   108,   110,   246,   227,   246,   227,   246,
     227,   249,    -1,   108,   110,   246,   227,   249,   227,   249,
     227,   249,    -1,   138,   254,   227,   246,   227,   246,   227,
     249,   227,   249,   227,   249,   227,   246,    -1,   138,   110,
     246,   227,   249,    -1,   128,   129,   246,    -1,    93,    94,
     246,    -1,   214,   110,   246,    -1,   142,   144,   249,    -1,
     142,   144,   224,   249,   225,    -1,   142,    82,   249,    -1,
     142,    82,   224,   249,   225,    -1,   135,   254,   242,   254,
     227,   246,   227,   249,   227,   249,   227,   246,    -1,   135,
     110,   246,   227,   246,   227,   249,    -1,   135,   110,   246,
     227,   246,   227,   249,   227,   249,    -1,   136,   254,   242,
     254,   227,   246,   227,   249,   227,   246,    -1,   136,   110,
     246,   227,   249,    -1,   116,   254,   227,   246,   227,   246,
     227,   246,   227,   246,    -1,   116,    60,   246,   227,   246,
     227,   249,   227,   249,   227,   249,    -1,   158,   110,   246,
     227,   246,   227,   246,   227,   246,    -1,   158,    91,   246,
     227,   246,    -1,   154,   246,   242,   249,   227,   249,    -1,
      91,    57,    -1,    82,   249,    -1,    83,    -1,   184,    -1,
     184,   224,   225,    -1,   184,   224,   249,   225,    -1,   198,
     224,   246,   225,    -1,   201,   246,   227,   246,    -1,   201,
     246,   227,   249,    -1,   201,   335,   227,   246,    -1,   201,
     335,   227,   249,    -1,    54,    -1,    55,    -1,    55,   249,
      -1,     6,    -1,    87,   246,    -1,     5,    70,   246,    -1,
     180,   224,   245,   227,   249,   227,   249,   225,    70,   246,
      -1,   180,   224,   245,   227,   249,   225,    70,   246,    -1,
     178,   224,   245,   227,   249,   225,    70,   246,    -1,   179,
     224,   245,   227,   249,   225,    70,   246,    -1,   261,    70,
     246,    -1,   227,    -1,    10,    -1,    75,   335,   227,   246,
     227,   246,    -1,    75,   335,   227,   246,    -1,    75,   246,
       9,    80,    79,   335,    -1,    75,   246,     9,    81,    79,
     335,    -1,    77,   335,   227,   249,    -1,    77,   335,   227,
     249,   227,   246,    -1,     5,    -1,     5,   224,   262,   225,
      -1,     5,    -1,   247,    -1,   261,    -1,     8,    -1,   246,
     220,   246,    -1,   224,   246,   225,    -1,   178,   224,   246,
     227,   249,   225,    -1,   179,   224,   246,   227,   249,   225,
      -1,   180,   224,   246,   227,   249,   227,   249,   225,    -1,
     180,   224,   246,   227,   249,   225,    -1,   183,   224,   249,
     225,    -1,   183,   224,   249,   227,   246,   225,    -1,   183,
     224,   249,   227,   246,   227,   246,   225,    -1,   184,    -1,
     184,   224,   225,    -1,   184,   224,   249,   225,    -1,   185,
     224,   249,   225,    -1,   190,   224,   246,   225,    -1,   191,
     224,   246,   225,    -1,   193,   224,   246,   225,    -1,   194,
     224,   246,   225,    -1,   192,   224,   246,   225,    -1,   197,
     224,   246,   225,    -1,   202,    -1,   202,   224,   225,    -1,
     203,    -1,   203,   224,   225,    -1,   200,   224,   246,   225,
      -1,   200,   224,   246,   227,   246,   225,    -1,   205,   224,
     245,   227,   246,   225,    -1,   205,   224,   245,   225,    -1,
     207,   224,   245,   227,   246,   225,    -1,   207,   224,   245,
     225,    -1,   153,   224,   249,   227,   249,   242,   249,   227,
     249,   225,    -1,   187,   224,   249,   225,    -1,   189,   224,
     249,   225,    -1,    29,   224,   262,   225,    -1,   209,    -1,
     209,   224,   225,    -1,   214,   209,    -1,   214,   209,   224,
     225,    -1,   212,   224,   246,   225,    -1,    97,   212,   224,
     246,   225,    -1,   111,   213,   246,    -1,   111,   213,   246,
     227,   249,    -1,   111,   213,   246,   227,   246,    -1,   100,
     213,   246,    -1,   106,   246,   227,   246,   227,   246,    -1,
     106,   246,   227,   246,   227,   246,   227,   246,    -1,   214,
     209,   246,    -1,   216,   209,   246,    -1,   128,   217,    -1,
     123,   213,   246,   227,   249,   227,   249,    -1,   127,   213,
     246,    -1,   101,   213,   246,   227,   249,    -1,   122,   213,
     246,   227,   249,    -1,   137,   254,   227,   246,   227,   246,
      -1,   102,   213,   246,   227,   249,    -1,   147,   213,   246,
      -1,   158,   213,   246,   227,   246,    -1,     4,    70,   249,
      -1,   260,    70,   249,    -1,    -1,   249,    62,   250,   249,
      -1,    -1,   249,    61,   251,   249,    -1,    63,   249,    -1,
     249,    70,   249,    -1,   249,    65,   249,    -1,   249,    68,
     249,    -1,   249,    66,   249,    -1,   249,    69,   249,    -1,
     249,    67,   249,    -1,   169,   224,   335,   225,    -1,   208,
     224,   246,   227,   246,   225,    -1,   257,    -1,    85,   224,
     252,   225,    -1,    85,   224,   253,   225,    -1,    86,   224,
     252,   227,   249,   225,    -1,    86,   224,   253,   227,   249,
     225,    -1,   260,    -1,     4,    -1,   249,   220,   249,    -1,
     249,   219,   249,    -1,   249,   221,   249,    -1,   249,   222,
     249,    -1,   249,    71,   249,    -1,   219,   249,    -1,   246,
      70,   246,    -1,   246,    65,   246,    -1,   246,    68,   246,
      -1,   246,    66,   246,    -1,   246,    69,   246,    -1,   246,
      67,   246,    -1,   255,    -1,   224,   249,   225,    -1,     4,
     224,   225,    -1,     5,   224,   225,    -1,   249,   227,   249,
      -1,   159,   224,   249,   225,    -1,   160,   224,   249,   225,
      -1,   161,   224,   249,   225,    -1,   162,   224,   249,   225,
      -1,   163,   224,   249,   225,    -1,   164,   224,   249,   225,
      -1,   164,   224,   249,   227,   249,   225,    -1,   165,   224,
     249,   225,    -1,   166,   224,   249,   225,    -1,   166,   224,
     249,   227,   249,   225,    -1,   167,   224,   249,   225,    -1,
     168,   224,   249,   225,    -1,   172,   224,   249,   225,    -1,
     173,   224,   249,   225,    -1,   170,   224,   249,   225,    -1,
     171,   224,   249,   225,    -1,   174,   224,   249,   227,   249,
     225,    -1,   175,   224,   249,   225,    -1,   175,   224,   225,
      -1,   181,   224,   249,   227,   249,   225,    -1,   182,   224,
     249,   227,   249,   225,    -1,   176,   224,   246,   225,    -1,
     177,   224,   246,   225,    -1,   186,   224,   246,   225,    -1,
     188,   224,   246,   225,    -1,   188,   224,   246,   227,   249,
     225,    -1,   195,   224,   246,   227,   246,   225,    -1,   195,
     224,   246,   227,   246,   227,   249,   225,    -1,   196,   224,
     246,   227,   246,   225,    -1,   196,   224,   246,   227,   246,
     227,   249,   225,    -1,   198,   224,   246,   225,    -1,   199,
     224,   335,   225,    -1,   199,   224,   246,   225,    -1,    61,
     224,   249,   227,   249,   225,    -1,    62,   224,   249,   227,
     249,   225,    -1,    64,   224,   249,   227,   249,   225,    -1,
      78,   224,   335,   225,    -1,   204,   224,   246,   227,   253,
     227,   246,   225,    -1,   204,   224,   246,   227,   253,   225,
      -1,   206,   224,   246,   227,   253,   227,   246,   225,    -1,
     206,   224,   246,   227,   253,   225,    -1,    28,   224,   262,
     225,    -1,    75,   224,   246,   225,    -1,    75,   224,   246,
     227,   246,   225,    -1,    75,   224,   335,   227,   246,   225,
      -1,    75,   224,   335,   227,   246,   227,   246,   225,    -1,
     147,   210,   249,   227,   249,   227,   246,   227,   246,    -1,
     147,   210,   254,   242,   254,   227,   246,   227,   246,    -1,
     211,   254,   242,   254,   227,   246,   227,   246,    -1,    88,
     112,    -1,   215,   246,    -1,   123,   112,   246,    -1,    88,
     218,   246,   227,   246,    -1,   113,   218,   246,   227,   246,
      -1,    96,   246,   227,   246,   227,   246,   227,   246,   227,
     246,    -1,   101,   112,   246,    -1,   122,   112,   246,    -1,
     132,   218,   246,   227,   246,    -1,   135,   218,   246,   227,
     246,    -1,   136,   218,   246,    -1,   115,   218,   246,    -1,
     138,   218,   246,    -1,   102,   112,   246,    -1,   107,   218,
     246,    -1,   121,   218,   246,   227,   246,    -1,   111,   218,
     246,   227,   246,    -1,   111,   218,   246,   227,   246,   227,
     249,    -1,   111,   218,   246,   227,   246,   227,   246,    -1,
     147,   218,   246,   227,   246,   227,   246,    -1,   147,   218,
     246,   227,   246,    -1,   147,   218,   254,   227,   246,   227,
     246,    -1,   140,   139,   246,   227,   246,    -1,   141,   104,
     246,   227,   249,    -1,   141,   218,   246,   227,   246,    -1,
      93,   246,   227,   246,   227,   246,    -1,   142,   143,   246,
      -1,   146,    -1,   101,   218,   246,    -1,   102,   218,   246,
      -1,   122,   218,   246,    -1,   123,   218,   246,    -1,   122,
     218,   246,   227,   246,   227,   249,    -1,   117,   151,   246,
     227,   246,   227,   246,    -1,   117,   210,   246,   227,   246,
      -1,   117,   218,   246,   227,   246,    -1,   117,    60,   249,
     227,   249,   227,   246,   227,   246,    -1,   158,   218,   246,
     227,   246,    -1,   257,    -1,   220,   257,    -1,   219,   257,
      -1,     3,    -1,     7,    -1,     7,    -1,     4,    -1,     4,
     224,   262,   225,    -1,   259,   227,     4,   224,   262,   225,
      -1,     5,   224,   262,   225,    -1,   259,   227,     5,   224,
     262,   225,    -1,     4,   224,   262,   225,    -1,     5,   224,
     262,   225,    -1,    -1,   263,   264,    -1,    -1,   265,    -1,
     264,   227,   265,    -1,   246,    -1,   249,    -1,    -1,    -1,
      -1,   272,    22,   267,   271,   268,   224,   277,   225,   269,
     231,   270,    -1,    42,    -1,    23,    -1,     4,    -1,     5,
      -1,    -1,    26,    -1,    31,    -1,    31,    26,    -1,   274,
      -1,   273,   227,   274,    -1,     4,    -1,     5,    -1,     4,
     224,   262,   225,    -1,     5,   224,   262,   225,    -1,   276,
      -1,   275,   227,   276,    -1,     4,    -1,     5,    -1,     4,
     224,   262,   225,    -1,     5,   224,   262,   225,    -1,    -1,
     278,    -1,   277,   227,   278,    -1,     4,    -1,     5,    -1,
       4,   224,   225,    -1,     5,   224,   225,    -1,    -1,    -1,
      -1,    -1,     9,   280,     4,    70,   281,   249,    10,   249,
     285,   282,   231,   283,   284,   286,    -1,    42,    -1,    12,
      -1,    -1,    11,   249,    -1,    -1,     4,    -1,    -1,    35,
     288,   290,   289,   291,   294,    36,    -1,    41,    -1,   289,
      41,    -1,   249,    -1,   246,    -1,    -1,    -1,    -1,   291,
      37,   292,   290,   293,   231,    -1,    -1,    -1,    38,    41,
     295,   231,    -1,    -1,    40,   297,   231,   298,    -1,    42,
      -1,    39,    -1,    -1,    -1,    13,   300,   224,   249,   225,
     301,   231,   302,    -1,    42,    -1,    14,    -1,    -1,    15,
     304,   231,   305,    -1,    42,    -1,    16,   224,   249,   225,
      -1,    -1,    -1,    -1,    -1,    43,   249,   307,    44,   308,
     231,   309,   315,   314,   310,   311,    -1,    42,    -1,    47,
      -1,    -1,    43,   249,   313,   231,    47,    -1,    -1,    45,
     231,    -1,    -1,    -1,    -1,    46,   249,   318,   316,   231,
     317,   315,    -1,    -1,    44,    -1,   321,    -1,    -1,   321,
     227,   320,   319,    -1,     4,    -1,     4,   224,   262,   225,
      -1,     5,    -1,     5,   224,   262,   225,    -1,   323,    -1,
     322,   227,   323,    -1,     4,    -1,     4,   224,   262,   225,
      -1,     5,    -1,     5,   224,   262,   225,    -1,     8,    -1,
     256,    -1,   324,   227,     8,    -1,   324,   227,   256,    -1,
      -1,   249,   326,    -1,   325,   227,   249,   326,    -1,   246,
      -1,   325,   227,   246,    -1,    -1,    48,   246,    -1,    48,
     224,   246,   227,   246,   225,    -1,    -1,   228,     4,   328,
     319,    -1,    -1,   228,     7,   329,   319,    -1,    -1,   228,
     224,   249,   225,   330,   319,    -1,    -1,    56,   224,   249,
     227,   249,   225,   331,   333,   319,    -1,    -1,   332,   333,
     319,    -1,    -1,     8,    -1,    -1,   228,     4,    -1,   228,
       7,    -1,   228,   224,   249,   225,    -1,    59,    -1,    60,
     224,   246,   225,    -1,    60,   224,   246,   227,   246,   225,
      -1,    56,   224,   249,   227,   249,   225,    -1,    59,    56,
     224,   249,   227,   249,   225,    -1,    60,   224,   246,   225,
      56,   224,   249,   227,   249,   225,    -1,    60,   224,   246,
     227,   246,   225,    56,   224,   249,   227,   249,   225,    -1,
      56,   224,   249,   227,   249,   225,    59,    -1,    56,   224,
     249,   227,   249,   225,    60,   224,   246,   225,    -1,    56,
     224,   249,   227,   249,   225,    60,   224,   246,   227,   246,
     225,    -1,   228,   249,    -1,   249,    -1,   258,    -1,   336,
     227,   258,    -1,   258,    -1,   337,   227,   258,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   148,   148,   151,   152,   153,   152,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   173,   174,   174,   175,   176,
     177,   178,   179,   180,   181,   181,   183,   183,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   195,
     196,   196,   197,   198,   199,   200,   201,   202,   211,   212,
     213,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   250,   251,   252,   253,   254,   255,   256,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   282,   283,   284,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   300,   301,   302,
     303,   304,   305,   306,   307,   308,   309,   310,   311,   312,
     313,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   378,   379,   380,   381,   382,   383,
     384,   385,   386,   398,   399,   400,   401,   402,   403,   406,
     407,   410,   411,   413,   414,   417,   418,   421,   422,   425,
     426,   427,   428,   429,   430,   433,   434,   435,   436,   437,
     438,   439,   440,   441,   442,   443,   444,   445,   446,   447,
     448,   449,   450,   451,   452,   453,   454,   455,   456,   457,
     458,   459,   460,   461,   462,   463,   464,   465,   466,   467,
     468,   469,   470,   471,   472,   473,   474,   475,   476,   478,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   491,
     492,   495,   495,   496,   496,   497,   498,   499,   500,   501,
     502,   503,   504,   505,   506,   507,   508,   509,   510,   511,
     512,   513,   514,   515,   516,   517,   518,   519,   520,   521,
     522,   523,   524,   525,   526,   529,   532,   535,   538,   539,
     540,   541,   542,   543,   544,   545,   546,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,   558,   559,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   584,   585,   586,   587,   588,   589,   590,   591,   592,
     593,   594,   595,   596,   597,   598,   599,   600,   602,   603,
     604,   605,   606,   607,   608,   609,   610,   611,   612,   613,
     614,   615,   616,   617,   618,   619,   620,   621,   622,   623,
     624,   625,   626,   627,   628,   629,   630,   631,   632,   633,
     634,   635,   636,   637,   638,   641,   642,   643,   646,   647,
     650,   651,   654,   655,   656,   657,   660,   663,   666,   666,
     669,   670,   671,   674,   675,   678,   679,   682,   678,   687,
     688,   691,   692,   695,   696,   697,   698,   701,   702,   705,
     706,   707,   708,   711,   712,   715,   716,   717,   718,   721,
     722,   723,   726,   727,   728,   729,   732,   733,   737,   750,
     732,   755,   756,   759,   760,   763,   764,   769,   769,   774,
     775,   778,   779,   783,   784,   785,   784,   789,   790,   790,
     794,   794,   800,   801,   805,   806,   805,   812,   813,   817,
     817,   822,   823,   827,   828,   828,   830,   827,   834,   835,
     838,   838,   842,   843,   846,   848,   850,   847,   854,   855,
     858,   859,   859,   862,   863,   865,   866,   870,   871,   874,
     875,   877,   878,   882,   883,   884,   885,   888,   889,   890,
     891,   892,   895,   896,   897,   900,   900,   901,   901,   902,
     902,   903,   903,   904,   904,   907,   908,   911,   912,   913,
     914,   915,   916,   917,   918,   919,   920,   921,   922,   923,
     924,   927,   928,   930,   931,   934,   935
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "tFNUM", "tSYMBOL", "tSTRSYM", "tDOCU",
  "tDIGITS", "tSTRING", "tFOR", "tTO", "tSTEP", "tNEXT", "tWHILE", "tWEND",
  "tREPEAT", "tUNTIL", "tIMPORT", "tGOTO", "tGOSUB", "tLABEL", "tON",
  "tSUB", "tENDSUB", "tLOCAL", "tSTATIC", "tEXPORT", "tERROR", "tEXECUTE",
  "tEXECUTE2", "tCOMPILE", "tRUNTIME_CREATED_SUB", "tINTERRUPT", "tBREAK",
  "tCONTINUE", "tSWITCH", "tSEND", "tCASE", "tDEFAULT", "tLOOP", "tDO",
  "tSEP", "tEOPROG", "tIF", "tTHEN", "tELSE", "tELSIF", "tENDIF", "tUSING",
  "tPRINT", "tINPUT", "tLINE", "tRETURN", "tDIM", "tEND", "tEXIT", "tAT",
  "tSCREEN", "tSCREENSHOT", "tREVERSE", "tCOLOUR", "tAND", "tOR", "tNOT",
  "tEOR", "tNEQ", "tLEQ", "tGEQ", "tLTN", "tGTN", "tEQU", "tPOW", "tREAD",
  "tDATA", "tRESTORE", "tOPEN", "tCLOSE", "tSEEK", "tTELL", "tAS",
  "tREADING", "tWRITING", "tWAIT", "tBELL", "tLET", "tARDIM", "tARSIZE",
  "tBIND", "tWINDOW", "tDOT", "tCIRCLE", "tCLEAR", "tFILL", "tPRINTER",
  "tSETUP", "tBUTTON", "tALERT", "tMENU", "tCHECKBOX", "tRADIOBUTTON",
  "tTEXTCONTROL", "tLISTBOX", "tDROPBOX", "tADD", "tREMOVE", "tLOCALIZE",
  "tFILEPANEL", "tSLIDER", "tSTATUSBAR", "tLAYOUT", "tSET", "tTEXTEDIT",
  "tCOUNT", "tVIEW", "tBOXVIEW", "tTABVIEW", "tTEXTURL", "tBITMAP",
  "tCANVAS", "tOPTION", "tDROPZONE", "tCOLORCONTROL", "tTREEBOX",
  "tCOLUMNBOX", "tCOLUMN", "tSORT", "tTOOLTIP", "tCALENDAR", "tCLIPBOARD",
  "tCOPY", "tSUBMENU", "tSELECT", "tSCROLLBAR", "tEXPAND", "tCOLLAPSE",
  "tSPLITVIEW", "tSTACKVIEW", "tPOPUPMENU", "tSPINCONTROL", "tMSEND",
  "tNUMMESSAGE", "tTHREAD", "tSOUND", "tPLAY", "tSTOP", "tSHORTCUT",
  "tISCOMPUTERON", "tDRAW", "tTEXT", "tFLUSH", "tELLIPSE", "tSAVE",
  "tRECT", "tGETCHAR", "tPUTCHAR", "tNEW", "tCURVE", "tLAUNCH",
  "tATTRIBUTE", "tSIN", "tASIN", "tCOS", "tACOS", "tTAN", "tATAN", "tEXP",
  "tLOG", "tSQRT", "tSQR", "tMYEOF", "tABS", "tSIG", "tINT", "tFRAC",
  "tMOD", "tRAN", "tLEN", "tVAL", "tLEFT", "tRIGHT", "tMID", "tMIN",
  "tMAX", "tSTR", "tINKEY", "tCHR", "tASC", "tHEX", "tDEC", "tBIN",
  "tUPPER", "tLOWER", "tTRIM", "tLTRIM", "tRTRIM", "tINSTR", "tRINSTR",
  "tSYSTEM", "tSYSTEM2", "tPEEK", "tPEEK2", "tPOKE", "tDATE", "tTIME",
  "tTOKEN", "tTOKENALT", "tSPLIT", "tSPLITALT", "tGLOB", "tMESSAGE",
  "tIMAGE", "tSVG", "tTRANSLATE", "tGET", "tMOUSE", "tISMOUSEIN",
  "tKEYBOARD", "tPASTE", "tGETNUM", "'-'", "'+'", "'*'", "'/'", "UMINUS",
  "'('", "')'", "';'", "','", "'#'", "$accept", "program",
  "statement_list", "$@1", "$@2", "statement", "$@3", "$@4", "$@5", "$@6",
  "$@7", "$@8", "string_assignment", "to", "open_clause", "seek_clause",
  "string_scalar_or_array", "string_expression", "string_function",
  "assignment", "expression", "$@9", "$@10", "arrayref", "string_arrayref",
  "coordinates", "function", "const", "number", "symbol_or_lineno",
  "dimlist", "function_or_array", "stringfunction_or_array", "call_list",
  "$@11", "calls", "call_item", "function_definition", "$@12", "$@13",
  "$@14", "endsub", "function_name", "export", "local_list", "local_item",
  "static_list", "static_item", "paramlist", "paramitem", "for_loop",
  "$@15", "$@16", "$@17", "$@18", "next", "step_part", "next_symbol",
  "switch_number_or_string", "$@19", "sep_list", "number_or_string",
  "case_list", "$@20", "$@21", "default", "$@22", "do_loop", "$@23",
  "loop", "while_loop", "$@24", "$@25", "wend", "repeat_loop", "$@26",
  "until", "if_clause", "$@27", "$@28", "$@29", "$@30", "endif",
  "short_if", "$@31", "else_part", "elsif_part", "$@32", "$@33",
  "maybe_then", "inputlist", "$@34", "input", "readlist", "readitem",
  "datalist", "printlist", "using", "inputbody", "$@35", "$@36", "$@37",
  "$@38", "$@39", "prompt", "printintro", "hashed_number", "goto_list",
  "gosub_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   462,   463,   464,
     465,   466,   467,   468,   469,   470,   471,   472,   473,    45,
      43,    42,    47,   474,    40,    41,    59,    44,    35
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   229,   230,   231,   232,   233,   231,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   235,   234,   236,   234,   234,   234,
     234,   234,   234,   234,   237,   234,   238,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   239,   234,
     240,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   234,   234,   234,   234,   234,
     234,   234,   234,   241,   241,   241,   241,   241,   241,   242,
     242,   243,   243,   243,   243,   244,   244,   245,   245,   246,
     246,   246,   246,   246,   246,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   248,
     248,   250,   249,   251,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   252,   253,   254,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   256,   256,   256,   257,   257,
     258,   258,   259,   259,   259,   259,   260,   261,   263,   262,
     264,   264,   264,   265,   265,   267,   268,   269,   266,   270,
     270,   271,   271,   272,   272,   272,   272,   273,   273,   274,
     274,   274,   274,   275,   275,   276,   276,   276,   276,   277,
     277,   277,   278,   278,   278,   278,   280,   281,   282,   283,
     279,   284,   284,   285,   285,   286,   286,   288,   287,   289,
     289,   290,   290,   291,   292,   293,   291,   294,   295,   294,
     297,   296,   298,   298,   300,   301,   299,   302,   302,   304,
     303,   305,   305,   307,   308,   309,   310,   306,   311,   311,
     313,   312,   314,   314,   315,   316,   317,   315,   318,   318,
     319,   320,   319,   321,   321,   321,   321,   322,   322,   323,
     323,   323,   323,   324,   324,   324,   324,   325,   325,   325,
     325,   325,   326,   326,   326,   328,   327,   329,   327,   330,
     327,   331,   327,   332,   327,   333,   333,   334,   334,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   335,   335,   336,   336,   337,   337
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     0,     5,     0,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     0,     3,     0,     3,     1,     1,
       2,     2,     3,     3,     0,     5,     0,     5,     2,     1,
       2,     1,     2,     4,     4,     3,     4,     4,     0,     3,
       0,     4,     2,     2,     1,     2,     2,     1,     2,     2,
       2,     9,    10,     8,    10,    10,    12,    10,     3,     5,
       7,    10,     5,     3,     5,     5,     5,     5,     6,     8,
      10,     5,     1,     2,     2,     7,     7,     3,     3,     4,
       5,     7,     9,     6,    10,     5,     5,     7,     7,     7,
      11,     3,     5,     5,    11,     5,     7,     8,     3,    12,
      10,     5,     5,     5,     5,     7,     7,     9,    11,    14,
      16,     7,     7,    11,     5,     2,     7,    11,     5,     7,
       9,     4,     9,     7,     7,     9,    11,     3,     6,     8,
       3,     6,     9,     5,     5,     3,    10,     5,     9,    11,
       7,     3,     5,     5,     5,     7,     5,     5,    13,    17,
       5,     5,     4,     9,     3,     3,    12,    11,    15,     3,
       5,     5,    11,    10,     5,     6,     7,     9,     5,     5,
       7,     9,    10,     9,    11,    12,     9,     9,    14,     5,
       3,     3,     3,     3,     5,     3,     5,    12,     7,     9,
      10,     5,    10,    11,     9,     5,     6,     2,     2,     1,
       1,     3,     4,     4,     4,     4,     4,     4,     1,     1,
       2,     1,     2,     3,    10,     8,     8,     8,     3,     1,
       1,     6,     4,     6,     6,     4,     6,     1,     4,     1,
       1,     1,     1,     3,     3,     6,     6,     8,     6,     4,
       6,     8,     1,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     3,     1,     3,     4,     6,     6,     4,
       6,     4,    10,     4,     4,     4,     1,     3,     2,     4,
       4,     5,     3,     5,     5,     3,     6,     8,     3,     3,
       2,     7,     3,     5,     5,     6,     5,     3,     5,     3,
       3,     0,     4,     0,     4,     2,     3,     3,     3,     3,
       3,     3,     4,     6,     1,     4,     4,     6,     6,     1,
       1,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     3,     3,     4,     4,
       4,     4,     4,     4,     6,     4,     4,     6,     4,     4,
       4,     4,     4,     4,     6,     4,     3,     6,     6,     4,
       4,     4,     4,     6,     6,     8,     6,     8,     4,     4,
       4,     6,     6,     6,     4,     8,     6,     8,     6,     4,
       4,     6,     6,     8,     9,     9,     8,     2,     2,     3,
       5,     5,    10,     3,     3,     5,     5,     3,     3,     3,
       3,     3,     5,     5,     7,     7,     7,     5,     7,     5,
       5,     5,     6,     3,     1,     3,     3,     3,     3,     7,
       7,     5,     5,     9,     5,     1,     2,     2,     1,     1,
       1,     1,     4,     6,     4,     6,     4,     4,     0,     2,
       0,     1,     3,     1,     1,     0,     0,     0,    11,     1,
       1,     1,     1,     0,     1,     1,     2,     1,     3,     1,
       1,     4,     4,     1,     3,     1,     1,     4,     4,     0,
       1,     3,     1,     1,     3,     3,     0,     0,     0,     0,
      14,     1,     1,     0,     2,     0,     1,     0,     7,     1,
       2,     1,     1,     0,     0,     0,     6,     0,     0,     4,
       0,     4,     1,     1,     0,     0,     8,     1,     1,     0,
       4,     1,     4,     0,     0,     0,     0,    11,     1,     1,
       0,     5,     0,     2,     0,     0,     0,     7,     0,     1,
       1,     0,     4,     1,     4,     1,     4,     1,     3,     1,
       4,     1,     4,     1,     1,     3,     3,     0,     2,     4,
       1,     3,     0,     2,     6,     0,     4,     0,     4,     0,
       6,     0,     9,     0,     3,     0,     1,     0,     2,     2,
       4,     1,     4,     6,     6,     7,    10,    12,     7,    10,
      12,     2,     1,     1,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       7,     0,     0,   221,   476,   504,   509,    12,     0,     0,
       0,     0,    24,    26,   454,     0,     0,     0,     0,   455,
      19,    20,   487,   500,     0,   567,    48,     0,    57,     0,
     218,   219,     0,     0,     0,    54,     0,     0,     0,     0,
     209,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   210,     0,     0,
       0,     0,     4,     3,     8,    39,    41,    10,    22,    23,
      21,     0,    14,    15,    18,    17,    16,    28,    29,     0,
     438,     0,   438,     0,     0,     7,   431,   430,    30,    31,
      38,   428,   320,   239,   429,   242,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   414,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   252,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   262,
     264,     0,     0,     0,     0,     0,   276,     0,     0,     0,
       0,     0,     0,     0,     0,   240,     0,   333,   314,   319,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,   438,   438,    42,   456,     0,     7,   520,     0,
     571,     0,     0,   547,   563,    50,    59,    58,     0,     0,
      60,   220,     0,     0,   539,   541,    52,   537,   543,     0,
       0,   544,   425,    53,    56,    55,     0,     0,   582,     0,
      40,     0,   208,     9,    11,     0,     0,   222,     0,     0,
       0,   207,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     2,     0,     0,
       0,   445,   299,     0,   440,   223,     0,     0,     0,     4,
     438,   438,    32,    33,     0,     0,   305,     0,     0,     0,
       0,     0,   387,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   290,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     278,   388,     0,   326,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    36,   303,   301,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   459,   460,
      25,   457,   465,   466,    27,   463,     0,     0,     0,   492,
     491,     0,     4,     0,     7,     0,     0,     0,   568,   569,
       0,   550,   552,    45,     0,     0,    49,   565,   563,   438,
     438,     0,     0,   230,   229,     0,   438,   438,     0,   427,
     426,     0,   581,     0,     0,     0,     0,    88,     0,   191,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     145,     0,     0,    68,     0,     0,   164,     0,     0,    73,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,     0,     0,   108,   140,     0,     0,
       0,     0,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   151,     0,     0,   165,
       0,     0,     0,     0,     0,   169,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   190,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   195,     0,   193,
       0,     0,     0,     0,     0,     0,     0,     0,    87,     0,
       0,     0,     0,   229,     0,     0,     0,     0,   237,     0,
       0,     0,   211,     0,     0,     0,     0,   192,     5,   300,
     228,     0,   436,   443,   444,   439,   441,   437,   477,     0,
       0,   511,   510,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   285,   393,     0,   415,   400,     0,   416,     0,   401,
     282,     0,     0,   398,     0,     0,     0,     0,     0,   394,
       0,   417,   389,     0,   418,   292,     0,     0,   397,     0,
     399,     0,     0,     0,   413,     0,     0,   297,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   356,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   253,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   263,   265,
       0,     0,     0,     0,     0,   277,     0,     0,     0,   288,
     289,   244,   334,   328,   330,   332,   329,   331,   327,   243,
       0,     0,     0,     0,   307,   309,   311,   308,   310,   306,
     325,   322,   321,   323,   324,   438,   438,     0,   438,   438,
       0,    43,    44,   489,   493,   503,   502,   501,   514,     4,
       0,     0,     0,     0,     0,   548,    46,    47,     0,   555,
     557,     0,   566,     0,    51,     0,     0,     0,     0,   337,
       0,     0,     0,   538,   545,   546,     0,     0,   232,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   131,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   162,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   229,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   438,     0,     0,     0,
     212,   213,   214,   215,   216,   217,     7,   451,   452,   446,
       0,     0,   505,     0,   379,   275,     0,     0,     0,   380,
       0,     0,   374,     0,     0,   315,   316,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     338,   339,   340,   341,   342,   343,     0,   345,   346,     0,
     348,   349,   312,   352,   353,   350,   351,     0,   355,   359,
     360,     0,     0,     0,     0,     0,   249,     0,   254,   255,
     361,   273,   362,     0,   274,   256,   257,   260,   258,   259,
       0,     0,   261,   368,   370,   369,   266,     0,     0,   269,
       0,     0,   271,     0,     0,     0,   280,   279,   583,    35,
     585,    37,   304,   302,     0,     0,   458,     0,     0,   464,
     490,   497,     7,   521,     0,     0,   572,     0,   570,     0,
     553,   551,   552,     0,     0,     0,     0,   533,   535,   564,
     530,   432,   434,   438,   438,     0,   540,   542,     0,     0,
       0,     0,     0,    90,     0,     0,     0,     0,     0,     0,
     160,     0,     0,   161,     0,   143,   144,     0,    69,     0,
      75,    76,    77,     0,    72,    74,   179,     0,     0,     0,
       0,   124,     0,     0,     0,     0,     0,    95,    96,     0,
       0,     0,   112,   113,   111,     0,     0,     0,     0,     0,
       0,     0,     0,   128,     0,     0,   147,   152,   154,   153,
     156,   157,     0,     0,     0,   170,     0,   171,     0,     0,
     174,     0,     0,     0,   178,     0,     0,     0,   201,     0,
     189,     0,   196,   194,     0,     0,   114,     0,   102,   105,
     103,     0,     0,     0,     0,     0,     0,    81,     0,     0,
       0,   205,     0,     0,     0,     0,     0,     6,     0,   442,
       0,     7,     0,     0,     0,     0,     0,     0,   335,   336,
       0,     0,   390,     0,     0,   281,   293,   296,     0,   284,
     283,   403,   391,     0,     0,   421,   422,   402,   294,     0,
       0,   395,   396,     0,   409,   410,   411,   337,     0,   407,
       0,     0,   298,   424,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   461,   462,   467,   468,   494,
       0,     0,   515,     0,     0,     0,     0,     0,   549,     0,
     556,   558,   559,   438,   438,   531,     0,     0,   138,   233,
     234,   231,   236,     0,     0,     0,     0,    78,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   175,     0,     0,     0,     0,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   206,     0,   238,     0,     0,     0,     0,   469,     0,
       4,   512,   371,   372,   373,   381,   382,     0,   317,   318,
     412,     0,   286,     0,     0,     0,     0,     0,   295,     0,
       0,     0,     0,     0,   344,   347,   354,   245,   246,   248,
       0,   357,   358,   250,     0,   363,   364,     0,   366,     0,
     267,   376,     0,   268,   378,     0,   270,   313,     0,   584,
     586,     0,   498,   488,   524,   574,     0,     0,   573,     0,
       0,     0,     0,     0,     0,   433,   435,     0,    91,     0,
       0,     0,     0,   180,     0,     0,     0,     0,     0,    70,
       0,     0,   121,     0,   122,     0,     0,     0,     0,    99,
       0,    98,    97,     0,     0,     0,     0,     0,     0,   134,
     133,     0,     0,     0,   126,   129,     0,     0,   150,   155,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     176,   198,     0,     0,     0,   115,   116,   106,     0,     0,
       0,    85,     0,    86,     0,     0,     0,     0,     0,     0,
       0,     0,   472,   473,     0,   470,   483,   508,   507,   506,
       0,     0,     0,   405,   404,     0,   420,   419,   291,     0,
       0,   406,   408,     0,     0,     0,     0,     0,     0,     0,
       0,   495,     7,     0,   522,   578,     0,   575,     0,     0,
       0,   561,   560,   534,   536,   532,     0,     0,     0,     0,
       0,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   107,     0,     0,     0,     0,
       0,   139,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,     0,     0,
     226,   227,   225,     0,     0,     0,   447,     0,     0,   478,
     383,     0,   287,     0,     0,     0,     0,   247,   251,   365,
     367,   375,   377,   386,     7,     4,   528,     7,   516,     0,
       0,     0,   554,   565,    61,    92,     0,     0,   181,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   187,     0,
       0,     0,     0,     0,     0,     0,   132,     0,   130,   142,
     148,     0,     0,     0,     0,     0,     0,   163,     0,     0,
     183,     0,   177,   199,     0,     0,     0,     0,   135,     0,
     117,     0,     0,   204,     0,   474,   475,     7,   471,   484,
       7,     0,   423,   384,   385,     0,   496,   529,   525,   523,
       0,     0,     0,     0,     0,     0,    62,     0,    64,    65,
       0,    67,    71,     0,     0,     0,     0,    94,     0,   110,
       0,   202,     0,     0,   146,     0,     0,     0,     0,   173,
       0,   182,     0,   200,     0,     0,     0,     0,    80,   224,
       4,   479,   392,   272,     7,   518,   519,   517,   579,     0,
     576,     0,   562,     0,     0,     0,   123,     0,     0,   100,
       0,   203,   127,   149,   172,   167,     0,     0,   184,     0,
       0,   104,   136,   118,   450,   449,   448,     0,   526,     0,
       0,     0,     0,    66,     0,   185,   109,     0,   166,   197,
       0,   482,   481,   485,   524,   580,   577,   158,     0,     0,
       0,     0,   486,   480,   527,     0,   119,     0,   188,     0,
       0,   168,     0,   120,   159
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    91,    92,   408,  1036,    93,   231,   232,   870,   871,
     254,   588,    94,   595,    95,    96,   719,   224,   225,    97,
     262,   873,   872,   753,   754,   263,   227,   271,   228,   118,
     260,   229,   230,   413,   414,   735,   736,   100,   731,  1298,
    1797,  1886,  1039,   101,   560,   561,   564,   565,  1614,  1615,
     102,   113,  1041,  1800,  1887,  1903,  1719,  1913,   103,   246,
     894,   571,  1161,  1521,  1734,  1371,  1642,   104,   247,   897,
     105,   114,  1301,  1619,   106,   115,   742,   107,   573,  1162,
    1524,  1810,  1857,   108,   574,  1738,  1644,  1854,  1904,  1808,
    1179,  1534,  1180,   266,   267,   273,   583,   905,   586,  1174,
    1175,  1531,  1743,   587,   913,   253,   279,  1149,  1151
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -1169
static const yytype_int16 yypact[] =
{
   10703,   -52,   -45, -1169, -1169, -1169, -1169, -1169,   124,   124,
     124,  6567, -1169, -1169, -1169, 10248,  -105,   -94, 10248,   160,
   -1169, -1169, -1169, -1169,  8965,   -22, -1169,   153,  8965,   242,
   -1169,  8965,  8965,   416,    33,  2576,  2136,  2136,  2136,  8965,
   -1169,    11, 10248,   -11,   113,   136,  6785, 10248,  9643,  5695,
    7003,  5913,  4605,  4823,  9764,  5259,  7221, 10248,  5041,  6131,
    8965,  5477,  7439,  6349,  8965,   -34,  7657,  4169,  4387,  9885,
    7875,    89, 10006, 10127,  8093,  8311,  8529,   -23, 10248,  1069,
    8747, 10248, 10248,   -31,    26,    54,    95,    99,   105,  2136,
     197,   276,   315, -1169, -1169, -1169, -1169, -1169,   322,   324,
   -1169,   366, -1169, -1169, -1169, -1169, -1169, -1169, -1169,  8965,
   -1169, 10248, -1169,   394,   193, 10703, -1169, -1169, -1169, -1169,
   -1169, -1169,   205,   211, -1169, -1169,   223,   227,    28,   296,
     306,  8965,   320,   368,   402,   429,   438,   -62, 10248, 10248,
     254,   297,   -59,   -56, 10248,   364,   -26,   450,   452,   -25,
     466,   137,   167,   482,   513,   503,   524,   575,  8965,   585,
     566,   -85,   625, -1169,   -30,   555,     2,   648,   660,   698,
     710,   725,   740,   752,   754,   768,   778,   779,   782,   810,
     813,   823,   824,   840,   871,   882,   913,   914,   923,   925,
     927,   953,   958,   961,   967,   984,   987,   989,   999,  1000,
    1004,  1014,  1025,  1031,  1055,  1056,  1067,  1073,  1078,  1087,
    1089,  1090,  1093,  1107,  1110,  1111,  1119,  8965,  1122,   596,
   10248,   614,  8965,  8965,    70, -1169,   590, -1169, -1169, -1169,
   -1169,   484,   618,   692,   775,   791,   809,   811,   833,   848,
   10248,   686, -1169, -1169,   686, -1169,  8965, 10703,   335,  1131,
     921,  1148,     4,  8965,   -32, -1169,    70,  2812,  1152,  1153,
     870,  2812,  1065,     0,  1194,  1195,   938, -1169, -1169,    94,
      94, -1169, -1169,   982,   686, -1169,  8965,     3,  2812,  1006,
   -1169,  1030,  2812, -1169, -1169,   322,   324,   686,  8965, 10248,
   10248, -1169, 10248,  8965,     0,  -143, 10248,  -142, 10248,  8965,
    1039, 10248,  1062, 10248, 10248,     0, 10248, 10248, 10248, 10248,
   10248,     0, 10248, 10248, 10248, 10248,     0, -1169,   686, 10248,
   10248, 10248,     0, 10248,     0,   -93, 10248, 10248, 10248, 10248,
       0, 10248, 10248,     0,     0, 10248, 10248, 10248,     0, 10248,
    1133, 10248,  8965,  1176,     0, 10248, 10248, 10248,  1193, 10248,
   10248, 10248, 10248, 10248, 10248, 10248,     0, 10248, 10248, 10248,
   10248, 10248, 10248,     0, 10248,    24, 10248,  1197, 10248, 10248,
      38, 10248,   121, 10248,     0, 10248,     0, 10248,  1206,  9183,
    9401,   145,  8965,  8965,  8965,  8965,  8965,  8965, 10248,  8965,
    8965,  8965, 10248,    12,    -1,   686, 10248, 10248,  1432,  1432,
    1432,  3450, 10248,    82,  1214, 10248, -1169, -1169,  1402,  8965,
   10248, -1169,  2812,  1221,  8965,   686,  1230,  1401,  8965,    13,
   -1169, -1169, -1169, -1169,  8965,  8965,  1074,  8965,  2136,  2136,
     734,   734, -1169, 10248,   148,   166,  1243, 10248, 10248, 10248,
   10248, 10248, 10248, 10248,   188, 10248, 10248, 10248, 10248, 10248,
    8965, 10248, 10248, 10248, 10248, 10248, 10248, 10248, 10248, 10248,
   10248, 10248, -1169, 10248, 10248, 10248,  1246, 10248, 10248, 10248,
   10248, 10248,  8965, 10248,  8965,  8965, 10248, 10248,  8965,  8965,
    8965,  8965,  8965,  8965,  8965,  8965,  8965,  8965,  2136,  8965,
    8965,  8965,  8965,  8965,  3723, 10248, 10248, 10248, 10248, 10248,
    8965,  8965,  8965,  3946,  8965, 10248,  8965, 10248,  8965, 10248,
   10248, 10248, 10248, 10248, 10248, 10248, 10248, 10248,  2136, 10248,
    1257,  1258, 10248,  1432, 10248,  1432, 10248,  1260,     0, 10248,
   10369,   686, 10248, -1169,   108,   693, 10248, 10248, 10248, 10248,
   10248, 10248, 10248, -1169, -1169, -1169, -1169,  8965,  8965,  8965,
    8965,  8965,  8965,  8965,  8965,  8965,  8965,  8965,  1272,  1275,
    1280, -1169,  1288,  1310,  1286, -1169,    -4,  1290,  1322,    70,
    2812,  1518,   165,  1516, 10703,  8965,  1318, 10248, -1169, -1169,
    8965,    70,   471,   514,  1338,    10, -1169,  1556,   -32, -1169,
   -1169,   761,  8965, -1169, -1169,  8965, -1169, -1169,   416, -1169,
   -1169,    40,  2812,   741, 10248,  8965,     0,   686,   189,   686,
    1346,  8965, 10248,   237, 10248,   285,  1348, 10248,   286, 10248,
     686,   308,  8965,   686,   326,   340,   686,   356,  8965,   686,
     357,   358,   361,  8965,   371,   373,   374,  8965,   376,  8965,
   10248,   386,   686,   387,   404,  8965,   686,   686,  8965,  8965,
     421,   422,   427,  8965,   459, 10248,   686,    98,  1239,     0,
   10248,  8965,   469,   477,   479, 10248,   686,   487,   502,   686,
     556,   561,   562,  8965,   570,   686,   571,   581,   597,   599,
    8965,   600, 10248,   617, 10248,   686,   644, 10248,   647,  8965,
     653,  8965,   663,  8965,   680, 10248,  8965,  2812,  8965,  2812,
   10248,     0,  1357,  1360,   132,  1259,    18,  1370,   686,  1371,
       0,  1373,   682, 10248,  8965,  8965,   683,   684,  1388,  1405,
    1413,  1415, -1169,  9595,    90,  8965,  8965,   686, -1169,  2812,
     686,   835, -1169,    70,  2812,  1419, -1169, -1169, -1169,  9716,
    1424, -1169, -1169,  1426,  1427,  1271,  1283,  1300,    76,  1437,
    1447,  1450,  1451,  1480,  1481,  1449,  1474,   699, 10248, 10248,
   10248,   686,   686,   701,   686,   686,   704,   686, 10248,   686,
     705,   715,   716,   686,  1361,   720,   728,   731,   732,   686,
     733,   743,   686,   753,   686,   686,   755,   766,   686, 10248,
     686,   767,   769,   788,   686,  1383,     0,   686,   144,  1514,
    1588,   800,   839,  9958, 10079, 10200, 10321, 10442,   550, 11726,
     666, 11737, 11755,  1520, 11778, 11789, 11800, 11811,  1616, -1169,
   11822,   158,   243,   849,   852,   857,  1820,  1926,   792, -1169,
   11833, 11844,   309, 11855,  -127, 11899,   338,   339,   370,   385,
     418,   872,   873,   419,   446,   829,  1534,   -67, -1169, -1169,
     874,   -43,   878,    57,   897, -1169,  8965,   488,  9522,   686,
     686, -1169, -1169,   686,   686,   686,   686,   686,   686, -1169,
     124,   124,  8965,  8965,  1894,    47,   481,   594,    35,    51,
   -1169,   -27,   -27,  1672,  1672, -1169, -1169,   484, -1169, -1169,
     618, -1169, -1169, -1169,  1714, -1169, -1169, -1169, -1169,  1722,
    1988,  8965,    -3, 11917, 10490, -1169, -1169,  8965,  8965, -1169,
   -1169,  8965, -1169,   837, -1169,  1557,  1559,  1563,  1565,  2812,
    1564,  1567,  1568, -1169, -1169, -1169,  1711,  1715,   926,  2304,
    8965, 10248, 10248,  1569,   928,  8965,   937,  8965, 10248,   940,
    8965,   942,  8965,  1570,  8965,  8965,  8965,  1571, 10248,  8965,
    8965,  1572, 10248, 10248,  8965,  1574,  8965,  1577,   686, 10248,
   10248, 10248,  1578,  1584,  1585, 10248,  8965,  8965,  1586, 10248,
     951, 10248,  8965,  8965,   686,  1587, 10248, 10248,  8965,   968,
   10248,  8965,  8965, 10248, 10248,  1589, 10248,  8965,  8965, 10248,
    8965,  1590,  8965,   686, 10248,   974, 10248,   976, 10248,  2316,
   10248,  1591,  8965,  1592,  8965,   977, 12017, 12028,   979,  8965,
   10248,  8965,  8965, 10248, 10248,  8965, 10248,  8965,  8965,  8965,
   10248,   985,  1593,  2329, 10248, 10248, -1169,  8965,  8965,  8965,
   -1169, -1169,    70,  2812,    70,  2812, 10703, -1169, -1169, -1169,
    8965,  8965, -1169,  8965, -1169, -1169,  8965,  8965,  8965, -1169,
   10248, 10248, -1169,  1597,  1598, -1169, -1169,  8965,  8965, 10248,
    1007,  1009,   532,  8965,  8965,  1024,  8965, 10248, 10248,  8965,
   10248, 10248, 10248, 10248,  8965, 10248,  8965, 10248, 10248,  1033,
   10248,  8965, 10248,  8965,  8965, 10248, 10248,  8965, 10248, 10248,
   -1169, -1169, -1169, -1169, -1169, -1169,  8965, -1169, -1169,  8965,
   -1169, -1169, -1169, -1169, -1169, -1169, -1169,  8965, -1169, -1169,
   -1169,  8965,  8965,  8965,  8965,  8965, -1169, 10248, -1169, -1169,
   -1169, -1169, -1169,  8965, -1169, -1169, -1169, -1169, -1169, -1169,
   10248, 10248, -1169, -1169, -1169, -1169, -1169, 10248,  1479, -1169,
   10248,  1479, -1169, 10248, 10248,  1599, -1169, -1169, -1169,  1600,
   -1169,  1601,  1074,  1646,  1604,  1608, -1169,  1609,  1614, -1169,
   -1169,   814, 10703, -1169,  8965,  2345,  1739, 10248, -1169, 10248,
     686,    70,   471,  2381,   837,   837, 12039,  1617,  1618, -1169,
    1613, -1169, -1169, -1169, -1169, 10248, -1169, -1169,  2136,  2136,
   10248, 10248,  1619,  1045,  1048, 10248, 10248,   567,  2589, 10248,
    2812,  1050, 10248,  2812, 10248,    70,  2812, 10248,    70,  2670,
      70,  2812,  2812, 10248,   686,  2812,  2812, 10248,  1051,  1061,
     608,  2812, 10248,   650,  2681, 10248,  1063,   686,  1092, 10248,
   10248, 10248,   686,  2812,  2812, 10248,  1095, 10248,  1096,   681,
    1620, 10248,  1136,  1137,  2756, 10248,  1155,   764,  2812,  2812,
     686,   686, 10248,  1161,  2768,  2812,  1165,  2812, 10248,  2845,
     686, 10248,  1167, 10248,  1169, 10248,  1171, 10248,  2812, 10248,
    2812, 10248, 12635, 12635, 10248,  1622,   686,  2865,   780,  2939,
     686,  1175,  1625,  1179,  3038,  1629,  1631,   686, 10248, 10248,
    8965,   686,  1184,  1634, 12061, 12079,  1020, -1169,  1621, -1169,
      42, 10703, 12090, 12101, 12112, 12123,   560,    60, -1169, -1169,
   12134, 12145,   686, 10248, 10248, -1169,  2812,  2812, 10248,    70,
    2812,  1185,   686,  3074,  1187,   686,   686,   686,  2812,  1236,
    3085,   686,   686, 10248,   686,  2812,   686,  3173,  1633,  1237,
    1245,    21,   686,   686, 12156, 12201, 12223, 12318, 12329,  1042,
   12340, 12363,   149, 12385,   164,   187,   579,   260,   582,   291,
     747,   798, 10248,   124,   124, -1169, -1169, -1169, -1169, -1169,
    1783,  1825,  1822, 12396,  8965,  1645,   801,   240, -1169,  8965,
   -1169, -1169, -1169, -1169, -1169, -1169,  1648,  1649,   686, -1169,
   -1169,   686,   686, 10248,  8965, 10248,  1267,   686, 10248, 10248,
    1268, 10248,  1281,  1289,  1291, 10248,  1297,  1303, 10248,  8965,
    8965,  1305, 10248,  8965,  1308,  8965,  8965,  1311,  1317,  1319,
    1325,  8965,  1328, 10248, 10248, 10248,  1336,  8965,  8965,  8965,
     686,  8965, 10248,  1345,  8965,  8965,  8965,  1350,  8965,  1358,
    8965,  1359,  8965,   686,  8965,  1369,  1372,  1381,   686, 10248,
   10248, 10248,  8965, 10248, 10248, 10248,  8965, 10248,  8965,  1389,
    1391,  2812, 10248, -1169,  1800,  1801,  1805,  8965,   864,  8965,
       9, -1169, -1169, -1169, -1169, -1169, -1169, 10248, -1169, -1169,
     686,  1393,  1394,  8965, 10248, 10248,  8965,  8965,   686, 10248,
   10248, 10248, 10248,  8965, -1169, -1169, -1169, -1169, -1169, -1169,
    8965, -1169, -1169, -1169, 10248, -1169, -1169,  8965, -1169,  8965,
   -1169, -1169, 10248, -1169, -1169, 10248, -1169, -1169,  1395, -1169,
   -1169,  8965, -1169, -1169,  1832,   822, 12407,  8965,  1823, 10248,
   12418,   837,  1655,  1658,   837, -1169, -1169,  1397,    70,  3262,
    1403, 10248,  1406,   686, 10248,  1407,  8965,  8965, 10248,   686,
    8965, 10248,   686,  3273,  2812, 10248,  1408,  3310, 10248,    70,
    3653,    70,  2812,  8965, 10248, 10248, 10248, 10701, 10248,   686,
     686,  1409, 10248, 10797,    70, 10808, 10823,   963, 10841,   686,
    8965, 10864, 10875, 10886,  8965, 10897, 10248,   973, 10908, 10248,
   10919, 10930,  8965,  8965,  8965,   686,   686,   686, 10941,  1411,
    1417,   686, 10986,   686,  1657, 10248, 10248,  1440, 10248, 10248,
   10248, 12429,  1668,  1669,   318, -1169,   408, -1169, -1169, -1169,
     825, 10248, 10248,    70,  2812,  1442,   686,  2812,  2812,  1443,
    1446,   686,   686, 11004, 12440,   855, 12451, 12462,   858,   894,
   10248, -1169, 10703,  8965,  1850, -1169,  1673, -1169, 11104,  1674,
     898, -1169, -1169, -1169, -1169, -1169, 10248,  8965, 10248,  1471,
   10248,   686, 10248, 11115, 11126,  1472, 11149,  1473,  8965,  1475,
    8965,  8965,  1476,  8965, 11167,   686,  1477,  1498,  8965,  1499,
   10248,   686,  8965,  8965,  8965,  8965,  8965, 11178,  8965,  8965,
    8965, 11189,  8965,  1500, 10248, 10248,  1501,  8965,  8965, 11200,
   11211, 11222,  8965, 10248, 10248, 10248,  8965,   686,  1502, 10248,
     686,   686,   686,  1829,  1675,  1676, -1169,   864,  8965, -1169,
   -1169,  1503,   686, 10248, 10248, 10248,  8965, -1169, -1169, -1169,
   -1169, -1169, -1169,   686, 10703,  1867,   504, 10703, -1169, 10248,
    8965,  8965, -1169,  1556,   686,  2812,  1513, 10248,   686,  1522,
   10248, 10248, 10248, 10248, 10248, 11233,  8965,  2812,  2812, 10248,
   11244, 10248,  8965, 10248, 11289, 10248,   686, 11312,  2812,  2812,
    2812, 11407, 10248, 11418, 11429, 11452, 10248,  2812, 10248,  1527,
     686, 10248,  2812,  2812,  8965, 10248,  8965, 11475,   686,  1531,
     686,  1677, 10248,   686, 10248, -1169, -1169, 10703, -1169,  2812,
   10703, 10248,   686,   686,   686, 12502,  1822, -1169, -1169,  1822,
     640,   266, 12525, 11486,   837, 10248,   686, 10248,   686,   686,
    1540,   686,   686,  8965, 11497,  1544,  8965,   686, 11508,   686,
    8965,   686,  8965,  8965,   686,  8965, 10248,  8965,  1545,   686,
   10248,   686, 11519,   686, 11530, 10248, 10248, 10248,   686,   686,
      52,  1822,   686, -1169, 10703, -1169, -1169, -1169, -1169, 10248,
   -1169,  8965, -1169,  1548,  1553, 10248,  2812,  8965, 10248,  2812,
   10248,  2812,  2812,  2812,  2812,   686, 11541, 10248,   686, 10248,
    8965,   686,   686,   686, -1169, -1169, -1169,    83,  1822,   941,
   12624, 10248, 10248,   686, 11552,   686,   686,  8965,   686,   686,
   11592, -1169, -1169,  1902,  1832, -1169, -1169,   686,  1554, 10248,
   11615, 10248, -1169, -1169, -1169,  8965,  1558, 10248,   686, 11715,
   10248,   686, 10248,   686,   686
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
   -1169, -1169,   -66, -1169, -1169,   876, -1169, -1169, -1169, -1169,
   -1169, -1169,  1872,   462, -1169, -1169,  -354,   -15, -1169,  1875,
    1530, -1169, -1169,  1487,  -429,  2795, -1169,  1307,   -33,    -5,
   -1169,   114,   120,   -10, -1169, -1169,   879, -1169, -1169, -1169,
   -1169, -1169, -1169, -1169, -1169,  1034, -1169,  1032, -1169,   206,
   -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169,
   -1169,   403, -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169,
   -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169, -1169,
   -1169, -1169, -1169, -1169, -1169, -1169,    22, -1169, -1169, -1169,
   -1168, -1169, -1169, -1169,  1327, -1169, -1169,   756,  1339, -1169,
   -1169, -1169, -1169, -1169,   186, -1169,    43, -1169, -1169
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -514
static const yytype_int16 yytable[] =
{
     241,   272,   756,   244,   119,   120,  1380,  1381,   578,   593,
     593,   579,   603,   256,   909,     1,     2,   910,   109,   469,
     274,   277,   593,  1617,   584,   111,   345,   287,   593,   740,
     275,   593,   295,   297,   249,   450,   121,   250,   251,   318,
     124,   268,   325,   121,   553,   720,   721,   124,   924,   419,
     432,  1618,  1469,   438,   365,   741,   441,   370,   372,   379,
     396,   422,   423,   381,   288,   289,   394,   395,   536,   537,
     538,   539,   540,   541,   403,  1884,   346,   542,   542,   397,
     280,   281,   545,   546,   612,   614,   547,   548,   549,   550,
     551,   552,   553,   542,  1885,  1901,   415,   121,  1122,   290,
    1123,   124,   416,   545,   546,   552,   553,   547,   548,   549,
     550,   551,   552,   553,    98,   550,   551,   552,   553,   242,
      99,   380,   553,   434,   435,  1902,   451,   542,   116,   444,
     243,   117,   404,   470,   640,   536,   537,   538,   539,   540,
     541,   536,   537,   538,   539,   540,   541,   536,   537,   538,
     539,   540,   541,   542,   439,   285,   433,   442,  1136,   440,
    1137,   286,   443,   536,   537,   538,   539,   540,   541,   851,
     291,   853,   110,   536,   537,   538,   539,   540,   541,   112,
     472,   572,  1139,   473,  1140,   452,   245,   446,   474,    84,
      85,    86,   447,   453,   556,   557,   585,   536,   537,   538,
     539,   540,   541,   255,   895,   531,   252,   896,   534,   536,
     537,   538,   539,   540,   541,   476,   542,   542,   368,   542,
     477,   861,  1166,   542,  1167,   566,   594,   594,   580,    98,
     292,   569,   567,   568,   911,    99,   599,   600,   581,   713,
     554,   555,   556,   557,   542,  1014,   258,   259,   594,   455,
     398,   682,   269,   270,   554,   555,   556,   557,   542,   269,
     270,   554,   555,   556,   557,   687,   554,   555,   556,   557,
     554,   555,   556,   557,   607,   608,   406,   609,   399,   458,
     542,   613,  1142,   615,  1143,  1476,   618,  1477,   620,   621,
     542,   623,   624,   625,   626,   627,   542,   629,   630,   631,
     632,  1049,   542,  1050,   634,   635,   636,   405,   638,   725,
     542,   641,   642,   643,   644,  1031,   646,   647,   542,   400,
     650,   651,   652,   401,   654,   971,   656,   657,   542,   402,
     662,   663,   664,   861,   666,   667,   668,   669,   670,   671,
     672,   542,   674,   675,   676,   677,   678,   679,   689,   681,
     456,   683,   542,   685,   686,   457,   688,   407,   690,  1012,
     692,    98,   694,  1652,   542,   542,  1655,    99,   542,   542,
     704,  1085,   700,   708,  1503,   758,  1504,   712,   542,  -513,
     459,   716,   717,  1109,   542,   460,   542,   724,   411,  1506,
     727,  1507,   409,   759,   410,   730,   545,   546,   417,   733,
     547,   548,   549,   550,   551,   552,   553,   542,   542,   542,
     743,   744,  1508,   748,  1509,   768,   931,   418,   757,  1718,
     264,   265,   761,   762,   763,   764,   765,   766,   767,   110,
     769,   770,   771,   772,   773,   112,   775,   776,   777,   778,
     779,   780,   781,   782,   783,   784,   785,   420,   786,   787,
     788,   421,   790,   791,   792,   793,   794,   542,   797,   798,
     542,   801,   802,   542,   935,   861,   436,  1529,  1110,   545,
     546,   749,   750,   547,   548,   549,   550,   551,   552,   553,
     821,   822,   823,   824,   825,  1511,   542,  1512,   558,   559,
     832,  1858,   834,  1859,   836,   837,   838,   839,   840,   841,
     842,   843,   844,   845,   847,   542,   542,   850,   899,   852,
     437,   854,   937,   940,   857,   859,  1514,   860,  1515,   904,
     424,   863,   864,   865,   866,   867,   868,   869,   542,   542,
     425,   813,   545,   546,  1120,   942,   547,   548,   549,   550,
     551,   552,   553,  1716,   427,  1717,   542,   548,  1807,   550,
     551,   552,   553,   944,   554,   555,   556,   557,   542,   542,
     542,   846,   902,  1125,  1126,   545,   546,   945,   272,   547,
     548,   549,   550,   551,   552,   553,   542,   542,   542,   915,
     916,   542,   445,   946,   948,   949,   921,   922,   950,   928,
     542,   542,   428,   542,   542,  1127,   542,   934,   952,   936,
     953,   954,   939,   956,   941,   542,   542,   542,   543,   544,
    1128,   545,   546,   959,   960,   547,   548,   549,   550,   551,
     552,   553,   562,   563,   542,   958,   429,   554,   555,   556,
     557,   961,   536,   537,   538,   539,   540,   541,   542,   542,
     970,   542,   542,  1129,  1132,   974,  1862,   542,   965,   966,
     979,   545,   546,   430,   967,   547,   548,   549,   550,   551,
     552,   553,   431,   551,   552,   553,   542,   993,   448,   995,
     449,  1133,   997,   536,   537,   538,   539,   540,   541,   542,
    1005,   534,  1855,   534,   454,  1008,   969,  1856,    98,   542,
     554,   555,   556,   557,    99,   461,   976,   542,  1021,   542,
     554,   555,   556,   557,   977,   468,   978,   542,   542,  1357,
    1032,  1034,  1359,  1146,   980,   536,   537,   538,   539,   540,
     541,   463,   542,   554,   555,   556,   557,   545,   546,   981,
     462,   547,   548,   549,   550,   551,   552,   553,   751,   752,
     906,   907,   464,  1060,  1061,  1062,   536,   537,   538,   539,
     540,   541,   542,  1065,   545,   546,   611,  1315,   547,   548,
     549,   550,   551,   552,   553,   917,   918,   622,   471,   554,
     555,   556,   557,   628,  1079,  1095,   542,  1096,   633,   475,
     542,   542,   542,   982,   637,  1475,   639,   542,   983,   984,
     542,   542,   645,   465,  1398,   648,   649,   986,   987,   542,
     653,   542,   542,   467,  1510,   530,   661,  1513,   988,   554,
     555,   556,   557,   554,   555,   556,   557,   542,   673,   542,
     542,   926,   927,   532,   989,   680,   990,   992,   542,   536,
     537,   538,   539,   540,   541,  1410,   691,   542,   693,  1037,
    1038,  1177,  1178,   566,   994,   536,   537,   538,   539,   540,
     541,  1369,  1370,   545,   546,   714,   715,   547,   548,   549,
     550,   551,   552,   553,   542,  1148,  1150,   542,  1612,  1613,
     542,   996,   478,   542,   998,  1154,  1155,  1412,  1157,  1158,
    1000,  1645,  1646,   542,   479,   554,   555,   556,   557,  1170,
    1002,  1098,  1171,  1099,   536,   537,   538,   539,   540,   541,
     542,   542,   542,   542,   542,   439,   542,  1004,  1424,  1020,
    1024,  1025,   554,   555,   556,   557,  1193,  1194,   862,   542,
    1197,   542,   480,  1201,   542,   542,  1059,  1205,  1063,  1208,
    1210,  1064,  1066,  1214,   481,   542,   542,  1218,  1219,  1220,
     542,  1223,  1067,  1068,  1226,  1227,  1228,  1070,   542,   482,
    1232,   542,   542,   542,  1236,  1071,  1238,  1239,  1072,  1073,
    1074,  1242,  1243,   542,   483,  1246,  1247,   542,  1250,  1251,
    1075,  1253,  1516,   542,  1256,   542,   484,   576,   485,  1260,
    1076,  1262,  1077,  1264,   542,  1266,   542,   542,   442,   542,
     856,  1432,   486,  1078,  1080,  1276,  1081,  1278,  1280,  1281,
     542,  1283,   487,   488,   446,  1287,   489,  1451,   542,  1291,
    1292,   554,   555,   556,   557,  1082,  1293,  1116,   542,  1117,
     542,   542,   456,  1517,   459,   733,  1528,  1088,   536,   537,
     538,   539,   540,   541,   490,  1306,  1307,   491,   536,   537,
     538,   539,   540,   541,  1312,   542,   473,   492,   493,   542,
    1720,  1319,  1321,  1322,  1134,  1324,  1325,  1326,  1327,   542,
    1329,   476,  1331,  1332,   494,  1334,  1089,  1336,   930,   542,
    1339,  1340,   542,  1342,  1343,   542,  1111,   542,   542,  1112,
    1728,   545,   546,  1731,  1113,   547,   548,   549,   550,   551,
     552,   553,   542,   542,   542,   495,  1372,   591,   542,  1130,
    1131,  1138,  1352,   545,   546,  1141,   496,   547,   548,   549,
     550,   551,   552,   553,   542,  1354,  1355,   542,   542,  1732,
     382,   973,  1356,  1742,  1144,  1358,   545,   546,  1360,  1361,
     547,   548,   549,   550,   551,   552,   553,   497,   498,   547,
     548,   549,   550,   551,   552,   553,   542,   499,   542,   500,
      98,   501,  1376,  1190,  1377,  1196,    99,   542,   383,   384,
     542,   542,   542,  1009,  1199,   598,  1905,  1202,  1015,  1204,
    1388,   542,  1018,  1386,  1387,  1391,  1392,   502,  1237,   385,
    1396,  1397,   503,   542,  1400,   504,   386,  1402,   542,  1403,
    1685,   505,  1404,   542,   542,  1245,   542,   542,  1406,   542,
    1694,  1261,  1407,  1263,  1271,   542,  1274,  1411,   506,   601,
    1414,   507,  1288,   508,  1417,  1418,  1419,   387,   388,   389,
    1420,   390,  1422,   509,   510,   391,  1426,   542,   511,   542,
    1430,  1389,  1390,   604,  1313,  1470,  1314,  1433,   512,   554,
     555,   556,   557,  1437,   542,  1466,  1439,  1467,  1441,   513,
    1443,  1318,  1445,   542,  1446,   514,  1447,   605,  1084,  1448,
    1333,   554,   555,   556,   557,   542,   617,  1499,   542,  1500,
     542,   542,  1394,  1459,  1460,  1395,    98,  1401,  1408,   515,
     516,   542,    99,   542,   554,   555,   556,   557,  1409,   619,
    1415,   517,   592,   554,   555,   556,   557,   518,  1480,  1481,
     545,   546,   519,  1482,   547,   548,   549,   550,   551,   552,
     553,   520,   542,   521,   522,   542,   542,   523,  1488,  1416,
     545,   546,  1421,  1423,   547,   548,   549,   550,   551,   552,
     553,   524,   545,   546,   525,   526,   547,   548,   549,   550,
     551,   552,   553,   527,   545,   546,   529,  1518,   547,   548,
     549,   550,   551,   552,   553,   575,   542,   542,  1519,  1520,
     655,   545,   546,  1427,  1428,   547,   548,   549,   550,   551,
     552,   553,   577,  1532,  1533,   542,   589,   590,  1537,  1538,
    1540,   542,  1431,  1542,  1543,   542,  1545,   542,  1434,   542,
    1549,   542,  1436,  1552,  1440,   542,  1442,  1556,  1444,   542,
    1559,  1561,  1453,   660,   542,   542,  1455,   542,  1569,  1570,
    1571,  1462,  1483,  1574,  1485,    98,  1577,  1579,   596,   597,
     665,    99,   545,   546,   684,  1587,   547,   548,   549,   550,
     551,   552,   553,   695,  1595,  1596,  1597,   718,  1599,  1600,
    1601,   726,  1603,   728,   545,   546,   732,  1607,   547,   548,
     549,   550,   551,   552,   553,   737,   542,   542,   554,   555,
     556,   557,  1620,  1486,  1491,   542,   972,   760,  1623,  1625,
    1626,   738,  1492,   789,  1629,  1630,  1631,  1632,   554,   555,
     556,   557,   848,   849,   752,   855,  1013,   542,   542,  1635,
     554,   555,   556,   557,  1541,  1544,   885,  1638,  1046,   886,
    1639,   542,   554,   555,   556,   557,   569,   887,  1546,   542,
    1047,   542,   888,   890,  1650,   891,  1547,   542,  1548,   554,
     555,   556,   557,   542,  1550,   542,  1659,  1048,   542,  1661,
    1551,   542,  1555,  1665,   889,  1558,  1667,   542,  1563,   542,
    1669,   226,   901,  1672,  1564,   542,  1565,   892,   542,  1675,
    1676,  1677,  1566,  1679,   248,  1568,   542,  1681,   257,   893,
     898,   261,   908,  1572,   912,   542,   278,   278,   278,   282,
     542,  1693,  1580,   932,  1696,   938,  1735,  1584,   542,   542,
     554,   555,   556,   557,  1010,  1586,  1589,  1011,  1069,   542,
    1707,  1708,   542,  1710,  1711,  1712,  1592,  1016,  1017,  1593,
    1019,   542,   554,   555,   556,   557,  1721,  1722,  1594,   542,
    1083,   542,  1026,   542,   542,   542,  1605,   542,  1606,   278,
    1621,  1622,  1640,   542,  1656,  1733,   542,   542,   542,   542,
    1658,   542,  1027,  1660,  1662,  1670,  1680,   542,  1703,   412,
    1028,  1744,  1029,  1746,  1704,  1748,  1040,  1749,  1043,   545,
     546,  1044,  1045,   547,   548,   549,   550,   551,   552,   553,
     542,   426,   542,   542,  1051,  1766,   542,  1709,  1806,  1723,
    1724,  1809,  1052,  1725,  1053,  1054,  1057,   545,   546,  1779,
    1780,   547,   548,   549,   550,   551,   552,   553,  1788,  1789,
    1790,   542,   542,   542,  1793,   542,   542,   542,  1747,  1752,
    1754,  1058,  1756,  1759,  1762,  1055,  1056,   545,  1802,  1803,
    1804,   547,   548,   549,   550,   551,   552,   553,   542,   542,
     542,   542,   542,   542,  1811,  1763,  1765,  1778,  1781,  1792,
    1801,  1850,  1816,   542,  1851,  1818,  1819,  1820,  1821,  1822,
    1815,  1086,   542,   553,  1825,  1102,  1827,   542,  1829,  1817,
    1831,   542,   533,   535,  1840,  1160,    98,  1834,  1846,  1135,
     542,  1838,    99,  1839,   542,   542,  1841,  1865,   542,  1163,
    1843,  1868,  1877,   542,   542,  1891,   570,  1848,   542,  1849,
    1892,  1915,  1181,   582,  1182,  1920,  1852,  1183,  1888,  1184,
    1188,  1185,  1186,  1187,  1189,  1375,  1195,  1207,  1213,  1217,
    1863,  1222,  1864,  1493,  1225,  1229,   602,   554,   555,   556,
     557,  1230,  1231,  1235,  1241,  1087,  1252,  1258,  1267,  1269,
    1289,  1875,  1308,  1309,  1522,  1878,  1362,  1363,  1364,  1365,
    1881,  1882,  1883,  1366,  1367,   554,   555,   556,   557,  1368,
    1385,  1383,  1384,  1107,  1889,  1468,  1393,  1425,    98,  1449,
    1893,    98,  1454,  1895,    99,  1896,  1457,    99,  1458,  1463,
    1490,  1523,  1898,    -4,  1899,   554,   555,   556,   557,  1527,
    1608,  1609,   658,  1535,  1536,  1610,  1907,  1908,  1643,  1649,
    1653,   545,   546,  1654,  1706,   547,   548,   549,   550,   551,
     552,   553,  1714,  1715,  1916,  1737,  1918,  1739,  1741,  1794,
    1795,  1796,  1921,  -499,  1847,  1923,  1912,  1924,   925,   697,
     699,    98,  1297,   283,    98,   705,   284,    99,   755,  1299,
      99,  1156,  1159,  1798,  1641,   923,  1914,   914,  1378,  1814,
       0,   723,     0,     0,     0,     0,     0,     0,     0,   729,
       0,     0,     0,     0,   734,     0,     0,     0,   739,     0,
       0,     0,     0,     0,   745,   746,     0,   747,   278,   278,
     548,   549,   550,   551,   552,   553,     0,     0,    98,     0,
       0,     0,     0,     0,    99,     0,     0,     0,     0,     0,
     774,     0,     0,     0,     0,     0,     0,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,     0,     0,
       0,     0,   795,     0,     0,   800,     0,     0,   803,   804,
     805,   806,   807,   808,   809,   810,   811,   812,   278,   814,
     815,   816,   817,   818,   820,     0,     0,     0,     0,     0,
     826,   827,   828,   830,   831,     0,   833,     0,   835,   554,
     555,   556,   557,     0,     0,     0,     0,  1114,   278,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   874,   875,   876,
     877,   878,   879,   880,   881,   882,   883,   884,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   900,     0,     0,     0,     0,
     903,     0,     0,   554,   555,   556,   557,     0,     0,     0,
       0,     0,   919,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   929,     0,     0,     0,   121,
     122,   123,     0,   124,   125,   554,   555,   556,   557,     0,
       0,     0,     0,  1115,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,   554,   555,   556,
     557,   133,     0,     0,   134,  1164,     0,     0,     0,   999,
       0,   135,   136,     0,   137,     0,  1006,     0,  1007,   138,
       0,     0,   139,   140,     0,     0,   141,   142,   143,     0,
       0,     0,   144,   145,     0,  1023,     0,   146,     0,   147,
       0,   148,     0,   149,     0,  1033,  1035,   150,   151,   152,
       0,     0,     0,   153,   154,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,     0,   160,   161,   162,     0,
       0,     0,   163,   164,     0,     0,     0,     0,     0,   165,
       0,     0,     0,     0,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,     0,   217,   218,     0,
     219,   220,   221,     0,     0,   222,     0,     0,     0,     0,
     223,     0,     0,     0,   276,   545,   546,     0,     0,   547,
     548,   549,   550,   551,   552,   553,     0,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,     0,     0,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,     0,  1152,  1153,     0,     0,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  1165,     0,     0,     0,     0,     0,  1172,  1173,     0,
       0,  1176,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  1198,     0,  1200,     0,     0,
    1203,     0,  1206,     0,  1209,  1211,  1212,     0,     0,  1215,
    1216,     0,     0,     0,  1221,     0,  1224,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1233,  1234,     0,     0,
       0,     0,   919,     0,     0,     0,     0,     0,  1244,     0,
       0,  1248,  1249,     0,     0,     0,     0,  1254,  1255,     0,
    1257,     0,  1259,   554,   555,   556,   557,     0,     0,     0,
       0,  1191,  1268,     0,  1270,   554,   555,   556,   557,     0,
       0,  1277,  1279,  1265,     0,     0,     0,  1284,   554,   555,
     556,   557,     0,     0,     0,     0,  1290,  1294,  1295,  1296,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
     734,  1300,  1374,  1302,     0,     0,  1303,  1304,  1305,     0,
     116,   123,     0,   117,   125,     0,     0,  1310,  1311,     0,
       0,     0,     0,  1316,  1317,     0,  1320,     0,     0,  1323,
     554,   555,   556,   557,  1328,   127,  1330,     0,  1379,     0,
       0,  1335,     0,  1337,     0,     0,     0,  1341,     0,     0,
       0,     0,     0,     0,     0,     0,  1344,     0,     0,  1345,
       0,     0,     0,     0,     0,     0,     0,  1346,     0,     0,
       0,  1347,  1348,  1349,  1350,  1351,     0,     0,     0,     0,
     545,   546,     0,  1353,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   140,     0,     0,   141,   233,   234,     0,
       0,     0,   144,     0,     0,     0,     0,   235,     0,     0,
       0,     0,     0,     0,  1373,     0,     0,     0,   236,   237,
       0,     0,     0,   153,   154,     0,     0,     0,     0,     0,
       0,     0,     0,   158,     0,     0,     0,     0,   278,   278,
       0,     0,     0,   238,     0,     0,     0,     0,     0,   165,
       0,   545,   546,     0,   239,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,     0,   186,   187,   188,     0,     0,   191,
     192,   193,     0,   195,     0,   197,   198,   199,   200,   201,
     202,     0,     0,   205,     0,     0,   208,     0,   209,   210,
       0,   212,     0,   214,     0,   216,     0,     0,   218,     0,
     219,     0,   221,     0,     0,     0,     0,     0,     0,     0,
     240,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     556,   557,     0,     0,     0,     0,  1399,   545,   546,     0,
    1461,   547,   548,   549,   550,   551,   552,   553,     0,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
       0,   294,     0,     0,   300,   302,   305,   311,   316,     0,
     322,   324,     0,   330,   333,   334,   338,   340,   343,   344,
       0,   348,   356,   363,     0,   367,     0,     0,     0,   374,
     376,   378,     0,   545,   546,   393,     0,   547,   548,   549,
     550,   551,   552,   553,     0,     0,     0,     0,     0,   554,
     555,   556,   557,     0,     0,     0,     0,  1405,     0,     0,
     554,   555,   556,   557,  1526,     0,   545,   546,  1413,  1530,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,  1539,     0,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,     0,     0,  1553,
    1554,     0,     0,  1557,     0,  1560,  1562,     0,     0,     0,
       0,  1567,     0,   466,     0,     0,     0,  1573,  1575,  1576,
       0,  1578,     0,     0,  1581,  1582,  1583,     0,  1585,     0,
    1588,     0,  1590,     0,  1591,   554,   555,   556,   557,     0,
       0,     0,  1598,  1429,     0,     0,  1602,   554,   555,   556,
     557,     0,     0,     0,     0,  1435,     0,  1611,     0,  1616,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,     0,   528,  1624,     0,     0,  1627,  1628,     0,     0,
       0,     0,     0,  1633,     0,     0,     0,     0,     0,     0,
    1634,   554,   555,   556,   557,     0,     0,  1636,     0,  1637,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   570,     0,     0,     0,     0,     0,  1648,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,  1438,     0,     0,     0,  1663,  1664,     0,     0,
    1666,     0,     0,   606,   554,   555,   556,   557,   610,     0,
       0,     0,  1450,  1674,   616,     0,     0,     0,     0,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
    1687,     0,     0,     0,  1691,     0,     0,     0,     0,     0,
       0,     0,  1699,  1700,  1701,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   545,   546,   659,     0,   547,
     548,   549,   550,   551,   552,   553,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,     0,   554,   555,
     556,   557,     0,     0,     0,     0,  1452,     0,     0,     0,
       0,     0,     0,  1736,     0,     0,     0,   701,   702,   703,
       0,   706,   707,     0,   709,   710,   711,  1745,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1755,     0,
    1757,  1758,     0,  1760,     0,     0,     0,     0,  1764,     0,
       0,     0,  1767,  1768,  1769,  1770,  1771,     0,  1773,  1774,
    1775,     0,  1777,     0,     0,     0,     0,  1782,  1783,     0,
       0,     0,  1787,     0,   545,   546,     0,     0,   547,   548,
     549,   550,   551,   552,   553,     0,     0,     0,  1799,     0,
       0,     0,     0,     0,     0,     0,  1805,   554,   555,   556,
     557,     0,     0,     0,     0,  1456,     0,   796,     0,   799,
    1812,  1813,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  1824,     0,     0,     0,
       0,     0,  1828,   554,   555,   556,   557,     0,     0,     0,
       0,  1484,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,  1487,     0,  1842,     0,  1844,     0,     0,     0,
       0,     0,     0,   545,   546,     0,     0,   547,   548,   549,
     550,   551,   552,   553,   545,   546,     0,     0,   547,   548,
     549,   550,   551,   552,   553,     0,     0,     0,     0,     0,
       0,     0,     0,  1866,     0,     0,  1869,     0,     0,     0,
    1871,     0,  1872,  1873,     0,  1874,     0,  1876,     0,     0,
       0,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     920,  1890,   554,   555,   556,   557,     0,  1894,     0,     0,
    1489,     0,     0,     0,     0,     0,   933,     0,     0,     0,
    1900,     0,     0,     0,     0,     0,     0,   943,     0,     0,
       0,     0,     0,   947,     0,     0,     0,  1910,   951,     0,
       0,     0,   955,     0,   957,     0,     0,     0,     0,     0,
     962,     0,     0,   963,   964,  1919,     0,     0,   968,     0,
       0,     0,     0,   121,   122,   123,   975,   124,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   985,     0,
       0,     0,     0,     0,     0,   991,     0,     0,   126,   127,
       0,   554,   555,   556,   557,     0,  1001,     0,  1003,  1657,
       0,     0,   554,   555,   556,   557,     0,     0,     0,     0,
    1668,     0,     0,     0,     0,     0,     0,     0,     0,  1022,
       0,   129,   130,   131,   132,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,     0,     0,   134,   554,
     555,   556,   557,     0,     0,   135,   136,  1671,   137,     0,
       0,     0,     0,   138,     0,     0,   139,   140,     0,     0,
     141,   142,   143,     0,     0,     0,   144,   145,     0,     0,
       0,   146,     0,   147,     0,   148,     0,   149,     0,     0,
       0,   150,   151,   152,     0,     0,     0,   153,   154,     0,
       0,     0,   155,     0,     0,   156,   157,   158,   159,     0,
     160,   161,   162,     0,     0,     0,   163,   164,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,  1145,   209,   210,   211,   212,   213,   214,   215,   216,
       0,   217,   218,     0,   219,   220,   221,     0,     0,   222,
       0,     0,     0,     0,   223,   722,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   545,   546,     0,     0,   547,   548,
     549,   550,   551,   552,   553,  1192,   121,   122,   123,     0,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  1240,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,  1275,     0,     0,     0,   135,   136,
    1282,   137,     0,  1285,  1286,     0,   138,     0,     0,   139,
     140,     0,     0,   141,   142,   143,     0,     0,     0,   144,
     145,     0,     0,     0,   146,     0,   147,     0,   148,     0,
     149,     0,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,     0,     0,     0,   155,     0,     0,   156,   157,
     158,   159,     0,   160,   161,   162,     0,     0,     0,   163,
     164,     0,   554,   555,   556,   557,   165,     0,     0,  1338,
    1673,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,     0,     0,     0,   223,   819,   121,
     122,   123,     0,   124,   125,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   126,   127,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,     0,     0,   134,     0,     0,     0,     0,     0,
       0,   135,   136,     0,   137,     0,     0,     0,     0,   138,
       0,     0,   139,   140,     0,     0,   141,   142,   143,     0,
       0,     0,   144,   145,     0,     0,     0,   146,     0,   147,
       0,   148,     0,   149,     0,     0,     0,   150,   151,   152,
       0,     0,     0,   153,   154,     0,     0,     0,   155,     0,
       0,   156,   157,   158,   159,     0,   160,   161,   162,     0,
       0,     0,   163,   164,     0,     0,     0,     0,     0,   165,
       0,     0,     0,     0,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,     0,   209,   210,
     211,   212,   213,   214,   215,   216,     0,   217,   218,     0,
     219,   220,   221,     0,     0,   222,     0,     0,     0,     0,
     223,   829,   121,   122,   123,     0,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   134,     0,     0,
       0,     0,     0,  1604,   135,   136,     0,   137,     0,     0,
     349,     0,   138,     0,     0,   139,   140,     0,     0,   141,
     142,   143,   350,   351,     0,   144,   145,     0,     0,     0,
     146,     0,   147,     0,   148,     0,   149,     0,     0,     0,
     150,   151,   152,     0,   352,     0,   153,   154,     0,     0,
     353,   155,   354,   355,   156,   157,   158,   159,     0,   160,
     161,   162,     0,     0,     0,   163,   164,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     217,   218,     0,   219,   220,   221,     0,     0,   222,     0,
     121,   122,   123,   223,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   357,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   135,   136,     0,   137,     0,     0,   358,     0,
     138,     0,     0,   139,   140,     0,     0,   141,   142,   143,
     359,   360,     0,   144,   145,     0,     0,     0,   146,     0,
     147,  1791,   148,     0,   149,     0,     0,     0,   150,   151,
     152,   361,     0,     0,   153,   154,     0,     0,   362,   155,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
       0,     0,     0,   163,   164,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
       0,   219,   220,   221,     0,     0,   222,     0,   121,   122,
     123,   223,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,     0,
     135,   136,     0,   137,     0,     0,   306,     0,   138,     0,
       0,   139,   140,     0,     0,   141,   142,   143,   307,   308,
       0,   144,   145,     0,     0,     0,   146,     0,   147,     0,
     148,     0,   149,     0,     0,     0,   150,   151,   152,     0,
     309,     0,   153,   154,     0,     0,   310,   155,     0,     0,
     156,   157,   158,   159,     0,   160,   161,   162,     0,     0,
       0,   163,   164,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,     0,   217,   218,     0,   219,
     220,   221,     0,     0,   222,     0,   121,   122,   123,   223,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,     0,     0,     0,     0,   135,   136,
       0,   137,     0,     0,   312,     0,   138,     0,     0,   139,
     140,     0,     0,   141,   142,   143,   313,   314,     0,   144,
     145,     0,     0,     0,   146,     0,   147,     0,   148,     0,
     149,     0,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,     0,     0,   315,   155,     0,     0,   156,   157,
     158,   159,     0,   160,   161,   162,     0,     0,     0,   163,
     164,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,   121,   122,   123,   223,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   326,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   135,   136,     0,   137,
       0,     0,   327,     0,   138,     0,     0,   139,   140,     0,
       0,   141,   142,   143,   328,     0,     0,   144,   145,     0,
       0,   329,   146,     0,   147,     0,   148,     0,   149,     0,
       0,     0,   150,   151,   152,     0,     0,     0,   153,   154,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
       0,   160,   161,   162,     0,     0,     0,   163,   164,     0,
       0,     0,     0,     0,   165,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,     0,   219,   220,   221,     0,     0,
     222,     0,   121,   122,   123,   223,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   319,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   320,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   134,     0,     0,
       0,     0,     0,     0,   135,   136,     0,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,     0,     0,   141,
     142,   143,     0,     0,     0,   144,   145,     0,     0,   321,
     146,     0,   147,     0,   148,     0,   149,     0,     0,     0,
     150,   151,   152,     0,     0,     0,   153,   154,     0,     0,
       0,   155,     0,     0,   156,   157,   158,   159,     0,   160,
     161,   162,     0,     0,     0,   163,   164,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     217,   218,     0,   219,   220,   221,     0,     0,   222,     0,
     121,   122,   123,   223,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   135,   136,     0,   137,     0,     0,     0,     0,
     138,     0,     0,   139,   140,     0,     0,   141,   142,   143,
     335,   336,     0,   144,   145,     0,     0,   337,   146,     0,
     147,     0,   148,     0,   149,     0,     0,     0,   150,   151,
     152,     0,     0,     0,   153,   154,     0,     0,     0,   155,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
       0,     0,     0,   163,   164,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
       0,   219,   220,   221,     0,     0,   222,     0,   121,   122,
     123,   223,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,     0,
     135,   136,     0,   137,     0,     0,     0,     0,   138,     0,
       0,   139,   140,     0,     0,   141,   142,   143,     0,     0,
       0,   144,   145,     0,     0,   298,   146,     0,   147,     0,
     148,     0,   149,     0,     0,     0,   150,   151,   152,     0,
       0,     0,   153,   154,     0,     0,     0,   155,     0,     0,
     156,   157,   158,   159,     0,   160,   161,   162,     0,     0,
       0,   163,   164,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   299,   217,   218,     0,   219,
     220,   221,     0,     0,   222,     0,   121,   122,   123,   223,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,     0,     0,     0,     0,   135,   136,
       0,   137,     0,     0,   303,     0,   138,     0,     0,   139,
     140,     0,     0,   141,   142,   143,     0,     0,     0,   144,
     145,     0,     0,   304,   146,     0,   147,     0,   148,     0,
     149,     0,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,     0,     0,     0,   155,     0,     0,   156,   157,
     158,   159,     0,   160,   161,   162,     0,     0,     0,   163,
     164,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,   121,   122,   123,   223,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   135,   136,     0,   137,
       0,     0,     0,     0,   138,     0,     0,   139,   140,     0,
       0,   141,   142,   143,     0,   331,     0,   144,   145,     0,
       0,     0,   146,     0,   147,     0,   148,     0,   149,     0,
       0,   332,   150,   151,   152,     0,     0,     0,   153,   154,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
       0,   160,   161,   162,     0,     0,     0,   163,   164,     0,
       0,     0,     0,     0,   165,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,     0,   219,   220,   221,     0,     0,
     222,     0,   121,   122,   123,   223,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   134,     0,     0,
       0,     0,     0,     0,   135,   136,     0,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,     0,     0,   141,
     142,   143,     0,   341,     0,   144,   145,     0,     0,     0,
     146,     0,   147,     0,   148,     0,   149,     0,     0,     0,
     150,   151,   152,     0,     0,     0,   153,   154,     0,     0,
       0,   155,     0,     0,   156,   157,   158,   159,     0,   160,
     161,   162,     0,     0,     0,   163,   164,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     217,   218,     0,   219,   220,   221,     0,   342,   222,     0,
     121,   122,   123,   223,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   135,   136,     0,   137,     0,     0,     0,     0,
     138,     0,     0,   139,   140,     0,     0,   141,   142,   143,
       0,     0,     0,   144,   145,     0,     0,     0,   146,     0,
     147,     0,   148,     0,   149,     0,     0,     0,   150,   151,
     152,     0,     0,     0,   153,   154,     0,     0,     0,   155,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
       0,     0,     0,   163,   164,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
       0,   219,   220,   221,     0,     0,   222,     0,   121,   122,
     123,   223,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,     0,
     135,   136,     0,   137,     0,     0,     0,     0,   138,     0,
       0,   139,   140,     0,     0,   141,   142,   143,     0,     0,
       0,   144,   145,     0,     0,     0,   146,     0,   147,     0,
     148,     0,   149,     0,     0,     0,   150,   151,   152,     0,
       0,     0,   153,   154,     0,     0,     0,   155,     0,     0,
     156,   157,   158,   159,     0,   160,   161,   162,     0,     0,
       0,   163,   164,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,   293,   217,   218,     0,   219,
     220,   221,     0,     0,   222,     0,   121,   122,   123,   223,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,     0,     0,     0,     0,   135,   136,
       0,   137,     0,     0,     0,     0,   138,     0,     0,   139,
     140,     0,     0,   141,   142,   143,     0,     0,     0,   144,
     145,     0,     0,   301,   146,     0,   147,     0,   148,     0,
     149,     0,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,     0,     0,     0,   155,     0,     0,   156,   157,
     158,   159,     0,   160,   161,   162,     0,     0,     0,   163,
     164,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,   121,   122,   123,   223,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   135,   136,     0,   137,
       0,     0,     0,     0,   138,     0,     0,   139,   140,     0,
       0,   141,   142,   143,     0,     0,     0,   144,   145,     0,
       0,   323,   146,     0,   147,     0,   148,     0,   149,     0,
       0,     0,   150,   151,   152,     0,     0,     0,   153,   154,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
       0,   160,   161,   162,     0,     0,     0,   163,   164,     0,
       0,     0,     0,     0,   165,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,     0,   219,   220,   221,     0,     0,
     222,     0,   121,   122,   123,   223,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   339,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   134,     0,     0,
       0,     0,     0,     0,   135,   136,     0,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,     0,     0,   141,
     142,   143,     0,     0,     0,   144,   145,     0,     0,     0,
     146,     0,   147,     0,   148,     0,   149,     0,     0,     0,
     150,   151,   152,     0,     0,     0,   153,   154,     0,     0,
       0,   155,     0,     0,   156,   157,   158,   159,     0,   160,
     161,   162,     0,     0,     0,   163,   164,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     217,   218,     0,   219,   220,   221,     0,     0,   222,     0,
     121,   122,   123,   223,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   135,   136,     0,   137,     0,     0,     0,     0,
     138,     0,     0,   139,   140,     0,     0,   141,   142,   143,
       0,     0,     0,   144,   145,     0,     0,   347,   146,     0,
     147,     0,   148,     0,   149,     0,     0,     0,   150,   151,
     152,     0,     0,     0,   153,   154,     0,     0,     0,   155,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
       0,     0,     0,   163,   164,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
       0,   219,   220,   221,     0,     0,   222,     0,   121,   122,
     123,   223,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,     0,
     135,   136,     0,   137,     0,     0,     0,     0,   138,     0,
       0,   139,   140,     0,     0,   141,   142,   143,     0,     0,
       0,   144,   145,     0,     0,   366,   146,     0,   147,     0,
     148,     0,   149,     0,     0,     0,   150,   151,   152,     0,
       0,     0,   153,   154,     0,     0,     0,   155,     0,     0,
     156,   157,   158,   159,     0,   160,   161,   162,     0,     0,
       0,   163,   164,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,     0,   217,   218,     0,   219,
     220,   221,     0,     0,   222,     0,   121,   122,   123,   223,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,     0,     0,     0,     0,   135,   136,
       0,   137,     0,     0,     0,     0,   138,     0,     0,   139,
     140,     0,     0,   141,   142,   143,     0,     0,     0,   144,
     145,     0,     0,   373,   146,     0,   147,     0,   148,     0,
     149,     0,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,     0,     0,     0,   155,     0,     0,   156,   157,
     158,   159,     0,   160,   161,   162,     0,     0,     0,   163,
     164,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,   121,   122,   123,   223,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   135,   136,     0,   137,
       0,     0,     0,     0,   138,     0,     0,   139,   140,     0,
       0,   141,   142,   143,     0,     0,     0,   144,   145,     0,
       0,   375,   146,     0,   147,     0,   148,     0,   149,     0,
       0,     0,   150,   151,   152,     0,     0,     0,   153,   154,
       0,     0,     0,   155,     0,     0,   156,   157,   158,   159,
       0,   160,   161,   162,     0,     0,     0,   163,   164,     0,
       0,     0,     0,     0,   165,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,     0,   219,   220,   221,     0,     0,
     222,     0,   121,   122,   123,   223,   124,   125,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   126,   127,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,     0,     0,   134,     0,     0,
       0,     0,     0,     0,   135,   136,     0,   137,     0,     0,
       0,     0,   138,     0,     0,   139,   140,     0,     0,   141,
     142,   143,     0,     0,     0,   144,   145,     0,     0,   377,
     146,     0,   147,     0,   148,     0,   149,     0,     0,     0,
     150,   151,   152,     0,     0,     0,   153,   154,     0,     0,
       0,   155,     0,     0,   156,   157,   158,   159,     0,   160,
     161,   162,     0,     0,     0,   163,   164,     0,     0,     0,
       0,     0,   165,     0,     0,     0,     0,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
       0,   209,   210,   211,   212,   213,   214,   215,   216,     0,
     217,   218,     0,   219,   220,   221,     0,     0,   222,     0,
     121,   122,   123,   223,   124,   125,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   127,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,   134,     0,     0,     0,     0,
       0,     0,   135,   136,     0,   137,     0,     0,     0,     0,
     138,     0,     0,   139,   140,     0,     0,   141,   142,   143,
       0,     0,     0,   144,   145,     0,     0,   392,   146,     0,
     147,     0,   148,     0,   149,     0,     0,     0,   150,   151,
     152,     0,     0,     0,   153,   154,     0,     0,     0,   155,
       0,     0,   156,   157,   158,   159,     0,   160,   161,   162,
       0,     0,     0,   163,   164,     0,     0,     0,     0,     0,
     165,     0,     0,     0,     0,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,     0,   209,
     210,   211,   212,   213,   214,   215,   216,     0,   217,   218,
       0,   219,   220,   221,     0,     0,   222,     0,   121,   122,
     123,   223,   124,   125,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   126,   127,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,     0,     0,   134,     0,     0,     0,     0,     0,     0,
     135,   136,     0,   137,     0,     0,     0,     0,   138,     0,
       0,   139,   140,     0,     0,   141,   142,   143,     0,     0,
       0,   144,   145,     0,     0,     0,   146,     0,   147,     0,
     148,     0,   149,     0,     0,     0,   150,   151,   152,     0,
       0,     0,   153,   154,     0,     0,     0,   155,     0,     0,
     156,   157,   158,   159,     0,   160,   161,   162,     0,     0,
       0,   163,   164,     0,     0,     0,     0,     0,   165,     0,
       0,     0,     0,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,     0,   209,   210,   211,
     212,   213,   214,   215,   216,     0,   217,   218,     0,   219,
     220,   221,     0,     0,   222,     0,   121,   122,   123,   223,
     124,   125,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   126,   127,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,     0,
       0,   134,     0,     0,     0,     0,     0,     0,   135,   136,
       0,   137,     0,     0,     0,     0,   138,     0,     0,   139,
     140,     0,     0,   141,   142,   143,     0,     0,     0,   144,
     145,     0,     0,     0,   146,     0,   147,     0,   148,     0,
     149,     0,     0,     0,   150,   151,   152,     0,     0,     0,
     153,   154,     0,     0,     0,   155,     0,     0,   156,   157,
     158,   159,     0,   160,   161,   162,     0,     0,     0,   163,
     164,     0,     0,     0,     0,     0,   165,     0,     0,     0,
       0,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,     0,   209,   210,   211,   212,   213,
     214,   215,   216,     0,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,   121,   122,   123,   696,   124,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   126,
     127,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   133,     0,     0,   134,
       0,     0,     0,     0,     0,     0,   135,   136,     0,   137,
       0,     0,     0,     0,   138,     0,     0,   139,   140,     0,
       0,   141,   142,   143,     0,     0,     0,   144,   145,     0,
       0,     0,   146,     0,   147,     0,   148,     0,   149,     0,
       0,     0,   150,   151,   152,     0,     0,   123,   153,   154,
     125,     0,     0,   155,     0,     0,   156,   157,   158,   159,
       0,   160,   161,   162,     0,     0,     0,   163,   164,     0,
       0,   127,     0,     0,   165,     0,     0,     0,     0,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,     0,   209,   210,   211,   212,   213,   214,   215,
     216,     0,   217,   218,     0,   219,   220,   221,     0,   140,
     222,     0,   141,   233,   234,   698,     0,     0,   144,     0,
       0,     0,     0,   235,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   236,   237,     0,     0,   123,   153,
     154,   125,     0,     0,     0,     0,   545,   546,     0,   158,
     547,   548,   549,   550,   551,   552,   553,     0,     0,   238,
       0,     0,   127,     0,     0,   165,     0,     0,     0,     0,
     239,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     186,   187,   188,     0,     0,   191,   192,   193,     0,   195,
       0,   197,   198,   199,   200,   201,   202,     0,     0,   205,
       0,     0,   208,     0,   209,   210,     0,   212,     0,   214,
       0,   216,     0,     0,   218,     0,   219,     0,   221,     0,
     140,     0,     0,   141,   233,   234,   240,  1147,     0,   144,
       0,     0,     0,   296,   235,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   236,   237,     0,     0,   123,
     153,   154,   125,     0,     0,     0,     0,   545,   546,     0,
     158,   547,   548,   549,   550,   551,   552,   553,     0,     0,
     238,     0,     0,   127,     0,     0,   165,     0,     0,     0,
       0,   239,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
    1030,   186,   187,   188,     0,     0,   191,   192,   193,     0,
     195,     0,   197,   198,   199,   200,   201,   202,     0,     0,
     205,     0,     0,   208,     0,   209,   210,     0,   212,     0,
     214,     0,   216,     0,     0,   218,     0,   219,     0,   221,
       0,   140,     0,     0,   141,   233,   234,   240,     0,     0,
     144,     0,     0,     0,     0,   235,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   236,   237,     0,     0,
     123,   153,   154,   125,     0,     0,     0,     0,     0,     0,
       0,   158,     0,     0,     0,     0,     0,     0,   317,     0,
       0,   238,     0,     0,   127,     0,     0,   165,     0,     0,
       0,     0,   239,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   554,   555,   556,   557,     0,
       0,  1042,   186,   187,   188,   364,     0,   191,   192,   193,
       0,   195,     0,   197,   198,   199,   200,   201,   202,     0,
       0,   205,     0,     0,   208,     0,   209,   210,     0,   212,
       0,   214,     0,   216,     0,     0,   218,     0,   219,     0,
     221,     0,   140,     0,     0,   141,   233,   234,   240,     0,
       0,   144,     0,     0,     0,     0,   235,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   236,   237,     0,
       0,   123,   153,   154,   125,     0,     0,     0,     0,   545,
     546,     0,   158,   547,   548,   549,   550,   551,   552,   553,
       0,     0,   238,     0,     0,   127,     0,     0,   165,     0,
       0,     0,     0,   239,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   186,   187,   188,     0,     0,   191,   192,
     193,     0,   195,     0,   197,   198,   199,   200,   201,   202,
       0,     0,   205,     0,     0,   208,     0,   209,   210,     0,
     212,     0,   214,     0,   216,     0,     0,   218,     0,   219,
       0,   221,     0,   140,     0,     0,   141,   233,   234,   240,
       0,     0,   144,     0,     0,     0,   369,   235,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   236,   237,
       0,     0,   123,   153,   154,   125,     0,     0,     0,     0,
     545,   546,     0,   158,   547,   548,   549,   550,   551,   552,
     553,     0,     0,   238,     0,     0,   127,     0,     0,   165,
       0,     0,     0,     0,   239,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   554,   555,   556,
     557,     0,     0,  1090,   186,   187,   188,     0,     0,   191,
     192,   193,     0,   195,     0,   197,   198,   199,   200,   201,
     202,     0,     0,   205,     0,     0,   208,     0,   209,   210,
       0,   212,     0,   214,     0,   216,     0,     0,   218,     0,
     219,     0,   221,     0,   140,     0,     0,   141,   233,   234,
     240,     0,     0,   144,     0,     0,     0,   371,   235,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,     0,   123,   153,   154,   125,     0,     0,     0,
       0,   545,   546,     0,   158,   547,   548,   549,   550,   551,
     552,   553,     0,     0,   238,     0,     0,   127,     0,     0,
     165,     0,     0,     0,     0,   239,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     556,   557,     0,     0,  1091,   186,   187,   188,     0,     0,
     191,   192,   193,     0,   195,     0,   197,   198,   199,   200,
     201,   202,     0,     0,   205,     0,     0,   208,     0,   209,
     210,     0,   212,     0,   214,     0,   216,     0,     0,   218,
       0,   219,     0,   221,     0,   140,     0,     0,   141,   233,
     234,   240,     0,     0,   144,     0,     0,     0,     0,   235,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     236,   237,     0,     0,   123,   153,   154,   125,     0,     0,
       0,     0,   545,   546,     0,   158,   547,   548,   549,   550,
     551,   552,   553,     0,     0,   238,     0,     0,   127,     0,
       0,   165,     0,     0,     0,     0,   239,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   554,
     555,   556,   557,     0,     0,  1092,   186,   187,   188,     0,
       0,   191,   192,   193,     0,   195,     0,   197,   198,   199,
     200,   201,   202,     0,     0,   205,     0,     0,   208,     0,
     209,   210,     0,   212,     0,   214,     0,   216,     0,     0,
     218,     0,   219,     0,   221,     0,   140,     0,     0,   141,
     233,   234,   240,     0,     0,   144,     0,     0,     0,     0,
     235,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   236,   237,     0,     0,   123,   153,   154,   125,     0,
       0,     0,     0,   545,   546,     0,   158,   547,   548,   549,
     550,   551,   552,   553,     0,     0,   238,     0,     0,   127,
       0,     0,   165,     0,     0,     0,     0,   239,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,  1093,   186,   187,   188,
       0,     0,   191,   192,   193,     0,   195,     0,   197,   198,
     199,   200,   201,   202,     0,     0,   205,     0,     0,   208,
       0,   209,   210,     0,   212,     0,   214,     0,   216,     0,
       0,   218,     0,   219,     0,   221,     0,   140,     0,     0,
     141,   233,   234,   858,     0,     0,   144,     0,     0,     0,
       0,   235,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   236,   237,     0,     0,     0,   153,   154,     0,
       0,     0,     0,     0,     0,     0,     0,   158,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,     0,     0,
       0,     0,     0,   165,     0,     0,     0,     0,   239,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,     0,     0,  1094,   186,   187,
     188,     0,     0,   191,   192,   193,     0,   195,     0,   197,
     198,   199,   200,   201,   202,     0,     0,   205,     0,     0,
     208,     0,   209,   210,     0,   212,     0,   214,     0,   216,
       0,     0,   218,     0,   219,     0,   221,     1,     2,     3,
       0,     0,     4,     0,  1169,     0,     5,     0,     6,     0,
       7,     8,     9,    10,    11,  -453,     0,    12,    13,    14,
      15,    16,    17,    18,    19,     0,    20,    21,    22,     0,
       0,     0,     0,    23,     0,     0,    24,     0,     0,     0,
       0,     0,    25,    26,    27,    28,    29,    30,    31,     0,
       0,    32,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,     0,     0,    33,    34,    35,    36,    37,
      38,     0,     0,     0,     0,    39,    40,    41,     0,     0,
      42,    43,     0,     0,    44,     0,    45,     0,    46,    47,
      48,    49,    50,    51,    52,    53,     0,     0,    54,     0,
      55,    56,    57,     0,    58,     0,    59,    60,    61,    62,
      63,    64,    65,     0,    66,    67,    68,     0,     0,    69,
      70,    71,     0,    72,     0,    73,     0,     0,    74,    75,
       0,    76,     0,     0,     0,    77,     0,     0,    78,     0,
      79,    80,     0,     0,     0,     0,     0,    81,   545,   546,
      82,    83,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
       0,    84,    85,    86,   545,   546,     0,    87,   547,   548,
     549,   550,   551,   552,   553,     0,     0,     0,     0,     0,
       0,    88,   545,   546,    89,     0,   547,   548,   549,   550,
     551,   552,   553,     0,     0,     0,     0,    90,     0,     0,
     554,   555,   556,   557,     0,   545,   546,     0,  1678,   547,
     548,   549,   550,   551,   552,   553,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,   545,   546,
       0,     0,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,     0,     0,     0,   554,   555,   556,   557,
       0,     0,     0,     0,  1682,     0,     0,   554,   555,   556,
     557,     0,     0,     0,     0,  1683,     0,     0,     0,     0,
       0,     0,   554,   555,   556,   557,     0,   545,   546,     0,
    1684,   547,   548,   549,   550,   551,   552,   553,     0,     0,
     554,   555,   556,   557,     0,   545,   546,     0,  1686,   547,
     548,   549,   550,   551,   552,   553,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,     0,     0,     0,
       0,  1688,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,  1689,     0,     0,   554,   555,   556,   557,     0,
       0,     0,     0,  1690,     0,     0,   554,   555,   556,   557,
       0,     0,     0,     0,  1692,     0,     0,   554,   555,   556,
     557,     0,     0,     0,     0,  1695,     0,     0,   554,   555,
     556,   557,     0,     0,     0,     0,  1697,     0,     0,   554,
     555,   556,   557,     0,     0,     0,     0,  1698,     0,     0,
     554,   555,   556,   557,     0,   545,   546,     0,  1702,   547,
     548,   549,   550,   551,   552,   553,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,     0,     0,
       0,     0,     0,     0,     0,   554,   555,   556,   557,     0,
     545,   546,     0,  1705,   547,   548,   549,   550,   551,   552,
     553,     0,     0,   554,   555,   556,   557,     0,   545,   546,
       0,  1726,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,   545,   546,     0,     0,   547,   548,   549,
     550,   551,   552,   553,   545,   546,     0,     0,   547,   548,
     549,   550,   551,   552,   553,   545,   546,     0,     0,   547,
     548,   549,   550,   551,   552,   553,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,     0,     0,     0,
       0,  1740,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,  1750,     0,     0,   554,   555,   556,   557,     0,
     545,   546,     0,  1751,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     556,   557,     0,   545,   546,     0,  1753,   547,   548,   549,
     550,   551,   552,   553,     0,     0,   554,   555,   556,   557,
       0,     0,     0,     0,  1761,     0,     0,   554,   555,   556,
     557,     0,     0,     0,     0,  1772,     0,     0,   554,   555,
     556,   557,     0,     0,     0,     0,  1776,     0,     0,   554,
     555,   556,   557,     0,     0,     0,     0,  1784,     0,     0,
     554,   555,   556,   557,     0,     0,     0,     0,  1785,     0,
       0,   554,   555,   556,   557,     0,     0,     0,     0,  1786,
       0,     0,   554,   555,   556,   557,     0,     0,     0,     0,
    1823,     0,     0,   554,   555,   556,   557,     0,   545,   546,
       0,  1826,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     556,   557,     0,   545,   546,     0,  1830,   547,   548,   549,
     550,   551,   552,   553,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,     0,   545,   546,     0,  1832,
     547,   548,   549,   550,   551,   552,   553,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,   545,   546,
       0,     0,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,   545,   546,     0,     0,   547,   548,   549,
     550,   551,   552,   553,     0,     0,   554,   555,   556,   557,
       0,     0,     0,     0,  1833,     0,     0,   554,   555,   556,
     557,     0,     0,     0,     0,  1835,     0,     0,   554,   555,
     556,   557,     0,   545,   546,     0,  1836,   547,   548,   549,
     550,   551,   552,   553,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,     0,   545,   546,     0,  1837,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,  1845,     0,     0,   554,   555,   556,   557,     0,
       0,     0,     0,  1861,     0,     0,   554,   555,   556,   557,
       0,     0,     0,     0,  1867,     0,     0,   554,   555,   556,
     557,     0,     0,     0,     0,  1870,     0,     0,   554,   555,
     556,   557,     0,     0,     0,     0,  1879,     0,     0,   554,
     555,   556,   557,     0,     0,     0,     0,  1880,     0,     0,
     554,   555,   556,   557,     0,     0,     0,     0,  1897,     0,
       0,   554,   555,   556,   557,     0,   545,   546,     0,  1909,
     547,   548,   549,   550,   551,   552,   553,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,   545,   546,
       0,     0,   547,   548,   549,   550,   551,   552,   553,     0,
       0,   554,   555,   556,   557,     0,   545,   546,     0,  1911,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,   545,
     546,     0,  1917,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,   545,   546,     0,     0,   547,   548,   549,
     550,   551,   552,   553,   545,   546,     0,     0,   547,   548,
     549,   550,   551,   552,   553,   545,   546,     0,     0,   547,
     548,   549,   550,   551,   552,   553,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
       0,     0,  1922,     0,     0,   554,   555,   556,   557,     0,
       0,  1097,     0,     0,     0,     0,   554,   555,   556,   557,
     545,   546,  1100,     0,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,   554,   555,   556,   557,   545,   546,
    1101,     0,   547,   548,   549,   550,   551,   552,   553,     0,
       0,     0,     0,     0,     0,     0,     0,   554,   555,   556,
     557,     0,     0,  1103,     0,     0,     0,     0,   554,   555,
     556,   557,     0,     0,  1104,     0,     0,     0,     0,   554,
     555,   556,   557,     0,     0,  1105,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,  1106,     0,     0,     0,
       0,   554,   555,   556,   557,     0,     0,  1108,     0,     0,
       0,     0,   554,   555,   556,   557,     0,     0,  1118,     0,
       0,     0,     0,   554,   555,   556,   557,     0,     0,  1119,
       0,     0,     0,     0,   554,   555,   556,   557,   545,   546,
    1121,     0,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,     0,     0,     0,     0,     0,     0,     0,   554,   555,
     556,   557,   545,   546,  1124,     0,   547,   548,   549,   550,
     551,   552,   553,     0,     0,     0,   554,   555,   556,   557,
     545,   546,  1168,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,   545,   546,     0,     0,   547,   548,   549,
     550,   551,   552,   553,   545,   546,     0,     0,   547,   548,
     549,   550,   551,   552,   553,   545,   546,     0,     0,   547,
     548,   549,   550,   551,   552,   553,   545,   546,     0,     0,
     547,   548,   549,   550,   551,   552,   553,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,     0,     0,
       0,     0,     0,     0,     0,     0,   554,   555,   556,   557,
       0,     0,  1272,     0,     0,     0,     0,   554,   555,   556,
     557,     0,     0,  1273,     0,     0,     0,     0,   554,   555,
     556,   557,   545,   546,  1382,     0,   547,   548,   549,   550,
     551,   552,   553,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,   545,   546,  1464,     0,   547,   548,
     549,   550,   551,   552,   553,     0,     0,     0,   554,   555,
     556,   557,     0,     0,  1465,     0,     0,     0,     0,   554,
     555,   556,   557,     0,     0,  1471,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,  1472,     0,     0,     0,
       0,   554,   555,   556,   557,     0,     0,  1473,     0,     0,
       0,     0,   554,   555,   556,   557,     0,     0,  1474,     0,
       0,     0,     0,   554,   555,   556,   557,     0,     0,  1478,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
    1479,     0,     0,     0,     0,   554,   555,   556,   557,   545,
     546,  1494,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,     0,     0,     0,     0,     0,     0,     0,     0,
     554,   555,   556,   557,   545,   546,  1495,     0,   547,   548,
     549,   550,   551,   552,   553,     0,     0,     0,     0,     0,
       0,     0,   554,   555,   556,   557,   545,   546,  1496,     0,
     547,   548,   549,   550,   551,   552,   553,   545,   546,     0,
       0,   547,   548,   549,   550,   551,   552,   553,   545,   546,
       0,     0,   547,   548,   549,   550,   551,   552,   553,   545,
     546,     0,     0,   547,   548,   549,   550,   551,   552,   553,
     545,   546,     0,     0,   547,   548,   549,   550,   551,   552,
     553,   545,   546,     0,     0,   547,   548,   549,   550,   551,
     552,   553,   545,   546,     0,     0,   547,   548,   549,   550,
     551,   552,   553,   545,   546,     0,     0,   547,   548,   549,
     550,   551,   552,   553,     0,     0,     0,   554,   555,   556,
     557,     0,     0,  1497,     0,     0,     0,     0,   554,   555,
     556,   557,     0,     0,  1498,     0,     0,     0,     0,   554,
     555,   556,   557,   545,   546,  1501,     0,   547,   548,   549,
     550,   551,   552,   553,     0,     0,     0,     0,     0,     0,
       0,     0,   554,   555,   556,   557,   545,   546,  1502,     0,
     547,   548,   549,   550,   551,   552,   553,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
    1505,     0,     0,     0,     0,   554,   555,   556,   557,     0,
       0,  1525,     0,     0,     0,     0,   554,   555,   556,   557,
       0,     0,  1647,     0,     0,     0,     0,   554,   555,   556,
     557,     0,     0,  1651,     0,     0,     0,     0,   554,   555,
     556,   557,     0,     0,  1713,     0,     0,     0,     0,   554,
     555,   556,   557,     0,     0,  1727,     0,     0,     0,     0,
     554,   555,   556,   557,     0,     0,  1729,     0,     0,     0,
       0,   554,   555,   556,   557,   545,   546,  1730,     0,   547,
     548,   549,   550,   551,   552,   553,  -334,  -334,     0,     0,
    -334,  -334,  -334,  -334,  -334,  -334,  -334,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   554,   555,   556,   557,     0,     0,  1853,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   554,   555,   556,   557,     0,     0,
    1860,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   554,   555,   556,   557,     0,     0,  1906,
       0,     0,     0,     0,  -334,  -334,  -334,  -334
};

static const yytype_int16 yycheck[] =
{
      15,    34,   431,    18,     9,    10,  1174,  1175,     4,    10,
      10,     7,     9,    28,     4,     4,     5,     7,    70,   104,
      35,    36,    10,    14,    56,    70,    60,    42,    10,    16,
      35,    10,    47,    48,    56,    60,     3,    59,    60,    54,
       7,     8,    57,     3,    71,   399,   400,     7,     8,   115,
     112,    42,    10,   112,    69,    42,   112,    72,    73,    82,
      91,    33,    34,    78,    75,    76,    81,    82,    65,    66,
      67,    68,    69,    70,    89,    23,   110,   220,   220,   110,
      37,    38,    61,    62,   227,   227,    65,    66,    67,    68,
      69,    70,    71,   220,    42,    12,   111,     3,   225,   110,
     227,     7,   112,    61,    62,    70,    71,    65,    66,    67,
      68,    69,    70,    71,     0,    68,    69,    70,    71,   224,
       0,   144,    71,   138,   139,    42,   151,   220,     4,   144,
     224,     7,    89,   218,   227,    65,    66,    67,    68,    69,
      70,    65,    66,    67,    68,    69,    70,    65,    66,    67,
      68,    69,    70,   220,   213,    41,   218,   213,   225,   218,
     227,    41,   218,    65,    66,    67,    68,    69,    70,   523,
      57,   525,   224,    65,    66,    67,    68,    69,    70,   224,
     210,   247,   225,   213,   227,   210,    26,   213,   218,   178,
     179,   180,   218,   218,   221,   222,   228,    65,    66,    67,
      68,    69,    70,    50,    39,   220,   228,    42,   223,    65,
      66,    67,    68,    69,    70,   213,   220,   220,   129,   220,
     218,   225,   225,   220,   227,   240,   227,   227,   224,   115,
      94,   246,   242,   243,   224,   115,   269,   270,   253,   227,
     219,   220,   221,   222,   220,   227,     4,     5,   227,   112,
     224,   227,   219,   220,   219,   220,   221,   222,   220,   219,
     220,   219,   220,   221,   222,   227,   219,   220,   221,   222,
     219,   220,   221,   222,   289,   290,     0,   292,   224,   112,
     220,   296,   225,   298,   227,   225,   301,   227,   303,   304,
     220,   306,   307,   308,   309,   310,   220,   312,   313,   314,
     315,   225,   220,   227,   319,   320,   321,   110,   323,   227,
     220,   326,   327,   328,   329,   225,   331,   332,   220,   224,
     335,   336,   337,   224,   339,   227,   341,   342,   220,   224,
     345,   346,   347,   225,   349,   350,   351,   352,   353,   354,
     355,   220,   357,   358,   359,   360,   361,   362,   227,   364,
     213,   366,   220,   368,   369,   218,   371,    42,   373,   227,
     375,   247,   377,  1531,   220,   220,  1534,   247,   220,   220,
     385,   227,   227,   388,   225,   227,   227,   392,   220,    44,
     213,   396,   397,   225,   220,   218,   220,   402,    22,   225,
     405,   227,    70,   227,    70,   410,    61,    62,     4,   414,
      65,    66,    67,    68,    69,    70,    71,   220,   220,   220,
     420,   421,   225,   428,   227,   227,   227,   224,   433,    11,
       4,     5,   437,   438,   439,   440,   441,   442,   443,   224,
     445,   446,   447,   448,   449,   224,   451,   452,   453,   454,
     455,   456,   457,   458,   459,   460,   461,   224,   463,   464,
     465,   224,   467,   468,   469,   470,   471,   220,   473,   474,
     220,   476,   477,   220,   227,   225,   212,   227,   225,    61,
      62,   428,   429,    65,    66,    67,    68,    69,    70,    71,
     495,   496,   497,   498,   499,   225,   220,   227,     4,     5,
     505,   225,   507,   227,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   220,   220,   522,   574,   524,
     213,   526,   227,   227,   529,   530,   225,   532,   227,    48,
     224,   536,   537,   538,   539,   540,   541,   542,   220,   220,
     224,   488,    61,    62,   225,   227,    65,    66,    67,    68,
      69,    70,    71,   225,   224,   227,   220,    66,    44,    68,
      69,    70,    71,   227,   219,   220,   221,   222,   220,   220,
     220,   518,   577,   225,   225,    61,    62,   227,   601,    65,
      66,    67,    68,    69,    70,    71,   220,   220,   220,   589,
     590,   220,   218,   227,   227,   227,   596,   597,   227,   604,
     220,   220,   224,   220,   220,   225,   220,   612,   227,   614,
     227,   227,   617,   227,   619,   220,   220,   220,    18,    19,
     225,    61,    62,   227,   227,    65,    66,    67,    68,    69,
      70,    71,     4,     5,   220,   640,   224,   219,   220,   221,
     222,   227,    65,    66,    67,    68,    69,    70,   220,   220,
     655,   220,   220,   225,   225,   660,  1814,   220,   227,   227,
     665,    61,    62,   224,   227,    65,    66,    67,    68,    69,
      70,    71,   224,    69,    70,    71,   220,   682,   218,   684,
     218,   225,   687,    65,    66,    67,    68,    69,    70,   220,
     695,   696,    42,   698,   218,   700,   227,    47,   574,   220,
     219,   220,   221,   222,   574,   213,   227,   220,   713,   220,
     219,   220,   221,   222,   227,   139,   227,   220,   220,  1138,
     725,   726,  1141,   225,   227,    65,    66,    67,    68,    69,
      70,   218,   220,   219,   220,   221,   222,    61,    62,   227,
     217,    65,    66,    67,    68,    69,    70,    71,     4,     5,
     226,   227,   218,   758,   759,   760,    65,    66,    67,    68,
      69,    70,   220,   768,    61,    62,   294,   225,    65,    66,
      67,    68,    69,    70,    71,     4,     5,   305,   143,   219,
     220,   221,   222,   311,   789,   225,   220,   227,   316,   224,
     220,   220,   220,   227,   322,   225,   324,   220,   227,   227,
     220,   220,   330,   218,   227,   333,   334,   227,   227,   220,
     338,   220,   220,   218,   225,   209,   344,   225,   227,   219,
     220,   221,   222,   219,   220,   221,   222,   220,   356,   220,
     220,    80,    81,   209,   227,   363,   227,   227,   220,    65,
      66,    67,    68,    69,    70,   227,   374,   220,   376,     4,
       5,     4,     5,   858,   227,    65,    66,    67,    68,    69,
      70,    37,    38,    61,    62,   393,   394,    65,    66,    67,
      68,    69,    70,    71,   220,   870,   871,   220,     4,     5,
     220,   227,   224,   220,   227,   885,   886,   227,   888,   889,
     227,    59,    60,   220,   224,   219,   220,   221,   222,   904,
     227,   225,   907,   227,    65,    66,    67,    68,    69,    70,
     220,   220,   220,   220,   220,   213,   220,   227,   227,   227,
     227,   227,   219,   220,   221,   222,   931,   932,   225,   220,
     935,   220,   224,   938,   220,   220,   227,   942,   227,   944,
     945,   227,   227,   948,   224,   220,   220,   952,   953,   954,
     220,   956,   227,   227,   959,   960,   961,   227,   220,   224,
     965,   220,   220,   220,   969,   227,   971,   972,   227,   227,
     227,   976,   977,   220,   224,   980,   981,   220,   983,   984,
     227,   986,   225,   220,   989,   220,   224,    56,   224,   994,
     227,   996,   227,   998,   220,  1000,   220,   220,   213,   220,
     528,   227,   224,   227,   227,  1010,   227,  1012,  1013,  1014,
     220,  1016,   224,   224,   213,  1020,   224,   227,   220,  1024,
    1025,   219,   220,   221,   222,   227,  1026,   225,   220,   227,
     220,   220,   213,   225,   213,  1040,   225,   227,    65,    66,
      67,    68,    69,    70,   224,  1050,  1051,   224,    65,    66,
      67,    68,    69,    70,  1059,   220,   213,   224,   224,   220,
     225,  1066,  1067,  1068,   225,  1070,  1071,  1072,  1073,   220,
    1075,   213,  1077,  1078,   224,  1080,   227,  1082,   606,   220,
    1085,  1086,   220,  1088,  1089,   220,   227,   220,   220,   227,
     225,    61,    62,   225,   227,    65,    66,    67,    68,    69,
      70,    71,   220,   220,   220,   224,  1162,   227,   220,   227,
     227,   227,  1117,    61,    62,   227,   224,    65,    66,    67,
      68,    69,    70,    71,   220,  1130,  1131,   220,   220,   225,
      51,   659,  1137,   225,   227,  1140,    61,    62,  1143,  1144,
      65,    66,    67,    68,    69,    70,    71,   224,   224,    65,
      66,    67,    68,    69,    70,    71,   220,   224,   220,   224,
    1036,   224,  1167,   227,  1169,   227,  1036,   220,    89,    90,
     220,   220,   220,   701,   227,   227,   225,   227,   706,   227,
    1185,   220,   710,  1183,  1184,  1190,  1191,   224,   227,   110,
    1195,  1196,   224,   220,  1199,   224,   117,  1202,   220,  1204,
     227,   224,  1207,   220,   220,   227,   220,   220,  1213,   220,
     227,   227,  1217,   227,   227,   220,   227,  1222,   224,   227,
    1225,   224,   227,   224,  1229,  1230,  1231,   148,   149,   150,
    1235,   152,  1237,   224,   224,   156,  1241,   220,   224,   220,
    1245,  1188,  1189,   227,   227,  1301,   227,  1252,   224,   219,
     220,   221,   222,  1258,   220,   225,  1261,   227,  1263,   224,
    1265,   227,  1267,   220,  1269,   224,  1271,   227,   796,  1274,
     227,   219,   220,   221,   222,   220,   227,   225,   220,   227,
     220,   220,   227,  1288,  1289,   227,  1162,   227,   227,   224,
     224,   220,  1162,   220,   219,   220,   221,   222,   227,   227,
     227,   224,   227,   219,   220,   221,   222,   224,  1313,  1314,
      61,    62,   224,  1318,    65,    66,    67,    68,    69,    70,
      71,   224,   220,   224,   224,   220,   220,   224,  1333,   227,
      61,    62,   227,   227,    65,    66,    67,    68,    69,    70,
      71,   224,    61,    62,   224,   224,    65,    66,    67,    68,
      69,    70,    71,   224,    61,    62,   224,  1362,    65,    66,
      67,    68,    69,    70,    71,   224,   220,   220,  1363,  1364,
     227,    61,    62,   227,   227,    65,    66,    67,    68,    69,
      70,    71,   224,  1383,  1384,   220,   224,   224,  1393,  1394,
    1395,   220,   227,  1398,  1399,   220,  1401,   220,   227,   220,
    1405,   220,   227,  1408,   227,   220,   227,  1412,   227,   220,
    1415,  1416,   227,   227,   220,   220,   227,   220,  1423,  1424,
    1425,   227,   227,  1428,   227,  1301,  1431,  1432,   224,   224,
     227,  1301,    61,    62,   227,  1440,    65,    66,    67,    68,
      69,    70,    71,   227,  1449,  1450,  1451,     5,  1453,  1454,
    1455,   227,  1457,    41,    61,    62,   225,  1462,    65,    66,
      67,    68,    69,    70,    71,   225,   220,   220,   219,   220,
     221,   222,  1477,   227,   227,   220,   227,   224,  1483,  1484,
    1485,    70,   227,   227,  1489,  1490,  1491,  1492,   219,   220,
     221,   222,   225,   225,     5,   225,   227,   220,   220,  1504,
     219,   220,   221,   222,   227,   227,   224,  1512,   227,   224,
    1515,   220,   219,   220,   221,   222,  1521,   227,   227,   220,
     227,   220,   224,   227,  1529,   225,   227,   220,   227,   219,
     220,   221,   222,   220,   227,   220,  1541,   227,   220,  1544,
     227,   220,   227,  1548,   224,   227,  1551,   220,   227,   220,
    1555,    11,   224,  1558,   227,   220,   227,   225,   220,  1564,
    1565,  1566,   227,  1568,    24,   227,   220,  1572,    28,    41,
      44,    31,   224,   227,     8,   220,    36,    37,    38,    39,
     220,  1586,   227,   227,  1589,   227,  1642,   227,   220,   220,
     219,   220,   221,   222,   227,   227,   227,   227,   227,   220,
    1605,  1606,   220,  1608,  1609,  1610,   227,   227,   227,   227,
     227,   220,   219,   220,   221,   222,  1621,  1622,   227,   220,
     227,   220,   224,   220,   220,   220,   227,   220,   227,    89,
     227,   227,   227,   220,   227,  1640,   220,   220,   220,   220,
     227,   220,   227,   227,   227,   227,   227,   220,   227,   109,
     227,  1656,   227,  1658,   227,  1660,   227,  1662,   224,    61,
      62,   225,   225,    65,    66,    67,    68,    69,    70,    71,
     220,   131,   220,   220,   227,  1680,   220,   227,  1734,   227,
     227,  1737,   225,   227,   224,   224,   227,    61,    62,  1694,
    1695,    65,    66,    67,    68,    69,    70,    71,  1703,  1704,
    1705,   220,   220,   220,  1709,   220,   220,   220,   227,   227,
     227,   227,   227,   227,   227,   225,   225,    61,  1723,  1724,
    1725,    65,    66,    67,    68,    69,    70,    71,   220,   220,
     220,   220,   220,   220,  1739,   227,   227,   227,   227,   227,
     227,  1797,  1747,   220,  1800,  1750,  1751,  1752,  1753,  1754,
     227,   227,   220,    71,  1759,   225,  1761,   220,  1763,   227,
    1765,   220,   222,   223,   227,    41,  1642,  1772,   227,   225,
     220,  1776,  1642,  1778,   220,   220,  1781,   227,   220,    47,
    1785,   227,   227,   220,   220,   227,   246,  1792,   220,  1794,
     227,   227,   225,   253,   225,   227,  1801,   224,  1854,   224,
      79,   227,   225,   225,    79,    56,   227,   227,   227,   227,
    1815,   227,  1817,  1341,   227,   227,   276,   219,   220,   221,
     222,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,  1836,   225,   225,    41,  1840,   227,   227,   227,   225,
    1845,  1846,  1847,   225,   225,   219,   220,   221,   222,   225,
     227,   224,   224,   227,  1859,   224,   227,   227,  1734,   227,
    1865,  1737,   227,  1868,  1734,  1870,   227,  1737,   227,   225,
     227,    36,  1877,    41,  1879,   219,   220,   221,   222,   224,
      70,    70,   342,   225,   225,    70,  1891,  1892,    46,    56,
     225,    61,    62,   225,   227,    65,    66,    67,    68,    69,
      70,    71,   224,   224,  1909,    45,  1911,   224,   224,    70,
     225,   225,  1917,    36,   227,  1920,     4,  1922,   601,   379,
     380,  1797,  1036,    41,  1800,   385,    41,  1797,   431,  1040,
    1800,   887,   890,  1717,  1521,   598,  1904,   588,  1172,  1743,
      -1,   401,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   409,
      -1,    -1,    -1,    -1,   414,    -1,    -1,    -1,   418,    -1,
      -1,    -1,    -1,    -1,   424,   425,    -1,   427,   428,   429,
      66,    67,    68,    69,    70,    71,    -1,    -1,  1854,    -1,
      -1,    -1,    -1,    -1,  1854,    -1,    -1,    -1,    -1,    -1,
     450,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,   472,    -1,    -1,   475,    -1,    -1,   478,   479,
     480,   481,   482,   483,   484,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,    -1,    -1,    -1,    -1,    -1,
     500,   501,   502,   503,   504,    -1,   506,    -1,   508,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,   518,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   547,   548,   549,
     550,   551,   552,   553,   554,   555,   556,   557,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   575,    -1,    -1,    -1,    -1,
     580,    -1,    -1,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,    -1,   592,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   605,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,     8,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,   221,
     222,    75,    -1,    -1,    78,   227,    -1,    -1,    -1,   689,
      -1,    85,    86,    -1,    88,    -1,   696,    -1,   698,    93,
      -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,    -1,   106,   107,    -1,   715,    -1,   111,    -1,   113,
      -1,   115,    -1,   117,    -1,   725,   726,   121,   122,   123,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,
      -1,   135,   136,   137,   138,    -1,   140,   141,   142,    -1,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,   211,   212,    -1,
     214,   215,   216,    -1,    -1,   219,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,   228,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,   872,   873,    -1,    -1,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   901,    -1,    -1,    -1,    -1,    -1,   907,   908,    -1,
      -1,   911,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   935,    -1,   937,    -1,    -1,
     940,    -1,   942,    -1,   944,   945,   946,    -1,    -1,   949,
     950,    -1,    -1,    -1,   954,    -1,   956,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   966,   967,    -1,    -1,
      -1,    -1,   972,    -1,    -1,    -1,    -1,    -1,   978,    -1,
      -1,   981,   982,    -1,    -1,    -1,    -1,   987,   988,    -1,
     990,    -1,   992,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,  1002,    -1,  1004,   219,   220,   221,   222,    -1,
      -1,  1011,  1012,   227,    -1,    -1,    -1,  1017,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,  1027,  1028,  1029,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
    1040,  1041,   227,  1043,    -1,    -1,  1046,  1047,  1048,    -1,
       4,     5,    -1,     7,     8,    -1,    -1,  1057,  1058,    -1,
      -1,    -1,    -1,  1063,  1064,    -1,  1066,    -1,    -1,  1069,
     219,   220,   221,   222,  1074,    29,  1076,    -1,   227,    -1,
      -1,  1081,    -1,  1083,    -1,    -1,    -1,  1087,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1096,    -1,    -1,  1099,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,  1107,    -1,    -1,
      -1,  1111,  1112,  1113,  1114,  1115,    -1,    -1,    -1,    -1,
      61,    62,    -1,  1123,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,    -1,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,
      -1,    -1,    -1,    -1,  1164,    -1,    -1,    -1,   122,   123,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,    -1,    -1,    -1,    -1,  1188,  1189,
      -1,    -1,    -1,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    61,    62,    -1,   158,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,   178,   179,   180,    -1,    -1,   183,
     184,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,    -1,    -1,   197,    -1,    -1,   200,    -1,   202,   203,
      -1,   205,    -1,   207,    -1,   209,    -1,    -1,   212,    -1,
     214,    -1,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     224,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    61,    62,    -1,
    1290,    65,    66,    67,    68,    69,    70,    71,    -1,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    -1,
      55,    56,    -1,    58,    59,    60,    61,    62,    63,    64,
      -1,    66,    67,    68,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    -1,    61,    62,    80,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
     219,   220,   221,   222,  1374,    -1,    61,    62,   227,  1379,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,  1394,    -1,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,  1409,
    1410,    -1,    -1,  1413,    -1,  1415,  1416,    -1,    -1,    -1,
      -1,  1421,    -1,   158,    -1,    -1,    -1,  1427,  1428,  1429,
      -1,  1431,    -1,    -1,  1434,  1435,  1436,    -1,  1438,    -1,
    1440,    -1,  1442,    -1,  1444,   219,   220,   221,   222,    -1,
      -1,    -1,  1452,   227,    -1,    -1,  1456,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,  1467,    -1,  1469,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,   217,  1483,    -1,    -1,  1486,  1487,    -1,    -1,
      -1,    -1,    -1,  1493,    -1,    -1,    -1,    -1,    -1,    -1,
    1500,   219,   220,   221,   222,    -1,    -1,  1507,    -1,  1509,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,  1521,    -1,    -1,    -1,    -1,    -1,  1527,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,  1546,  1547,    -1,    -1,
    1550,    -1,    -1,   288,   219,   220,   221,   222,   293,    -1,
      -1,    -1,   227,  1563,   299,    -1,    -1,    -1,    -1,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
    1580,    -1,    -1,    -1,  1584,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,  1592,  1593,  1594,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    61,    62,   342,    -1,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,
      -1,    -1,    -1,  1643,    -1,    -1,    -1,   382,   383,   384,
      -1,   386,   387,    -1,   389,   390,   391,  1657,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,  1668,    -1,
    1670,  1671,    -1,  1673,    -1,    -1,    -1,    -1,  1678,    -1,
      -1,    -1,  1682,  1683,  1684,  1685,  1686,    -1,  1688,  1689,
    1690,    -1,  1692,    -1,    -1,    -1,    -1,  1697,  1698,    -1,
      -1,    -1,  1702,    -1,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,  1718,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1726,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,   472,    -1,   474,
    1740,  1741,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,  1756,    -1,    -1,    -1,
      -1,    -1,  1762,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,  1784,    -1,  1786,    -1,    -1,    -1,
      -1,    -1,    -1,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,  1823,    -1,    -1,  1826,    -1,    -1,    -1,
    1830,    -1,  1832,  1833,    -1,  1835,    -1,  1837,    -1,    -1,
      -1,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     595,  1861,   219,   220,   221,   222,    -1,  1867,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,   611,    -1,    -1,    -1,
    1880,    -1,    -1,    -1,    -1,    -1,    -1,   622,    -1,    -1,
      -1,    -1,    -1,   628,    -1,    -1,    -1,  1897,   633,    -1,
      -1,    -1,   637,    -1,   639,    -1,    -1,    -1,    -1,    -1,
     645,    -1,    -1,   648,   649,  1915,    -1,    -1,   653,    -1,
      -1,    -1,    -1,     3,     4,     5,   661,     7,     8,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   673,    -1,
      -1,    -1,    -1,    -1,    -1,   680,    -1,    -1,    28,    29,
      -1,   219,   220,   221,   222,    -1,   691,    -1,   693,   227,
      -1,    -1,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   714,
      -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,   219,
     220,   221,   222,    -1,    -1,    85,    86,   227,    88,    -1,
      -1,    -1,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,
     100,   101,   102,    -1,    -1,    -1,   106,   107,    -1,    -1,
      -1,   111,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,
      -1,   121,   122,   123,    -1,    -1,    -1,   127,   128,    -1,
      -1,    -1,   132,    -1,    -1,   135,   136,   137,   138,    -1,
     140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   856,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,   211,   212,    -1,   214,   215,   216,    -1,    -1,   219,
      -1,    -1,    -1,    -1,   224,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,   930,     3,     4,     5,    -1,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   973,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,  1009,    -1,    -1,    -1,    85,    86,
    1015,    88,    -1,  1018,  1019,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,   219,   220,   221,   222,   153,    -1,    -1,  1084,
     227,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
      -1,    -1,   219,    -1,    -1,    -1,    -1,   224,   225,     3,
       4,     5,    -1,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,
      -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,    -1,
      -1,    -1,   106,   107,    -1,    -1,    -1,   111,    -1,   113,
      -1,   115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,
      -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,
      -1,   135,   136,   137,   138,    -1,   140,   141,   142,    -1,
      -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,    -1,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,   211,   212,    -1,
     214,   215,   216,    -1,    -1,   219,    -1,    -1,    -1,    -1,
     224,   225,     3,     4,     5,    -1,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,  1458,    85,    86,    -1,    88,    -1,    -1,
      91,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,   100,
     101,   102,   103,   104,    -1,   106,   107,    -1,    -1,    -1,
     111,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,   125,    -1,   127,   128,    -1,    -1,
     131,   132,   133,   134,   135,   136,   137,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,    -1,    -1,   219,    -1,
       3,     4,     5,   224,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    91,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,    -1,   106,   107,    -1,    -1,    -1,   111,    -1,
     113,  1706,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,   124,    -1,    -1,   127,   128,    -1,    -1,   131,   132,
      -1,    -1,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,    -1,    -1,   219,    -1,     3,     4,
       5,   224,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    -1,    -1,    91,    -1,    93,    -1,
      -1,    96,    97,    -1,    -1,   100,   101,   102,   103,   104,
      -1,   106,   107,    -1,    -1,    -1,   111,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
     125,    -1,   127,   128,    -1,    -1,   131,   132,    -1,    -1,
     135,   136,   137,   138,    -1,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,   211,   212,    -1,   214,
     215,   216,    -1,    -1,   219,    -1,     3,     4,     5,   224,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,   100,   101,   102,   103,   104,    -1,   106,
     107,    -1,    -1,    -1,   111,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,    -1,    -1,   131,   132,    -1,    -1,   135,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
      -1,    -1,   219,    -1,     3,     4,     5,   224,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    91,    -1,    93,    -1,    -1,    96,    97,    -1,
      -1,   100,   101,   102,   103,    -1,    -1,   106,   107,    -1,
      -1,   110,   111,    -1,   113,    -1,   115,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,   138,
      -1,   140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,    -1,    -1,
     219,    -1,     3,     4,     5,   224,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,   107,    -1,    -1,   110,
     111,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,   127,   128,    -1,    -1,
      -1,   132,    -1,    -1,   135,   136,   137,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,    -1,    -1,   219,    -1,
       3,     4,     5,   224,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,
     103,   104,    -1,   106,   107,    -1,    -1,   110,   111,    -1,
     113,    -1,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,
      -1,    -1,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,    -1,    -1,   219,    -1,     3,     4,
       5,   224,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,   107,    -1,    -1,   110,   111,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,    -1,
     135,   136,   137,   138,    -1,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,   219,    -1,     3,     4,     5,   224,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    -1,    -1,    91,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,   110,   111,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
      -1,    -1,   219,    -1,     3,     4,     5,   224,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    97,    -1,
      -1,   100,   101,   102,    -1,   104,    -1,   106,   107,    -1,
      -1,    -1,   111,    -1,   113,    -1,   115,    -1,   117,    -1,
      -1,   120,   121,   122,   123,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,   138,
      -1,   140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,    -1,    -1,
     219,    -1,     3,     4,     5,   224,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,   100,
     101,   102,    -1,   104,    -1,   106,   107,    -1,    -1,    -1,
     111,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,   127,   128,    -1,    -1,
      -1,   132,    -1,    -1,   135,   136,   137,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,    -1,   218,   219,    -1,
       3,     4,     5,   224,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    32,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,    -1,   106,   107,    -1,    -1,    -1,   111,    -1,
     113,    -1,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,
      -1,    -1,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,    -1,    -1,   219,    -1,     3,     4,
       5,   224,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,    -1,
     135,   136,   137,   138,    -1,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,    -1,   214,
     215,   216,    -1,    -1,   219,    -1,     3,     4,     5,   224,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,   110,   111,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
      -1,    -1,   219,    -1,     3,     4,     5,   224,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,    -1,   106,   107,    -1,
      -1,   110,   111,    -1,   113,    -1,   115,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,   138,
      -1,   140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,    -1,    -1,
     219,    -1,     3,     4,     5,   224,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,   107,    -1,    -1,    -1,
     111,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,   127,   128,    -1,    -1,
      -1,   132,    -1,    -1,   135,   136,   137,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,    -1,    -1,   219,    -1,
       3,     4,     5,   224,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,    -1,   106,   107,    -1,    -1,   110,   111,    -1,
     113,    -1,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,
      -1,    -1,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,    -1,    -1,   219,    -1,     3,     4,
       5,   224,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,   107,    -1,    -1,   110,   111,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,    -1,
     135,   136,   137,   138,    -1,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,   211,   212,    -1,   214,
     215,   216,    -1,    -1,   219,    -1,     3,     4,     5,   224,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,   110,   111,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
      -1,    -1,   219,    -1,     3,     4,     5,   224,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,    -1,   106,   107,    -1,
      -1,   110,   111,    -1,   113,    -1,   115,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,    -1,   127,   128,
      -1,    -1,    -1,   132,    -1,    -1,   135,   136,   137,   138,
      -1,   140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,    -1,    -1,
     219,    -1,     3,     4,     5,   224,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,    29,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    -1,    -1,    78,    -1,    -1,
      -1,    -1,    -1,    -1,    85,    86,    -1,    88,    -1,    -1,
      -1,    -1,    93,    -1,    -1,    96,    97,    -1,    -1,   100,
     101,   102,    -1,    -1,    -1,   106,   107,    -1,    -1,   110,
     111,    -1,   113,    -1,   115,    -1,   117,    -1,    -1,    -1,
     121,   122,   123,    -1,    -1,    -1,   127,   128,    -1,    -1,
      -1,   132,    -1,    -1,   135,   136,   137,   138,    -1,   140,
     141,   142,    -1,    -1,    -1,   146,   147,    -1,    -1,    -1,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
      -1,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
     211,   212,    -1,   214,   215,   216,    -1,    -1,   219,    -1,
       3,     4,     5,   224,     7,     8,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    -1,    -1,    78,    -1,    -1,    -1,    -1,
      -1,    -1,    85,    86,    -1,    88,    -1,    -1,    -1,    -1,
      93,    -1,    -1,    96,    97,    -1,    -1,   100,   101,   102,
      -1,    -1,    -1,   106,   107,    -1,    -1,   110,   111,    -1,
     113,    -1,   115,    -1,   117,    -1,    -1,    -1,   121,   122,
     123,    -1,    -1,    -1,   127,   128,    -1,    -1,    -1,   132,
      -1,    -1,   135,   136,   137,   138,    -1,   140,   141,   142,
      -1,    -1,    -1,   146,   147,    -1,    -1,    -1,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,    -1,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,   211,   212,
      -1,   214,   215,   216,    -1,    -1,   219,    -1,     3,     4,
       5,   224,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    86,    -1,    88,    -1,    -1,    -1,    -1,    93,    -1,
      -1,    96,    97,    -1,    -1,   100,   101,   102,    -1,    -1,
      -1,   106,   107,    -1,    -1,    -1,   111,    -1,   113,    -1,
     115,    -1,   117,    -1,    -1,    -1,   121,   122,   123,    -1,
      -1,    -1,   127,   128,    -1,    -1,    -1,   132,    -1,    -1,
     135,   136,   137,   138,    -1,   140,   141,   142,    -1,    -1,
      -1,   146,   147,    -1,    -1,    -1,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,    -1,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,   211,   212,    -1,   214,
     215,   216,    -1,    -1,   219,    -1,     3,     4,     5,   224,
       7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,
      -1,    78,    -1,    -1,    -1,    -1,    -1,    -1,    85,    86,
      -1,    88,    -1,    -1,    -1,    -1,    93,    -1,    -1,    96,
      97,    -1,    -1,   100,   101,   102,    -1,    -1,    -1,   106,
     107,    -1,    -1,    -1,   111,    -1,   113,    -1,   115,    -1,
     117,    -1,    -1,    -1,   121,   122,   123,    -1,    -1,    -1,
     127,   128,    -1,    -1,    -1,   132,    -1,    -1,   135,   136,
     137,   138,    -1,   140,   141,   142,    -1,    -1,    -1,   146,
     147,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,    -1,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,   211,   212,    -1,   214,   215,   216,
      -1,    -1,   219,    -1,     3,     4,     5,   224,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    86,    -1,    88,
      -1,    -1,    -1,    -1,    93,    -1,    -1,    96,    97,    -1,
      -1,   100,   101,   102,    -1,    -1,    -1,   106,   107,    -1,
      -1,    -1,   111,    -1,   113,    -1,   115,    -1,   117,    -1,
      -1,    -1,   121,   122,   123,    -1,    -1,     5,   127,   128,
       8,    -1,    -1,   132,    -1,    -1,   135,   136,   137,   138,
      -1,   140,   141,   142,    -1,    -1,    -1,   146,   147,    -1,
      -1,    29,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,    -1,   202,   203,   204,   205,   206,   207,   208,
     209,    -1,   211,   212,    -1,   214,   215,   216,    -1,    97,
     219,    -1,   100,   101,   102,   224,    -1,    -1,   106,    -1,
      -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   122,   123,    -1,    -1,     5,   127,
     128,     8,    -1,    -1,    -1,    -1,    61,    62,    -1,   137,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,   147,
      -1,    -1,    29,    -1,    -1,   153,    -1,    -1,    -1,    -1,
     158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     178,   179,   180,    -1,    -1,   183,   184,   185,    -1,   187,
      -1,   189,   190,   191,   192,   193,   194,    -1,    -1,   197,
      -1,    -1,   200,    -1,   202,   203,    -1,   205,    -1,   207,
      -1,   209,    -1,    -1,   212,    -1,   214,    -1,   216,    -1,
      97,    -1,    -1,   100,   101,   102,   224,   225,    -1,   106,
      -1,    -1,    -1,   110,   111,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,     5,
     127,   128,     8,    -1,    -1,    -1,    -1,    61,    62,    -1,
     137,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
     147,    -1,    -1,    29,    -1,    -1,   153,    -1,    -1,    -1,
      -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
     225,   178,   179,   180,    -1,    -1,   183,   184,   185,    -1,
     187,    -1,   189,   190,   191,   192,   193,   194,    -1,    -1,
     197,    -1,    -1,   200,    -1,   202,   203,    -1,   205,    -1,
     207,    -1,   209,    -1,    -1,   212,    -1,   214,    -1,   216,
      -1,    97,    -1,    -1,   100,   101,   102,   224,    -1,    -1,
     106,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,    -1,
       5,   127,   128,     8,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,   144,    -1,
      -1,   147,    -1,    -1,    29,    -1,    -1,   153,    -1,    -1,
      -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,
      -1,   225,   178,   179,   180,    60,    -1,   183,   184,   185,
      -1,   187,    -1,   189,   190,   191,   192,   193,   194,    -1,
      -1,   197,    -1,    -1,   200,    -1,   202,   203,    -1,   205,
      -1,   207,    -1,   209,    -1,    -1,   212,    -1,   214,    -1,
     216,    -1,    97,    -1,    -1,   100,   101,   102,   224,    -1,
      -1,   106,    -1,    -1,    -1,    -1,   111,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,    -1,
      -1,     5,   127,   128,     8,    -1,    -1,    -1,    -1,    61,
      62,    -1,   137,    65,    66,    67,    68,    69,    70,    71,
      -1,    -1,   147,    -1,    -1,    29,    -1,    -1,   153,    -1,
      -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   178,   179,   180,    -1,    -1,   183,   184,
     185,    -1,   187,    -1,   189,   190,   191,   192,   193,   194,
      -1,    -1,   197,    -1,    -1,   200,    -1,   202,   203,    -1,
     205,    -1,   207,    -1,   209,    -1,    -1,   212,    -1,   214,
      -1,   216,    -1,    97,    -1,    -1,   100,   101,   102,   224,
      -1,    -1,   106,    -1,    -1,    -1,   110,   111,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,   123,
      -1,    -1,     5,   127,   128,     8,    -1,    -1,    -1,    -1,
      61,    62,    -1,   137,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,   147,    -1,    -1,    29,    -1,    -1,   153,
      -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,   225,   178,   179,   180,    -1,    -1,   183,
     184,   185,    -1,   187,    -1,   189,   190,   191,   192,   193,
     194,    -1,    -1,   197,    -1,    -1,   200,    -1,   202,   203,
      -1,   205,    -1,   207,    -1,   209,    -1,    -1,   212,    -1,
     214,    -1,   216,    -1,    97,    -1,    -1,   100,   101,   102,
     224,    -1,    -1,   106,    -1,    -1,    -1,   110,   111,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   122,
     123,    -1,    -1,     5,   127,   128,     8,    -1,    -1,    -1,
      -1,    61,    62,    -1,   137,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,   147,    -1,    -1,    29,    -1,    -1,
     153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,   225,   178,   179,   180,    -1,    -1,
     183,   184,   185,    -1,   187,    -1,   189,   190,   191,   192,
     193,   194,    -1,    -1,   197,    -1,    -1,   200,    -1,   202,
     203,    -1,   205,    -1,   207,    -1,   209,    -1,    -1,   212,
      -1,   214,    -1,   216,    -1,    97,    -1,    -1,   100,   101,
     102,   224,    -1,    -1,   106,    -1,    -1,    -1,    -1,   111,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     122,   123,    -1,    -1,     5,   127,   128,     8,    -1,    -1,
      -1,    -1,    61,    62,    -1,   137,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,   147,    -1,    -1,    29,    -1,
      -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,   225,   178,   179,   180,    -1,
      -1,   183,   184,   185,    -1,   187,    -1,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,    -1,
     202,   203,    -1,   205,    -1,   207,    -1,   209,    -1,    -1,
     212,    -1,   214,    -1,   216,    -1,    97,    -1,    -1,   100,
     101,   102,   224,    -1,    -1,   106,    -1,    -1,    -1,    -1,
     111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   122,   123,    -1,    -1,     5,   127,   128,     8,    -1,
      -1,    -1,    -1,    61,    62,    -1,   137,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,   147,    -1,    -1,    29,
      -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,   225,   178,   179,   180,
      -1,    -1,   183,   184,   185,    -1,   187,    -1,   189,   190,
     191,   192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,
      -1,   202,   203,    -1,   205,    -1,   207,    -1,   209,    -1,
      -1,   212,    -1,   214,    -1,   216,    -1,    97,    -1,    -1,
     100,   101,   102,   224,    -1,    -1,   106,    -1,    -1,    -1,
      -1,   111,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   122,   123,    -1,    -1,    -1,   127,   128,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   147,    -1,    -1,
      -1,    -1,    -1,   153,    -1,    -1,    -1,    -1,   158,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    -1,    -1,   225,   178,   179,
     180,    -1,    -1,   183,   184,   185,    -1,   187,    -1,   189,
     190,   191,   192,   193,   194,    -1,    -1,   197,    -1,    -1,
     200,    -1,   202,   203,    -1,   205,    -1,   207,    -1,   209,
      -1,    -1,   212,    -1,   214,    -1,   216,     4,     5,     6,
      -1,    -1,     9,    -1,   224,    -1,    13,    -1,    15,    -1,
      17,    18,    19,    20,    21,    22,    -1,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    33,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    55,    -1,
      -1,    58,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    72,    73,    74,    75,    76,
      77,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      87,    88,    -1,    -1,    91,    -1,    93,    -1,    95,    96,
      97,    98,    99,   100,   101,   102,    -1,    -1,   105,    -1,
     107,   108,   109,    -1,   111,    -1,   113,   114,   115,   116,
     117,   118,   119,    -1,   121,   122,   123,    -1,    -1,   126,
     127,   128,    -1,   130,    -1,   132,    -1,    -1,   135,   136,
      -1,   138,    -1,    -1,    -1,   142,    -1,    -1,   145,    -1,
     147,   148,    -1,    -1,    -1,    -1,    -1,   154,    61,    62,
     157,   158,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      -1,   178,   179,   180,    61,    62,    -1,   184,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,   198,    61,    62,   201,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,   214,    -1,    -1,
     219,   220,   221,   222,    -1,    61,    62,    -1,   227,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,    -1,    61,    62,    -1,
     227,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
     219,   220,   221,   222,    -1,    61,    62,    -1,   227,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
     219,   220,   221,   222,    -1,    61,    62,    -1,   227,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,
      61,    62,    -1,   227,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,   219,   220,   221,   222,    -1,    61,    62,
      -1,   227,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,    -1,
      -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,
      61,    62,    -1,   227,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    61,    62,    -1,   227,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,
      -1,    -1,   219,   220,   221,   222,    -1,    -1,    -1,    -1,
     227,    -1,    -1,   219,   220,   221,   222,    -1,    61,    62,
      -1,   227,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    61,    62,    -1,   227,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    -1,    61,    62,    -1,   227,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,
     221,   222,    -1,    61,    62,    -1,   227,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    -1,    61,    62,    -1,   227,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,
      -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,    -1,    -1,   227,    -1,
      -1,   219,   220,   221,   222,    -1,    61,    62,    -1,   227,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,   219,   220,   221,   222,    -1,    61,    62,    -1,   227,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    61,
      62,    -1,   227,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
      -1,    -1,   227,    -1,    -1,   219,   220,   221,   222,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   219,   220,   221,   222,
      61,    62,   225,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,   219,   220,   221,   222,    61,    62,
     225,    -1,    65,    66,    67,    68,    69,    70,    71,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    61,    62,
     225,    -1,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    61,    62,   225,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,   219,   220,   221,   222,
      61,    62,   225,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    61,    62,    -1,    -1,    65,    66,
      67,    68,    69,    70,    71,    61,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    61,    62,   225,    -1,    65,    66,    67,    68,
      69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,    61,    62,   225,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    -1,    -1,   225,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,    -1,    -1,   225,    -1,
      -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   219,   220,   221,   222,    61,
      62,   225,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,    61,    62,   225,    -1,    65,    66,
      67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,    61,    62,   225,    -1,
      65,    66,    67,    68,    69,    70,    71,    61,    62,    -1,
      -1,    65,    66,    67,    68,    69,    70,    71,    61,    62,
      -1,    -1,    65,    66,    67,    68,    69,    70,    71,    61,
      62,    -1,    -1,    65,    66,    67,    68,    69,    70,    71,
      61,    62,    -1,    -1,    65,    66,    67,    68,    69,    70,
      71,    61,    62,    -1,    -1,    65,    66,    67,    68,    69,
      70,    71,    61,    62,    -1,    -1,    65,    66,    67,    68,
      69,    70,    71,    61,    62,    -1,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,
     220,   221,   222,    61,    62,   225,    -1,    65,    66,    67,
      68,    69,    70,    71,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   219,   220,   221,   222,    61,    62,   225,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
     225,    -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,
      -1,   225,    -1,    -1,    -1,    -1,   219,   220,   221,   222,
      -1,    -1,   225,    -1,    -1,    -1,    -1,   219,   220,   221,
     222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,   220,
     221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,   219,
     220,   221,   222,    -1,    -1,   225,    -1,    -1,    -1,    -1,
     219,   220,   221,   222,    -1,    -1,   225,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    61,    62,   225,    -1,    65,
      66,    67,    68,    69,    70,    71,    61,    62,    -1,    -1,
      65,    66,    67,    68,    69,    70,    71,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   219,   220,   221,   222,    -1,    -1,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   219,   220,   221,   222,    -1,    -1,   225,
      -1,    -1,    -1,    -1,   219,   220,   221,   222
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,     4,     5,     6,     9,    13,    15,    17,    18,    19,
      20,    21,    24,    25,    26,    27,    28,    29,    30,    31,
      33,    34,    35,    40,    43,    49,    50,    51,    52,    53,
      54,    55,    58,    72,    73,    74,    75,    76,    77,    82,
      83,    84,    87,    88,    91,    93,    95,    96,    97,    98,
      99,   100,   101,   102,   105,   107,   108,   109,   111,   113,
     114,   115,   116,   117,   118,   119,   121,   122,   123,   126,
     127,   128,   130,   132,   135,   136,   138,   142,   145,   147,
     148,   154,   157,   158,   178,   179,   180,   184,   198,   201,
     214,   230,   231,   234,   241,   243,   244,   248,   260,   261,
     266,   272,   279,   287,   296,   299,   303,   306,   312,    70,
     224,    70,   224,   280,   300,   304,     4,     7,   258,   258,
     258,     3,     4,     5,     7,     8,    28,    29,    32,    61,
      62,    63,    64,    75,    78,    85,    86,    88,    93,    96,
      97,   100,   101,   102,   106,   107,   111,   113,   115,   117,
     121,   122,   123,   127,   128,   132,   135,   136,   137,   138,
     140,   141,   142,   146,   147,   153,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   202,
     203,   204,   205,   206,   207,   208,   209,   211,   212,   214,
     215,   216,   219,   224,   246,   247,   249,   255,   257,   260,
     261,   235,   236,   101,   102,   111,   122,   123,   147,   158,
     224,   246,   224,   224,   246,    26,   288,   297,   249,    56,
      59,    60,   228,   334,   239,    50,   246,   249,     4,     5,
     259,   249,   249,   254,     4,     5,   322,   323,     8,   219,
     220,   256,   257,   324,   246,   258,   228,   246,   249,   335,
     335,   335,   249,   241,   248,   260,   261,   246,    75,    76,
     110,    57,    94,   210,   254,   246,   110,   246,   110,   210,
     254,   110,   254,    91,   110,   254,    91,   103,   104,   125,
     131,   254,    91,   103,   104,   131,   254,   144,   246,    20,
      60,   110,   254,   110,   254,   246,    60,    91,   103,   110,
     254,   104,   120,   254,   254,   103,   104,   110,   254,    60,
     254,   104,   218,   254,   254,    60,   110,   110,   254,    91,
     103,   104,   125,   131,   133,   134,   254,    60,    91,   103,
     104,   124,   131,   254,    60,   246,   110,   254,   129,   110,
     246,   110,   246,   110,   254,   110,   254,   110,   254,    82,
     144,   246,    51,    89,    90,   110,   117,   148,   149,   150,
     152,   156,   110,   254,   246,   246,    91,   110,   224,   224,
     224,   224,   224,   246,   335,   110,     0,    42,   232,    70,
      70,    22,   249,   262,   263,   246,   262,     4,   224,   231,
     224,   224,    33,    34,   224,   224,   249,   224,   224,   224,
     224,   224,   112,   218,   246,   246,   212,   213,   112,   213,
     218,   112,   213,   218,   246,   218,   213,   218,   218,   218,
      60,   151,   210,   218,   218,   112,   213,   218,   112,   213,
     218,   213,   217,   218,   218,   218,   254,   218,   139,   104,
     218,   143,   210,   213,   218,   224,   213,   218,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   224,   224,
     224,   224,   224,   224,   224,   224,   224,   224,   254,   224,
     209,   246,   209,   249,   246,   249,    65,    66,    67,    68,
      69,    70,   220,    18,    19,    61,    62,    65,    66,    67,
      68,    69,    70,    71,   219,   220,   221,   222,     4,     5,
     273,   274,     4,     5,   275,   276,   246,   262,   262,   246,
     249,   290,   231,   307,   313,   224,    56,   224,     4,     7,
     224,   246,   249,   325,    56,   228,   327,   332,   240,   224,
     224,   227,   227,    10,   227,   242,   224,   224,   227,   257,
     257,   227,   249,     9,   227,   227,   254,   246,   246,   246,
     254,   242,   227,   246,   227,   246,   254,   227,   246,   227,
     246,   246,   242,   246,   246,   246,   246,   246,   242,   246,
     246,   246,   246,   242,   246,   246,   246,   242,   246,   242,
     227,   246,   246,   246,   246,   242,   246,   246,   242,   242,
     246,   246,   246,   242,   246,   227,   246,   246,   249,   254,
     227,   242,   246,   246,   246,   227,   246,   246,   246,   246,
     246,   246,   246,   242,   246,   246,   246,   246,   246,   246,
     242,   246,   227,   246,   227,   246,   246,   227,   246,   227,
     246,   242,   246,   242,   246,   227,   224,   249,   224,   249,
     227,   254,   254,   254,   246,   249,   254,   254,   246,   254,
     254,   254,   246,   227,   242,   242,   246,   246,     5,   245,
     245,   245,   225,   249,   246,   227,   227,   246,    41,   249,
     246,   267,   225,   246,   249,   264,   265,   225,    70,   249,
      16,    42,   305,   262,   262,   249,   249,   249,   246,   335,
     335,     4,     5,   252,   253,   252,   253,   246,   227,   227,
     224,   246,   246,   246,   246,   246,   246,   246,   227,   246,
     246,   246,   246,   246,   249,   246,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   246,   246,   246,   227,
     246,   246,   246,   246,   246,   249,   254,   246,   246,   254,
     249,   246,   246,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   335,   249,   249,   249,   249,   249,   225,
     249,   246,   246,   246,   246,   246,   249,   249,   249,   225,
     249,   249,   246,   249,   246,   249,   246,   246,   246,   246,
     246,   246,   246,   246,   246,   246,   335,   246,   225,   225,
     246,   245,   246,   245,   246,   225,   242,   246,   224,   246,
     246,   225,   225,   246,   246,   246,   246,   246,   246,   246,
     237,   238,   251,   250,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   224,   224,   227,   224,   224,
     227,   225,   225,    41,   289,    39,    42,   298,    44,   231,
     249,   224,   246,   249,    48,   326,   226,   227,   224,     4,
       7,   224,     8,   333,   327,   262,   262,     4,     5,   249,
     254,   262,   262,   323,     8,   256,    80,    81,   246,   249,
     242,   227,   227,   254,   246,   227,   246,   227,   227,   246,
     227,   246,   227,   254,   227,   227,   227,   254,   227,   227,
     227,   254,   227,   227,   227,   254,   227,   254,   246,   227,
     227,   227,   254,   254,   254,   227,   227,   227,   254,   227,
     246,   227,   227,   242,   246,   254,   227,   227,   227,   246,
     227,   227,   227,   227,   227,   254,   227,   227,   227,   227,
     227,   254,   227,   246,   227,   246,   227,   246,   227,   249,
     227,   254,   227,   254,   227,   246,   249,   249,   246,   242,
     227,   227,   227,   227,   227,   242,   227,   227,   242,   227,
     227,   246,   254,   249,   227,   227,   224,   227,   227,   227,
     225,   225,   246,   249,   246,   249,   233,     4,     5,   271,
     227,   281,   225,   224,   225,   225,   227,   227,   227,   225,
     227,   227,   225,   224,   224,   225,   225,   227,   227,   227,
     246,   246,   246,   227,   227,   246,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   246,
     227,   227,   227,   227,   242,   227,   227,   227,   227,   227,
     225,   225,   225,   225,   225,   225,   227,   225,   225,   227,
     225,   225,   225,   225,   225,   225,   225,   227,   225,   225,
     225,   227,   227,   227,   227,   227,   225,   227,   225,   225,
     225,   225,   225,   227,   225,   225,   225,   225,   225,   225,
     227,   227,   225,   225,   225,   225,   225,   227,   227,   225,
     227,   227,   225,   227,   227,   254,   225,   225,   258,   336,
     258,   337,   249,   249,   262,   262,   274,   262,   262,   276,
      41,   291,   308,    47,   227,   249,   225,   227,   225,   224,
     246,   246,   249,   249,   328,   329,   249,     4,     5,   319,
     321,   225,   225,   224,   224,   227,   225,   225,    79,    79,
     227,   227,   254,   246,   246,   227,   227,   246,   249,   227,
     249,   246,   227,   249,   227,   246,   249,   227,   246,   249,
     246,   249,   249,   227,   246,   249,   249,   227,   246,   246,
     246,   249,   227,   246,   249,   227,   246,   246,   246,   227,
     227,   227,   246,   249,   249,   227,   246,   227,   246,   246,
     254,   227,   246,   246,   249,   227,   246,   246,   249,   249,
     246,   246,   227,   246,   249,   249,   246,   249,   227,   249,
     246,   227,   246,   227,   246,   227,   246,   227,   249,   227,
     249,   227,   225,   225,   227,   254,   246,   249,   246,   249,
     246,   246,   254,   246,   249,   254,   254,   246,   227,   227,
     227,   246,   246,   262,   249,   249,   249,   234,   268,   265,
     249,   301,   249,   249,   249,   249,   246,   246,   225,   225,
     249,   249,   246,   227,   227,   225,   249,   249,   227,   246,
     249,   246,   246,   249,   246,   246,   246,   246,   249,   246,
     249,   246,   246,   227,   246,   249,   246,   249,   254,   246,
     246,   249,   246,   246,   249,   249,   249,   249,   249,   249,
     249,   249,   246,   249,   246,   246,   246,   253,   246,   253,
     246,   246,   227,   227,   227,   225,   225,   225,   225,    37,
      38,   294,   231,   249,   227,    56,   246,   246,   326,   227,
     319,   319,   225,   224,   224,   227,   262,   262,   246,   335,
     335,   246,   246,   227,   227,   227,   246,   246,   227,   227,
     246,   227,   246,   246,   246,   227,   246,   246,   227,   227,
     227,   246,   227,   227,   246,   227,   227,   246,   246,   246,
     246,   227,   246,   227,   227,   227,   246,   227,   227,   227,
     246,   227,   227,   246,   227,   227,   227,   246,   227,   246,
     227,   246,   227,   246,   227,   246,   246,   246,   246,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   246,
     246,   249,   227,   225,   225,   225,   225,   227,   224,    10,
     231,   225,   225,   225,   225,   225,   225,   227,   225,   225,
     246,   246,   246,   227,   227,   227,   227,   227,   246,   227,
     227,   227,   227,   242,   225,   225,   225,   225,   225,   225,
     227,   225,   225,   225,   227,   225,   225,   227,   225,   227,
     225,   225,   227,   225,   225,   227,   225,   225,   246,   258,
     258,   292,    41,    36,   309,   225,   249,   224,   225,   227,
     249,   330,   262,   262,   320,   225,   225,   246,   246,   249,
     246,   227,   246,   246,   227,   246,   227,   227,   227,   246,
     227,   227,   246,   249,   249,   227,   246,   249,   227,   246,
     249,   246,   249,   227,   227,   227,   227,   249,   227,   246,
     246,   246,   227,   249,   246,   249,   249,   246,   249,   246,
     227,   249,   249,   249,   227,   249,   227,   246,   249,   227,
     249,   249,   227,   227,   227,   246,   246,   246,   249,   246,
     246,   246,   249,   246,   254,   227,   227,   246,    70,    70,
      70,   249,     4,     5,   277,   278,   249,    14,    42,   302,
     246,   227,   227,   246,   249,   246,   246,   249,   249,   246,
     246,   246,   246,   249,   249,   246,   249,   249,   246,   246,
     227,   290,   295,    46,   315,    59,    60,   225,   249,    56,
     246,   225,   319,   225,   225,   319,   227,   227,   227,   246,
     227,   246,   227,   249,   249,   246,   249,   246,   227,   246,
     227,   227,   246,   227,   249,   246,   246,   246,   227,   246,
     227,   246,   227,   227,   227,   227,   227,   249,   227,   227,
     227,   249,   227,   246,   227,   227,   246,   227,   227,   249,
     249,   249,   227,   227,   227,   227,   227,   246,   246,   227,
     246,   246,   246,   225,   224,   224,   225,   227,    11,   285,
     225,   246,   246,   227,   227,   227,   227,   225,   225,   225,
     225,   225,   225,   246,   293,   231,   249,    45,   314,   224,
     227,   224,   225,   331,   246,   249,   246,   227,   246,   246,
     227,   227,   227,   227,   227,   249,   227,   249,   249,   227,
     249,   227,   227,   227,   249,   227,   246,   249,   249,   249,
     249,   249,   227,   249,   249,   249,   227,   249,   227,   246,
     246,   227,   249,   249,   227,   227,   227,   249,   246,   246,
     246,   254,   227,   246,    70,   225,   225,   269,   278,   249,
     282,   227,   246,   246,   246,   249,   231,    44,   318,   231,
     310,   246,   249,   249,   333,   227,   246,   227,   246,   246,
     246,   246,   246,   227,   249,   246,   227,   246,   249,   246,
     227,   246,   227,   227,   246,   227,   227,   227,   246,   246,
     227,   246,   249,   246,   249,   227,   227,   227,   246,   246,
     231,   231,   246,   225,   316,    42,    47,   311,   225,   227,
     225,   227,   319,   246,   246,   227,   249,   227,   227,   249,
     227,   249,   249,   249,   249,   246,   249,   227,   246,   227,
     227,   246,   246,   246,    23,    42,   270,   283,   231,   246,
     249,   227,   227,   246,   249,   246,   246,   227,   246,   246,
     249,    12,    42,   284,   317,   225,   225,   246,   246,   227,
     249,   227,     4,   286,   315,   227,   246,   227,   246,   249,
     227,   246,   227,   246,   246
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

    {YYACCEPT;;}
    break;

  case 4:

    {if (errorlevel<=ERROR) {YYABORT;};}
    break;

  case 5:

    {if ((yyvsp[(3) - (3)].sep)>=0) mylineno+=(yyvsp[(3) - (3)].sep); else switchlib();;}
    break;

  case 12:

    {report_missing(ERROR,"do not import a library in a loop or an if-statement");switchlib();;}
    break;

  case 13:

    {add_command(cERROR,NULL);;}
    break;

  case 19:

    {add_command(cBREAK,NULL);if (!in_loop) error(ERROR,"break outside loop");;}
    break;

  case 20:

    {add_command(cCONTINUE,NULL);if (!in_loop) error(ERROR,"continue outside loop");;}
    break;

  case 22:

    {create_call((yyvsp[(1) - (1)].symbol));add_command(cPOP,NULL);;}
    break;

  case 23:

    {create_call((yyvsp[(1) - (1)].symbol));add_command(cPOP,NULL);;}
    break;

  case 24:

    {if (function_type==ftNONE) error(ERROR,"no use for 'local' outside functions");;}
    break;

  case 26:

    {if (function_type==ftNONE) error(ERROR,"no use for 'static' outside functions");;}
    break;

  case 30:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[(2) - (2)].symbol),TRUE):(yyvsp[(2) - (2)].symbol));;}
    break;

  case 31:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[(2) - (2)].symbol),TRUE):(yyvsp[(2) - (2)].symbol));;}
    break;

  case 32:

    {create_exception(TRUE);;}
    break;

  case 33:

    {create_exception(FALSE);;}
    break;

  case 34:

    {add_command(cSKIPPER,NULL);;}
    break;

  case 35:

    {add_command(cNOP,NULL);;}
    break;

  case 36:

    {add_command(cSKIPPER,NULL);;}
    break;

  case 37:

    {add_command(cNOP,NULL);;}
    break;

  case 38:

    {create_label((function_type!=ftNONE)?dotify((yyvsp[(2) - (2)].symbol),TRUE):(yyvsp[(2) - (2)].symbol),cLABEL);;}
    break;

  case 39:

    {add_command(cCHECKOPEN,NULL);;}
    break;

  case 40:

    {add_command(cCLOSE,NULL);;}
    break;

  case 41:

    {add_command(cCHECKSEEK,NULL);;}
    break;

  case 42:

    {add_command(cCOMPILE,NULL);;}
    break;

  case 43:

    {create_execute(0);add_command(cPOP,NULL);add_command(cPOP,NULL);;}
    break;

  case 44:

    {create_execute(1);add_command(cPOP,NULL);add_command(cPOP,NULL);;}
    break;

  case 45:

    {create_colour(0);create_print('n');create_pps(cPOPSTREAM,0);;}
    break;

  case 46:

    {create_colour(0);create_pps(cPOPSTREAM,0);;}
    break;

  case 47:

    {create_colour(0);create_print('t');create_pps(cPOPSTREAM,0);;}
    break;

  case 48:

    {tileol=FALSE;;}
    break;

  case 50:

    {tileol=TRUE;;}
    break;

  case 54:

    {create_restore("");;}
    break;

  case 55:

    {create_restore((function_type!=ftNONE)?dotify((yyvsp[(2) - (2)].symbol),TRUE):(yyvsp[(2) - (2)].symbol));;}
    break;

  case 56:

    {add_command(cRESTORE2, NULL);;}
    break;

  case 57:

    {if (get_switch_id()) create_clean_switch_mark(0,TRUE);
             if (function_type!=ftNONE) {
	       add_command(cCLEARREFS,NULL);lastcmd->nextref=firstref;
	       add_command(cPOPSYMLIST,NULL);
               create_retval(ftNONE,function_type);
               add_command(cRET_FROM_FUN,NULL);
            } else {
               add_command(cRETURN,NULL);
            };}
    break;

  case 58:

    {if (get_switch_id()) create_clean_switch_mark(1,TRUE); if (function_type==ftNONE) {error(ERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL);create_retval(ftNUMBER,function_type);add_command(cRET_FROM_FUN,NULL);;}
    break;

  case 59:

    {if (get_switch_id()) create_clean_switch_mark(1,TRUE); if (function_type==ftNONE) {error(ERROR,"can not return value"); YYABORT;} add_command(cCLEARREFS,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL);create_retval(ftSTRING,function_type);add_command(cRET_FROM_FUN,NULL);;}
    break;

  case 61:

    {create_openwin(TRUE);;}
    break;

  case 62:

    {add_command(cBUTTON,NULL);;}
    break;

  case 63:

    {add_command(cMENU,NULL);;}
    break;

  case 64:

    {add_command(cCHECKBOX,NULL);;}
    break;

  case 65:

    {add_command(cRADIOBUTTON,NULL);;}
    break;

  case 66:

    {add_command(cTEXTCONTROL,NULL);;}
    break;

  case 67:

    {add_command(cLISTBOX,NULL);;}
    break;

  case 68:

    {add_command(cITEMCLEAR, NULL);;}
    break;

  case 69:

    {add_command(cLISTBOXADD1, NULL);;}
    break;

  case 70:

    {add_command(cLISTBOXADD2, NULL);;}
    break;

  case 71:

    {add_command(cDROPBOX,NULL);;}
    break;

  case 72:

    {add_command(cITEMADD,NULL);;}
    break;

  case 73:

    {add_command(cDROPBOXCLEAR,NULL);;}
    break;

  case 74:

    {add_command(cDROPBOXREMOVE,NULL);;}
    break;

  case 75:

    {add_command(cITEMDEL,NULL);;}
    break;

  case 76:

    {add_command(cLISTBOXDEL2,NULL);;}
    break;

  case 77:

    {add_command(cLISTBOXSELECT,NULL);;}
    break;

  case 78:

    {add_command(cALERT,NULL);;}
    break;

  case 79:

    {add_command(cTEXT,NULL);;}
    break;

  case 80:

    {add_command(cTEXT2, NULL);;}
    break;

  case 81:

    {add_command(cTEXTALIGN,NULL);;}
    break;

  case 82:

    {add_command(cLOCALIZE,NULL);;}
    break;

  case 83:

    {add_command(cLOCALIZE2,NULL);;}
    break;

  case 84:

    {add_command(cLOCALIZESTOP, NULL);;}
    break;

  case 85:

    {add_command(cDRAWTEXT,NULL);;}
    break;

  case 86:

    {add_command(cDRAWRECT,NULL);;}
    break;

  case 87:

    {add_command(cDRAWCLEAR,NULL);;}
    break;

  case 88:

    {add_command(cCLOSEWIN,NULL);;}
    break;

  case 89:

    {add_command(cLAYOUT,NULL);;}
    break;

  case 90:

    {add_command(cWINSET4,NULL);;}
    break;

  case 91:

    {add_command(cWINSET1,NULL);;}
    break;

  case 92:

    {add_command(cWINSET3,NULL);;}
    break;

  case 93:

    {add_command(cSHORTCUT,NULL);;}
    break;

  case 94:

    {add_command(cTEXTEDIT,NULL);;}
    break;

  case 95:

    {add_command(cTEXTADD,NULL);;}
    break;

  case 96:

    {add_command(cTEXTSET,NULL);;}
    break;

  case 97:

    {add_command(cTEXTSET2,NULL);;}
    break;

  case 98:

    {add_command(cTEXTSET3,NULL);;}
    break;

  case 99:

    {add_command(cTEXTCOLOR1,NULL);;}
    break;

  case 100:

    {add_command(cTEXTCOLOR2,NULL);;}
    break;

  case 101:

    {add_command(cTEXTCLEAR,NULL);;}
    break;

  case 102:

    {add_command(cDRAWSET1,NULL);;}
    break;

  case 103:

    {add_command(cDRAWSET2,NULL);;}
    break;

  case 104:

    {add_command(cWINSET2,NULL);;}
    break;

  case 105:

    {add_command(cDRAWSET3,NULL);;}
    break;

  case 106:

    {add_command(cDRAWSET4,NULL);;}
    break;

  case 107:

    {add_command(cVIEW,NULL);;}
    break;

  case 108:

    {add_command(cWINCLEAR,NULL);;}
    break;

  case 109:

    {add_command(cBOXVIEW,NULL);;}
    break;

  case 110:

    {add_command(cTAB,NULL);;}
    break;

  case 111:

    {add_command(cTABSET,NULL);;}
    break;

  case 112:

    {add_command(cTABADD, NULL);;}
    break;

  case 113:

    {add_command(cTABDEL, NULL);;}
    break;

  case 114:

    {add_command(cDOT,NULL);;}
    break;

  case 115:

    {add_command(cLINE,NULL);;}
    break;

  case 116:

    {add_command(cCIRCLE,NULL);;}
    break;

  case 117:

    {add_command(cELLIPSE,NULL);;}
    break;

  case 118:

    {add_command(cCURVE,NULL);;}
    break;

  case 119:

    {add_command(cSLIDER1,NULL);;}
    break;

  case 120:

    {add_command(cSLIDER2,NULL);;}
    break;

  case 121:

    {add_command(cSLIDER3,NULL);;}
    break;

  case 122:

    {add_command(cSLIDER4,NULL);;}
    break;

  case 123:

    {add_command(cSLIDER5,NULL);;}
    break;

  case 124:

    {add_command(cSLIDER6,NULL);;}
    break;

  case 125:

    {add_command(cLAUNCH,NULL);;}
    break;

  case 126:

    {add_command(cOPTION1,NULL);;}
    break;

  case 127:

    {add_command(cOPTION2,NULL);;}
    break;

  case 128:

    {add_command(cOPTION4,NULL);;}
    break;

  case 129:

    {add_command(cOPTION5,NULL);;}
    break;

  case 130:

    {add_command(cOPTION3,NULL);;}
    break;

  case 131:

    {add_command(cBITMAP,NULL);;}
    break;

  case 132:

    {add_command(cBITMAPGET, NULL);;}
    break;

  case 133:

    {add_command(cBITMAPGET2, NULL);;}
    break;

  case 134:

    {add_command(cBITMAPGETICON, NULL);;}
    break;

  case 135:

    {add_command(cBITMAPDRAW,NULL);;}
    break;

  case 136:

    {add_command(cBITMAPDRAW2,NULL);;}
    break;

  case 137:

    {add_command(cBITMAPREMOVE,NULL);;}
    break;

  case 138:

    {add_command(cSCREENSHOT,NULL);;}
    break;

  case 139:

    {add_command(cCANVAS,NULL);;}
    break;

  case 140:

    {add_command(cDROPZONE,NULL);;}
    break;

  case 141:

    {add_command(cCOLORCONTROL1,NULL);;}
    break;

  case 142:

    {add_command(cCOLORCONTROL2,NULL);;}
    break;

  case 143:

    {add_command(cTEXTCONTROL2,NULL);;}
    break;

  case 144:

    {add_command(cTEXTCONTROL3,NULL);;}
    break;

  case 145:

    {add_command(cTEXTCONTROL4,NULL);;}
    break;

  case 146:

    {add_command(cTREEBOX1,NULL);;}
    break;

  case 147:

    {add_command(cTREEBOX2,NULL);;}
    break;

  case 148:

    {add_command(cTREEBOX3,NULL);;}
    break;

  case 149:

    {add_command(cTREEBOX13,NULL);;}
    break;

  case 150:

    {add_command(cTREEBOX12,NULL);;}
    break;

  case 151:

    {add_command(cTREEBOX4,NULL);;}
    break;

  case 152:

    {add_command(cTREEBOX5,NULL);;}
    break;

  case 153:

    {add_command(cTREEBOX7,NULL);;}
    break;

  case 154:

    {add_command(cTREEBOX8,NULL);;}
    break;

  case 155:

    {add_command(cTREEBOX9,NULL);;}
    break;

  case 156:

    {add_command(cTREEBOX10,NULL);;}
    break;

  case 157:

    {add_command(cTREEBOX11,NULL);;}
    break;

  case 158:

    {add_command(cBUTTONIMAGE,NULL);;}
    break;

  case 159:

    {add_command(cCHECKBOXIMAGE,NULL);;}
    break;

  case 160:

    {add_command(cCHECKBOXSET,NULL);;}
    break;

  case 161:

    {add_command(cRADIOSET,NULL);;}
    break;

  case 162:

    {add_command(cTOOLTIP,NULL);;}
    break;

  case 163:

    {add_command(cTOOLTIPCOLOR,NULL);;}
    break;

  case 164:

    {add_command(cLISTSORT,NULL);;}
    break;

  case 165:

    {add_command(cTREESORT,NULL);;}
    break;

  case 166:

    {add_command(cFILEBOX,NULL);;}
    break;

  case 167:

    {add_command(cCOLUMNBOXADD,NULL);;}
    break;

  case 168:

    {add_command(cFILEBOXADD2,NULL);;}
    break;

  case 169:

    {add_command(cFILEBOXCLEAR,NULL);;}
    break;

  case 170:

    {add_command(cCOLUMNBOXREMOVE,NULL);;}
    break;

  case 171:

    {add_command(cCOLUMNBOXSELECT,NULL);;}
    break;

  case 172:

    {add_command(cCOLUMNBOXCOLOR,NULL);;}
    break;

  case 173:

    {add_command(cCALENDAR,NULL);;}
    break;

  case 174:

    {add_command(cCALENDARSET,NULL);;}
    break;

  case 175:

    {add_command(cSCROLLBAR,NULL);;}
    break;

  case 176:

    {add_command(cSCROLLBARSET1,NULL);;}
    break;

  case 177:

    {add_command(cSCROLLBARSET2,NULL);;}
    break;

  case 178:

    {add_command(cSCROLLBARSET3,NULL);;}
    break;

  case 179:

    {add_command(cDROPBOXSELECT,NULL);;}
    break;

  case 180:

    {add_command(cMENU2,NULL);;}
    break;

  case 181:

    {add_command(cMENU3,NULL);;}
    break;

  case 182:

    {add_command(cSUBMENU1,NULL);;}
    break;

  case 183:

    {add_command(cSUBMENU2,NULL);;}
    break;

  case 184:

    {add_command(cSUBMENU3,NULL);;}
    break;

  case 185:

    {add_command(cSTATUSBAR,NULL);;}
    break;

  case 186:

    {add_command(cSTATUSBARSET,NULL);;}
    break;

  case 187:

    {add_command(cSTATUSBARSET3,NULL);;}
    break;

  case 188:

    {add_command(cSPINCONTROL1,NULL);;}
    break;

  case 189:

    {add_command(cSPINCONTROL2,NULL);;}
    break;

  case 190:

    {add_command(cCLIPBOARDCOPY,NULL);;}
    break;

  case 191:

    {add_command(cPRINTERCONFIG,NULL);;}
    break;

  case 192:

    {add_command(cMOUSESET,NULL);;}
    break;

  case 193:

    {add_command(cSOUNDSTOP,NULL);;}
    break;

  case 194:

    {add_command(cSOUNDSTOP,NULL);;}
    break;

  case 195:

    {add_command(cSOUNDWAIT,NULL);;}
    break;

  case 196:

    {add_command(cSOUNDWAIT,NULL);;}
    break;

  case 197:

    {add_command(cSPLITVIEW1,NULL);;}
    break;

  case 198:

    {add_command(cSPLITVIEW2,NULL);;}
    break;

  case 199:

    {add_command(cSPLITVIEW3,NULL);;}
    break;

  case 200:

    {add_command(cSTACKVIEW1,NULL);;}
    break;

  case 201:

    {add_command(cSTACKVIEW2,NULL);;}
    break;

  case 202:

    {add_command(cTEXTURL1, NULL);;}
    break;

  case 203:

    {add_command(cTEXTURL2, NULL);;}
    break;

  case 204:

    {add_command(cATTRIBUTE1, NULL);;}
    break;

  case 205:

    {add_command(cATTRIBUTECLEAR, NULL);;}
    break;

  case 206:

    {add_command(cPUTCHAR,NULL);;}
    break;

  case 207:

    {add_command(cCLEARSCR,NULL);;}
    break;

  case 208:

    {add_command(cWAIT,NULL);;}
    break;

  case 209:

    {add_command(cBELL,NULL);;}
    break;

  case 210:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL);;}
    break;

  case 211:

    {create_pushdbl(-1);create_function(fINKEY);add_command(cPOP,NULL);;}
    break;

  case 212:

    {create_function(fINKEY);add_command(cPOP,NULL);;}
    break;

  case 213:

    {create_function(fSYSTEM2);
	add_command(cPOP,NULL);;}
    break;

  case 214:

    {create_poke('s');;}
    break;

  case 215:

    {create_poke('d');;}
    break;

  case 216:

    {create_poke('S');;}
    break;

  case 217:

    {create_poke('D');;}
    break;

  case 218:

    {add_command(cEND,NULL);;}
    break;

  case 219:

    {create_pushdbl(0);add_command(cEXIT,NULL);;}
    break;

  case 220:

    {add_command(cEXIT,NULL);;}
    break;

  case 221:

    {create_docu((yyvsp[(1) - (1)].symbol));;}
    break;

  case 222:

    {add_command(cBIND,NULL);;}
    break;

  case 223:

    {add_command(cPOPSTRSYM,dotify((yyvsp[(1) - (3)].symbol),FALSE));;}
    break;

  case 224:

    {create_changestring(fMID);;}
    break;

  case 225:

    {create_changestring(fMID2);;}
    break;

  case 226:

    {create_changestring(fLEFT);;}
    break;

  case 227:

    {create_changestring(fRIGHT);;}
    break;

  case 228:

    {create_doarray(dotify((yyvsp[(1) - (3)].symbol),FALSE),ASSIGNSTRINGARRAY);;}
    break;

  case 231:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);;}
    break;

  case 232:

    {create_myopen(OPEN_HAS_STREAM);;}
    break;

  case 233:

    {add_command(cSWAP,NULL);create_pushstr("r");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);;}
    break;

  case 234:

    {add_command(cSWAP,NULL);create_pushstr("w");create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);;}
    break;

  case 235:

    {add_command(cSEEK,NULL);;}
    break;

  case 236:

    {add_command(cSEEK2,NULL);;}
    break;

  case 237:

    {add_command(cPUSHSTRPTR,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 238:

    {create_doarray(dotify((yyvsp[(1) - (4)].symbol),FALSE),GETSTRINGPOINTER);;}
    break;

  case 239:

    {add_command(cPUSHSTRSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 241:

    {add_command(cSTRINGFUNCTION_OR_ARRAY,(yyvsp[(1) - (1)].symbol));;}
    break;

  case 242:

    {if ((yyvsp[(1) - (1)].string)==NULL) {error(ERROR,"String not terminated");create_pushstr("");} else {create_pushstr((yyvsp[(1) - (1)].string));};}
    break;

  case 243:

    {add_command(cCONCAT,NULL);;}
    break;

  case 245:

    {create_function(fLEFT);;}
    break;

  case 246:

    {create_function(fRIGHT);;}
    break;

  case 247:

    {create_function(fMID);;}
    break;

  case 248:

    {create_function(fMID2);;}
    break;

  case 249:

    {create_function(fSTR);;}
    break;

  case 250:

    {create_function(fSTR2);;}
    break;

  case 251:

    {create_function(fSTR3);;}
    break;

  case 252:

    {create_pushdbl(-1);create_function(fINKEY);;}
    break;

  case 253:

    {create_pushdbl(-1);create_function(fINKEY);;}
    break;

  case 254:

    {create_function(fINKEY);;}
    break;

  case 255:

    {create_function(fCHR);;}
    break;

  case 256:

    {create_function(fUPPER);;}
    break;

  case 257:

    {create_function(fLOWER);;}
    break;

  case 258:

    {create_function(fLTRIM);;}
    break;

  case 259:

    {create_function(fRTRIM);;}
    break;

  case 260:

    {create_function(fTRIM);;}
    break;

  case 261:

    {create_function(fSYSTEM);;}
    break;

  case 262:

    {create_function(fDATE);;}
    break;

  case 263:

    {create_function(fDATE);;}
    break;

  case 264:

    {create_function(fTIME);;}
    break;

  case 265:

    {create_function(fTIME);;}
    break;

  case 266:

    {create_function(fPEEK2);;}
    break;

  case 267:

    {create_function(fPEEK3);;}
    break;

  case 268:

    {add_command(cTOKENALT2,NULL);;}
    break;

  case 269:

    {add_command(cTOKENALT,NULL);;}
    break;

  case 270:

    {add_command(cSPLITALT2,NULL);;}
    break;

  case 271:

    {add_command(cSPLITALT,NULL);;}
    break;

  case 272:

    {create_function(fGETCHAR);;}
    break;

  case 273:

    {create_function(fHEX);;}
    break;

  case 274:

    {create_function(fBIN);;}
    break;

  case 275:

    {create_execute(1);add_command(cSWAP,NULL);add_command(cPOP,NULL);;}
    break;

  case 276:

    {create_function(fMESSAGE);;}
    break;

  case 277:

    {create_function(fMESSAGE);;}
    break;

  case 278:

    {create_function(fMOUSEMOVE);;}
    break;

  case 279:

    {create_function(fMOUSEMOVE);;}
    break;

  case 280:

    {create_function(fTRANSLATE);;}
    break;

  case 281:

    {create_function(fMENUTRANSLATE);;}
    break;

  case 282:

    {create_function(fTEXTGET);;}
    break;

  case 283:

    {create_function(fTEXTGET3);;}
    break;

  case 284:

    {create_function(fTEXTGET6);;}
    break;

  case 285:

    {create_function(fTEXTCONTROLGET);;}
    break;

  case 286:

    {create_function(fLOAD);;}
    break;

  case 287:

    {create_function(fSAVE);;}
    break;

  case 288:

    {create_function(fMOUSE);;}
    break;

  case 289:

    {create_function(fKEYBOARD);;}
    break;

  case 290:

    {create_function(fCLIPBOARDPASTE);;}
    break;

  case 291:

    {create_function(fCOLUMNBOXGET);;}
    break;

  case 292:

    {create_function(fCALENDAR);;}
    break;

  case 293:

    {create_function(fLISTBOXGET);;}
    break;

  case 294:

    {create_function(fTREEBOXGET);;}
    break;

  case 295:

    {create_function(fPOPUPMENU);;}
    break;

  case 296:

    {create_function(fDROPBOXGET);;}
    break;

  case 297:

    {create_function(fDRAWGET3);;}
    break;

  case 298:

    {create_function(fATTRIBUTEGET1);;}
    break;

  case 299:

    {add_command(cPOPDBLSYM,dotify((yyvsp[(1) - (3)].symbol),FALSE));;}
    break;

  case 300:

    {create_doarray((yyvsp[(1) - (3)].symbol),ASSIGNARRAY);;}
    break;

  case 301:

    {add_command(cORSHORT,NULL);pushlabel();;}
    break;

  case 302:

    {poplabel();create_boole('|');;}
    break;

  case 303:

    {add_command(cANDSHORT,NULL);pushlabel();;}
    break;

  case 304:

    {poplabel();create_boole('&');;}
    break;

  case 305:

    {create_boole('!');;}
    break;

  case 306:

    {create_dblrelop('=');;}
    break;

  case 307:

    {create_dblrelop('!');;}
    break;

  case 308:

    {create_dblrelop('<');;}
    break;

  case 309:

    {create_dblrelop('{');;}
    break;

  case 310:

    {create_dblrelop('>');;}
    break;

  case 311:

    {create_dblrelop('}');;}
    break;

  case 312:

    {add_command(cTESTEOF,NULL);;}
    break;

  case 313:

    {add_command(cGLOB,NULL);;}
    break;

  case 314:

    {create_pushdbl((yyvsp[(1) - (1)].fnum));;}
    break;

  case 315:

    {add_command(cARDIM,"");;}
    break;

  case 316:

    {add_command(cARDIM,"");;}
    break;

  case 317:

    {add_command(cARSIZE,"");;}
    break;

  case 318:

    {add_command(cARSIZE,"");;}
    break;

  case 319:

    {add_command(cFUNCTION_OR_ARRAY,(yyvsp[(1) - (1)].symbol));;}
    break;

  case 320:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 321:

    {create_dblbin('+');;}
    break;

  case 322:

    {create_dblbin('-');;}
    break;

  case 323:

    {create_dblbin('*');;}
    break;

  case 324:

    {create_dblbin('/');;}
    break;

  case 325:

    {create_dblbin('^');;}
    break;

  case 326:

    {add_command(cNEGATE,NULL);;}
    break;

  case 327:

    {create_strrelop('=');;}
    break;

  case 328:

    {create_strrelop('!');;}
    break;

  case 329:

    {create_strrelop('<');;}
    break;

  case 330:

    {create_strrelop('{');;}
    break;

  case 331:

    {create_strrelop('>');;}
    break;

  case 332:

    {create_strrelop('}');;}
    break;

  case 335:

    {create_pusharrayref(dotify((yyvsp[(1) - (3)].symbol),FALSE),stNUMBERARRAYREF);;}
    break;

  case 336:

    {create_pusharrayref(dotify((yyvsp[(1) - (3)].symbol),FALSE),stSTRINGARRAYREF);;}
    break;

  case 338:

    {create_function(fSIN);;}
    break;

  case 339:

    {create_function(fASIN);;}
    break;

  case 340:

    {create_function(fCOS);;}
    break;

  case 341:

    {create_function(fACOS);;}
    break;

  case 342:

    {create_function(fTAN);;}
    break;

  case 343:

    {create_function(fATAN);;}
    break;

  case 344:

    {create_function(fATAN2);;}
    break;

  case 345:

    {create_function(fEXP);;}
    break;

  case 346:

    {create_function(fLOG);;}
    break;

  case 347:

    {create_function(fLOG2);;}
    break;

  case 348:

    {create_function(fSQRT);;}
    break;

  case 349:

    {create_function(fSQR);;}
    break;

  case 350:

    {create_function(fINT);;}
    break;

  case 351:

    {create_function(fFRAC);;}
    break;

  case 352:

    {create_function(fABS);;}
    break;

  case 353:

    {create_function(fSIG);;}
    break;

  case 354:

    {create_function(fMOD);;}
    break;

  case 355:

    {create_function(fRAN);;}
    break;

  case 356:

    {create_function(fRAN2);;}
    break;

  case 357:

    {create_function(fMIN);;}
    break;

  case 358:

    {create_function(fMAX);;}
    break;

  case 359:

    {create_function(fLEN);;}
    break;

  case 360:

    {create_function(fVAL);;}
    break;

  case 361:

    {create_function(fASC);;}
    break;

  case 362:

    {create_function(fDEC);;}
    break;

  case 363:

    {create_function(fDEC2);;}
    break;

  case 364:

    {if (check_compat) error(WARNING,"instr() has changed in version 2.712"); create_function(fINSTR);;}
    break;

  case 365:

    {create_function(fINSTR2);;}
    break;

  case 366:

    {create_function(fRINSTR);;}
    break;

  case 367:

    {create_function(fRINSTR2);;}
    break;

  case 368:

    {create_function(fSYSTEM2);;}
    break;

  case 369:

    {create_function(fPEEK4);;}
    break;

  case 370:

    {create_function(fPEEK);;}
    break;

  case 371:

    {create_function(fAND);;}
    break;

  case 372:

    {create_function(fOR);;}
    break;

  case 373:

    {create_function(fEOR);;}
    break;

  case 374:

    {create_function(fTELL);;}
    break;

  case 375:

    {add_command(cTOKEN2,NULL);;}
    break;

  case 376:

    {add_command(cTOKEN,NULL);;}
    break;

  case 377:

    {add_command(cSPLIT2,NULL);;}
    break;

  case 378:

    {add_command(cSPLIT,NULL);;}
    break;

  case 379:

    {create_execute(0);add_command(cSWAP,NULL);add_command(cPOP,NULL);;}
    break;

  case 380:

    {create_myopen(0);;}
    break;

  case 381:

    {create_myopen(OPEN_HAS_MODE);;}
    break;

  case 382:

    {create_myopen(OPEN_HAS_STREAM);;}
    break;

  case 383:

    {create_myopen(OPEN_HAS_STREAM+OPEN_HAS_MODE);;}
    break;

  case 384:

    {create_function(fDRAWIMAGE);;}
    break;

  case 385:

    {create_function(fDRAWIMAGE2);;}
    break;

  case 386:

    {create_function(fDRAWSVG);;}
    break;

  case 387:

    {create_function(fNUMWINDOWS);;}
    break;

  case 388:

    {create_function(fISMOUSEIN);;}
    break;

  case 389:

    {create_function(fCOLUMNBOXCOUNT);;}
    break;

  case 390:

    {create_function(fWINDOWGET);;}
    break;

  case 391:

    {create_function(fVIEWGET);;}
    break;

  case 392:

    {create_function(fALERT);;}
    break;

  case 393:

    {create_function(fLISTBOXCOUNT);;}
    break;

  case 394:

    {create_function(fTREEBOXCOUNT);;}
    break;

  case 395:

    {create_function(fSCROLLBARGET);;}
    break;

  case 396:

    {create_function(fSPLITVIEWGET);;}
    break;

  case 397:

    {create_function(fSTACKVIEWGET);;}
    break;

  case 398:

    {create_function(fTABVIEWGET);;}
    break;

  case 399:

    {create_function(fSPINCONTROLGET);;}
    break;

  case 400:

    {create_function(fDROPBOXCOUNT);;}
    break;

  case 401:

    {create_function(fSLIDERGET);;}
    break;

  case 402:

    {create_function(fCOLORCONTROLGET);;}
    break;

  case 403:

    {create_function(fTEXTGET2);;}
    break;

  case 404:

    {create_function(fTEXTGET4);;}
    break;

  case 405:

    {create_function(fTEXTGET5);;}
    break;

  case 406:

    {create_function(fDRAWGET1);;}
    break;

  case 407:

    {create_function(fDRAWGET2);;}
    break;

  case 408:

    {create_function(fDRAWGET4);;}
    break;

  case 409:

    {create_function(fMESSAGESEND);;}
    break;

  case 410:

    {create_function(fTHREADKILL);;}
    break;

  case 411:

    {create_function(fTHREADGET);;}
    break;

  case 412:

    {create_function(fPRINTER);;}
    break;

  case 413:

    {create_function(fSOUND);;}
    break;

  case 414:

    {create_function(fISCOMPUTERON);;}
    break;

  case 415:

    {create_function(fLISTBOXGETNUM);;}
    break;

  case 416:

    {create_function(fDROPBOXGETNUM);;}
    break;

  case 417:

    {create_function(fTREEBOXGETNUM);;}
    break;

  case 418:

    {create_function(fCOLUMNBOXGETNUM);;}
    break;

  case 419:

    {create_function(fTREEBOXGETOPT);;}
    break;

  case 420:

    {create_function(fBITMAPSAVE);;}
    break;

  case 421:

    {create_function(fBITMAPLOAD);;}
    break;

  case 422:

    {create_function(fBITMAPGET);;}
    break;

  case 423:

    {create_function(fBITMAPCOLOR);;}
    break;

  case 424:

    {create_function(fATTRIBUTEGET2);;}
    break;

  case 425:

    {(yyval.fnum)=(yyvsp[(1) - (1)].fnum);;}
    break;

  case 426:

    {(yyval.fnum)=(yyvsp[(2) - (2)].fnum);;}
    break;

  case 427:

    {(yyval.fnum)=-(yyvsp[(2) - (2)].fnum);;}
    break;

  case 428:

    {(yyval.fnum)=(yyvsp[(1) - (1)].fnum);;}
    break;

  case 429:

    {(yyval.fnum)=strtod((yyvsp[(1) - (1)].digits),NULL);;}
    break;

  case 430:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[(1) - (1)].digits),FALSE));;}
    break;

  case 431:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 432:

    {create_dim(dotify((yyvsp[(1) - (4)].symbol),FALSE),'D');;}
    break;

  case 433:

    {create_dim(dotify((yyvsp[(3) - (6)].symbol),FALSE),'D');;}
    break;

  case 434:

    {create_dim(dotify((yyvsp[(1) - (4)].symbol),FALSE),'S');;}
    break;

  case 435:

    {create_dim(dotify((yyvsp[(3) - (6)].symbol),FALSE),'S');;}
    break;

  case 436:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[(1) - (4)].symbol),FALSE));;}
    break;

  case 437:

    {(yyval.symbol)=my_strdup(dotify((yyvsp[(1) - (4)].symbol),FALSE));;}
    break;

  case 438:

    {add_command(cPUSHFREE,NULL);;}
    break;

  case 445:

    {missing_endsub++;missing_endsub_line=mylineno;pushlabel();report_missing(WARNING,"do not define a function in a loop or an if-statement");if (function_type!=ftNONE) {error(ERROR,"nested functions not allowed");YYABORT;};}
    break;

  case 446:

    {if (exported) create_sublink((yyvsp[(4) - (4)].symbol)); create_label((yyvsp[(4) - (4)].symbol),cUSER_FUNCTION);
	               add_command(cPUSHSYMLIST,NULL);add_command(cCLEARREFS,NULL);firstref=lastref=lastcmd;
		       create_numparam();;}
    break;

  case 447:

    {create_require(stFREE);add_command(cPOP,NULL);;}
    break;

  case 448:

    {add_command(cCLEARREFS,NULL);lastcmd->nextref=firstref;add_command(cPOPSYMLIST,NULL);create_retval(ftNONE,function_type);function_type=ftNONE;add_command(cRET_FROM_FUN,NULL);lastref=NULL;create_endfunction();poplabel();;}
    break;

  case 449:

    {if (missing_endsub) {sprintf(string,"%d end-sub(s) are missing (last at line %d)",missing_endsub,missing_endsub_line);error(ERROR,string);} YYABORT;;}
    break;

  case 450:

    {missing_endsub--;;}
    break;

  case 451:

    {function_type=ftNUMBER;current_function=my_strdup(dotify((yyvsp[(1) - (1)].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 452:

    {function_type=ftSTRING;current_function=my_strdup(dotify((yyvsp[(1) - (1)].symbol),FALSE));(yyval.symbol)=my_strdup(dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 453:

    {exported=FALSE;;}
    break;

  case 454:

    {exported=TRUE;;}
    break;

  case 455:

    {exported=FALSE;;}
    break;

  case 456:

    {exported=TRUE;;}
    break;

  case 459:

    {create_makelocal(dotify((yyvsp[(1) - (1)].symbol),FALSE),syNUMBER);;}
    break;

  case 460:

    {create_makelocal(dotify((yyvsp[(1) - (1)].symbol),FALSE),sySTRING);;}
    break;

  case 461:

    {create_makelocal(dotify((yyvsp[(1) - (4)].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[(1) - (4)].symbol),FALSE),'d');;}
    break;

  case 462:

    {create_makelocal(dotify((yyvsp[(1) - (4)].symbol),FALSE),syARRAY);create_dim(dotify((yyvsp[(1) - (4)].symbol),FALSE),'s');;}
    break;

  case 465:

    {create_makestatic(dotify((yyvsp[(1) - (1)].symbol),TRUE),syNUMBER);;}
    break;

  case 466:

    {create_makestatic(dotify((yyvsp[(1) - (1)].symbol),TRUE),sySTRING);;}
    break;

  case 467:

    {create_makestatic(dotify((yyvsp[(1) - (4)].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[(1) - (4)].symbol),TRUE),'D');;}
    break;

  case 468:

    {create_makestatic(dotify((yyvsp[(1) - (4)].symbol),TRUE),syARRAY);create_dim(dotify((yyvsp[(1) - (4)].symbol),TRUE),'S');;}
    break;

  case 472:

    {create_require(stNUMBER);create_makelocal(dotify((yyvsp[(1) - (1)].symbol),FALSE),syNUMBER);add_command(cPOPDBLSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 473:

    {create_require(stSTRING);create_makelocal(dotify((yyvsp[(1) - (1)].symbol),FALSE),sySTRING);add_command(cPOPSTRSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 474:

    {create_require(stNUMBERARRAYREF);create_arraylink(dotify((yyvsp[(1) - (3)].symbol),FALSE),stNUMBERARRAYREF);;}
    break;

  case 475:

    {create_require(stSTRINGARRAYREF);create_arraylink(dotify((yyvsp[(1) - (3)].symbol),FALSE),stSTRINGARRAYREF);;}
    break;

  case 476:

    {missing_next++;missing_next_line=mylineno;;}
    break;

  case 477:

    {pushname(dotify((yyvsp[(3) - (4)].symbol),FALSE)); /* will be used by next_symbol to check equality */
	     add_command(cRESETSKIPONCE,NULL);
	     pushgoto();add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);;}
    break;

  case 478:

    { /* pushes another expression */
	     add_command(cSKIPONCE,NULL);
	     pushlabel();
	     add_command(cSTARTFOR,NULL);
	     add_command(cPOPDBLSYM,dotify((yyvsp[(3) - (9)].symbol),FALSE));
	     poplabel();
	     add_command(cPUSHDBLSYM,dotify((yyvsp[(3) - (9)].symbol),FALSE));
	     add_command(cFORINCREMENT,NULL);
	     add_command(cPOPDBLSYM,dotify((yyvsp[(3) - (9)].symbol),FALSE));
	     add_command(cPUSHDBLSYM,dotify((yyvsp[(3) - (9)].symbol),FALSE));
	     add_command(cFORCHECK,NULL);
	     add_command(cDECIDE,NULL);
             pushlabel();;}
    break;

  case 479:

    {
             swap();popgoto();poplabel();;}
    break;

  case 480:

    {create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);;}
    break;

  case 481:

    {if (missing_next) {sprintf(string,"%d next(s) are missing (last at line %d)",missing_next,missing_next_line);error(ERROR,string);} YYABORT;;}
    break;

  case 482:

    {missing_next--;;}
    break;

  case 483:

    {create_pushdbl(1);;}
    break;

  case 485:

    {pop(stSTRING);;}
    break;

  case 486:

    {if (strcmp(pop(stSTRING)->pointer,dotify((yyvsp[(1) - (1)].symbol),FALSE))) 
             {error(ERROR,"'for' and 'next' do not match"); YYABORT;}
           ;}
    break;

  case 487:

    {push_switch_id();add_command(cPUSH_SWITCH_MARK,NULL);create_break_mark(0,1);
	add_command(cCONTINUE_CORRECTION,NULL);;}
    break;

  case 488:

    {create_break_mark(-1,0);add_command(cBREAK_HERE,NULL);create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);create_clean_switch_mark(0,FALSE);pop_switch_id();;}
    break;

  case 489:

    {if ((yyvsp[(1) - (1)].sep)>=0) mylineno+=(yyvsp[(1) - (1)].sep);;}
    break;

  case 490:

    {if ((yyvsp[(2) - (2)].sep)>=0) mylineno+=(yyvsp[(2) - (2)].sep);;}
    break;

  case 494:

    {create_break_mark(-1,0);add_command(cBREAK_HERE,NULL);;}
    break;

  case 495:

    {add_command(cSWITCH_COMPARE,NULL);add_command(cDECIDE,NULL);add_command(cMINOR_BREAK,NULL);create_break_mark(1,0);;}
    break;

  case 496:

    {add_command(cNEXT_CASE,NULL);;}
    break;

  case 498:

    {if ((yyvsp[(2) - (2)].sep)>=0) mylineno+=(yyvsp[(2) - (2)].sep); create_break_mark(-1,0);add_command(cBREAK_HERE,NULL);;}
    break;

  case 500:

    {add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);missing_loop++;missing_loop_line=mylineno;pushgoto();;}
    break;

  case 502:

    {if (missing_loop) {sprintf(string,"%d loop(s) are missing (last at line %d)",missing_loop,missing_loop_line);error(ERROR,string);} YYABORT;;}
    break;

  case 503:

    {missing_loop--;popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);;}
    break;

  case 504:

    {add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);missing_wend++;missing_wend_line=mylineno;pushgoto();}
    break;

  case 505:

    {add_command(cDECIDE,NULL);
	      pushlabel();;}
    break;

  case 507:

    {if (missing_wend) {sprintf(string,"%d wend(s) are missing (last at line %d)",missing_wend,missing_wend_line);error(ERROR,string);} YYABORT;;}
    break;

  case 508:

    {missing_wend--;swap();popgoto();poplabel();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);;}
    break;

  case 509:

    {add_command(cCONTINUE_HERE,NULL);create_break_mark(0,1);missing_until++;missing_until_line=mylineno;pushgoto();;}
    break;

  case 511:

    {if (missing_until) {sprintf(string,"%d until(s) are missing (last at line %d)",missing_until,missing_until_line);error(ERROR,string);} YYABORT;;}
    break;

  case 512:

    {missing_until--;add_command(cDECIDE,NULL);popgoto();create_break_mark(0,-1);add_command(cBREAK_HERE,NULL);;}
    break;

  case 513:

    {add_command(cDECIDE,NULL);storelabel();pushlabel();;}
    break;

  case 514:

    {missing_endif++;missing_endif_line=mylineno;;}
    break;

  case 515:

    {swap();matchgoto();swap();poplabel();;}
    break;

  case 516:

    {poplabel();;}
    break;

  case 518:

    {if (missing_endif) {sprintf(string,"%d endif(s) are missing (last at line %d)",missing_endif,missing_endif_line);error(ERROR,string);} YYABORT;;}
    break;

  case 519:

    {missing_endif--;;}
    break;

  case 520:

    {fi_pending++;add_command(cDECIDE,NULL);pushlabel();;}
    break;

  case 521:

    {poplabel();;}
    break;

  case 525:

    {add_command(cDECIDE,NULL);pushlabel();;}
    break;

  case 526:

    {swap();matchgoto();swap();poplabel();;}
    break;

  case 531:

    {add_command(cCHKPROMPT,NULL);;}
    break;

  case 533:

    {create_myread('d',tileol);add_command(cPOPDBLSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 534:

    {create_myread('d',tileol);create_doarray(dotify((yyvsp[(1) - (4)].symbol),FALSE),ASSIGNARRAY);;}
    break;

  case 535:

    {create_myread('s',tileol);add_command(cPOPSTRSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 536:

    {create_myread('s',tileol);create_doarray(dotify((yyvsp[(1) - (4)].symbol),FALSE),ASSIGNSTRINGARRAY);;}
    break;

  case 539:

    {create_readdata('d');add_command(cPOPDBLSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 540:

    {create_readdata('d');create_doarray(dotify((yyvsp[(1) - (4)].symbol),FALSE),ASSIGNARRAY);;}
    break;

  case 541:

    {create_readdata('s');add_command(cPOPSTRSYM,dotify((yyvsp[(1) - (1)].symbol),FALSE));;}
    break;

  case 542:

    {create_readdata('s');create_doarray(dotify((yyvsp[(1) - (4)].symbol),FALSE),ASSIGNSTRINGARRAY);;}
    break;

  case 543:

    {create_strdata((yyvsp[(1) - (1)].string));;}
    break;

  case 544:

    {create_dbldata((yyvsp[(1) - (1)].fnum));;}
    break;

  case 545:

    {create_strdata((yyvsp[(3) - (3)].string));;}
    break;

  case 546:

    {create_dbldata((yyvsp[(3) - (3)].fnum));;}
    break;

  case 550:

    {create_print('s');;}
    break;

  case 551:

    {create_print('s');;}
    break;

  case 552:

    {create_print('d');;}
    break;

  case 553:

    {create_print('u');;}
    break;

  case 554:

    {create_print('U');;}
    break;

  case 555:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[(2) - (2)].symbol),FALSE));create_pps(cPUSHSTREAM,1);;}
    break;

  case 556:

    {create_pps(cPOPSTREAM,0);;}
    break;

  case 557:

    {create_pushdbl(atoi((yyvsp[(2) - (2)].digits)));create_pps(cPUSHSTREAM,1);;}
    break;

  case 558:

    {create_pps(cPOPSTREAM,0);;}
    break;

  case 559:

    {create_pps(cPUSHSTREAM,1);;}
    break;

  case 560:

    {create_pps(cPOPSTREAM,0);;}
    break;

  case 561:

    {add_command(cMOVE,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);;}
    break;

  case 562:

    {create_pps(cPOPSTREAM,0);;}
    break;

  case 563:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,1);;}
    break;

  case 564:

    {create_pps(cPOPSTREAM,0);;}
    break;

  case 565:

    {create_pushstr("?");create_print('s');;}
    break;

  case 566:

    {create_pushstr((yyvsp[(1) - (1)].string));create_print('s');;}
    break;

  case 567:

    {create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 568:

    {add_command(cPUSHDBLSYM,dotify((yyvsp[(2) - (2)].symbol),FALSE));create_pps(cPUSHSTREAM,0);;}
    break;

  case 569:

    {create_pushdbl(atoi((yyvsp[(2) - (2)].digits)));create_pps(cPUSHSTREAM,0);;}
    break;

  case 570:

    {create_pps(cPUSHSTREAM,0);;}
    break;

  case 571:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 572:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 573:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 574:

    {add_command(cMOVE,NULL);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 575:

    {add_command(cMOVE,NULL);create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 576:

    {add_command(cMOVE,NULL);create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 577:

    {add_command(cMOVE,NULL);create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);;}
    break;

  case 578:

    {create_colour(1);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL);;}
    break;

  case 579:

    {create_colour(2);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL);;}
    break;

  case 580:

    {create_colour(3);create_pushdbl(STDIO_STREAM);create_pps(cPUSHSTREAM,0);add_command(cMOVE,NULL);;}
    break;

  case 583:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[(1) - (1)].symbol),TRUE):(yyvsp[(1) - (1)].symbol));add_command(cFINDNOP,NULL);;}
    break;

  case 584:

    {create_goto((function_type!=ftNONE)?dotify((yyvsp[(3) - (3)].symbol),TRUE):(yyvsp[(3) - (3)].symbol));add_command(cFINDNOP,NULL);;}
    break;

  case 585:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[(1) - (1)].symbol),TRUE):(yyvsp[(1) - (1)].symbol));add_command(cFINDNOP,NULL);;}
    break;

  case 586:

    {create_gosub((function_type!=ftNONE)?dotify((yyvsp[(3) - (3)].symbol),TRUE):(yyvsp[(3) - (3)].symbol));add_command(cFINDNOP,NULL);;}
    break;



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



