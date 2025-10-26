/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "codegen.h"

extern int yylex(void);
extern int yylineno;
extern FILE *yyin;
void yyerror(const char *s);

void push_scope();
void pop_scope();

int semantic_errors = 0;

#line 89 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LET = 3,                        /* LET  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_FOR = 7,                        /* FOR  */
  YYSYMBOL_IN = 8,                         /* IN  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_REPEAT = 10,                    /* REPEAT  */
  YYSYMBOL_FUNC = 11,                      /* FUNC  */
  YYSYMBOL_STRUCT = 12,                    /* STRUCT  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_PRINT = 14,                     /* PRINT  */
  YYSYMBOL_SWITCH = 15,                    /* SWITCH  */
  YYSYMBOL_CASE = 16,                      /* CASE  */
  YYSYMBOL_DEFAULT = 17,                   /* DEFAULT  */
  YYSYMBOL_BOOLEAN_LITERAL = 18,           /* BOOLEAN_LITERAL  */
  YYSYMBOL_INT_LITERAL = 19,               /* INT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 20,            /* DOUBLE_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 21,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 22,         /* CHARACTER_LITERAL  */
  YYSYMBOL_IDENTIFIER = 23,                /* IDENTIFIER  */
  YYSYMBOL_TYPE = 24,                      /* TYPE  */
  YYSYMBOL_PLUS = 25,                      /* PLUS  */
  YYSYMBOL_MINUS = 26,                     /* MINUS  */
  YYSYMBOL_MUL = 27,                       /* MUL  */
  YYSYMBOL_DIV = 28,                       /* DIV  */
  YYSYMBOL_MOD = 29,                       /* MOD  */
  YYSYMBOL_EQ = 30,                        /* EQ  */
  YYSYMBOL_NEQ = 31,                       /* NEQ  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_GT = 33,                        /* GT  */
  YYSYMBOL_LE = 34,                        /* LE  */
  YYSYMBOL_GE = 35,                        /* GE  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_OR = 37,                        /* OR  */
  YYSYMBOL_NOT = 38,                       /* NOT  */
  YYSYMBOL_ASSIGN = 39,                    /* ASSIGN  */
  YYSYMBOL_ARROW = 40,                     /* ARROW  */
  YYSYMBOL_LOWER_THAN_ELSE = 41,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_42_ = 42,                       /* '.'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* ';'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ':'  */
  YYSYMBOL_49_ = 49,                       /* '{'  */
  YYSYMBOL_50_ = 50,                       /* '}'  */
  YYSYMBOL_51_ = 51,                       /* ','  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_stmts = 54,                     /* stmts  */
  YYSYMBOL_stmt = 55,                      /* stmt  */
  YYSYMBOL_type_specifier = 56,            /* type_specifier  */
  YYSYMBOL_decl = 57,                      /* decl  */
  YYSYMBOL_assign = 58,                    /* assign  */
  YYSYMBOL_func = 59,                      /* func  */
  YYSYMBOL_60_1 = 60,                      /* $@1  */
  YYSYMBOL_param_list_opt = 61,            /* param_list_opt  */
  YYSYMBOL_param_list = 62,                /* param_list  */
  YYSYMBOL_param = 63,                     /* param  */
  YYSYMBOL_struct_decl = 64,               /* struct_decl  */
  YYSYMBOL_65_2 = 65,                      /* $@2  */
  YYSYMBOL_ifstmt = 66,                    /* ifstmt  */
  YYSYMBOL_whilestmt = 67,                 /* whilestmt  */
  YYSYMBOL_forstmt = 68,                   /* forstmt  */
  YYSYMBOL_69_3 = 69,                      /* $@3  */
  YYSYMBOL_switchstmt = 70,                /* switchstmt  */
  YYSYMBOL_case_list = 71,                 /* case_list  */
  YYSYMBOL_case_stmt = 72,                 /* case_stmt  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_arg_list_opt = 74,              /* arg_list_opt  */
  YYSYMBOL_arg_list = 75,                  /* arg_list  */
  YYSYMBOL_arg = 76,                       /* arg  */
  YYSYMBOL_expr_list_opt = 77,             /* expr_list_opt  */
  YYSYMBOL_expr_list = 78                  /* expr_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   775

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  188

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      46,    47,     2,     2,    51,     2,    42,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    48,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
       0,    52,    52,    82,    83,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   101,   102,   103,   111,
     121,   131,   144,   155,   166,   166,   176,   177,   181,   182,
     186,   193,   193,   203,   206,   212,   215,   221,   221,   229,
     235,   236,   240,   243,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     272,   273,   274,   275,   276,   277,   278,   279,   280,   284,
     285,   289,   290,   294,   295,   299,   300,   304,   305
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "LET", "VAR", "IF",
  "ELSE", "FOR", "IN", "WHILE", "REPEAT", "FUNC", "STRUCT", "RETURN",
  "PRINT", "SWITCH", "CASE", "DEFAULT", "BOOLEAN_LITERAL", "INT_LITERAL",
  "DOUBLE_LITERAL", "STRING_LITERAL", "CHARACTER_LITERAL", "IDENTIFIER",
  "TYPE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "EQ", "NEQ", "LT", "GT",
  "LE", "GE", "AND", "OR", "NOT", "ASSIGN", "ARROW", "LOWER_THAN_ELSE",
  "'.'", "'['", "']'", "';'", "'('", "')'", "':'", "'{'", "'}'", "','",
  "$accept", "program", "stmts", "stmt", "type_specifier", "decl",
  "assign", "func", "$@1", "param_list_opt", "param_list", "param",
  "struct_decl", "$@2", "ifstmt", "whilestmt", "forstmt", "$@3",
  "switchstmt", "case_list", "case_stmt", "expr", "arg_list_opt",
  "arg_list", "arg", "expr_list_opt", "expr_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-70)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -70,     4,   454,   -70,    -4,     0,   -21,    32,    -9,     8,
      35,    37,    -5,    15,    -5,   -70,   -70,   -70,   -70,   -70,
      36,    -5,    -5,    -5,   -70,   -70,   -70,   -70,   -70,   -70,
     -70,   -70,   -70,   145,    26,   -27,    -5,    55,    -5,   -70,
      30,    28,    34,   189,    -5,   453,    -5,    -5,    46,   -14,
     682,    44,    39,   527,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    58,    -5,   -70,
     -16,    -5,   -16,   550,    -5,   573,   146,    64,   -70,   -70,
     596,    14,   233,   642,   -26,   682,    47,    40,   -70,   -70,
      -5,   -70,    43,    43,   -14,   -14,   -14,   732,   732,    70,
      70,    70,    70,   720,   701,   -70,   662,   -70,   -70,   -16,
      54,   277,    62,    56,   478,    57,    94,    59,    61,    53,
     -70,   -70,    69,    -5,    67,   -11,   -70,   -70,    77,    -5,
     -70,    46,   682,   -70,    65,    -5,   -70,    -5,   -70,   -70,
     -70,    72,   -16,    81,    64,   190,   -70,   503,   -70,   -70,
     -70,    -5,   682,   -70,   -70,   321,   365,   234,   -70,   278,
      -5,   -70,    98,   -70,   -70,   -70,   454,   409,   -70,   -70,
     118,   322,   -70,   619,    79,   454,   -70,    80,   -70,    85,
     -70,   -70,   -70,   -70,   366,   410,   -70,   -70
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     2,     1,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    63,    60,    61,    62,    64,
      59,     0,    75,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,     0,     0,     0,     0,     0,     0,     3,
       0,     0,    59,     0,     0,     0,     0,     0,    69,    57,
      77,     0,    76,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,     0,     0,     0,     0,    26,    31,    13,
       0,     0,     0,     0,    59,    73,     0,    70,    71,    68,
       0,    58,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    65,     0,    17,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
      28,     3,     0,     0,     0,     0,    40,    22,     0,     0,
      67,     0,    78,    66,     0,     0,    21,     0,     3,    37,
       3,     0,     0,     0,     0,     0,    14,     0,     3,    39,
      41,     0,    74,    72,    18,     0,     0,     0,     3,     0,
       0,    30,     0,    29,    32,     3,    43,     0,    19,    20,
      33,     0,    35,     0,     0,    42,    23,     0,    38,     0,
      24,     3,    36,     3,     0,     0,    34,    25
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -70,   -70,   -38,   -70,   -69,   -70,   -70,   -70,   -70,   -70,
     -70,   -18,   -70,   -70,   -70,   -70,   -70,   -70,   -70,   -70,
       6,   -12,   -70,   -70,     1,   -70,   -70
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    24,   110,    25,    26,    27,   183,   118,
     119,   120,    28,   121,    29,    30,    31,   158,    32,   125,
     126,    33,    86,    87,    88,    51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      43,    76,    45,   112,     3,   123,   124,   107,   108,    49,
      50,    53,    71,    15,    16,    17,    18,    19,    42,    34,
      48,    72,   129,    35,    73,    36,    75,   109,    67,    68,
     123,   124,    80,    21,    82,    83,    85,    38,    22,   149,
     134,    23,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,    37,   106,    39,    40,   111,
      41,    44,   114,    74,    15,    16,    17,    18,    19,    84,
      56,    57,    58,   161,    70,    46,    77,    78,   132,    47,
      48,   105,    48,   145,    21,    67,    68,   117,    89,    22,
      90,   131,    23,   135,   130,    54,    55,    56,    57,    58,
     157,   137,   159,   141,   144,   138,   140,   142,   143,   154,
     166,   147,    67,    68,   146,   148,   151,   152,   160,    85,
     171,   162,   174,   155,   177,   156,   163,   175,   180,   181,
     182,   150,   153,     0,     0,     0,     0,     0,     0,   167,
       0,     0,     0,   184,     0,   185,     0,     0,   173,     4,
       5,     6,     0,     7,     0,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    15,    16,    17,    18,    19,    20,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    21,     0,     0,    67,    68,    22,
      69,     0,    23,     4,     5,     6,   116,     7,     0,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    15,    16,
      17,    18,    19,    20,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    21,     0,
       0,    67,    68,    22,    79,     0,    23,     4,     5,     6,
     164,     7,     0,     8,     9,    10,    11,    12,    13,    14,
       0,     0,    15,    16,    17,    18,    19,    20,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    21,     0,     0,    67,    68,    22,   127,     0,
      23,     4,     5,     6,   170,     7,     0,     8,     9,    10,
      11,    12,    13,    14,     0,     0,    15,    16,    17,    18,
      19,    20,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,    21,     0,     0,    67,
      68,    22,   136,     0,    23,     4,     5,     6,   172,     7,
       0,     8,     9,    10,    11,    12,    13,    14,     0,     0,
      15,    16,    17,    18,    19,    20,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     0,
      21,     0,     0,    67,    68,    22,   168,     0,    23,     4,
       5,     6,   178,     7,     0,     8,     9,    10,    11,    12,
      13,    14,     0,     0,    15,    16,    17,    18,    19,    20,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,     0,    21,     0,     0,    67,    68,    22,
     169,     0,    23,     4,     5,     6,   186,     7,     0,     8,
       9,    10,    11,    12,    13,    14,     0,     0,    15,    16,
      17,    18,    19,    20,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,    21,     0,
       0,    67,    68,    22,   176,     0,    23,     4,     5,     6,
     187,     7,     0,     8,     9,    10,    11,    12,    13,    14,
       0,     0,    15,    16,    17,    18,    19,    20,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,    21,     0,     0,    67,    68,    22,     0,     0,
      23,     0,    81,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
      67,    68,     0,     0,     0,     0,     0,   139,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,    67,    68,     0,     0,     0,
       0,   165,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     0,     0,     0,     0,    67,
      68,     0,     0,     0,    91,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,     0,     0,
       0,     0,    67,    68,     0,     0,     0,   113,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,     0,     0,     0,     0,    67,    68,     0,     0,     0,
     115,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,     0,     0,     0,     0,    67,    68,
       0,     0,     0,   122,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,     0,     0,     0,
       0,    67,    68,     0,     0,     0,   179,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,     0,    67,    68,   128,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,     0,    67,    68,   133,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
       0,     0,     0,     0,    67,    68,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,     0,     0,    67,    68,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,     0,    54,    55,    56,
      57,    58,    67,    68,    61,    62,    63,    64,     0,     0,
       0,     0,     0,     0,    67,    68
};

static const yytype_int16 yycheck[] =
{
      12,    39,    14,    72,     0,    16,    17,    23,    24,    21,
      22,    23,    39,    18,    19,    20,    21,    22,    23,    23,
      46,    48,    48,    23,    36,    46,    38,    43,    42,    43,
      16,    17,    44,    38,    46,    47,    48,    46,    43,    50,
     109,    46,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    23,    68,    49,    23,    71,
      23,    46,    74,     8,    18,    19,    20,    21,    22,    23,
      27,    28,    29,   142,    48,    39,    46,    49,    90,    43,
      46,    23,    46,   121,    38,    42,    43,    23,    44,    43,
      51,    51,    46,    39,    47,    25,    26,    27,    28,    29,
     138,    39,   140,     9,    51,    49,    49,    48,    47,    44,
     148,   123,    42,    43,    45,    48,    39,   129,    46,   131,
     158,    40,    24,   135,     6,   137,   144,   165,    49,    49,
      45,   125,   131,    -1,    -1,    -1,    -1,    -1,    -1,   151,
      -1,    -1,    -1,   181,    -1,   183,    -1,    -1,   160,     3,
       4,     5,    -1,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    38,    -1,    -1,    42,    43,    43,
      45,    -1,    46,     3,     4,     5,    50,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    38,    -1,
      -1,    42,    43,    43,    45,    -1,    46,     3,     4,     5,
      50,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    38,    -1,    -1,    42,    43,    43,    45,    -1,
      46,     3,     4,     5,    50,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    18,    19,    20,    21,
      22,    23,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    38,    -1,    -1,    42,
      43,    43,    45,    -1,    46,     3,     4,     5,    50,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    -1,    -1,
      18,    19,    20,    21,    22,    23,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    -1,
      38,    -1,    -1,    42,    43,    43,    45,    -1,    46,     3,
       4,     5,    50,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    -1,    -1,    18,    19,    20,    21,    22,    23,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    38,    -1,    -1,    42,    43,    43,
      45,    -1,    46,     3,     4,     5,    50,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    -1,    -1,    18,    19,
      20,    21,    22,    23,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    38,    -1,
      -1,    42,    43,    43,    45,    -1,    46,     3,     4,     5,
      50,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      -1,    -1,    18,    19,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    38,    -1,    -1,    42,    43,    43,    -1,    -1,
      46,    -1,    49,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,
      42,    43,    -1,    -1,    -1,    -1,    -1,    49,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      -1,    48,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,
      43,    -1,    -1,    -1,    47,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    42,    43,    -1,    -1,    -1,    47,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    -1,    -1,    -1,    -1,    42,    43,    -1,    -1,    -1,
      47,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    42,    43,
      -1,    -1,    -1,    47,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    -1,    -1,    -1,
      -1,    42,    43,    -1,    -1,    -1,    47,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    44,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    42,    43,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      -1,    -1,    -1,    42,    43,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    -1,    25,    26,    27,
      28,    29,    42,    43,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    53,    54,     0,     3,     4,     5,     7,     9,    10,
      11,    12,    13,    14,    15,    18,    19,    20,    21,    22,
      23,    38,    43,    46,    55,    57,    58,    59,    64,    66,
      67,    68,    70,    73,    23,    23,    46,    23,    46,    49,
      23,    23,    23,    73,    46,    73,    39,    43,    46,    73,
      73,    77,    78,    73,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    42,    43,    45,
      48,    39,    48,    73,     8,    73,    54,    46,    49,    45,
      73,    49,    73,    73,    23,    73,    74,    75,    76,    44,
      51,    47,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    23,    73,    23,    24,    43,
      56,    73,    56,    47,    73,    47,    50,    23,    61,    62,
      63,    65,    47,    16,    17,    71,    72,    45,    44,    48,
      47,    51,    73,    44,    56,    39,    45,    39,    49,    49,
      49,     9,    48,    47,    51,    54,    45,    73,    48,    50,
      72,    39,    73,    76,    44,    73,    73,    54,    69,    54,
      46,    56,    40,    63,    50,    48,    54,    73,    45,    45,
      50,    54,    50,    73,    24,    54,    45,     6,    50,    47,
      49,    49,    45,    60,    54,    54,    50,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    57,
      57,    57,    58,    58,    60,    59,    61,    61,    62,    62,
      63,    65,    64,    66,    66,    67,    67,    69,    68,    70,
      71,    71,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     5,     2,     1,     1,     3,     7,
       7,     5,     4,     7,     0,    11,     0,     1,     1,     3,
       3,     0,     6,     7,    11,     7,     9,     0,     8,     5,
       1,     2,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     3,     0,
       1,     1,     3,     1,     3,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* program: stmts  */
#line 52 "parser.y"
          { 
        (yyval.node) = (yyvsp[0].node); 
        printf("\n=== PARSING COMPLETE ===\n");
        printf("Abstract Syntax Tree built successfully\n");
        
        if (semantic_errors == 0) {
            printf("\n=== SEMANTIC ANALYSIS ===\n");
            printf("Checking variable declarations...\n");
            printf("Checking type compatibility...\n");
            printf("Checking constant assignments...\n");
            printf("Status: PASSED\n");
            
            printf("\n=== SYMBOL TABLE ===\n");
            print_symbol_table();
            
            printf("\n=== CODE GENERATION ===\n");
            printf("Generating intermediate code...\n");
            printf("Translating to C...\n");
            generate_code((yyval.node));
            printf("Status: COMPLETE\n");
            printf("\n=== THREE ADDRESS CODE ===\n");
            print_three_address_code();
        } else {
            printf("\n=== SEMANTIC ANALYSIS ===\n");
            printf("Status: FAILED with %d error(s)\n", semantic_errors);
        }
    }
#line 1413 "parser.tab.c"
    break;

  case 3: /* stmts: %empty  */
#line 82 "parser.y"
    { (yyval.node) = NULL; }
#line 1419 "parser.tab.c"
    break;

  case 4: /* stmts: stmts stmt  */
#line 83 "parser.y"
                 { (yyval.node) = create_stmt_list((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1425 "parser.tab.c"
    break;

  case 5: /* stmt: decl  */
#line 87 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1431 "parser.tab.c"
    break;

  case 6: /* stmt: assign  */
#line 88 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1437 "parser.tab.c"
    break;

  case 7: /* stmt: func  */
#line 89 "parser.y"
           { (yyval.node) = (yyvsp[0].node); }
#line 1443 "parser.tab.c"
    break;

  case 8: /* stmt: struct_decl  */
#line 90 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1449 "parser.tab.c"
    break;

  case 9: /* stmt: ifstmt  */
#line 91 "parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1455 "parser.tab.c"
    break;

  case 10: /* stmt: whilestmt  */
#line 92 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1461 "parser.tab.c"
    break;

  case 11: /* stmt: forstmt  */
#line 93 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1467 "parser.tab.c"
    break;

  case 12: /* stmt: switchstmt  */
#line 94 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1473 "parser.tab.c"
    break;

  case 13: /* stmt: RETURN expr ';'  */
#line 95 "parser.y"
                      { (yyval.node) = create_return_node((yyvsp[-1].node)); }
#line 1479 "parser.tab.c"
    break;

  case 14: /* stmt: PRINT '(' expr ')' ';'  */
#line 96 "parser.y"
                             { (yyval.node) = create_print_node((yyvsp[-2].node)); }
#line 1485 "parser.tab.c"
    break;

  case 15: /* stmt: expr ';'  */
#line 97 "parser.y"
               { (yyval.node) = (yyvsp[-1].node); }
#line 1491 "parser.tab.c"
    break;

  case 16: /* type_specifier: TYPE  */
#line 101 "parser.y"
         { (yyval.str) = (yyvsp[0].str); }
#line 1497 "parser.tab.c"
    break;

  case 17: /* type_specifier: IDENTIFIER  */
#line 102 "parser.y"
                 { (yyval.str) = (yyvsp[0].str); }
#line 1503 "parser.tab.c"
    break;

  case 18: /* type_specifier: '[' type_specifier ']'  */
#line 103 "parser.y"
                             { 
        char *arr_type = malloc(strlen((yyvsp[-1].str)) + 10);
        sprintf(arr_type, "[%s]", (yyvsp[-1].str));
        (yyval.str) = arr_type;
    }
#line 1513 "parser.tab.c"
    break;

  case 19: /* decl: LET IDENTIFIER ':' type_specifier ASSIGN expr ';'  */
#line 111 "parser.y"
                                                      {
        Symbol *sym = lookup_symbol((yyvsp[-5].str));
        if (sym != NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' already declared\n", yylineno, (yyvsp[-5].str));
            semantic_errors++;
        } else {
            insert_symbol((yyvsp[-5].str), (yyvsp[-3].str), 1);
        }
        (yyval.node) = create_decl_node((yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].node), 1);
    }
#line 1528 "parser.tab.c"
    break;

  case 20: /* decl: VAR IDENTIFIER ':' type_specifier ASSIGN expr ';'  */
#line 121 "parser.y"
                                                        {
        Symbol *sym = lookup_symbol((yyvsp[-5].str));
        if (sym != NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' already declared\n", yylineno, (yyvsp[-5].str));
            semantic_errors++;
        } else {
            insert_symbol((yyvsp[-5].str), (yyvsp[-3].str), 0);
        }
        (yyval.node) = create_decl_node((yyvsp[-5].str), (yyvsp[-3].str), (yyvsp[-1].node), 0);
    }
#line 1543 "parser.tab.c"
    break;

  case 21: /* decl: VAR IDENTIFIER ASSIGN expr ';'  */
#line 131 "parser.y"
                                     {
        Symbol *sym = lookup_symbol((yyvsp[-3].str));
        if (sym != NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' already declared\n", yylineno, (yyvsp[-3].str));
            semantic_errors++;
        } else {
            insert_symbol((yyvsp[-3].str), "Int", 0);
        }
        (yyval.node) = create_decl_node((yyvsp[-3].str), "Int", (yyvsp[-1].node), 0);
    }
#line 1558 "parser.tab.c"
    break;

  case 22: /* assign: IDENTIFIER ASSIGN expr ';'  */
#line 144 "parser.y"
                               {
        Symbol *sym = lookup_symbol((yyvsp[-3].str));
        if (sym == NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' not declared\n", yylineno, (yyvsp[-3].str));
            semantic_errors++;
        } else if (sym->is_const) {
            fprintf(stderr, "Error line %d: Cannot assign to constant '%s'\n", yylineno, (yyvsp[-3].str));
            semantic_errors++;
        }
        (yyval.node) = create_assign_node((yyvsp[-3].str), (yyvsp[-1].node));
    }
#line 1574 "parser.tab.c"
    break;

  case 23: /* assign: IDENTIFIER '[' expr ']' ASSIGN expr ';'  */
#line 155 "parser.y"
                                              {
        Symbol *sym = lookup_symbol((yyvsp[-6].str));
        if (sym == NULL) {
            fprintf(stderr, "Error line %d: Array '%s' not declared\n", yylineno, (yyvsp[-6].str));
            semantic_errors++;
        }
        (yyval.node) = create_array_assign_node((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1587 "parser.tab.c"
    break;

  case 24: /* $@1: %empty  */
#line 166 "parser.y"
                                                          {
        insert_function((yyvsp[-6].str), (yyvsp[-1].str));
        push_scope();
    }
#line 1596 "parser.tab.c"
    break;

  case 25: /* func: FUNC IDENTIFIER '(' param_list_opt ')' ARROW TYPE '{' $@1 stmts '}'  */
#line 169 "parser.y"
                {
        pop_scope();
        (yyval.node) = create_func_node((yyvsp[-9].str), (yyvsp[-7].node), (yyvsp[-4].str), (yyvsp[-1].node));
    }
#line 1605 "parser.tab.c"
    break;

  case 26: /* param_list_opt: %empty  */
#line 176 "parser.y"
    { (yyval.node) = NULL; }
#line 1611 "parser.tab.c"
    break;

  case 27: /* param_list_opt: param_list  */
#line 177 "parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1617 "parser.tab.c"
    break;

  case 28: /* param_list: param  */
#line 181 "parser.y"
          { (yyval.node) = (yyvsp[0].node); }
#line 1623 "parser.tab.c"
    break;

  case 29: /* param_list: param_list ',' param  */
#line 182 "parser.y"
                           { (yyval.node) = create_param_list((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1629 "parser.tab.c"
    break;

  case 30: /* param: IDENTIFIER ':' type_specifier  */
#line 186 "parser.y"
                                  {
        insert_symbol((yyvsp[-2].str), (yyvsp[0].str), 0);
        (yyval.node) = create_param_node((yyvsp[-2].str), (yyvsp[0].str));
    }
#line 1638 "parser.tab.c"
    break;

  case 31: /* $@2: %empty  */
#line 193 "parser.y"
                          {
        insert_struct((yyvsp[-1].str));
        push_scope();
    }
#line 1647 "parser.tab.c"
    break;

  case 32: /* struct_decl: STRUCT IDENTIFIER '{' $@2 stmts '}'  */
#line 196 "parser.y"
                {
        pop_scope();
        (yyval.node) = create_struct_node((yyvsp[-4].str), (yyvsp[-1].node));
    }
#line 1656 "parser.tab.c"
    break;

  case 33: /* ifstmt: IF '(' expr ')' '{' stmts '}'  */
#line 203 "parser.y"
                                                        {
        (yyval.node) = create_if_node((yyvsp[-4].node), (yyvsp[-1].node), NULL);
    }
#line 1664 "parser.tab.c"
    break;

  case 34: /* ifstmt: IF '(' expr ')' '{' stmts '}' ELSE '{' stmts '}'  */
#line 206 "parser.y"
                                                       {
        (yyval.node) = create_if_node((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
    }
#line 1672 "parser.tab.c"
    break;

  case 35: /* whilestmt: WHILE '(' expr ')' '{' stmts '}'  */
#line 212 "parser.y"
                                     {
        (yyval.node) = create_while_node((yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1680 "parser.tab.c"
    break;

  case 36: /* whilestmt: REPEAT '{' stmts '}' WHILE '(' expr ')' ';'  */
#line 215 "parser.y"
                                                  {
        (yyval.node) = create_repeat_while_node((yyvsp[-6].node), (yyvsp[-2].node));
    }
#line 1688 "parser.tab.c"
    break;

  case 37: /* $@3: %empty  */
#line 221 "parser.y"
                               {
        insert_symbol((yyvsp[-3].str), "Int", 0);
    }
#line 1696 "parser.tab.c"
    break;

  case 38: /* forstmt: FOR IDENTIFIER IN expr '{' $@3 stmts '}'  */
#line 223 "parser.y"
                {
        (yyval.node) = create_for_node((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-1].node));
    }
#line 1704 "parser.tab.c"
    break;

  case 39: /* switchstmt: SWITCH expr '{' case_list '}'  */
#line 229 "parser.y"
                                  {
        (yyval.node) = create_switch_node((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 1712 "parser.tab.c"
    break;

  case 40: /* case_list: case_stmt  */
#line 235 "parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1718 "parser.tab.c"
    break;

  case 41: /* case_list: case_list case_stmt  */
#line 236 "parser.y"
                          { (yyval.node) = create_case_list((yyvsp[-1].node), (yyvsp[0].node)); }
#line 1724 "parser.tab.c"
    break;

  case 42: /* case_stmt: CASE expr ':' stmts  */
#line 240 "parser.y"
                        {
        (yyval.node) = create_case_node((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 1732 "parser.tab.c"
    break;

  case 43: /* case_stmt: DEFAULT ':' stmts  */
#line 243 "parser.y"
                        {
        (yyval.node) = create_default_node((yyvsp[0].node));
    }
#line 1740 "parser.tab.c"
    break;

  case 44: /* expr: expr PLUS expr  */
#line 249 "parser.y"
                   { (yyval.node) = create_binop_node("+", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1746 "parser.tab.c"
    break;

  case 45: /* expr: expr MINUS expr  */
#line 250 "parser.y"
                      { (yyval.node) = create_binop_node("-", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1752 "parser.tab.c"
    break;

  case 46: /* expr: expr MUL expr  */
#line 251 "parser.y"
                    { (yyval.node) = create_binop_node("*", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1758 "parser.tab.c"
    break;

  case 47: /* expr: expr DIV expr  */
#line 252 "parser.y"
                    { (yyval.node) = create_binop_node("/", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1764 "parser.tab.c"
    break;

  case 48: /* expr: expr MOD expr  */
#line 253 "parser.y"
                    { (yyval.node) = create_binop_node("%", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1770 "parser.tab.c"
    break;

  case 49: /* expr: expr EQ expr  */
#line 254 "parser.y"
                   { (yyval.node) = create_binop_node("==", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1776 "parser.tab.c"
    break;

  case 50: /* expr: expr NEQ expr  */
#line 255 "parser.y"
                    { (yyval.node) = create_binop_node("!=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1782 "parser.tab.c"
    break;

  case 51: /* expr: expr LT expr  */
#line 256 "parser.y"
                   { (yyval.node) = create_binop_node("<", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1788 "parser.tab.c"
    break;

  case 52: /* expr: expr GT expr  */
#line 257 "parser.y"
                   { (yyval.node) = create_binop_node(">", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1794 "parser.tab.c"
    break;

  case 53: /* expr: expr LE expr  */
#line 258 "parser.y"
                   { (yyval.node) = create_binop_node("<=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1800 "parser.tab.c"
    break;

  case 54: /* expr: expr GE expr  */
#line 259 "parser.y"
                   { (yyval.node) = create_binop_node(">=", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1806 "parser.tab.c"
    break;

  case 55: /* expr: expr AND expr  */
#line 260 "parser.y"
                    { (yyval.node) = create_binop_node("&&", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1812 "parser.tab.c"
    break;

  case 56: /* expr: expr OR expr  */
#line 261 "parser.y"
                   { (yyval.node) = create_binop_node("||", (yyvsp[-2].node), (yyvsp[0].node)); }
#line 1818 "parser.tab.c"
    break;

  case 57: /* expr: NOT expr  */
#line 262 "parser.y"
               { (yyval.node) = create_unop_node("!", (yyvsp[0].node)); }
#line 1824 "parser.tab.c"
    break;

  case 58: /* expr: '(' expr ')'  */
#line 263 "parser.y"
                   { (yyval.node) = (yyvsp[-1].node); }
#line 1830 "parser.tab.c"
    break;

  case 59: /* expr: IDENTIFIER  */
#line 264 "parser.y"
                 {
        Symbol *sym = lookup_symbol((yyvsp[0].str));
        if (sym == NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' not declared\n", yylineno, (yyvsp[0].str));
            semantic_errors++;
        }
        (yyval.node) = create_id_node((yyvsp[0].str));
    }
#line 1843 "parser.tab.c"
    break;

  case 60: /* expr: INT_LITERAL  */
#line 272 "parser.y"
                  { (yyval.node) = create_int_node((yyvsp[0].ival)); }
#line 1849 "parser.tab.c"
    break;

  case 61: /* expr: DOUBLE_LITERAL  */
#line 273 "parser.y"
                     { (yyval.node) = create_double_node((yyvsp[0].fval)); }
#line 1855 "parser.tab.c"
    break;

  case 62: /* expr: STRING_LITERAL  */
#line 274 "parser.y"
                     { (yyval.node) = create_string_node((yyvsp[0].str)); }
#line 1861 "parser.tab.c"
    break;

  case 63: /* expr: BOOLEAN_LITERAL  */
#line 275 "parser.y"
                      { (yyval.node) = create_bool_node((yyvsp[0].ival)); }
#line 1867 "parser.tab.c"
    break;

  case 64: /* expr: CHARACTER_LITERAL  */
#line 276 "parser.y"
                        { (yyval.node) = create_char_node((yyvsp[0].str)); }
#line 1873 "parser.tab.c"
    break;

  case 65: /* expr: expr '.' IDENTIFIER  */
#line 277 "parser.y"
                          { (yyval.node) = create_member_access_node((yyvsp[-2].node), (yyvsp[0].str)); }
#line 1879 "parser.tab.c"
    break;

  case 66: /* expr: expr '[' expr ']'  */
#line 278 "parser.y"
                        { (yyval.node) = create_array_access_node((yyvsp[-3].node), (yyvsp[-1].node)); }
#line 1885 "parser.tab.c"
    break;

  case 67: /* expr: IDENTIFIER '(' arg_list_opt ')'  */
#line 279 "parser.y"
                                      { (yyval.node) = create_func_call_node((yyvsp[-3].str), (yyvsp[-1].node)); }
#line 1891 "parser.tab.c"
    break;

  case 68: /* expr: '[' expr_list_opt ']'  */
#line 280 "parser.y"
                            { (yyval.node) = create_array_literal_node((yyvsp[-1].node)); }
#line 1897 "parser.tab.c"
    break;

  case 69: /* arg_list_opt: %empty  */
#line 284 "parser.y"
    { (yyval.node) = NULL; }
#line 1903 "parser.tab.c"
    break;

  case 70: /* arg_list_opt: arg_list  */
#line 285 "parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1909 "parser.tab.c"
    break;

  case 71: /* arg_list: arg  */
#line 289 "parser.y"
        { (yyval.node) = (yyvsp[0].node); }
#line 1915 "parser.tab.c"
    break;

  case 72: /* arg_list: arg_list ',' arg  */
#line 290 "parser.y"
                       { (yyval.node) = create_arg_list((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1921 "parser.tab.c"
    break;

  case 73: /* arg: expr  */
#line 294 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1927 "parser.tab.c"
    break;

  case 74: /* arg: IDENTIFIER ':' expr  */
#line 295 "parser.y"
                          { (yyval.node) = create_named_arg_node((yyvsp[-2].str), (yyvsp[0].node)); }
#line 1933 "parser.tab.c"
    break;

  case 75: /* expr_list_opt: %empty  */
#line 299 "parser.y"
    { (yyval.node) = NULL; }
#line 1939 "parser.tab.c"
    break;

  case 76: /* expr_list_opt: expr_list  */
#line 300 "parser.y"
                { (yyval.node) = (yyvsp[0].node); }
#line 1945 "parser.tab.c"
    break;

  case 77: /* expr_list: expr  */
#line 304 "parser.y"
         { (yyval.node) = (yyvsp[0].node); }
#line 1951 "parser.tab.c"
    break;

  case 78: /* expr_list: expr_list ',' expr  */
#line 305 "parser.y"
                         { (yyval.node) = create_expr_list((yyvsp[-2].node), (yyvsp[0].node)); }
#line 1957 "parser.tab.c"
    break;


#line 1961 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 308 "parser.y"


void yyerror(const char *s) {
    fprintf(stderr, "Syntax error at line %d: %s\n", yylineno, s);
}

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            perror(argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    init_symbol_table();
    init_codegen();
    
    printf("╔════════════════════════════════════════════════╗\n");
    printf("║        SWIFT SUBSET COMPILER - PART 3         ║\n");
    printf("╚════════════════════════════════════════════════╝\n");
    printf("\n=== COMPILATION STARTED ===\n");
    printf("\n=== LEXICAL ANALYSIS ===\n");
    printf("Tokenizing input file...\n");
    printf("Identifying keywords, operators, and identifiers...\n");
    printf("Status: IN PROGRESS\n");
    
    printf("\n=== SYNTAX ANALYSIS ===\n");
    printf("Building parse tree...\n");
    printf("Status: IN PROGRESS\n\n");
    
    yyparse();
    
    printf("\n╔════════════════════════════════════════════════╗\n");
    if (semantic_errors == 0) {
        printf("║           COMPILATION SUCCESSFUL              ║\n");
        printf("╚════════════════════════════════════════════════╝\n");
        printf("\nOutput file: output.c\n");
        printf("\nTo run the compiled program:\n");
        printf("  gcc -o program output.c\n");
        printf("  ./program\n");
    } else {
        printf("║           COMPILATION FAILED                  ║\n");
        printf("╚════════════════════════════════════════════════╝\n");
    }
    
    return semantic_errors > 0 ? 1 : 0;
}
