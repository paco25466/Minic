%code requires {
    #include "listaCodigo.h"
    #include "listaSimbolos.h"
}

%{

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

%}






%union{
    ListaC lc; 
    char *c;
}


%token READ VAR CONST INT IF ELSE WHILE PRINT LPAREN RPAREN SEMICOLON COMMA ASSIGNOP LCORCH RCORCH INTERR DOSPUNT PLUSOP MINUSOP DIV POR DO MENOR MAYOR MENORIGUAL MAYORIGUAL IGUAL DISTINTO
%token <c> NUM
%token <c> ID
%token <c> STRING

%type <lc>  declarations  var_list const_list statement_list statement expression print_list print_item read_list relative_expression

%left PLUSOP MINUSOP
%left DIV POR
%left UMINUS

%expect 1
%%


program:  {
            tablaSimb=creaLS();
            semantic_errors_count = 0; // Inicializar contadores
            syntactic_errors_count = 0;
            lexical_errors_count = 0;   // Inicializar
          }
          ID LPAREN RPAREN LCORCH declarations statement_list RCORCH
          {
            if(semantic_errors_count + syntactic_errors_count + lexical_errors_count == 0) {

                
                concatenaLC($6,$7);
                imprimirTablaS();  
                imprimirLC($6);

                liberaLC($6);
                liberaLC($7);
                liberaLS(tablaSimb);
                
            } else {
                printf("\n# Errores lexicos: %d\n", lexical_errors_count);
                printf("# Errores sintacticos: %d\n", syntactic_errors_count);
                printf("# Errores semanticos: %d\n", semantic_errors_count);
            }
            
            
          }
    ;


declarations : declarations VAR tipo var_list SEMICOLON
          {
            $$=$1;             
            concatenaLC($$,$4);     
            liberaLC($4);    
           
          }
    | declarations CONST tipo const_list SEMICOLON
          {
            $$=$1;    
            concatenaLC($$,$4); 
            liberaLC($4);
          }
    |   /* LAMBDA */  { $$=creaLC(); }
    ;

tipo :    INT  {
             
          };

var_list :   ID  {
            
            if (!(perteneceTablaS($1))) {
                 añadeEntrada($1,VARIABLE,0);
            } else {
                 fprintf(stderr, "Error semantico en linea %d: %s ya declarada\n", yylineno, $1); 
                 semantic_errors_count++;
            }
            
            
             $$ = creaLC(); 
          }
    | var_list COMMA ID {
            if (!(perteneceTablaS($3))) {
                 añadeEntrada($3,VARIABLE,0);
            } else {
                 fprintf(stderr, "Error semantico en linea %d: %s ya declarada\n", yylineno, $3); 
                 semantic_errors_count++;
            }
            
             $$ = creaLC(); 
            
          }
    ;



const_list : ID ASSIGNOP expression {
            if (!(perteneceTablaS($1))) 
                    añadeEntrada($1, CONSTANTE,0);
                else {
                    printf("Error  semantico en linea %d: %s ya declarada\n", yylineno, $1);
                    semantic_errors_count++;
                } 
                    

            $$ = $3;  // Código de la expresión
            Operacion op;
            op.op = "sw"; 
            op.res = recuperaResLC($3);  
            char* mem_addr = concatena("_", $1); 
            op.arg1 = mem_addr;  
            op.arg2 = NULL;
            insertaLC($$, finalLC($$), op);  
            liberarReg(op.res);  
           
           
          }



    | const_list COMMA ID ASSIGNOP expression {
            if (!(perteneceTablaS($3))) 
                    añadeEntrada($3, CONSTANTE,0);
                else {
                    printf("Error semantico en linea %d: %s ya declarada\n", yylineno, $3);
                    semantic_errors_count++;
                }
                

            
            Operacion op;
            op.op = "sw"; 
            op.res = recuperaResLC($5);  
            op.arg1 = concatena("_", $3); 
            op.arg2 = NULL;
            insertaLC($5, finalLC($5), op);  
            liberarReg(op.res);

            
            concatenaLC($1, $5);
            $$ = $1;  
            liberaLC($5);  

            
          
          }
    ;

statement_list : statement_list statement {
            $$ = $1;
            concatenaLC($$,$2);
            liberaLC($2);
          }
    |   /* LAMBDA */  { $$=creaLC(); }
    ;

statement : ID ASSIGNOP expression SEMICOLON {  
    if (!(perteneceTablaS($1))) {
        printf("Error semantico en linea %d: %s no declarada\n", yylineno, $1);
        semantic_errors_count++;
    }       
    else if ((esConstante($1))) {
            printf("Error semantico en linea %d: %s es constante\n", yylineno, $1);
            semantic_errors_count++;      
        }
        
                $$ = $3;                        
                Operacion op; 
                op.op = "sw"; 
                op.res = recuperaResLC($3);     
                op.arg1 = concatena("_",$1);   
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);    
                liberarReg(op.res);              
    }

    |   LCORCH statement_list RCORCH {$$ = $2;}

    |   IF LPAREN relative_expression RPAREN statement ELSE statement {
            $$ = $3;   
            Operacion op;
            char* etiqElse = nuevaEtiqueta();    
            char* etiqEndIf = nuevaEtiqueta();   

           
           op.op = "beqz";
            op.res = recuperaResLC($3);
            op.arg1 = etiqElse; 
            op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
            liberarReg(op.res); 

            
            concatenaLC($$,$5);
            liberaLC($5);

            
           op.op = "b";
            op.res = NULL;
            op.arg1 = etiqEndIf; 
            op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
            

            
            op.op = concatena(etiqElse,":"); 
            op.res = NULL;
            op.arg1 = NULL;
            op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
           
           

            
            concatenaLC($$,$7);
            liberaLC($7);

           
            op.op = concatena(etiqEndIf,":"); 
            op.res = NULL;
            op.arg1 = NULL;
            op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
            
          

            
         }
    |   IF LPAREN relative_expression RPAREN statement {
            $$ = $3;    
            Operacion op;
            char* etiqEndIf = nuevaEtiqueta();    

            
            op.op = "beqz";
            op.res = recuperaResLC($3);
            op.arg1 = etiqEndIf;    
            op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
            liberarReg(op.res); 

           
            concatenaLC($$,$5);
            liberaLC($5);

            
            op.op = concatena(etiqEndIf,":"); 
            op.res = NULL;
            op.arg1 = NULL;
            op.arg2 = NULL;
            insertaLC($$,finalLC($$),op);
           
            

            
          }
    |  WHILE LPAREN relative_expression RPAREN statement {
    $$ = creaLC();
    
    // Etiqueta de inicio del while
    char* etiqInicio = nuevaEtiqueta();
    char* etiqFin = nuevaEtiqueta();
    
    // Etiqueta de inicio
    Operacion op;
    op.op = concatena(etiqInicio, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);
    
    // Añadir código de la expresión
    concatenaLC($$, $3);
    
    // beqz para salir del bucle
    op.op = "beqz";
    op.res = recuperaResLC($3);
    op.arg1 = etiqFin;  // SIN los ":"
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);
    liberarReg(op.res);
    
    // Código del cuerpo del while
    concatenaLC($$, $5);
    
    // Salto al inicio del while
    op.op = "b";
    op.res = NULL;
    op.arg1 = etiqInicio;  // SIN los ":"
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);
    
    // Etiqueta de fin
    op.op = concatena(etiqFin, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);
    
    // Liberar memoria
    liberaLC($3);
    liberaLC($5);
}



    |   DO statement WHILE LPAREN relative_expression RPAREN SEMICOLON{
        $$ = creaLC();
        
        // Etiqueta de inicio del do-while
        char* etiqInicio = nuevaEtiqueta();
        
        // Etiqueta de inicio
        Operacion op;
        op.op = concatena(etiqInicio, ":");
        op.res = NULL;
        op.arg1 = NULL;
        op.arg2 = NULL;
        insertaLC($$, finalLC($$), op);
        
        // Código del cuerpo del do-while (se ejecuta al menos una vez)
        concatenaLC($$, $2);
        
        // Añadir código de la expresión de condición
        concatenaLC($$, $5);
        
        // bnez para continuar el bucle (si la condición es verdadera, volver al inicio)
        op.op = "bnez";
        op.res = recuperaResLC($5);
        op.arg1 = etiqInicio;  // Volver al inicio si la condición es verdadera
        op.arg2 = NULL;
        insertaLC($$, finalLC($$), op);
        liberarReg(recuperaResLC($5));
        
        // Liberar memoria
        liberaLC($2);
        liberaLC($5);
    }




    |   PRINT LPAREN print_list RPAREN SEMICOLON    { $$ = $3; }
    |   READ LPAREN read_list RPAREN SEMICOLON   { $$=$3; }
    ;



print_list : print_item  {  $$=$1;  }
    |print_list COMMA print_item
          {
            $$=$1;
            concatenaLC($$,$3);
            liberaLC($3);
          }
    ;

print_item : expression
            {

                $$ = $1;
                 Operacion op;
                op.op = "move";
                op.res = "$a0";
                op.arg1 = recuperaResLC($1);
                op.arg2 = NULL;
                liberarReg(op.arg1);
                insertaLC($$,finalLC($$),op);
                
                op.op = "li";
                op.res = "$v0";
                op.arg1 = "1";
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);
               
                op.op = "syscall";
                op.res = NULL;
                op.arg1 = NULL;
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);







            }
            









    | STRING {  
                

                
                añadeEntrada($1, CADENA, contCadena++); 
                
                
                $$ = creaLC();
                Operacion op;
                op.op = "la";
                op.res = "$a0";
                char* str;
                asprintf(&str,"$str%d",contCadena-1);
                op.arg1 = str;
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);
                op.op = "li";
                op.res = "$v0";
                op.arg1 = "4";
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);
                op.op = "syscall";
                op.res = NULL;
                op.arg1 = NULL;
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);

    }
;

read_list : ID 
                {if (!(perteneceTablaS($1))) {
                    printf("Error semantico en linea %d: %s no declarada\n", yylineno, $1); 
                    semantic_errors_count++;
                    }  
                else if (esConstante($1)) {
                    printf("Error semantico en linea %d: %s es constante\n", yylineno, $1);
                    semantic_errors_count++;                    
                    }
               
                

                $$=creaLC();
                Operacion op;
                op.op="li";
                op.res = "$v0";
                op.arg1="5";
                op.arg2=NULL;
                insertaLC($$,finalLC($$),op);
                op.op="syscall";
                op.res = NULL;
                op.arg1 = NULL;
                op.arg2 = NULL;
                insertaLC($$,finalLC($$),op);
                op.op="sw";
                op.res="$v0";
                op.arg1=concatena("_",$1);
                op.arg2=NULL;
                insertaLC($$,finalLC($$),op);
                liberarReg(op.res);
                }
    | read_list COMMA ID 
                {if (!(perteneceTablaS($3))) {
                    printf("Error semantico en linea %d: %s no declarada\n", yylineno, $3);
                    semantic_errors_count++;        
                }
                else if ((esConstante($3))) {
                    printf("Error semantico en linea %d: %s es constante\n", yylineno, $3);
                    semantic_errors_count++;
                    }
                

                 $$=$1;
                  Operacion op;
                  op.op="li";
                  op.res = "$v0";
                  op.arg1="5";
                  op.arg2=NULL;
                  insertaLC($$,finalLC($$),op);
                  op.op="syscall";
                  op.res = NULL;
                  op.arg1 = NULL;
                  op.arg2 = NULL;
                  insertaLC($$,finalLC($$),op);
                  op.op="sw";
                  op.res="$v0";
                  op.arg1=concatena("_",$3);
                  op.arg2=NULL;
                  insertaLC($$,finalLC($$),op);
                  liberarReg(op.res);


                }
    ;



relative_expression:
                    expression MENOR expression {
                        $$=$1;
                        concatenaLC($$,$3);
                        Operacion op;
                        op.op="slt";
                        op.res=recuperaResLC($1);
                        op.arg1=recuperaResLC($1);
                        op.arg2=recuperaResLC($3);
                        insertaLC($$,finalLC($$),op);
                        liberaLC($3);
                        liberarReg(op.arg2);
                    }

                |   expression MAYOR expression {
                        $$=$1;
                         concatenaLC($$,$3);
                         Operacion op;
                         op.op="sgt";
                         op.res=recuperaResLC($1);
                         op.arg1=recuperaResLC($1);
                         op.arg2=recuperaResLC($3);
                         insertaLC($$,finalLC($$),op);
                         liberaLC($3);
                         liberarReg(op.arg2);

                    } 

                |  expression MENORIGUAL expression{

                    $$=$1;
                    concatenaLC($$,$3);
                    Operacion op;
                    op.op="sle";
                    op.res=recuperaResLC($1);
                    op.arg1=recuperaResLC($1);
                    op.arg2=recuperaResLC($3);
                    insertaLC($$,finalLC($$),op);
                    liberaLC($3);
                    liberarReg(op.arg2);
                }

                | expression MAYORIGUAL expression{
                    $$=$1;
                    concatenaLC($$,$3);
                    Operacion op;
                    op.op="sge";
                    op.res=recuperaResLC($1);
                    op.arg1=recuperaResLC($1);
                    op.arg2=recuperaResLC($3);
                    insertaLC($$,finalLC($$),op);
                    liberaLC($3);
                    liberarReg(op.arg2);
                }
                |  expression IGUAL expression{
                    $$=$1;
                     concatenaLC($$,$3);
                     Operacion op;
                     op.op="seq";
                     op.res=recuperaResLC($1);
                     op.arg1=recuperaResLC($1);
                     op.arg2=recuperaResLC($3);
                     insertaLC($$,finalLC($$),op);
                     liberaLC($3);
                     liberarReg(op.arg2);
                }
                |expression  DISTINTO expression{
                    $$=$1;
                     concatenaLC($$,$3);
                     Operacion op;
                     op.op="sne";
                     op.res=recuperaResLC($1);
                     op.arg1=recuperaResLC($1);
                     op.arg2=recuperaResLC($3);
                     insertaLC($$,finalLC($$),op);
                     liberaLC($3);
                     liberarReg(op.arg2);
                }
                





expression :
    expression PLUSOP expression {
                    $$ = $1;
                    concatenaLC($$,$3);
                    Operacion op; 
                    op.op = "add";
                    op.res = recuperaResLC($1);
                    op.arg1 = recuperaResLC($1);
                    op.arg2 = recuperaResLC($3);
                    insertaLC($$,finalLC($$),op);
                    liberaLC($3);
                    liberarReg(op.arg2); 
                }
    |   expression MINUSOP expression {
                    $$ = $1;
                    concatenaLC($$,$3);
                    Operacion op; 
                    op.op = "sub";
                    op.res = recuperaResLC($1);
                    op.arg1 = recuperaResLC($1);
                    op.arg2 = recuperaResLC($3);
                    insertaLC($$,finalLC($$),op);
                    liberaLC($3);
                    liberarReg(op.arg2); 
                }
    |   expression POR expression {
                    $$ = $1;
                    concatenaLC($$,$3);
                    Operacion oper; 
                    oper.op = "mul";
                    oper.res = recuperaResLC($1);
                    oper.arg1 = recuperaResLC($1);
                    oper.arg2 = recuperaResLC($3);
                    insertaLC($$,finalLC($$),oper);
                    liberaLC($3);
                    liberarReg(oper.arg2); 
            }
    |    expression DIV expression {   
                    $$ = $1;
                     concatenaLC($$,$3);
                     Operacion op; 
                     op.op = "div";
                     op.res = recuperaResLC($1);  // registro destino
                     op.arg1 = recuperaResLC($1); // primer operando
                     op.arg2 = recuperaResLC($3); // segundo operando
                     insertaLC($$,finalLC($$),op);
                     liberaLC($3);
                    liberarReg(recuperaResLC($3)); 
        }
          
    |  LPAREN expression INTERR expression DOSPUNT expression RPAREN{
    $$ = creaLC();
    concatenaLC($$, $2);  // Añadimos código de la condición

    char* etiq1 = nuevaEtiqueta();  // Etiqueta para el caso falso
    char* etiq2 = nuevaEtiqueta();  // Etiqueta para el final

    Operacion op;
    // Salto condicional: si es falso, salta a etiq1
    op.op = "beqz";
    op.res = recuperaResLC($2);
    op.arg1 = etiq1;
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);

    // Código para el caso verdadero
    concatenaLC($$, $4);
    op.op = "b";
    op.res = NULL;
    op.arg1 = etiq2;
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);

    // Etiqueta para el caso falso
    op.op = concatena(etiq1, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);

    // Código para el caso falso
    concatenaLC($$, $6);

    // Etiqueta final
    op.op = concatena(etiq2, ":");  // AÑADIR los ":"
    op.res = NULL;
    op.arg1 = NULL;
    op.arg2 = NULL;
    insertaLC($$, finalLC($$), op);

    // Liberamos las listas y registros que ya no necesitamos
    liberaLC($2);
    liberaLC($4);
    liberaLC($6);
    liberarReg(recuperaResLC($2));

    // El resultado final estará en el registro de $4 o $6
    guardaResLC($$, recuperaResLC($4));
    }
    |   MINUSOP expression %prec UMINUS {
            $$=$2;
            Operacion op;
            op.op="neg";
            op.res=recuperaResLC($2);
            op.arg1=recuperaResLC($2);
            op.arg2=NULL;
            insertaLC($$,finalLC($$),op);
             guardaResLC($$, recuperaResLC($2));
          }
    |   LPAREN expression RPAREN {
            $$ = $2; 
          }
          
    |   ID  {if (!(perteneceTablaS($1))) {
                printf("Error semantico en linea %d: %s no declarada\n", yylineno, $1);
                semantic_errors_count++;
            }  
           
            $$=creaLC();
            Operacion op;
            op.op="lw";
            op.res = obtenerReg();
            op.arg1=concatena("_",$1);
            op.arg2=NULL;
            insertaLC($$,finalLC($$),op);
            guardaResLC($$,op.res);
            }
    |   NUM {
           $$=creaLC();
            Operacion op;
            op.op="li";
            op.res = obtenerReg();
            op.arg1=$1;
            op.arg2=NULL;
            insertaLC($$,finalLC($$),op); //donde la inserto,en que posicion, el que guardo
            guardaResLC($$,op.res);
          }
    ;

%%


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

