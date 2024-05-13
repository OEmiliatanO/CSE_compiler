/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "B103040012.y"

#include <stdio.h>
#include <string.h>
#include "symbol_table.h"
#include "parsing_type.h"
#include "expression_stack.h"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int yylex();
unsigned long _line = 1;
int var_declaration = 0;
int last_type = UD_TYPE;
int array_decl_rept = 0;
int dimension = 0;
char current_type[30];

const char * regular_type(const char* type)
{
    //"integer"|"double"|"string"|"float"|"real"|"single"|"byte"|"longint"|"word"|"longword"|"shortint"|"cardinal"|"object"
    if (strcmp(type, "integer") == 0 || strcmp(type, "i") == 0
        || strcmp(type, "byte") == 0
        || strcmp(type, "longint") == 0
        || strcmp(type, "word") == 0
        || strcmp(type, "shortint") == 0)
        return "i";
    if (strcmp(type, "float") == 0  || strcmp(type, "f") == 0
        || strcmp(type, "real") == 0 
        || strcmp(type, "single") == 0 
        || strcmp(type, "double") == 0)
        return "f";
    if (strcmp(type, "string") == 0 || strcmp(type, "s") == 0)
        return "s";
    if (strcmp(type, "char") == 0 || strcmp(type, "c") == 0)
        return "c";
    return type;
}

void yyerror(const char* message) {
    printf("\nLine %02lu: %s\nKeep processing: ", _line, message);
};

#line 120 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    PROGRAM = 258,
    FUNCTION = 259,
    PROCEDURE = 260,
    ARRAY = 261,
    IF = 262,
    THEN = 263,
    ELSE = 264,
    CASE = 265,
    OF = 266,
    END = 267,
    ASSIGN = 268,
    _BEGIN = 269,
    WHILE = 270,
    DO = 271,
    REPEAT = 272,
    UNTIL = 273,
    FOR = 274,
    TO = 275,
    DOWNTO = 276,
    BREAK = 277,
    CONTINUE = 278,
    VAR = 279,
    LOGICALNOT = 280,
    NEWLINE = 281,
    WITH = 282,
    WRITE = 283,
    WRITELN = 284,
    READ = 285,
    FLOAT = 286,
    INT = 287,
    STRING = 288,
    ID = 289,
    RELATIONAL_OP = 290,
    ADD_OP = 291,
    MUL_OP = 292,
    TYPE = 293,
    BUILTIN_FUNCTION = 294,
    COMMENT = 295,
    END_OF_FILE = 296
  };
#endif
/* Tokens.  */
#define PROGRAM 258
#define FUNCTION 259
#define PROCEDURE 260
#define ARRAY 261
#define IF 262
#define THEN 263
#define ELSE 264
#define CASE 265
#define OF 266
#define END 267
#define ASSIGN 268
#define _BEGIN 269
#define WHILE 270
#define DO 271
#define REPEAT 272
#define UNTIL 273
#define FOR 274
#define TO 275
#define DOWNTO 276
#define BREAK 277
#define CONTINUE 278
#define VAR 279
#define LOGICALNOT 280
#define NEWLINE 281
#define WITH 282
#define WRITE 283
#define WRITELN 284
#define READ 285
#define FLOAT 286
#define INT 287
#define STRING 288
#define ID 289
#define RELATIONAL_OP 290
#define ADD_OP 291
#define MUL_OP 292
#define TYPE 293
#define BUILTIN_FUNCTION 294
#define COMMENT 295
#define END_OF_FILE 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "B103040012.y"

    int 	intVal;
    char    charVal;
    float 	floatVal;
    char*   stringVal;

#line 261 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  134
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  308

#define YYUNDEFTOK  2
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,    44,     2,     2,    49,     2,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    42,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    67,    68,    68,    70,    70,    71,    71,
      73,    73,    74,    74,    75,    76,    78,    78,    77,    79,
      79,    84,    85,    85,    85,    86,    86,    86,    87,    87,
      88,    88,    89,    89,    90,    92,    94,    95,    91,   103,
     106,   107,   107,   108,   102,   116,   116,   116,   117,   117,
     135,   153,   153,   155,   155,   157,   157,   157,   159,   159,
     161,   161,   163,   163,   163,   165,   171,   174,   183,   187,
     193,   173,   194,   195,   195,   195,   198,   197,   202,   202,
     208,   209,   211,   212,   212,   228,   229,   229,   247,   248,
     248,   265,   266,   266,   267,   267,   278,   280,   281,   283,
     284,   285,   286,   308,   308,   342,   351,   352,   351,   361,
     361,   361,   386,   386,   386,   387,   389,   391,   391,   391,
     391,   392,   392,   392,   392,   394,   395,   395,   396,   396,
     396,   397,   398,   398,   398,   399,   399,   399,   401,   401,
     401,   401,   403,   403,   423,   444,   444,   444,   444,   446,
     446,   446,   446,   447,   447,   449,   449,   451,   451,   453,
     453,   453,   455,   455,   455,   457,   457,   457,   459,   459,
     461,   461,   461,   461,   461,   463,   463,   463,   463,   465,
     465,   465,   467,   469,   469,   469,   471,   472,   472,   472,
     473,   473,   473
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "FUNCTION", "PROCEDURE",
  "ARRAY", "IF", "THEN", "ELSE", "CASE", "OF", "END", "ASSIGN", "_BEGIN",
  "WHILE", "DO", "REPEAT", "UNTIL", "FOR", "TO", "DOWNTO", "BREAK",
  "CONTINUE", "VAR", "LOGICALNOT", "NEWLINE", "WITH", "WRITE", "WRITELN",
  "READ", "FLOAT", "INT", "STRING", "ID", "RELATIONAL_OP", "ADD_OP",
  "MUL_OP", "TYPE", "BUILTIN_FUNCTION", "COMMENT", "END_OF_FILE", "';'",
  "'('", "')'", "':'", "'.'", "'['", "']'", "','", "$accept", "program",
  "$@1", "$@2", "block", "block_", "procedure_function_decl_part",
  "procedure_or_function", "procedure_decl", "procedure_header", "$@3",
  "$@4", "procedure_header_common", "$@5", "formal_parameter_section_list",
  "formal_parameter_section_rept", "$@6", "formal_parameter_section",
  "$@7", "parameter_group", "$@8", "parameter_type", "return_type",
  "function_decl", "function_header", "$@9", "$@10", "$@11", "$@12",
  "$@13", "$@14", "$@15", "$@16", "var_decl_part", "$@17", "var_decl",
  "$@18", "var_decl_rept", "type", "simple_type", "scalar_type", "$@19",
  "subrange_type", "$@20", "const", "type_identifier", "structured_type",
  "array_type", "$@21", "$@22", "$@23", "$@24", "index_type",
  "index_type_rept", "$@25", "ID_list", "$@26", "ID_list_rept",
  "statement_part", "statement_part_", "expression", "$@27",
  "simple_expression", "$@28", "term", "$@29", "factor", "$@30", "$@31",
  "variable", "entire_variable", "indexed_variable", "$@32",
  "function_designator", "$@33", "$@34", "$@35", "$@36",
  "actual_parameter_list", "$@37", "actual_parameter", "EOSE",
  "if_statement", "$@38", "$@39", "else", "$@40", "case_statement",
  "case_list_rept", "case_list_element", "$@41", "case_label_list",
  "case_label_rept", "$@42", "case_label", "statement",
  "assignment_statement", "$@43", "structured_statement",
  "first_compound_statement", "$@44", "$@45", "$@46", "compound_statement",
  "$@47", "conditional_statement", "rept_statement", "reptive_statement",
  "while_stat", "$@48", "$@49", "rept_stat", "$@50", "$@51",
  "rept_rept_stat", "for_stat", "$@52", "$@53", "$@54", "$@55", "for_list",
  "$@56", "$@57", "with_statement", "$@58", "$@59", "variable_list",
  "variable_list_rept", "$@60", "procedure_statement", "$@61", "$@62",
  "$@63", "$@64", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,    59,    40,    41,    58,    46,    91,    93,    44
};
# endif

#define YYPACT_NINF (-210)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-191)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      42,    -2,    28,    52,    29,    37,  -210,  -210,  -210,    30,
      30,    71,  -210,    33,  -210,  -210,    84,    78,  -210,    66,
    -210,    64,   -14,  -210,    64,    84,    92,  -210,  -210,  -210,
      75,    96,  -210,    71,  -210,    33,  -210,  -210,  -210,  -210,
    -210,  -210,    11,   176,    98,   112,  -210,   144,   144,    -8,
    -210,   114,     8,  -210,    82,  -210,   142,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,   116,   117,    12,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,   121,
    -210,  -210,   123,   122,  -210,    92,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,   120,  -210,  -210,  -210,
       8,    18,   142,  -210,   135,   146,  -210,   188,    38,   159,
    -210,   153,  -210,   176,   142,   130,   167,   102,   162,   163,
     142,  -210,  -210,   114,     9,    -8,    92,  -210,   160,  -210,
     178,  -210,   174,    92,   179,  -210,    82,  -210,  -210,   214,
     142,   181,   183,   142,   -12,  -210,  -210,  -210,  -210,   211,
    -210,  -210,  -210,   153,   213,  -210,  -210,  -210,   142,   142,
     176,   218,  -210,  -210,  -210,   187,  -210,   190,  -210,     9,
    -210,  -210,   189,  -210,  -210,    82,  -210,  -210,  -210,  -210,
     191,  -210,  -210,  -210,   114,   192,  -210,   142,   142,   142,
       6,  -210,    -1,   221,   193,  -210,   142,   142,  -210,   195,
    -210,  -210,   194,  -210,  -210,    -8,  -210,  -210,  -210,   185,
    -210,   107,  -210,    82,   142,   142,  -210,   114,   226,  -210,
     196,   203,   159,  -210,  -210,    82,  -210,   130,  -210,  -210,
      82,  -210,  -210,  -210,  -210,   202,  -210,   204,  -210,  -210,
    -210,  -210,    18,  -210,  -210,  -210,  -210,   176,  -210,  -210,
     142,  -210,   142,   102,  -210,    17,    58,  -210,  -210,    74,
    -210,    61,    62,  -210,   -12,  -210,   108,   224,   153,  -210,
    -210,  -210,     9,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,   142,  -210,   230,   185,   142,   142,    82,  -210,   208,
    -210,  -210,  -210,  -210,  -210,  -210,     8,  -210
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     1,     4,     2,     0,
       0,    45,     5,    45,     3,    46,     0,     0,    19,     0,
      12,     0,     0,    13,     0,     0,     0,   149,     7,    80,
      35,     0,    11,    45,    14,    45,    15,    16,    34,     6,
      76,    51,     0,     0,     0,     0,    20,     0,     0,     0,
      78,     0,     0,    48,     0,   117,     0,   153,   162,   165,
     170,   179,   100,    99,   101,   102,   186,     0,    97,    98,
     155,   156,   157,   140,   139,   145,   146,   147,   159,   160,
     161,   148,   141,    36,    40,     9,    81,     8,    26,     0,
      22,    25,     0,    77,   116,    47,    67,    63,    62,    64,
      65,    58,    50,    53,    55,    56,     0,    57,    54,    66,
       0,     0,     0,    94,   102,   105,    92,     0,    82,    85,
      88,    91,    96,     0,     0,     0,     0,     0,     0,     0,
       0,   142,   103,   150,     0,     0,     0,    17,    21,    28,
       0,    52,     0,     0,     0,    49,     0,   122,   120,     0,
       0,     0,     0,     0,   128,    83,    86,    89,   157,     0,
     168,   171,   102,   183,     0,   191,   188,   144,     0,     0,
       0,     0,    37,    32,    33,     0,    27,     0,    23,     0,
      79,    68,     0,    60,   124,     0,   118,    95,   110,   107,
       0,   135,   136,   137,   126,     0,   132,     0,     0,     0,
       0,   163,     0,     0,   182,   180,     0,     0,   143,     0,
     158,   151,     0,    41,    18,     0,    29,    30,    31,     0,
      59,     0,   123,     0,     0,     0,    93,   126,     0,   129,
     131,    84,    87,    90,   154,     0,   166,     0,   172,   184,
       0,   115,   112,   112,   104,     0,    38,     0,    24,    72,
      73,    61,     0,   112,   112,   127,   125,     0,   133,   164,
       0,   169,     0,     0,   181,     0,     0,   152,    42,     0,
     119,     0,     0,   130,     0,   167,     0,     0,   185,   192,
     113,   189,     0,    69,    74,   111,   108,   134,   175,   177,
     173,     0,    43,     0,     0,     0,     0,     0,   114,     0,
      70,    75,   176,   178,   174,    44,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -210,  -210,  -210,  -210,   241,   228,    43,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,   118,  -210,  -210,    40,  -210,   124,
    -210,  -210,   -26,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,    20,  -210,   164,  -210,  -210,  -108,  -209,
    -210,  -210,  -210,  -210,    36,  -130,  -129,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,   -18,  -210,  -210,   233,   215,
     -49,  -210,    65,  -210,    63,  -210,  -141,  -210,  -210,   -43,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -167,  -210,
    -201,   -48,  -210,  -210,  -210,    13,  -210,  -210,    39,  -210,
    -210,  -210,  -210,  -210,   -10,   -53,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,   103,  -210,  -210,   109,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,  -210,
    -210,  -210,  -210,  -210
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,    10,     9,    12,    34,    13,    19,    20,    21,
      49,   177,    22,    31,    89,   138,   215,    90,   136,    91,
     179,   216,   172,    23,    24,    44,   134,   212,    45,   135,
     247,   282,   299,    16,    26,    41,   110,    51,   102,   103,
     104,   143,   105,   221,   106,   107,   108,   109,   142,   219,
     293,   306,   250,   269,   294,    92,    50,    93,    28,    85,
     241,   197,   118,   198,   119,   199,   120,   153,   150,   121,
      68,    69,   169,   122,   152,   225,   151,   224,   265,   291,
     242,   170,    70,   112,   223,   148,   185,    71,   228,   194,
     257,   195,   230,   274,   196,    72,    73,   168,    74,    29,
      43,   171,   245,    75,   123,    76,   133,    77,    78,   124,
     235,    79,   125,   260,   202,    80,   126,   203,   262,   297,
     277,   295,   296,    81,   127,   240,   164,   204,   263,    82,
     129,   207,   128,   206
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   111,   145,    95,   173,   174,   243,   117,    42,   187,
     249,    67,    52,   130,    96,    96,    88,   236,   234,   146,
     191,   192,   193,   253,   254,   131,    40,   147,    36,    37,
    -121,    11,     4,    25,   -10,   -10,  -121,    17,    18,    97,
      98,    94,    99,     1,   -10,     2,   100,   100,    94,   217,
     218,   101,     6,    47,   -10,    48,    53,    15,   233,   132,
    -121,   279,     5,   149,    35,    33,   280,    35,   -10,   -10,
     158,     7,   160,   155,   156,   159,   266,    42,   -10,     8,
      67,   167,    67,    54,   163,   301,   271,   272,   -10,    55,
     298,  -138,    56,   184,  -138,    15,    57,    58,    27,    59,
    -138,    60,   281,    67,   190,   285,   286,   280,    32,    61,
     280,   280,    30,    62,    63,    64,    65,   210,   -39,   208,
     209,    66,   283,   284,  -138,   182,    40,    67,   288,   289,
      46,    54,   222,    62,    63,    64,   162,    55,    97,    98,
      56,    99,    67,    83,    57,    58,   227,    59,  -138,    60,
      86,    86,   173,   174,   237,    84,    94,    61,    57,  -190,
    -187,    62,    63,    64,    65,   137,   144,   113,   139,    66,
     252,   140,  -138,    62,    63,    64,   114,    54,  -109,   227,
      67,   115,   259,    55,   261,   116,    56,   264,  -138,  -106,
      57,    58,    67,    59,    67,    60,   157,    67,   307,   154,
     132,   161,   178,    61,   273,   165,   166,    62,    63,    64,
      65,   275,   180,   276,    67,    66,    97,    98,  -138,    99,
     278,   181,   186,   100,   188,   183,   189,   201,   101,   205,
     211,   213,   214,   220,   238,   226,   246,   229,   256,   156,
     290,   300,   239,   244,   304,   258,   302,   303,   267,   268,
     305,    14,    38,   175,    67,   248,   292,   251,    39,   141,
     176,   232,   231,    87,   287,   270,   255,   200
};

static const yytype_int16 yycheck[] =
{
      43,    54,   110,    51,   134,   134,   207,    56,    26,   150,
     219,    54,     1,     1,     6,     6,    24,    18,    12,     1,
      32,    33,    34,   224,   225,    13,    34,     9,    42,    43,
      12,     1,    34,    13,     4,     5,    18,     4,     5,    31,
      32,    42,    34,     1,    14,     3,    38,    38,    42,   179,
     179,    43,     0,    33,    24,    35,    45,    24,   199,    47,
      42,    44,    34,   112,    21,     1,    49,    24,     4,     5,
     123,    42,   125,    35,    36,   124,   243,    95,    14,    42,
     123,   130,   125,     1,   127,   294,   253,   254,    24,     7,
     291,     9,    10,   146,    12,    24,    14,    15,    14,    17,
      18,    19,    44,   146,   153,    44,    44,    49,    42,    27,
      49,    49,    34,    31,    32,    33,    34,   170,    43,   168,
     169,    39,    48,    49,    42,   143,    34,   170,    20,    21,
      34,     1,   185,    31,    32,    33,    34,     7,    31,    32,
      10,    34,   185,    45,    14,    15,   194,    17,    18,    19,
      47,    48,   282,   282,   202,    43,    42,    27,    14,    43,
      43,    31,    32,    33,    34,    44,    46,    25,    45,    39,
     223,    49,    42,    31,    32,    33,    34,     1,    43,   227,
     223,    39,   235,     7,   237,    43,    10,   240,    12,    43,
      14,    15,   235,    17,   237,    19,    37,   240,   306,    11,
      47,    34,    42,    27,   257,    43,    43,    31,    32,    33,
      34,   260,    34,   262,   257,    39,    31,    32,    42,    34,
     263,    47,     8,    38,    43,    46,    43,    16,    43,    16,
      12,    44,    42,    44,    13,    44,    42,    45,    12,    36,
      16,    11,    49,    48,   297,    49,   295,   296,    46,    45,
      42,    10,    24,   135,   297,   215,   282,   221,    25,    95,
     136,   198,   197,    48,   274,   252,   227,   158
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    51,    34,    34,     0,    42,    42,    53,
      52,     1,    54,    56,    54,    24,    83,     4,     5,    57,
      58,    59,    62,    73,    74,    83,    84,    14,   108,   149,
      34,    63,    42,     1,    55,    56,    42,    43,    55,   108,
      34,    85,   105,   150,    75,    78,    34,    83,    83,    60,
     106,    87,     1,    45,     1,     7,    10,    14,    15,    17,
      19,    27,    31,    32,    33,    34,    39,   119,   120,   121,
     132,   137,   145,   146,   148,   153,   155,   157,   158,   161,
     165,   173,   179,    45,    43,   109,   153,   109,    24,    64,
      67,    69,   105,   107,    42,   131,     6,    31,    32,    34,
      38,    43,    88,    89,    90,    92,    94,    95,    96,    97,
      86,   145,   133,    25,    34,    39,    43,   110,   112,   114,
     116,   119,   123,   154,   159,   162,   166,   174,   182,   180,
       1,    13,    47,   156,    76,    79,    68,    44,    65,    45,
      49,    85,    98,    91,    46,    88,     1,     9,   135,   110,
     118,   126,   124,   117,    11,    35,    36,    37,   145,   110,
     145,    34,    34,   119,   176,    43,    43,   110,   147,   122,
     131,   151,    72,    95,    96,    64,    69,    61,    42,    70,
      34,    47,   105,    46,   145,   136,     8,   116,    43,    43,
     110,    32,    33,    34,   139,   141,   144,   111,   113,   115,
     156,    16,   164,   167,   177,    16,   183,   181,   110,   110,
     145,    12,    77,    44,    42,    66,    71,    95,    96,    99,
      44,    93,   145,   134,   127,   125,    44,   131,   138,    45,
     142,   112,   114,   116,    12,   160,    18,   131,    13,    49,
     175,   110,   130,   130,    48,   152,    42,    80,    67,    89,
     102,    94,   145,   130,   130,   138,    12,   140,    49,   145,
     163,   145,   168,   178,   145,   128,   128,    46,    45,   103,
     135,   128,   128,   145,   143,   110,   110,   170,   119,    44,
      49,    44,    81,    48,    49,    44,    44,   144,    20,    21,
      16,   129,    72,   100,   104,   171,   172,   169,   130,    82,
      11,    89,   110,   110,   145,    42,   101,    88
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    52,    51,    53,    51,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    59,    60,    61,    59,    63,
      62,    64,    65,    66,    65,    67,    68,    67,    70,    69,
      71,    71,    72,    72,    73,    75,    76,    77,    74,    78,
      79,    80,    81,    82,    74,    83,    84,    83,    86,    85,
      85,    87,    87,    88,    88,    89,    89,    89,    91,    90,
      93,    92,    94,    94,    94,    95,    96,    98,    99,   100,
     101,    97,   102,   103,   104,   103,   106,   105,   107,   107,
     108,   109,   110,   111,   110,   112,   113,   112,   114,   115,
     114,   116,   117,   116,   118,   116,   116,   119,   119,   120,
     120,   120,   120,   122,   121,   123,   124,   125,   123,   126,
     127,   123,   128,   129,   128,   130,   131,   133,   134,   132,
     132,   135,   136,   135,   135,   137,   138,   138,   139,   140,
     139,   141,   142,   143,   142,   144,   144,   144,   145,   145,
     145,   145,   147,   146,   146,   148,   148,   148,   148,   150,
     151,   152,   149,   154,   153,   155,   155,   156,   156,   157,
     157,   157,   159,   160,   158,   162,   163,   161,   164,   164,
     166,   167,   168,   169,   165,   171,   170,   172,   170,   174,
     175,   173,   176,   177,   178,   177,   179,   180,   181,   179,
     182,   183,   179
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     5,     0,     5,     3,     3,     3,     3,
       0,     3,     1,     1,     2,     2,     0,     0,     7,     0,
       3,     2,     0,     0,     4,     1,     0,     3,     0,     4,
       1,     1,     1,     1,     2,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    13,     0,     0,     5,     0,     4,
       3,     0,     3,     1,     1,     1,     1,     1,     0,     4,
       0,     5,     1,     1,     1,     1,     1,     0,     0,     0,
       0,    11,     1,     0,     0,     4,     0,     3,     0,     3,
       1,     1,     1,     0,     4,     1,     0,     4,     1,     0,
       4,     1,     0,     4,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     0,     5,     1,     0,     0,     7,     0,
       0,     7,     0,     0,     4,     1,     1,     0,     0,     7,
       3,     0,     0,     3,     2,     6,     0,     2,     0,     0,
       4,     2,     0,     0,     4,     1,     1,     1,     0,     1,
       1,     1,     0,     4,     3,     1,     1,     1,     1,     0,
       0,     0,     8,     0,     5,     1,     1,     0,     3,     1,
       1,     1,     0,     0,     6,     0,     0,     7,     0,     3,
       0,     0,     0,     0,    10,     0,     4,     0,     4,     0,
       0,     6,     2,     0,     0,     4,     1,     0,     0,     7,
       0,     0,     7
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
      yychar = yylex ();
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

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
#line 67 "B103040012.y"
                         { printf("Line %02lu: %s %s;", _line, "program", (yyvsp[-1].stringVal)); }
#line 1688 "y.tab.c"
    break;

  case 4:
#line 68 "B103040012.y"
                       { printf("%s;", (yyvsp[-1].stringVal)); }
#line 1694 "y.tab.c"
    break;

  case 11:
#line 73 "B103040012.y"
                                                                                       { printf(";"); }
#line 1700 "y.tab.c"
    break;

  case 15:
#line 76 "B103040012.y"
                                              { printf(";"); }
#line 1706 "y.tab.c"
    break;

  case 16:
#line 78 "B103040012.y"
                    { printf("("); }
#line 1712 "y.tab.c"
    break;

  case 17:
#line 78 "B103040012.y"
                                                                       { printf(")"); }
#line 1718 "y.tab.c"
    break;

  case 18:
#line 78 "B103040012.y"
                                                                                            { printf(";"); }
#line 1724 "y.tab.c"
    break;

  case 19:
#line 79 "B103040012.y"
                                   { printf("procedure "); }
#line 1730 "y.tab.c"
    break;

  case 20:
#line 80 "B103040012.y"
                        {
                            printf("%s", (yyvsp[0].stringVal));
                            insert((yyvsp[0].stringVal), "p");
                        }
#line 1739 "y.tab.c"
    break;

  case 23:
#line 85 "B103040012.y"
                                                                   { printf(";"); }
#line 1745 "y.tab.c"
    break;

  case 26:
#line 86 "B103040012.y"
                                                { printf("var "); }
#line 1751 "y.tab.c"
    break;

  case 28:
#line 87 "B103040012.y"
                             { printf(":"); }
#line 1757 "y.tab.c"
    break;

  case 29:
#line 87 "B103040012.y"
                                                             { memset(current_type, 0, sizeof(current_type)); }
#line 1763 "y.tab.c"
    break;

  case 35:
#line 92 "B103040012.y"
                {
                    printf("function %s", (yyvsp[0].stringVal));
                }
#line 1771 "y.tab.c"
    break;

  case 36:
#line 94 "B103040012.y"
                      { printf(":"); }
#line 1777 "y.tab.c"
    break;

  case 37:
#line 95 "B103040012.y"
                {
                    char func_type[100] = "n";
                    strcat(func_type, current_type);
                    insert((yyvsp[-4].stringVal), func_type);
                    memset(current_type, 0, sizeof(current_type));
                }
#line 1788 "y.tab.c"
    break;

  case 38:
#line 101 "B103040012.y"
                    { printf(";"); }
#line 1794 "y.tab.c"
    break;

  case 39:
#line 103 "B103040012.y"
                {
                    printf("function %s", (yyvsp[0].stringVal));
                }
#line 1802 "y.tab.c"
    break;

  case 40:
#line 106 "B103040012.y"
                    { printf("("); }
#line 1808 "y.tab.c"
    break;

  case 41:
#line 107 "B103040012.y"
                { printf(")"); }
#line 1814 "y.tab.c"
    break;

  case 42:
#line 107 "B103040012.y"
                                     { printf(":"); }
#line 1820 "y.tab.c"
    break;

  case 43:
#line 108 "B103040012.y"
                {
                    char func_type[100] = "n";
                    strcat(func_type, current_type);
                    insert((yyvsp[-9].stringVal), func_type);
                    memset(current_type, 0, sizeof(current_type));
                }
#line 1831 "y.tab.c"
    break;

  case 44:
#line 114 "B103040012.y"
                    { printf(";"); }
#line 1837 "y.tab.c"
    break;

  case 46:
#line 116 "B103040012.y"
                      { printf("%s", "var "); var_declaration = 1; }
#line 1843 "y.tab.c"
    break;

  case 47:
#line 116 "B103040012.y"
                                                                                                 { var_declaration = 0; }
#line 1849 "y.tab.c"
    break;

  case 48:
#line 117 "B103040012.y"
                       { printf(" : "); }
#line 1855 "y.tab.c"
    break;

  case 49:
#line 118 "B103040012.y"
         {
            while (!empty()) 
            { 
                char id[30]; 
                strcpy(id, top()); 
                if (exists(id))
                {
                    char buf[100];
                    sprintf(buf, "%sERROR%s: Duplicate identifier %s", KRED, KWHT, id);
                    yyerror(buf);
                }
                else
                    insert(id, current_type);
                pop(); 
            }
            memset(current_type, 0, sizeof(current_type));
         }
#line 1877 "y.tab.c"
    break;

  case 50:
#line 136 "B103040012.y"
         {
            while (!empty()) 
            {
                char id[30]; 
                strcpy(id, top()); 
                if (exists(id))
                {
                    char buf[100];
                    sprintf(buf, "%sERROR%s: Duplicate identifier %s", KRED, KWHT, id);
                    yyerror(buf);
                }
                else
                    insert(id, current_type);
                pop(); 
            }
            memset(current_type, 0, sizeof(current_type));
         }
#line 1899 "y.tab.c"
    break;

  case 58:
#line 159 "B103040012.y"
                  { printf("("); }
#line 1905 "y.tab.c"
    break;

  case 59:
#line 159 "B103040012.y"
                                              { printf(")"); }
#line 1911 "y.tab.c"
    break;

  case 60:
#line 161 "B103040012.y"
                              { printf(".."); }
#line 1917 "y.tab.c"
    break;

  case 62:
#line 163 "B103040012.y"
            { printf("%d", (yyvsp[0].intVal)); }
#line 1923 "y.tab.c"
    break;

  case 63:
#line 163 "B103040012.y"
                                          { printf("%f", (yyvsp[0].floatVal)); }
#line 1929 "y.tab.c"
    break;

  case 64:
#line 163 "B103040012.y"
                                                                     { printf("%s", (yyvsp[0].stringVal)); }
#line 1935 "y.tab.c"
    break;

  case 65:
#line 166 "B103040012.y"
                { 
                    printf("%s", (yyvsp[0].stringVal));
                    strcat(current_type, regular_type((yyvsp[0].stringVal)));
                }
#line 1944 "y.tab.c"
    break;

  case 67:
#line 174 "B103040012.y"
            { 
                printf("array"); 
                dimension = 0;
                if (current_type[0] == 'a')
                    sscanf(current_type+1, "%d", &dimension);
                else
                    strcat(current_type, "a"); 
            }
#line 1957 "y.tab.c"
    break;

  case 68:
#line 183 "B103040012.y"
            { 
                printf("[");
            }
#line 1965 "y.tab.c"
    break;

  case 69:
#line 187 "B103040012.y"
            {
                printf("]"); 
                char buf[2];
                sprintf(buf, "%d", dimension);
                strcpy(current_type+1, buf);
                dimension = 0; 
            }
#line 1977 "y.tab.c"
    break;

  case 70:
#line 193 "B103040012.y"
                 { printf(" of "); }
#line 1983 "y.tab.c"
    break;

  case 72:
#line 194 "B103040012.y"
                         { ++dimension; }
#line 1989 "y.tab.c"
    break;

  case 74:
#line 195 "B103040012.y"
                                        { printf(","); ++dimension; }
#line 1995 "y.tab.c"
    break;

  case 76:
#line 198 "B103040012.y"
        { 
            printf("%s", (yyvsp[0].stringVal)); 
            if (var_declaration) push((yyvsp[0].stringVal));
        }
#line 2004 "y.tab.c"
    break;

  case 79:
#line 203 "B103040012.y"
             {
                printf(", %s", (yyvsp[0].stringVal));
                if (var_declaration) push((yyvsp[0].stringVal));
             }
#line 2013 "y.tab.c"
    break;

  case 83:
#line 212 "B103040012.y"
                                             { printf(" %s ", (yyvsp[0].stringVal)); }
#line 2019 "y.tab.c"
    break;

  case 84:
#line 213 "B103040012.y"
           {
                node_t b = exp_top(); exp_pop();
                node_t a = exp_top(); exp_pop();
                if ((strcmp(a.type, "i") != 0 && strcmp(a.type, "f") != 0) 
                 || (strcmp(b.type, "i") != 0 && strcmp(b.type, "f") != 0))
                    if (!(strcmp(a.type, "s") == 0 && strcmp(b.type, "s") == 0)
                     || !(strcmp(a.type, "c") == 0 && strcmp(b.type, "c") == 0))
                    {
                        char buf[100];
                        sprintf(buf, "%sERROR%s: %s and %s type cannot use '%s' operation.", KRED, KWHT, cpretty(a.type), cpretty(b.type), (yyvsp[-2].stringVal));
                        yyerror(buf);
                    }
                exp_push(KIND_NUM, "i");
           }
#line 2038 "y.tab.c"
    break;

  case 86:
#line 229 "B103040012.y"
                                             { printf(" %s ", (yyvsp[0].stringVal)); }
#line 2044 "y.tab.c"
    break;

  case 87:
#line 230 "B103040012.y"
                  {
                    node_t b = exp_top(); exp_pop();
                    node_t a = exp_top(); exp_pop();
                    if ((strcmp(a.type, "i") != 0 && strcmp(a.type, "f") != 0)
                     || (strcmp(b.type, "i") != 0 && strcmp(b.type, "f") != 0))
                    {
                        char buf[100];
                        sprintf(buf, "%sERROR%s: %s and %s type cannot use '%s' operation.", KRED, KWHT, cpretty(a.type), cpretty(b.type), (yyvsp[-2].stringVal));
                        yyerror(buf);
                        exp_push(KIND_NUM, "i");
                    }
                    else if (strcmp(a.type, "f") == 0 || strcmp(b.type, "f") == 0)
                        exp_push(KIND_NUM, "f");
                    else
                        exp_push(KIND_NUM, "i");
                  }
#line 2065 "y.tab.c"
    break;

  case 89:
#line 248 "B103040012.y"
                   { printf(" %s ", (yyvsp[0].stringVal)); }
#line 2071 "y.tab.c"
    break;

  case 90:
#line 249 "B103040012.y"
     {
        node_t b = exp_top(); exp_pop();
        node_t a = exp_top(); exp_pop();
        if ((strcmp(a.type, "i") != 0 && strcmp(a.type, "f") != 0)
         || (strcmp(b.type, "i") != 0 && strcmp(b.type, "f") != 0))
        {
            char buf[100];
            sprintf(buf, "%sERROR%s: %s and %s type cannot use '%s' operation.", KRED, KWHT, cpretty(a.type), cpretty(b.type), (yyvsp[-2].stringVal));
            yyerror(buf);
        }
        else if (strcmp(a.type, "f") == 0 || strcmp(b.type, "f") == 0)
            exp_push(KIND_NUM, "f");
        else
            exp_push(KIND_NUM, "i");
     }
#line 2091 "y.tab.c"
    break;

  case 92:
#line 266 "B103040012.y"
             { printf(" ( "); }
#line 2097 "y.tab.c"
    break;

  case 93:
#line 266 "B103040012.y"
                                               { printf(" ) "); }
#line 2103 "y.tab.c"
    break;

  case 94:
#line 267 "B103040012.y"
                    { printf(" not "); }
#line 2109 "y.tab.c"
    break;

  case 95:
#line 268 "B103040012.y"
        { 
            node_t a = exp_top(); exp_pop();
            if (strcmp(a.type, "i") != 0)
            {
                char buf[100];
                sprintf(buf, "%sERROR%s: %s cannot be NOTed.", KRED, KWHT, cpretty(a.type));
                yyerror(buf);
            }
            exp_push(KIND_NUM, a.type);
        }
#line 2124 "y.tab.c"
    break;

  case 99:
#line 283 "B103040012.y"
                      { printf("%d", (yyvsp[0].intVal)); exp_push(KIND_NUM, "i"); }
#line 2130 "y.tab.c"
    break;

  case 100:
#line 284 "B103040012.y"
                        { printf("%f", (yyvsp[0].floatVal)); exp_push(KIND_NUM, "f"); }
#line 2136 "y.tab.c"
    break;

  case 101:
#line 285 "B103040012.y"
                         { printf("%s", (yyvsp[0].stringVal)); exp_push(KIND_NUM, "s"); }
#line 2142 "y.tab.c"
    break;

  case 102:
#line 287 "B103040012.y"
                {
                    if (exists((yyvsp[0].stringVal)) == 0)
                    {
                        char buf[100];
                        sprintf(buf, "%sERROR%s: %s was not declared in this scope.", KRED, KWHT, (yyvsp[0].stringVal));
                        yyerror(buf);
                        exp_push(KIND_NUM, "i");
                    }
                    else
                    {
                        const char* _type = lookup_type((yyvsp[0].stringVal));
                        printf("%s", (yyvsp[0].stringVal));
                        if (_type[0] == 'n' && strlen(_type) > 1)
                            exp_push(KIND_NUM, _type+1);
                        else
                        {
                            exp_push(KIND_NUM, lookup_type((yyvsp[0].stringVal)));
                        }
                    }
                }
#line 2167 "y.tab.c"
    break;

  case 103:
#line 308 "B103040012.y"
                                { printf("["); }
#line 2173 "y.tab.c"
    break;

  case 104:
#line 309 "B103040012.y"
                 {
                    printf("]");

                    node_t index = exp_top(); exp_pop();
                    node_t array = exp_top(); exp_pop();

                    if (array.type[0] != 'a')
                    {
                        char buf[100];
                        sprintf(buf, "%sERROR%s: Only array type can be indexed.", KRED, KWHT);
                        yyerror(buf);
                    }
                    else
                    {
                        sscanf(array.type+1, "%d", &dimension);
                        --dimension;
                        if (dimension == 0)
                            sprintf(array.type, "%c", array.type[strlen(array.type)-1]);
                        else
                            sprintf(array.type, "a%d%c", dimension, array.type[strlen(array.type)-1]);
                    }

                    if (strcmp(index.type, "i") != 0)
                    {
                        char buf[100];
                        sprintf(buf, "%sERROR%s: The index of array is not integer.", KRED, KWHT);
                        yyerror(buf);
                    }

                    dimension = 0;
                    exp_push(KIND_NUM, array.type);
                 }
#line 2210 "y.tab.c"
    break;

  case 105:
#line 343 "B103040012.y"
                    {
                        printf("%s", (yyvsp[0].stringVal));

                        if (strcmp((yyvsp[0].stringVal), "concat") == 0)
                            exp_push(KIND_NUM, "s");
                        else
                            exp_push(KIND_NUM, "n");
                    }
#line 2223 "y.tab.c"
    break;

  case 106:
#line 351 "B103040012.y"
                                       { printf("%s", (yyvsp[0].stringVal)); }
#line 2229 "y.tab.c"
    break;

  case 107:
#line 352 "B103040012.y"
                        { printf("("); }
#line 2235 "y.tab.c"
    break;

  case 108:
#line 353 "B103040012.y"
                    {
                        printf(")");

                        if (strcmp((yyvsp[-6].stringVal), "concat") == 0)
                            exp_push(KIND_NUM, "s");
                        else
                            exp_push(KIND_NUM, "n");
                    }
#line 2248 "y.tab.c"
    break;

  case 109:
#line 361 "B103040012.y"
                         { printf("%s", (yyvsp[0].stringVal)); }
#line 2254 "y.tab.c"
    break;

  case 110:
#line 361 "B103040012.y"
                                                   { printf("("); }
#line 2260 "y.tab.c"
    break;

  case 111:
#line 362 "B103040012.y"
                    {
                        printf(")");

                        if (exists((yyvsp[-6].stringVal)) == 0)
                        {
                            char buf[100];
                            sprintf(buf, "%sERROR%s: Function %s was not declared in this scope.", KRED, KWHT, (yyvsp[-6].stringVal));
                            yyerror(buf);
                        }
                        else if (lookup_type((yyvsp[-6].stringVal))[0] != 'n')
                        {
                            char buf[100];
                            sprintf(buf, "%sERROR%s: %s type is not callable.", KRED, KWHT, cpretty(lookup_type((yyvsp[-6].stringVal))));
                            yyerror(buf);
                        }
                        else
                        {
                            const char* _type = lookup_type((yyvsp[-6].stringVal));
                            if (strlen(_type) <= 1)
                                exp_push(KIND_NUM, "n");
                            else
                                exp_push(KIND_NUM, _type+1);
                        }
                    }
#line 2289 "y.tab.c"
    break;

  case 113:
#line 386 "B103040012.y"
                                                    { printf(", "); }
#line 2295 "y.tab.c"
    break;

  case 116:
#line 389 "B103040012.y"
           { printf(";"); }
#line 2301 "y.tab.c"
    break;

  case 117:
#line 391 "B103040012.y"
                  { printf("if "); }
#line 2307 "y.tab.c"
    break;

  case 118:
#line 391 "B103040012.y"
                                                     { printf(" then "); }
#line 2313 "y.tab.c"
    break;

  case 122:
#line 392 "B103040012.y"
             { printf("else "); }
#line 2319 "y.tab.c"
    break;

  case 129:
#line 396 "B103040012.y"
                                          { printf(":"); }
#line 2325 "y.tab.c"
    break;

  case 133:
#line 398 "B103040012.y"
                                        { printf(","); }
#line 2331 "y.tab.c"
    break;

  case 137:
#line 399 "B103040012.y"
                               { printf("%s", (yyvsp[0].stringVal)); }
#line 2337 "y.tab.c"
    break;

  case 142:
#line 403 "B103040012.y"
                                       { printf(" := "); }
#line 2343 "y.tab.c"
    break;

  case 143:
#line 404 "B103040012.y"
                     {
                        node_t expr = exp_top(); exp_pop();
                        node_t var  = exp_top(); exp_pop();
                        if (var.type[0] != expr.type[0])
                        {
                            if (var.type[0] == 'i' && expr.type[0] == 'f')
                            {
                                char buf[100];
                                sprintf(buf, "%sWARNING%s: Narrowing conversion form float to int.", KRED, KWHT);
                                yyerror(buf);
                            }
                            else
                            {
                                char buf[100];
                                sprintf(buf, "%sERROR%s: Cannot convert %s to %s.", KRED, KWHT, cpretty(expr.type), cpretty(var.type));
                                yyerror(buf);
                            }
                        }
                     }
#line 2367 "y.tab.c"
    break;

  case 144:
#line 424 "B103040012.y"
                     {
                        node_t expr = exp_top(); exp_pop();
                        node_t var  = exp_top(); exp_pop();
                        if (var.type[0] != expr.type[0])
                        {
                            if (var.type[0] == 'i' && expr.type[0] == 'f')
                            {
                                char buf[100];
                                sprintf(buf, "%sWARNING%s: Narrowing conversion form float to int.", KRED, KWHT);
                                yyerror(buf);
                            }
                            else
                            {
                                char buf[100];
                                sprintf(buf, "%sERROR%s: Cannot convert %s to %s.", KRED, KWHT, cpretty(expr.type), cpretty(var.type));
                                yyerror(buf);
                            }
                        }
                     }
#line 2391 "y.tab.c"
    break;

  case 149:
#line 446 "B103040012.y"
                                  { printf("begin"); }
#line 2397 "y.tab.c"
    break;

  case 150:
#line 446 "B103040012.y"
                                                                                { }
#line 2403 "y.tab.c"
    break;

  case 151:
#line 446 "B103040012.y"
                                                                                        { printf("end"); }
#line 2409 "y.tab.c"
    break;

  case 152:
#line 446 "B103040012.y"
                                                                                                               { printf("."); }
#line 2415 "y.tab.c"
    break;

  case 153:
#line 447 "B103040012.y"
                            { printf("begin"); }
#line 2421 "y.tab.c"
    break;

  case 154:
#line 447 "B103040012.y"
                                                                              { printf("end"); }
#line 2427 "y.tab.c"
    break;

  case 162:
#line 455 "B103040012.y"
                   { printf(" while "); }
#line 2433 "y.tab.c"
    break;

  case 163:
#line 455 "B103040012.y"
                                                        { printf(" do "); }
#line 2439 "y.tab.c"
    break;

  case 165:
#line 457 "B103040012.y"
                   { printf(" repeat "); }
#line 2445 "y.tab.c"
    break;

  case 166:
#line 457 "B103040012.y"
                                                                          { printf(" until "); }
#line 2451 "y.tab.c"
    break;

  case 170:
#line 461 "B103040012.y"
               { printf("for "); }
#line 2457 "y.tab.c"
    break;

  case 171:
#line 461 "B103040012.y"
                                      { printf("%s", (yyvsp[0].stringVal)); }
#line 2463 "y.tab.c"
    break;

  case 172:
#line 461 "B103040012.y"
                                                                   { printf(" := "); }
#line 2469 "y.tab.c"
    break;

  case 173:
#line 461 "B103040012.y"
                                                                                                   { printf(" do "); }
#line 2475 "y.tab.c"
    break;

  case 175:
#line 463 "B103040012.y"
                         { printf(" to "); }
#line 2481 "y.tab.c"
    break;

  case 177:
#line 463 "B103040012.y"
                                                                            { printf(" downto "); }
#line 2487 "y.tab.c"
    break;

  case 179:
#line 465 "B103040012.y"
                      { printf("with"); }
#line 2493 "y.tab.c"
    break;

  case 180:
#line 465 "B103040012.y"
                                                           { printf("do"); }
#line 2499 "y.tab.c"
    break;

  case 184:
#line 469 "B103040012.y"
                                              { printf(", "); }
#line 2505 "y.tab.c"
    break;

  case 186:
#line 471 "B103040012.y"
                                       { printf("%s", (yyvsp[0].stringVal)); }
#line 2511 "y.tab.c"
    break;

  case 187:
#line 472 "B103040012.y"
                                       { printf("%s", (yyvsp[0].stringVal)); }
#line 2517 "y.tab.c"
    break;

  case 188:
#line 472 "B103040012.y"
                                                                 { printf("("); }
#line 2523 "y.tab.c"
    break;

  case 189:
#line 472 "B103040012.y"
                                                                                                                             { printf(")"); }
#line 2529 "y.tab.c"
    break;

  case 190:
#line 473 "B103040012.y"
                         { printf("%s", (yyvsp[0].stringVal)); }
#line 2535 "y.tab.c"
    break;

  case 191:
#line 473 "B103040012.y"
                                                   { printf("("); }
#line 2541 "y.tab.c"
    break;

  case 192:
#line 474 "B103040012.y"
                    {
                        printf(")");

                        if (exists((yyvsp[-6].stringVal)) == 0)
                        {
                            char buf[100];
                            sprintf(buf, "%sERROR%s: Function %s was not declared in this scope.", KRED, KWHT, (yyvsp[-6].stringVal));
                            yyerror(buf);
                        }
                        else if (lookup_type((yyvsp[-6].stringVal))[0] != 'n')
                        {
                            char buf[100];
                            sprintf(buf, "%sERROR%s: %s type is not callable.", KRED, KWHT, cpretty(lookup_type((yyvsp[-6].stringVal))));
                            yyerror(buf);
                        }
                    }
#line 2562 "y.tab.c"
    break;


#line 2566 "y.tab.c"

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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
  return yyresult;
}
#line 491 "B103040012.y"

int main() {
    yyparse();
    printf("\n");
    show_symbol_table();
    return 0;
}
