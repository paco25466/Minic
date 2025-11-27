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
#line 6 "lexico.y"


#include "listaCodigo.h"
#include "listaSimbolos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


extern int yylex(void);


// Declaraciones de funciones
void yyerror(const char *s);

void imprimirLC(ListaC codigo); 
char* obtenerReg(void);
void liberarReg(char *reg);
extern char *yytext;
extern int yylineno;
Lista tablaSimb; 
int contCadena=0;

int contador_etiq=0;


// Contadores de errores
int semantic_errors_count = 0;
int syntactic_errors_count = 0;
int lexical_errors_count = 0;

int perteneceTablaS(char *nombre);
void añadeEntrada(char *nombre, Tipo tipo, int valor) ;
int esConstante(char *nombre);
void imprimirTablaS();

// Declaraciones de funciones
char* nuevaEtiqueta();
char* concatena(char* str1, char* str2);

// Array para gestionar registros temporales
int registros[10] = {0,0,0,0,0,0,0,0,0,0};

// Obtiene un registro temporal libre
char* obtenerReg() {
    for(int i = 0; i < 10; i++) {
        if(registros[i] == 0) {
            registros[i] = 1;
            char* reg = NULL;
            asprintf(&reg, "$t%d", i);
            if (reg == NULL) {
                perror("asprintf failed in obtenerReg");
                exit(EXIT_FAILURE);
            }
            return reg;
        }
    }
    fprintf(stderr, "Error: no hay registros temporales disponibles\n");
    exit(EXIT_FAILURE);
}


void liberarReg(char *reg) {
    if(reg == NULL) return;
    if (strlen(reg) > 2 && reg[0] == '$' && reg[1] == 't') {
        int idx = atoi(&reg[2]);
        if(idx >= 0 && idx < 10) {
            registros[idx] = 0;
        } 
    } 
    
     
}



void imprimirLC(ListaC codigo) {
    PosicionListaC p = inicioLC(codigo);
    Operacion op;

    printf("\n### CODIGO GENERADO ###\n"); 
    printf("\t.globl main\n");
    printf("main:\n"); 
    
    while (p != finalLC(codigo)) {
        op = recuperaLC(codigo, p);
        printf("%s", op.op);
        if (op.res != NULL) printf(" %s", op.res);
        if (op.arg1 != NULL) printf(",%s", op.arg1);
        if (op.arg2 != NULL) printf(",%s", op.arg2);
        printf("\n");
        p = siguienteLC(codigo, p);
    }
    printf("# ====\n");
    printf("#FIN\n");
    printf("li $v0, 10\n");
    printf("syscall\n");
}

char* concatena(char* str1, char* str2) {
    if (str1 == NULL || str2 == NULL) {
        fprintf(stderr, "Error: NULL pasado a  concatena\n");
        return NULL;
    }
    char* result = NULL;
    if (asprintf(&result, "%s%s", str1, str2) == -1) {
         perror("fallo en  concatena");
         return NULL;
    }
    return result;
}


#line 185 "lexico.tab.c"

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

#include "lexico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_READ = 3,                       /* READ  */
  YYSYMBOL_VAR = 4,                        /* VAR  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_LPAREN = 11,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 12,                    /* RPAREN  */
  YYSYMBOL_SEMICOLON = 13,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 14,                     /* COMMA  */
  YYSYMBOL_ASSIGNOP = 15,                  /* ASSIGNOP  */
  YYSYMBOL_LCORCH = 16,                    /* LCORCH  */
  YYSYMBOL_RCORCH = 17,                    /* RCORCH  */
  YYSYMBOL_INTERR = 18,                    /* INTERR  */
  YYSYMBOL_DOSPUNT = 19,                   /* DOSPUNT  */
  YYSYMBOL_PLUSOP = 20,                    /* PLUSOP  */
  YYSYMBOL_MINUSOP = 21,                   /* MINUSOP  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_POR = 23,                       /* POR  */
  YYSYMBOL_DO = 24,                        /* DO  */
  YYSYMBOL_MENOR = 25,                     /* MENOR  */
  YYSYMBOL_MAYOR = 26,                     /* MAYOR  */
  YYSYMBOL_MENORIGUAL = 27,                /* MENORIGUAL  */
  YYSYMBOL_MAYORIGUAL = 28,                /* MAYORIGUAL  */
  YYSYMBOL_IGUAL = 29,                     /* IGUAL  */
  YYSYMBOL_DISTINTO = 30,                  /* DISTINTO  */
  YYSYMBOL_NUM = 31,                       /* NUM  */
  YYSYMBOL_ID = 32,                        /* ID  */
  YYSYMBOL_STRING = 33,                    /* STRING  */
  YYSYMBOL_UMINUS = 34,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 35,                  /* $accept  */
  YYSYMBOL_program = 36,                   /* program  */
  YYSYMBOL_37_1 = 37,                      /* $@1  */
  YYSYMBOL_declarations = 38,              /* declarations  */
  YYSYMBOL_tipo = 39,                      /* tipo  */
  YYSYMBOL_var_list = 40,                  /* var_list  */
  YYSYMBOL_const_list = 41,                /* const_list  */
  YYSYMBOL_statement_list = 42,            /* statement_list  */
  YYSYMBOL_statement = 43,                 /* statement  */
  YYSYMBOL_print_list = 44,                /* print_list  */
  YYSYMBOL_print_item = 45,                /* print_item  */
  YYSYMBOL_read_list = 46,                 /* read_list  */
  YYSYMBOL_relative_expression = 47,       /* relative_expression  */
  YYSYMBOL_expression = 48                 /* expression  */
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
typedef yytype_int8 yy_state_t;

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
#define YYLAST   135

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  35
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  14
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  108

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   289


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   146,   146,   146,   176,   183,   189,   192,   196,   208,
     223,   247,   275,   280,   283,   303,   305,   355,   383,   433,
     469,   470,   475,   476,   484,   525,   555,   586,   623,   636,
     650,   664,   676,   688,   707,   719,   731,   743,   756,   805,
     815,   819,   833
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
  "\"end of file\"", "error", "\"invalid token\"", "READ", "VAR", "CONST",
  "INT", "IF", "ELSE", "WHILE", "PRINT", "LPAREN", "RPAREN", "SEMICOLON",
  "COMMA", "ASSIGNOP", "LCORCH", "RCORCH", "INTERR", "DOSPUNT", "PLUSOP",
  "MINUSOP", "DIV", "POR", "DO", "MENOR", "MAYOR", "MENORIGUAL",
  "MAYORIGUAL", "IGUAL", "DISTINTO", "NUM", "ID", "STRING", "UMINUS",
  "$accept", "program", "$@1", "declarations", "tipo", "var_list",
  "const_list", "statement_list", "statement", "print_list", "print_item",
  "read_list", "relative_expression", "expression", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-30)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -30,     4,   -22,   -30,     7,    13,    18,   -30,    34,    46,
      46,    -1,   -30,    35,    45,    68,    72,    79,    80,   -30,
     -30,    65,    77,   -30,   -30,    36,    90,    51,    62,     9,
       9,    67,    19,    86,     9,   -30,    89,     9,   -30,    91,
     -30,    -7,     9,     9,   -30,   -30,    84,    81,   110,   -30,
       5,   -30,    97,   -30,   113,    24,   -30,    97,   111,   112,
      95,    64,   -30,    65,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,    65,   115,    67,     9,   -30,     9,
     -30,   -30,   -30,     9,   121,    48,    48,   -30,   -30,    97,
      97,    97,    97,    97,    97,   -30,   -30,   -30,   118,    97,
      93,    65,   119,     9,   -30,   -30,    -9,   -30
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     6,    13,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,    13,
       3,     0,     0,    12,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     4,     0,     0,     5,     0,
      26,     0,     0,     0,    42,    41,     0,     0,     0,    25,
       0,    22,    24,    15,     0,     0,     9,    10,     0,     0,
       0,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      21,    27,    40,     0,    17,    34,    35,    37,    36,    28,
      29,    30,    31,    32,    33,    18,    20,    23,     0,    11,
       0,     0,     0,     0,    16,    19,     0,    38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -30,   -30,   -30,   -30,   123,   -30,   -30,   116,   -21,   -30,
      55,   -30,   -29,   -10
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     2,     8,    13,    25,    27,    11,    23,    50,
      51,    41,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      33,    48,    15,   107,     3,    59,    16,    60,    17,    18,
       4,    64,    65,    66,    67,    19,    20,    75,     5,    76,
      42,    52,    15,    21,    55,     6,    16,    57,    17,    18,
      43,    22,    61,    62,     7,    19,    53,    78,     9,    10,
      44,    45,    84,    21,    64,    65,    66,    67,    98,    35,
      36,    22,    12,    95,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    38,    39,    52,    24,    15,    99,
      66,    67,    16,   100,    17,    18,    82,    26,    42,    28,
     104,    19,    83,    29,    64,    65,    66,    67,    43,    21,
      30,    31,    34,   106,    40,    54,    63,    22,    44,    45,
      49,    64,    65,    66,    67,    37,    68,    69,    70,    71,
      72,    73,   103,    64,    65,    66,    67,    64,    65,    66,
      67,    56,    74,    58,    77,    80,    79,    81,    96,   101,
     102,    97,   105,    14,     0,    32
};

static const yytype_int8 yycheck[] =
{
      21,    30,     3,    12,     0,    12,     7,    14,     9,    10,
      32,    20,    21,    22,    23,    16,    17,    12,    11,    14,
      11,    31,     3,    24,    34,    12,     7,    37,     9,    10,
      21,    32,    42,    43,    16,    16,    17,    13,     4,     5,
      31,    32,    63,    24,    20,    21,    22,    23,    77,    13,
      14,    32,     6,    74,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    13,    14,    76,    32,     3,    79,
      22,    23,     7,    83,     9,    10,    12,    32,    11,    11,
     101,    16,    18,    11,    20,    21,    22,    23,    21,    24,
      11,    11,    15,   103,    32,     9,    12,    32,    31,    32,
      33,    20,    21,    22,    23,    15,    25,    26,    27,    28,
      29,    30,    19,    20,    21,    22,    23,    20,    21,    22,
      23,    32,    12,    32,    11,    13,    15,    32,    13,     8,
      12,    76,    13,    10,    -1,    19
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    37,     0,    32,    11,    12,    16,    38,     4,
       5,    42,     6,    39,    39,     3,     7,     9,    10,    16,
      17,    24,    32,    43,    32,    40,    32,    41,    11,    11,
      11,    11,    42,    43,    15,    13,    14,    15,    13,    14,
      32,    46,    11,    21,    31,    32,    47,    48,    47,    33,
      44,    45,    48,    17,     9,    48,    32,    48,    32,    12,
      14,    48,    48,    12,    20,    21,    22,    23,    25,    26,
      27,    28,    29,    30,    12,    12,    14,    11,    13,    15,
      13,    32,    12,    18,    43,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    43,    13,    45,    47,    48,
      48,     8,    12,    19,    43,    13,    48,    12
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    35,    37,    36,    38,    38,    38,    39,    40,    40,
      41,    41,    42,    42,    43,    43,    43,    43,    43,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    47,    47,
      47,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     8,     5,     5,     0,     1,     1,     3,
       3,     5,     2,     0,     4,     3,     7,     5,     5,     7,
       5,     5,     1,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     7,     2,
       3,     1,     1
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
  case 2: /* $@1: %empty  */
#line 146 "lexico.y"
          {
            tablaSimb=creaLS();
            semantic_errors_count = 0; // Inicializar contadores
            syntactic_errors_count = 0;
            lexical_errors_count = 0;   // Inicializar
          }
#line 1290 "lexico.tab.c"
    break;

  case 3: /* program: $@1 ID LPAREN RPAREN LCORCH declarations statement_list RCORCH  */
#line 153 "lexico.y"
          {
            if(semantic_errors_count + syntactic_errors_count + lexical_errors_count == 0) {

                
                concatenaLC((yyvsp[-2].lc),(yyvsp[-1].lc));
                imprimirTablaS();  
                imprimirLC((yyvsp[-2].lc));

                liberaLC((yyvsp[-2].lc));
                liberaLC((yyvsp[-1].lc));
                liberaLS(tablaSimb);
                
            } else {
                printf("\n# Errores lexicos: %d\n", lexical_errors_count);
                printf("# Errores sintacticos: %d\n", syntactic_errors_count);
                printf("# Errores semanticos: %d\n", semantic_errors_count);
            }
            
            
          }
#line 1315 "lexico.tab.c"
    break;

  case 4: /* declarations: declarations VAR tipo var_list SEMICOLON  */
#line 177 "lexico.y"
          {
            (yyval.lc)=(yyvsp[-4].lc);             
            concatenaLC((yyval.lc),(yyvsp[-1].lc));     
            liberaLC((yyvsp[-1].lc));    
           
          }
#line 1326 "lexico.tab.c"
    break;

  case 5: /* declarations: declarations CONST tipo const_list SEMICOLON  */
#line 184 "lexico.y"
          {
            (yyval.lc)=(yyvsp[-4].lc);    
            concatenaLC((yyval.lc),(yyvsp[-1].lc)); 
            liberaLC((yyvsp[-1].lc));
          }
#line 1336 "lexico.tab.c"
    break;

  case 6: /* declarations: %empty  */
#line 189 "lexico.y"
                      { (yyval.lc)=creaLC(); }
#line 1342 "lexico.tab.c"
    break;

  case 7: /* tipo: INT  */
#line 192 "lexico.y"
               {
             
          }
#line 1350 "lexico.tab.c"
    break;

  case 8: /* var_list: ID  */
#line 196 "lexico.y"
                 {
            
            if (!(perteneceTablaS((yyvsp[0].c)))) {
                 añadeEntrada((yyvsp[0].c),VARIABLE,0);
            } else {
                 fprintf(stderr, "Error semantico en linea %d: %s ya declarada\n", yylineno, (yyvsp[0].c)); 
                 semantic_errors_count++;
            }
            
            
             (yyval.lc) = creaLC(); 
          }
#line 1367 "lexico.tab.c"
    break;

  case 9: /* var_list: var_list COMMA ID  */
#line 208 "lexico.y"
                        {
            if (!(perteneceTablaS((yyvsp[0].c)))) {
                 añadeEntrada((yyvsp[0].c),VARIABLE,0);
            } else {
                 fprintf(stderr, "Error semantico en linea %d: %s ya declarada\n", yylineno, (yyvsp[0].c)); 
                 semantic_errors_count++;
            }
            
             (yyval.lc) = creaLC(); 
            
          }
#line 1383 "lexico.tab.c"
    break;

  case 10: /* const_list: ID ASSIGNOP expression  */
#line 223 "lexico.y"
                                    {
            if (!(perteneceTablaS((yyvsp[-2].c)))) 
                    añadeEntrada((yyvsp[-2].c), CONSTANTE,0);
                else {
                    printf("Error  semantico en linea %d: %s ya declarada\n", yylineno, (yyvsp[-2].c));
                    semantic_errors_count++;
                } 
                    

            (yyval.lc) = (yyvsp[0].lc);  // Código de la expresión
            Operacion op;
            op.op = "sw"; 
            op.res = recuperaResLC((yyvsp[0].lc));  
            char* mem_addr = concatena("_", (yyvsp[-2].c)); 
            op.arg1 = mem_addr;  
            op.arg2 = NULL;
            insertaLC((yyval.lc), finalLC((yyval.lc)), op);  
            liberarReg(op.res);  
           
           
          }
#line 1409 "lexico.tab.c"
    break;

  case 11: /* const_list: const_list COMMA ID ASSIGNOP expression  */
#line 247 "lexico.y"
                                              {
            if (!(perteneceTablaS((yyvsp[-2].c)))) 
                    añadeEntrada((yyvsp[-2].c), CONSTANTE,0);
                else {
                    printf("Error semantico en linea %d: %s ya declarada\n", yylineno, (yyvsp[-2].c));
                    semantic_errors_count++;
                }
                

            
            Operacion op;
            op.op = "sw"; 
            op.res = recuperaResLC((yyvsp[0].lc));  
            op.arg1 = concatena("_", (yyvsp[-2].c)); 
            op.arg2 = NULL;
            insertaLC((yyvsp[0].lc), finalLC((yyvsp[0].lc)), op);  
            liberarReg(op.res);

            
            concatenaLC((yyvsp[-4].lc), (yyvsp[0].lc));
            (yyval.lc) = (yyvsp[-4].lc);  
            liberaLC((yyvsp[0].lc));  

            
          
          }
#line 1440 "lexico.tab.c"
    break;

  case 12: /* statement_list: statement_list statement  */
#line 275 "lexico.y"
                                          {
            (yyval.lc) = (yyvsp[-1].lc);
            concatenaLC((yyval.lc),(yyvsp[0].lc));
            liberaLC((yyvsp[0].lc));
          }
#line 1450 "lexico.tab.c"
    break;

  case 13: /* statement_list: %empty  */
#line 280 "lexico.y"
                      { (yyval.lc)=creaLC(); }
#line 1456 "lexico.tab.c"
    break;

  case 14: /* statement: ID ASSIGNOP expression SEMICOLON  */
#line 283 "lexico.y"
                                             {  
    if (!(perteneceTablaS((yyvsp[-3].c)))) {
        printf("Error semantico en linea %d: %s no declarada\n", yylineno, (yyvsp[-3].c));
        semantic_errors_count++;
    }       
    else if ((esConstante((yyvsp[-3].c)))) {
            printf("Error semantico en linea %d: %s es constante\n", yylineno, (yyvsp[-3].c));
            semantic_errors_count++;      
        }
        
                (yyval.lc) = (yyvsp[-1].lc);                        
                Operacion op; 
                op.op = "sw"; 
                op.res = recuperaResLC((yyvsp[-1].lc));     
                op.arg1 = concatena("_",(yyvsp[-3].c));   
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);    
                liberarReg(op.res);              
    }
#line 1480 "lexico.tab.c"
    break;

  case 15: /* statement: LCORCH statement_list RCORCH  */
#line 303 "lexico.y"
                                     {(yyval.lc) = (yyvsp[-1].lc);}
#line 1486 "lexico.tab.c"
    break;

  case 16: /* statement: IF LPAREN relative_expression RPAREN statement ELSE statement  */
#line 305 "lexico.y"
                                                                      {
            (yyval.lc) = (yyvsp[-4].lc);   
            Operacion op;
            char* etiqElse = nuevaEtiqueta();    
            char* etiqEndIf = nuevaEtiqueta();   

           
           op.op = "beqz";
            op.res = recuperaResLC((yyvsp[-4].lc));
            op.arg1 = etiqElse; 
            op.arg2 = NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
            liberarReg(op.res); 

            
            concatenaLC((yyval.lc),(yyvsp[-2].lc));
            liberaLC((yyvsp[-2].lc));

            
           op.op = "b";
            op.res = NULL;
            op.arg1 = etiqEndIf; 
            op.arg2 = NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
            

            
            op.op = concatena(etiqElse,":"); 
            op.res = NULL;
            op.arg1 = NULL;
            op.arg2 = NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
           
           

            
            concatenaLC((yyval.lc),(yyvsp[0].lc));
            liberaLC((yyvsp[0].lc));

           
            op.op = concatena(etiqEndIf,":"); 
            op.res = NULL;
            op.arg1 = NULL;
            op.arg2 = NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
            
          

            
         }
#line 1541 "lexico.tab.c"
    break;

  case 17: /* statement: IF LPAREN relative_expression RPAREN statement  */
#line 355 "lexico.y"
                                                       {
            (yyval.lc) = (yyvsp[-2].lc);    
            Operacion op;
            char* etiqEndIf = nuevaEtiqueta();    

            
            op.op = "beqz";
            op.res = recuperaResLC((yyvsp[-2].lc));
            op.arg1 = etiqEndIf;    
            op.arg2 = NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
            liberarReg(op.res); 

           
            concatenaLC((yyval.lc),(yyvsp[0].lc));
            liberaLC((yyvsp[0].lc));

            
            op.op = concatena(etiqEndIf,":"); 
            op.res = NULL;
            op.arg1 = NULL;
            op.arg2 = NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
           
            

            
          }
#line 1574 "lexico.tab.c"
    break;

  case 18: /* statement: WHILE LPAREN relative_expression RPAREN statement  */
#line 383 "lexico.y"
                                                         {
    (yyval.lc) = creaLC();
    
    // Etiqueta de inicio del while
    char* etiqInicio = nuevaEtiqueta();
    char* etiqFin = nuevaEtiqueta();
    
    // Etiqueta de inicio
    Operacion op;
    op.op = concatena(etiqInicio, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);
    
    // Añadir código de la expresión
    concatenaLC((yyval.lc), (yyvsp[-2].lc));
    
    // beqz para salir del bucle
    op.op = "beqz";
    op.res = recuperaResLC((yyvsp[-2].lc));
    op.arg1 = etiqFin;  // SIN los ":"
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);
    liberarReg(op.res);
    
    // Código del cuerpo del while
    concatenaLC((yyval.lc), (yyvsp[0].lc));
    
    // Salto al inicio del while
    op.op = "b";
    op.res = NULL;
    op.arg1 = etiqInicio;  // SIN los ":"
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);
    
    // Etiqueta de fin
    op.op = concatena(etiqFin, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);
    
    // Liberar memoria
    liberaLC((yyvsp[-2].lc));
    liberaLC((yyvsp[0].lc));
}
#line 1626 "lexico.tab.c"
    break;

  case 19: /* statement: DO statement WHILE LPAREN relative_expression RPAREN SEMICOLON  */
#line 433 "lexico.y"
                                                                      {
        (yyval.lc) = creaLC();
        
        // Etiqueta de inicio del do-while
        char* etiqInicio = nuevaEtiqueta();
        
        // Etiqueta de inicio
        Operacion op;
        op.op = concatena(etiqInicio, ":");
        op.res = NULL;
        op.arg1 = NULL;
        op.arg2 = NULL;
        insertaLC((yyval.lc), finalLC((yyval.lc)), op);
        
        // Código del cuerpo del do-while (se ejecuta al menos una vez)
        concatenaLC((yyval.lc), (yyvsp[-5].lc));
        
        // Añadir código de la expresión de condición
        concatenaLC((yyval.lc), (yyvsp[-2].lc));
        
        // bnez para continuar el bucle (si la condición es verdadera, volver al inicio)
        op.op = "bnez";
        op.res = recuperaResLC((yyvsp[-2].lc));
        op.arg1 = etiqInicio;  // Volver al inicio si la condición es verdadera
        op.arg2 = NULL;
        insertaLC((yyval.lc), finalLC((yyval.lc)), op);
        liberarReg(recuperaResLC((yyvsp[-2].lc)));
        
        // Liberar memoria
        liberaLC((yyvsp[-5].lc));
        liberaLC((yyvsp[-2].lc));
    }
#line 1663 "lexico.tab.c"
    break;

  case 20: /* statement: PRINT LPAREN print_list RPAREN SEMICOLON  */
#line 469 "lexico.y"
                                                    { (yyval.lc) = (yyvsp[-2].lc); }
#line 1669 "lexico.tab.c"
    break;

  case 21: /* statement: READ LPAREN read_list RPAREN SEMICOLON  */
#line 470 "lexico.y"
                                                 { (yyval.lc)=(yyvsp[-2].lc); }
#line 1675 "lexico.tab.c"
    break;

  case 22: /* print_list: print_item  */
#line 475 "lexico.y"
                         {  (yyval.lc)=(yyvsp[0].lc);  }
#line 1681 "lexico.tab.c"
    break;

  case 23: /* print_list: print_list COMMA print_item  */
#line 477 "lexico.y"
          {
            (yyval.lc)=(yyvsp[-2].lc);
            concatenaLC((yyval.lc),(yyvsp[0].lc));
            liberaLC((yyvsp[0].lc));
          }
#line 1691 "lexico.tab.c"
    break;

  case 24: /* print_item: expression  */
#line 485 "lexico.y"
            {

                (yyval.lc) = (yyvsp[0].lc);
                 Operacion op;
                op.op = "move";
                op.res = "$a0";
                op.arg1 = recuperaResLC((yyvsp[0].lc));
                op.arg2 = NULL;
                liberarReg(op.arg1);
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                
                op.op = "li";
                op.res = "$v0";
                op.arg1 = "1";
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
               
                op.op = "syscall";
                op.res = NULL;
                op.arg1 = NULL;
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);







            }
#line 1726 "lexico.tab.c"
    break;

  case 25: /* print_item: STRING  */
#line 525 "lexico.y"
             {  
                

                
                añadeEntrada((yyvsp[0].c), CADENA, contCadena++); 
                
                
                (yyval.lc) = creaLC();
                Operacion op;
                op.op = "la";
                op.res = "$a0";
                char* str;
                asprintf(&str,"$str%d",contCadena-1);
                op.arg1 = str;
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                op.op = "li";
                op.res = "$v0";
                op.arg1 = "4";
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                op.op = "syscall";
                op.res = NULL;
                op.arg1 = NULL;
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);

    }
#line 1759 "lexico.tab.c"
    break;

  case 26: /* read_list: ID  */
#line 556 "lexico.y"
                {if (!(perteneceTablaS((yyvsp[0].c)))) {
                    printf("Error semantico en linea %d: %s no declarada\n", yylineno, (yyvsp[0].c)); 
                    semantic_errors_count++;
                    }  
                else if (esConstante((yyvsp[0].c))) {
                    printf("Error semantico en linea %d: %s es constante\n", yylineno, (yyvsp[0].c));
                    semantic_errors_count++;                    
                    }
               
                

                (yyval.lc)=creaLC();
                Operacion op;
                op.op="li";
                op.res = "$v0";
                op.arg1="5";
                op.arg2=NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                op.op="syscall";
                op.res = NULL;
                op.arg1 = NULL;
                op.arg2 = NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                op.op="sw";
                op.res="$v0";
                op.arg1=concatena("_",(yyvsp[0].c));
                op.arg2=NULL;
                insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                liberarReg(op.res);
                }
#line 1794 "lexico.tab.c"
    break;

  case 27: /* read_list: read_list COMMA ID  */
#line 587 "lexico.y"
                {if (!(perteneceTablaS((yyvsp[0].c)))) {
                    printf("Error semantico en linea %d: %s no declarada\n", yylineno, (yyvsp[0].c));
                    semantic_errors_count++;        
                }
                else if ((esConstante((yyvsp[0].c)))) {
                    printf("Error semantico en linea %d: %s es constante\n", yylineno, (yyvsp[0].c));
                    semantic_errors_count++;
                    }
                

                 (yyval.lc)=(yyvsp[-2].lc);
                  Operacion op;
                  op.op="li";
                  op.res = "$v0";
                  op.arg1="5";
                  op.arg2=NULL;
                  insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                  op.op="syscall";
                  op.res = NULL;
                  op.arg1 = NULL;
                  op.arg2 = NULL;
                  insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                  op.op="sw";
                  op.res="$v0";
                  op.arg1=concatena("_",(yyvsp[0].c));
                  op.arg2=NULL;
                  insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                  liberarReg(op.res);


                }
#line 1830 "lexico.tab.c"
    break;

  case 28: /* relative_expression: expression MENOR expression  */
#line 623 "lexico.y"
                                                {
                        (yyval.lc)=(yyvsp[-2].lc);
                        concatenaLC((yyval.lc),(yyvsp[0].lc));
                        Operacion op;
                        op.op="slt";
                        op.res=recuperaResLC((yyvsp[-2].lc));
                        op.arg1=recuperaResLC((yyvsp[-2].lc));
                        op.arg2=recuperaResLC((yyvsp[0].lc));
                        insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                        liberaLC((yyvsp[0].lc));
                        liberarReg(op.arg2);
                    }
#line 1847 "lexico.tab.c"
    break;

  case 29: /* relative_expression: expression MAYOR expression  */
#line 636 "lexico.y"
                                                {
                        (yyval.lc)=(yyvsp[-2].lc);
                         concatenaLC((yyval.lc),(yyvsp[0].lc));
                         Operacion op;
                         op.op="sgt";
                         op.res=recuperaResLC((yyvsp[-2].lc));
                         op.arg1=recuperaResLC((yyvsp[-2].lc));
                         op.arg2=recuperaResLC((yyvsp[0].lc));
                         insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                         liberaLC((yyvsp[0].lc));
                         liberarReg(op.arg2);

                    }
#line 1865 "lexico.tab.c"
    break;

  case 30: /* relative_expression: expression MENORIGUAL expression  */
#line 650 "lexico.y"
                                                   {

                    (yyval.lc)=(yyvsp[-2].lc);
                    concatenaLC((yyval.lc),(yyvsp[0].lc));
                    Operacion op;
                    op.op="sle";
                    op.res=recuperaResLC((yyvsp[-2].lc));
                    op.arg1=recuperaResLC((yyvsp[-2].lc));
                    op.arg2=recuperaResLC((yyvsp[0].lc));
                    insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                    liberaLC((yyvsp[0].lc));
                    liberarReg(op.arg2);
                }
#line 1883 "lexico.tab.c"
    break;

  case 31: /* relative_expression: expression MAYORIGUAL expression  */
#line 664 "lexico.y"
                                                  {
                    (yyval.lc)=(yyvsp[-2].lc);
                    concatenaLC((yyval.lc),(yyvsp[0].lc));
                    Operacion op;
                    op.op="sge";
                    op.res=recuperaResLC((yyvsp[-2].lc));
                    op.arg1=recuperaResLC((yyvsp[-2].lc));
                    op.arg2=recuperaResLC((yyvsp[0].lc));
                    insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                    liberaLC((yyvsp[0].lc));
                    liberarReg(op.arg2);
                }
#line 1900 "lexico.tab.c"
    break;

  case 32: /* relative_expression: expression IGUAL expression  */
#line 676 "lexico.y"
                                              {
                    (yyval.lc)=(yyvsp[-2].lc);
                     concatenaLC((yyval.lc),(yyvsp[0].lc));
                     Operacion op;
                     op.op="seq";
                     op.res=recuperaResLC((yyvsp[-2].lc));
                     op.arg1=recuperaResLC((yyvsp[-2].lc));
                     op.arg2=recuperaResLC((yyvsp[0].lc));
                     insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                     liberaLC((yyvsp[0].lc));
                     liberarReg(op.arg2);
                }
#line 1917 "lexico.tab.c"
    break;

  case 33: /* relative_expression: expression DISTINTO expression  */
#line 688 "lexico.y"
                                                {
                    (yyval.lc)=(yyvsp[-2].lc);
                     concatenaLC((yyval.lc),(yyvsp[0].lc));
                     Operacion op;
                     op.op="sne";
                     op.res=recuperaResLC((yyvsp[-2].lc));
                     op.arg1=recuperaResLC((yyvsp[-2].lc));
                     op.arg2=recuperaResLC((yyvsp[0].lc));
                     insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                     liberaLC((yyvsp[0].lc));
                     liberarReg(op.arg2);
                }
#line 1934 "lexico.tab.c"
    break;

  case 34: /* expression: expression PLUSOP expression  */
#line 707 "lexico.y"
                                 {
                    (yyval.lc) = (yyvsp[-2].lc);
                    concatenaLC((yyval.lc),(yyvsp[0].lc));
                    Operacion op; 
                    op.op = "add";
                    op.res = recuperaResLC((yyvsp[-2].lc));
                    op.arg1 = recuperaResLC((yyvsp[-2].lc));
                    op.arg2 = recuperaResLC((yyvsp[0].lc));
                    insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                    liberaLC((yyvsp[0].lc));
                    liberarReg(op.arg2); 
                }
#line 1951 "lexico.tab.c"
    break;

  case 35: /* expression: expression MINUSOP expression  */
#line 719 "lexico.y"
                                      {
                    (yyval.lc) = (yyvsp[-2].lc);
                    concatenaLC((yyval.lc),(yyvsp[0].lc));
                    Operacion op; 
                    op.op = "sub";
                    op.res = recuperaResLC((yyvsp[-2].lc));
                    op.arg1 = recuperaResLC((yyvsp[-2].lc));
                    op.arg2 = recuperaResLC((yyvsp[0].lc));
                    insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                    liberaLC((yyvsp[0].lc));
                    liberarReg(op.arg2); 
                }
#line 1968 "lexico.tab.c"
    break;

  case 36: /* expression: expression POR expression  */
#line 731 "lexico.y"
                                  {
                    (yyval.lc) = (yyvsp[-2].lc);
                    concatenaLC((yyval.lc),(yyvsp[0].lc));
                    Operacion oper; 
                    oper.op = "mul";
                    oper.res = recuperaResLC((yyvsp[-2].lc));
                    oper.arg1 = recuperaResLC((yyvsp[-2].lc));
                    oper.arg2 = recuperaResLC((yyvsp[0].lc));
                    insertaLC((yyval.lc),finalLC((yyval.lc)),oper);
                    liberaLC((yyvsp[0].lc));
                    liberarReg(oper.arg2); 
            }
#line 1985 "lexico.tab.c"
    break;

  case 37: /* expression: expression DIV expression  */
#line 743 "lexico.y"
                                   {   
                    (yyval.lc) = (yyvsp[-2].lc);
                     concatenaLC((yyval.lc),(yyvsp[0].lc));
                     Operacion op; 
                     op.op = "div";
                     op.res = recuperaResLC((yyvsp[-2].lc));  // registro destino
                     op.arg1 = recuperaResLC((yyvsp[-2].lc)); // primer operando
                     op.arg2 = recuperaResLC((yyvsp[0].lc)); // segundo operando
                     insertaLC((yyval.lc),finalLC((yyval.lc)),op);
                     liberaLC((yyvsp[0].lc));
                    liberarReg(recuperaResLC((yyvsp[0].lc))); 
        }
#line 2002 "lexico.tab.c"
    break;

  case 38: /* expression: LPAREN expression INTERR expression DOSPUNT expression RPAREN  */
#line 756 "lexico.y"
                                                                    {
    (yyval.lc) = creaLC();
    concatenaLC((yyval.lc), (yyvsp[-5].lc));  // Añadimos código de la condición

    char* etiq1 = nuevaEtiqueta();  // Etiqueta para el caso falso
    char* etiq2 = nuevaEtiqueta();  // Etiqueta para el final

    Operacion op;
    // Salto condicional: si es falso, salta a etiq1
    op.op = "beqz";
    op.res = recuperaResLC((yyvsp[-5].lc));
    op.arg1 = etiq1;
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);

    // Código para el caso verdadero
    concatenaLC((yyval.lc), (yyvsp[-3].lc));
    op.op = "b";
    op.res = NULL;
    op.arg1 = etiq2;
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);

    // Etiqueta para el caso falso
    op.op = concatena(etiq1, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);

    // Código para el caso falso
    concatenaLC((yyval.lc), (yyvsp[-1].lc));

    // Etiqueta final
    op.op = concatena(etiq2, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC((yyval.lc), finalLC((yyval.lc)), op);

    // Liberamos las listas y registros que ya no necesitamos
    liberaLC((yyvsp[-5].lc));
    liberaLC((yyvsp[-3].lc));
    liberaLC((yyvsp[-1].lc));
    liberarReg(recuperaResLC((yyvsp[-5].lc)));

    // El resultado final estará en el registro de $4 o $6
    guardaResLC((yyval.lc), recuperaResLC((yyvsp[-3].lc)));
    }
#line 2056 "lexico.tab.c"
    break;

  case 39: /* expression: MINUSOP expression  */
#line 805 "lexico.y"
                                        {
            (yyval.lc)=(yyvsp[0].lc);
            Operacion op;
            op.op="neg";
            op.res=recuperaResLC((yyvsp[0].lc));
            op.arg1=recuperaResLC((yyvsp[0].lc));
            op.arg2=NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
             guardaResLC((yyval.lc), recuperaResLC((yyvsp[0].lc)));
          }
#line 2071 "lexico.tab.c"
    break;

  case 40: /* expression: LPAREN expression RPAREN  */
#line 815 "lexico.y"
                                 {
            (yyval.lc) = (yyvsp[-1].lc); 
          }
#line 2079 "lexico.tab.c"
    break;

  case 41: /* expression: ID  */
#line 819 "lexico.y"
            {if (!(perteneceTablaS((yyvsp[0].c)))) {
                printf("Error semantico en linea %d: %s no declarada\n", yylineno, (yyvsp[0].c));
                semantic_errors_count++;
            }  
           
            (yyval.lc)=creaLC();
            Operacion op;
            op.op="lw";
            op.res = obtenerReg();
            op.arg1=concatena("_",(yyvsp[0].c));
            op.arg2=NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op);
            guardaResLC((yyval.lc),op.res);
            }
#line 2098 "lexico.tab.c"
    break;

  case 42: /* expression: NUM  */
#line 833 "lexico.y"
            {
           (yyval.lc)=creaLC();
            Operacion op;
            op.op="li";
            op.res = obtenerReg();
            op.arg1=(yyvsp[0].c);
            op.arg2=NULL;
            insertaLC((yyval.lc),finalLC((yyval.lc)),op); //donde la inserto,en que posicion, el que guardo
            guardaResLC((yyval.lc),op.res);
          }
#line 2113 "lexico.tab.c"
    break;


#line 2117 "lexico.tab.c"

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

#line 845 "lexico.y"



void yyerror(const char *s) {
   
    fprintf(stderr, "Error sintactico en linea %d cerca de '%s': %s\n", yylineno, yytext, s);
    syntactic_errors_count++;
    printf("\n # Errores lexicos: %d\n", lexical_errors_count);
    printf("# Errores sintacticos: %d\n", syntactic_errors_count);
    printf("# Errores semanticos: %d\n", semantic_errors_count);
}


// FUNCION PARA VER SI PERTENECE A LA TABLA
int perteneceTablaS(char *nombre) {
    if (nombre == NULL) return 0; 
    PosicionLista pos = buscaLS(tablaSimb, nombre);
    return (pos != finalLS(tablaSimb));
}

// FUNCION PARA AÑADIR LA ENTRADA 
void añadeEntrada(char *nombre, Tipo tipo, int valor) {
    Simbolo nuevoSimbolo;
    nuevoSimbolo.nombre = strdup(nombre);  
    nuevoSimbolo.tipo = tipo;
    nuevoSimbolo.valor = valor;  // inicializamos valor to 0

    insertaLS(tablaSimb, finalLS(tablaSimb), nuevoSimbolo);
}


//FUNCION PARA COMPROBAR SI ES CONSTANTE O NO
int esConstante(char *nombre) {
    if (nombre == NULL) return 0; 
    PosicionLista pos = buscaLS(tablaSimb, nombre);
    if (pos != finalLS(tablaSimb)) {
        Simbolo s = recuperaLS(tablaSimb, pos);
        return (s.tipo == CONSTANTE);
    }
    return 0; 
}


void imprimirTablaS() {
    printf("##########\n");
    printf(" # Seccion de datos\n");
    printf("\t.data\n\n");
    
    PosicionLista pos = inicioLS(tablaSimb);
    while (pos != finalLS(tablaSimb)) {
        Simbolo s = recuperaLS(tablaSimb, pos);
        if (s.tipo == VARIABLE || s.tipo == CONSTANTE) {
            printf("_%s: \t.word 0\n", s.nombre);
        } else if (s.tipo == CADENA) {
            printf("$str%d: \t.asciiz %s\n", s.valor, s.nombre);
        }
        pos = siguienteLS(tablaSimb, pos);
    }
    printf("\n\t.text\n");
}

char* nuevaEtiqueta(){
    char* etiq;
    asprintf(&etiq,"etiq%d",contador_etiq);  
    contador_etiq++;
    return etiq;
}

