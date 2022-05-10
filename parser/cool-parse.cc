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


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs
#define yylval          cool_yylval
#define yychar          cool_yychar
#define yylloc          cool_yylloc

/* First part of user prologue.  */
#line 6 "cool.y"

  #include <iostream>
  #include "cool-tree.h"           /* definicija AST stabla za jezik COOL */
  #include "stringtab.h"
  #include "utilities.h"
  
  extern char *curr_filename;
  
  
  /* Locations */
  #define YYLTYPE int              /* the type of locations */
  #define cool_yylloc curr_lineno  /* use the curr_lineno from the lexer
                                      for the location of tokens */
    
  extern int node_lineno;          /* postaviti prije nego se konstruira �vor stabla
                                      na vrijednosti broja linij koju �elim da ima 
                                      taj �vor stabla */      
      
  #define YYLLOC_DEFAULT(Current, Rhs, N)       \
    Current = Rhs[1];                           \
    node_lineno = Current;
    
  #define SET_NODELOC(Current)  \
    node_lineno = Current;
    
/* IMPORTANT NOTE ON LINE NUMBERS
*********************************
* The above definitions and macros cause every terminal in your grammar to 
* have the line number supplied by the lexer. The only task you have to
* implement for line numbers to work correctly, is to use SET_NODELOC()
* before constructing any constructs from non-terminals in your grammar.
* Example: Consider you are matching on the following very restrictive 
* (fictional) construct that matches a plus between two integer constants. 
* (SUCH A RULE SHOULD NOT BE  PART OF YOUR PARSER):
    
    plus_consts	: INT_CONST '+' INT_CONST 
    
* where INT_CONST is a terminal for an integer constant. Now, a correct
* action for this rule that attaches the correct line number to plus_const
* would look like the following:
    
    plus_consts	: INT_CONST '+' INT_CONST 
    {
      // Set the line number of the current non-terminal:
      // ***********************************************
      // You can access the line numbers of the i'th item with @i, just
      // like you acess the value of the i'th exporession with $i.
      //
      // Here, we choose the line number of the last INT_CONST (@3) as the
      // line number of the resulting expression (@$). You are free to pick
      // any reasonable line as the line number of non-terminals. If you 
      // omit the statement @$=..., bison has default rules for deciding which 
      // line number to use. Check the manual for details if you are interested.
      @$ = @3;
      
      
      // Observe that we call SET_NODELOC(@3); this will set the global variable
      // node_lineno to @3. Since the constructor call "plus" uses the value of 
      // this global, the plus node will now have the correct line number.
      SET_NODELOC(@3);
      
      // construct the result node:
      $$ = plus(int_const($1), int_const($3));
    }
    
*/
    
    
    
  void yyerror(char *s);        /*  funkcija koja se zove u slu�aju gre�ke
                                    definirana je dole */
  extern int yylex();           /*  poziv leksera  */
    
/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */
    
  Program ast_root;	      /* the result of the parse  */
  Classes parse_results;        /* for use in semantic analysis */
  int omerrs = 0;               /* number of errors in lexing and parsing */

#line 159 "cool.tab.c"

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
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_COOL_YY_COOL_TAB_H_INCLUDED
# define YY_COOL_YY_COOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int cool_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ELSE = 259,
    FI = 260,
    IF = 261,
    IN = 262,
    INHERITS = 263,
    LET = 264,
    LOOP = 265,
    POOL = 266,
    THEN = 267,
    WHILE = 268,
    CASE = 269,
    ESAC = 270,
    OF = 271,
    DARROW = 272,
    NEW = 273,
    ISVOID = 274,
    STR_CONST = 275,
    INT_CONST = 276,
    BOOL_CONST = 277,
    TYPEID = 278,
    OBJECTID = 279,
    ASSIGN = 280,
    NOT = 281,
    LE = 282,
    ERROR = 283
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 92 "cool.y"

  Boolean boolean;        /* bool vrijednost: true ili false */
  Symbol symbol;          /* simbol iz tablice simbola */
  Program program;        /* krovni tip:
                               program ::= [[class; ]]+ 
                                 - barem jedna klasa */
  Class_ class_;          /* jedna klasa:   
                               class ::= class TYPE [inherits TYPE] { [[feature; ]]* } 
                                 - prvo terminal class
                                 - onda neterminal tip
                                 - onda eventualno terminal inherits i tip,
                                 - onda u viti�astim zagradama prazno ili jedan ili vi�e neterminala feature */
  Classes classes;        /* vi�e klasa */
  Feature feature;        /* jedna funkcija ili varijabla klase:
                               feature ::= ID( [ formal [[, formal]]* ] ) : TYPE { expr }
                                         | ID : TYPE [ <- expr ]
                                 - ako je funkcija onda ima:
                                   - najprije identifikator
                                   - onda u zagradama jedan ili vi�e neterminala feature
                                   - onda iza dvoto�ke ide tip funkcije
                                   - onda u viti�astim zagradam tijelo funkcije kao neterminal expr
                                 - ako je varijabla, onda ima:
                                   - identifikator dvoto�ka tip
                                   - eventualno pridjela vrijednosti - strelica i neterminal expr
			  */
  Features features;      /* vi�e funkcija ili varijabla klase */
  Formal formal;          /* argument funkcije:
                               formal ::= ID : TYPE
			         - identiikator dvoto�ka tip */
  Formals formals;        /* vi�e argumenata funkcije */
  Case case_;             /* jedan case */
  Cases cases;            /* vi�e caseova */
  Expression expression;  /* jedan izraz */
  Expressions expressions;/* vi�e izraza */
  char *error_msg;        /* poruka o gre�ci */

#line 304 "cool.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE cool_yylval;
extern YYLTYPE cool_yylloc;
int cool_yyparse (void);

#endif /* !YY_COOL_YY_COOL_TAB_H_INCLUDED  */



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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   405

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  153

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


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
      44,    45,    35,    33,    40,    34,    39,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    41,
      31,    32,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,    37,     2,     2,     2,
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
      25,    26,    27,    28,     2,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   186,   186,   192,   197,   205,   206,   210,   217,   218,
     222,   228,   232,   236,   238,   242,   243,   247,   251,   253,
     256,   260,   268,   272,   276,   281,   285,   289,   293,   298,
     304,   310,   314,   318,   322,   326,   331,   335,   339,   343,
     347,   351,   355,   359,   361,   363,   365,   369,   373,   377,
     381,   385,   389,   393,   397,   401,   405,   409,   413,   417,
     421,   425,   429,   431
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "\"<-\"", "\"<=\"",
  "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'~'", "'@'", "'.'", "','",
  "';'", "'{'", "'}'", "'('", "')'", "':'", "$accept", "program",
  "class_list", "feature_list", "formal_list", "expression_list",
  "expr_list_comma", "case_list", "class", "feature", "formal", "case",
  "let_list", "expression", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   285,
     286,    60,    61,    43,    45,    42,    47,   126,    64,    46,
      44,    59,   123,   125,    40,    41,    58
};
# endif

#define YYPACT_NINF (-108)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-16)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      84,  -108,    -9,    38,   153,  -108,    -6,  -108,  -108,    28,
       3,     6,    23,    76,     4,  -108,     3,  -108,    44,    48,
      36,  -108,     9,    42,   -20,  -108,   -18,  -108,    54,    66,
      44,    61,   205,  -108,  -108,  -108,  -108,    85,   205,     2,
     205,   205,    90,   205,  -108,  -108,  -108,   -13,   205,   205,
     124,   151,   308,    57,   258,     2,    81,  -108,   233,   268,
    -108,   -17,   205,    60,   356,   -17,    83,    97,   320,    91,
     278,   205,   205,   205,   205,   205,   205,   205,   112,   123,
    -108,   205,   205,  -108,   126,   205,   127,   356,  -108,    -8,
     356,  -108,  -108,   114,  -108,   332,  -108,  -108,  -108,   366,
     366,   366,    93,    93,   -17,   -17,   119,   115,   294,   202,
      69,   247,   116,     0,  -108,   178,  -108,  -108,  -108,   139,
      60,   133,   205,  -108,   205,   205,     2,  -108,   144,  -108,
    -108,  -108,   356,   132,    25,  -108,    24,   356,   221,  -108,
     161,    60,  -108,  -108,   205,     2,   205,    56,   356,  -108,
     344,  -108,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    24,     0,     0,     0,     3,     0,     1,     4,     0,
       0,     0,     0,     0,     0,     6,     0,    28,     8,     0,
       0,     7,     0,     0,     0,     9,     0,    22,     0,     0,
       0,     0,     0,    26,    23,    29,    10,     0,     0,     0,
       0,     0,     0,     0,    60,    59,    61,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    44,     0,     0,
      46,    47,     0,     0,    56,    52,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      27,     0,     0,    35,     0,     0,     0,    36,    18,     0,
      16,    13,    62,     0,    43,     0,    11,    63,    57,    54,
      53,    55,    48,    49,    50,    51,     0,     0,     0,     0,
       0,     0,     0,     0,    20,     0,    39,    14,    12,     0,
       0,     0,     0,    40,     0,     0,     0,    42,     0,    45,
      21,    19,    17,     0,     0,    25,     0,    31,     0,    33,
       0,     0,    38,    41,     0,     0,     0,     0,    32,    34,
       0,    37,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,   164,  -108,  -108,  -107,  -108,   177,    53,
     152,    70,   -54,   -32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,    14,    24,    67,    89,   113,     5,    15,
      25,   114,    57,    90
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    83,     9,    55,    12,    12,    54,    32,    58,    59,
      12,    61,    62,   134,     6,   129,    64,    65,    68,    70,
      30,    78,    79,    33,   112,    31,    56,    13,    13,   143,
      87,    63,   115,    13,   147,    95,    10,   116,     7,    99,
     100,   101,   102,   103,   104,   105,    -5,    20,    16,   108,
     109,    11,    28,   111,    71,    72,    73,    74,    75,    76,
      77,    88,    78,    79,    17,   115,    38,    21,    23,    39,
     142,    26,   139,    40,    41,    21,   124,    27,    42,    43,
      44,    45,    46,   132,    47,     1,    48,     2,    29,    35,
     136,   149,   137,   138,   125,    34,   115,    49,    93,    81,
     -15,   151,    50,    38,    51,   -15,    39,    37,    53,   126,
      40,    41,   148,    60,   150,    42,    43,    44,    45,    46,
      18,    47,    19,    48,    91,    66,    92,    84,    76,    77,
      38,    78,    79,    39,    49,   106,    97,    40,    41,    50,
      94,    51,    42,    43,    44,    45,    46,   107,    47,   110,
      48,   112,    69,    -2,     1,   117,     2,    38,   119,   120,
      39,    49,   128,   133,    40,    41,    50,   140,    51,    42,
      43,    44,    45,    46,   135,    47,   141,    48,   146,   131,
      22,     8,    36,   130,    38,     0,     0,    39,    49,     0,
       0,    40,    41,    50,     0,    51,    42,    43,    44,    45,
      46,     0,    47,     0,    48,     0,   122,   123,     0,     0,
       0,    38,     0,     0,    39,    49,     0,     0,    40,    41,
      50,     0,    51,    42,    43,    44,    45,    46,   144,    47,
       0,    48,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    79,    49,    85,     0,     0,     0,    50,     0,    51,
       0,    71,    72,    73,    74,    75,    76,    77,   127,    78,
      79,   145,     0,    71,    72,    73,    74,    75,    76,    77,
      82,    78,    79,     0,     0,     0,     0,    71,    72,    73,
      74,    75,    76,    77,    86,    78,    79,     0,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,     0,     0,
       0,     0,     0,    98,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    79,     0,     0,     0,   121,    71,    72,
      73,    74,    75,    76,    77,     0,    78,    79,     0,    80,
      71,    72,    73,    74,    75,    76,    77,     0,    78,    79,
       0,    96,    71,    72,    73,    74,    75,    76,    77,     0,
      78,    79,     0,   118,    71,    72,    73,    74,    75,    76,
      77,     0,    78,    79,     0,   152,    71,    72,    73,    74,
      75,    76,    77,     0,    78,    79,   -16,   -16,   -16,    74,
      75,    76,    77,     0,    78,    79
};

static const yytype_int16 yycheck[] =
{
      32,    55,     8,     1,     1,     1,    38,    25,    40,    41,
       1,    43,    25,   120,    23,    15,    48,    49,    50,    51,
      40,    38,    39,    41,    24,    45,    24,    24,    24,     5,
      62,    44,    40,    24,   141,    67,    42,    45,     0,    71,
      72,    73,    74,    75,    76,    77,    43,    43,    42,    81,
      82,    23,    43,    85,    30,    31,    32,    33,    34,    35,
      36,     1,    38,    39,    41,    40,     6,    14,    24,     9,
      45,    23,   126,    13,    14,    22,     7,    41,    18,    19,
      20,    21,    22,   115,    24,     1,    26,     3,    46,    23,
     122,   145,   124,   125,    25,    41,    40,    37,     1,    42,
      40,    45,    42,     6,    44,    45,     9,    46,    23,    40,
      13,    14,   144,    23,   146,    18,    19,    20,    21,    22,
      44,    24,    46,    26,    41,     1,    43,    46,    35,    36,
       6,    38,    39,     9,    37,    23,    45,    13,    14,    42,
      43,    44,    18,    19,    20,    21,    22,    24,    24,    23,
      26,    24,     1,     0,     1,    41,     3,     6,    39,    44,
       9,    37,    46,    24,    13,    14,    42,    23,    44,    18,
      19,    20,    21,    22,    41,    24,    44,    26,    17,     1,
      16,     4,    30,   113,     6,    -1,    -1,     9,    37,    -1,
      -1,    13,    14,    42,    -1,    44,    18,    19,    20,    21,
      22,    -1,    24,    -1,    26,    -1,     4,     5,    -1,    -1,
      -1,     6,    -1,    -1,     9,    37,    -1,    -1,    13,    14,
      42,    -1,    44,    18,    19,    20,    21,    22,     7,    24,
      -1,    26,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    37,    10,    -1,    -1,    -1,    42,    -1,    44,
      -1,    30,    31,    32,    33,    34,    35,    36,    11,    38,
      39,    40,    -1,    30,    31,    32,    33,    34,    35,    36,
      12,    38,    39,    -1,    -1,    -1,    -1,    30,    31,    32,
      33,    34,    35,    36,    16,    38,    39,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    43,    30,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    41,
      30,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    41,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    41,    30,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    41,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    30,    31,    32,    33,
      34,    35,    36,    -1,    38,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    48,    49,    55,    23,     0,    55,     8,
      42,    23,     1,    24,    50,    56,    42,    41,    44,    46,
      43,    56,    50,    24,    51,    57,    23,    41,    43,    46,
      40,    45,    25,    41,    41,    23,    57,    46,     6,     9,
      13,    14,    18,    19,    20,    21,    22,    24,    26,    37,
      42,    44,    60,    23,    60,     1,    24,    59,    60,    60,
      23,    60,    25,    44,    60,    60,     1,    52,    60,     1,
      60,    30,    31,    32,    33,    34,    35,    36,    38,    39,
      41,    42,    12,    59,    46,    10,    16,    60,     1,    53,
      60,    41,    43,     1,    43,    60,    41,    45,    45,    60,
      60,    60,    60,    60,    60,    60,    23,    24,    60,    60,
      23,    60,    24,    54,    58,    40,    45,    41,    41,    39,
      44,    43,     4,     5,     7,    25,    40,    11,    46,    15,
      58,     1,    60,    24,    53,    41,    60,    60,    60,    59,
      23,    44,    45,     5,     7,    40,    17,    53,    60,    59,
      60,    45,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    50,    50,    50,    51,    51,
      51,    52,    52,    52,    52,    53,    53,    53,    53,    53,
      54,    54,    55,    55,    55,    56,    56,    56,    56,    57,
      58,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     1,     2,     0,     1,
       3,     2,     3,     2,     3,     0,     1,     3,     1,     3,
       1,     2,     6,     8,     1,    10,     4,     6,     2,     3,
       6,     5,     7,     5,     7,     2,     3,     8,     6,     4,
       5,     7,     5,     3,     2,     5,     2,     2,     3,     3,
       3,     3,     2,     3,     3,     3,     2,     3,     1,     1,
       1,     1,     3,     3
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 187 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          ast_root = program((yyvsp[0].classes)); }
#line 1739 "cool.tab.c"
    break;

  case 3:
#line 193 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.classes) = single_Classes((yyvsp[0].class_));
                          parse_results = (yyval.classes); }
#line 1748 "cool.tab.c"
    break;

  case 4:
#line 198 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.classes) = append_Classes((yyvsp[-1].classes),single_Classes((yyvsp[0].class_))); 
                          parse_results = (yyval.classes); }
#line 1757 "cool.tab.c"
    break;

  case 5:
#line 205 "cool.y"
                        { (yyval.features) = nil_Features(); }
#line 1763 "cool.tab.c"
    break;

  case 6:
#line 207 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.features) = single_Features((yyvsp[0].feature)); }
#line 1771 "cool.tab.c"
    break;

  case 7:
#line 211 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.features) = append_Features((yyvsp[-1].features),single_Features((yyvsp[0].feature))); }
#line 1779 "cool.tab.c"
    break;

  case 8:
#line 217 "cool.y"
                        { (yyval.formals) = nil_Formals(); }
#line 1785 "cool.tab.c"
    break;

  case 9:
#line 219 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.formals) = single_Formals((yyvsp[0].formal)); }
#line 1793 "cool.tab.c"
    break;

  case 10:
#line 223 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.formals) = append_Formals((yyvsp[-2].formals),single_Formals((yyvsp[0].formal))); }
#line 1801 "cool.tab.c"
    break;

  case 11:
#line 229 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expressions) = single_Expressions((yyvsp[-1].expression)); }
#line 1809 "cool.tab.c"
    break;

  case 12:
#line 233 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expressions) = append_Expressions((yyvsp[-2].expressions),single_Expressions((yyvsp[-1].expression))); }
#line 1817 "cool.tab.c"
    break;

  case 13:
#line 237 "cool.y"
                        {}
#line 1823 "cool.tab.c"
    break;

  case 15:
#line 242 "cool.y"
                        { (yyval.expressions) = nil_Expressions(); }
#line 1829 "cool.tab.c"
    break;

  case 16:
#line 244 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expressions) = single_Expressions((yyvsp[0].expression)); }
#line 1837 "cool.tab.c"
    break;

  case 17:
#line 248 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expressions) = append_Expressions((yyvsp[-2].expressions),single_Expressions((yyvsp[0].expression))); }
#line 1845 "cool.tab.c"
    break;

  case 18:
#line 252 "cool.y"
                        {}
#line 1851 "cool.tab.c"
    break;

  case 20:
#line 257 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.cases) = single_Cases((yyvsp[0].case_)); }
#line 1859 "cool.tab.c"
    break;

  case 21:
#line 261 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.cases) = append_Cases((yyvsp[-1].cases),single_Cases((yyvsp[0].case_))); }
#line 1867 "cool.tab.c"
    break;

  case 22:
#line 269 "cool.y"
                        { (yyloc) = (yylsp[-2]); 
                          SET_NODELOC((yylsp[-2]));
                          (yyval.class_) = class_((yyvsp[-4].symbol),idtable.add_string("Object"),(yyvsp[-2].features),stringtable.add_string(curr_filename)); }
#line 1875 "cool.tab.c"
    break;

  case 23:
#line 273 "cool.y"
                        { (yyloc) = (yylsp[-2]); 
                          SET_NODELOC((yylsp[-2]));
                          (yyval.class_) = class_((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].features),stringtable.add_string(curr_filename)); }
#line 1883 "cool.tab.c"
    break;

  case 24:
#line 277 "cool.y"
                        {}
#line 1889 "cool.tab.c"
    break;

  case 25:
#line 282 "cool.y"
                        { (yyloc) = (yylsp[-2]); 
                          SET_NODELOC((yylsp[-2]));
                          (yyval.feature) = method((yyvsp[-9].symbol), (yyvsp[-7].formals), (yyvsp[-4].symbol), (yyvsp[-2].expression)); }
#line 1897 "cool.tab.c"
    break;

  case 26:
#line 286 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.feature) = attr((yyvsp[-3].symbol), (yyvsp[-1].symbol), no_expr()); }
#line 1905 "cool.tab.c"
    break;

  case 27:
#line 290 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.feature) = attr((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression)); }
#line 1913 "cool.tab.c"
    break;

  case 28:
#line 294 "cool.y"
                        {}
#line 1919 "cool.tab.c"
    break;

  case 29:
#line 299 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol)); }
#line 1927 "cool.tab.c"
    break;

  case 30:
#line 305 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.case_) = branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression)); }
#line 1935 "cool.tab.c"
    break;

  case 31:
#line 311 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = let((yyvsp[-4].symbol),(yyvsp[-2].symbol),no_expr(),(yyvsp[0].expression)); }
#line 1943 "cool.tab.c"
    break;

  case 32:
#line 315 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = let((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].expression),(yyvsp[0].expression)); }
#line 1951 "cool.tab.c"
    break;

  case 33:
#line 319 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = let((yyvsp[-4].symbol),(yyvsp[-2].symbol),no_expr(),(yyvsp[0].expression)); }
#line 1959 "cool.tab.c"
    break;

  case 34:
#line 323 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = let((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].expression),(yyvsp[0].expression)); }
#line 1967 "cool.tab.c"
    break;

  case 35:
#line 327 "cool.y"
                        { (yyval.expression) = (yyvsp[0].expression); }
#line 1973 "cool.tab.c"
    break;

  case 36:
#line 332 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = assign((yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1981 "cool.tab.c"
    break;

  case 37:
#line 336 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = static_dispatch((yyvsp[-7].expression), (yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1989 "cool.tab.c"
    break;

  case 38:
#line 340 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = dispatch((yyvsp[-5].expression), (yyvsp[-3].symbol), (yyvsp[-1].expressions));}
#line 1997 "cool.tab.c"
    break;

  case 39:
#line 344 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = dispatch(object(idtable.add_string("self")),(yyvsp[-3].symbol),(yyvsp[-1].expressions)); }
#line 2005 "cool.tab.c"
    break;

  case 40:
#line 348 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = cond((yyvsp[-3].expression), (yyvsp[-1].expression), no_expr());  }
#line 2013 "cool.tab.c"
    break;

  case 41:
#line 352 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression));  }
#line 2021 "cool.tab.c"
    break;

  case 42:
#line 356 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = loop( (yyvsp[-3].expression), (yyvsp[-1].expression) );}
#line 2029 "cool.tab.c"
    break;

  case 43:
#line 360 "cool.y"
                        {  (yyval.expression) = block((yyvsp[-1].expressions)); }
#line 2035 "cool.tab.c"
    break;

  case 44:
#line 362 "cool.y"
                        {  (yyval.expression) = (yyvsp[0].expression); }
#line 2041 "cool.tab.c"
    break;

  case 45:
#line 364 "cool.y"
                        { (yyval.expression) = typcase( (yyvsp[-3].expression), (yyvsp[-1].cases) );}
#line 2047 "cool.tab.c"
    break;

  case 46:
#line 366 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = new_((yyvsp[0].symbol));  }
#line 2055 "cool.tab.c"
    break;

  case 47:
#line 370 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = isvoid((yyvsp[0].expression)); }
#line 2063 "cool.tab.c"
    break;

  case 48:
#line 374 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2071 "cool.tab.c"
    break;

  case 49:
#line 378 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2079 "cool.tab.c"
    break;

  case 50:
#line 382 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2087 "cool.tab.c"
    break;

  case 51:
#line 386 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2095 "cool.tab.c"
    break;

  case 52:
#line 390 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = neg((yyvsp[0].expression));}
#line 2103 "cool.tab.c"
    break;

  case 53:
#line 394 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = lt((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2111 "cool.tab.c"
    break;

  case 54:
#line 398 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2119 "cool.tab.c"
    break;

  case 55:
#line 402 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression));}
#line 2127 "cool.tab.c"
    break;

  case 56:
#line 406 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = comp((yyvsp[0].expression));}
#line 2135 "cool.tab.c"
    break;

  case 57:
#line 410 "cool.y"
                        { (yyloc) = (yylsp[-1]); 
                          SET_NODELOC((yylsp[-1]));
                          (yyval.expression) = (yyvsp[-1].expression); }
#line 2143 "cool.tab.c"
    break;

  case 58:
#line 414 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = object((yyvsp[0].symbol));}
#line 2151 "cool.tab.c"
    break;

  case 59:
#line 418 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = int_const((yyvsp[0].symbol)); }
#line 2159 "cool.tab.c"
    break;

  case 60:
#line 422 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = string_const((yyvsp[0].symbol)); }
#line 2167 "cool.tab.c"
    break;

  case 61:
#line 426 "cool.y"
                        { (yyloc) = (yylsp[0]); 
                          SET_NODELOC((yylsp[0]));
                          (yyval.expression) = bool_const((yyvsp[0].boolean)); }
#line 2175 "cool.tab.c"
    break;

  case 62:
#line 430 "cool.y"
                        {}
#line 2181 "cool.tab.c"
    break;

  case 63:
#line 432 "cool.y"
                        {}
#line 2187 "cool.tab.c"
    break;


#line 2191 "cool.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 436 "cool.y"

    
/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s)
{
      extern int curr_lineno;
      
      cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
      << s << " at or near ";
      print_cool_token(yychar);
      cerr << endl;
      omerrs++;
      
      if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
}
    
    
