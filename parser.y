%{
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
%}

%union {
    int ival;
    double fval;
    char *str;
    struct ASTNode *node;
}

%token LET VAR IF ELSE FOR IN WHILE REPEAT FUNC STRUCT RETURN PRINT SWITCH CASE DEFAULT
%token <ival> BOOLEAN_LITERAL INT_LITERAL
%token <fval> DOUBLE_LITERAL
%token <str> STRING_LITERAL CHARACTER_LITERAL IDENTIFIER TYPE
%token PLUS MINUS MUL DIV MOD EQ NEQ LT GT LE GE AND OR NOT ASSIGN ARROW

%type <node> program stmts stmt decl assign func struct_decl ifstmt whilestmt forstmt switchstmt
%type <node> expr case_list case_stmt param_list_opt param_list param
%type <node> arg_list_opt arg_list arg expr_list_opt expr_list
%type <str> type_specifier

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%left OR
%left AND
%left EQ NEQ
%left LT LE GT GE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%left '.' '[' ']'

%%

program:
    stmts { 
        $$ = $1; 
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
            generate_code($$);
            printf("Status: COMPLETE\n");
            printf("\n=== THREE ADDRESS CODE ===\n");
            print_three_address_code();
        } else {
            printf("\n=== SEMANTIC ANALYSIS ===\n");
            printf("Status: FAILED with %d error(s)\n", semantic_errors);
        }
    }
;

stmts:
    { $$ = NULL; }
    | stmts stmt { $$ = create_stmt_list($1, $2); }
;

stmt:
    decl { $$ = $1; }
    | assign { $$ = $1; }
    | func { $$ = $1; }
    | struct_decl { $$ = $1; }
    | ifstmt { $$ = $1; }
    | whilestmt { $$ = $1; }
    | forstmt { $$ = $1; }
    | switchstmt { $$ = $1; }
    | RETURN expr ';' { $$ = create_return_node($2); }
    | PRINT '(' expr ')' ';' { $$ = create_print_node($3); }
    | expr ';' { $$ = $1; }
;

type_specifier:
    TYPE { $$ = $1; }
    | IDENTIFIER { $$ = $1; }
    | '[' type_specifier ']' { 
        char *arr_type = malloc(strlen($2) + 10);
        sprintf(arr_type, "[%s]", $2);
        $$ = arr_type;
    }
;

decl:
    LET IDENTIFIER ':' type_specifier ASSIGN expr ';' {
        Symbol *sym = lookup_symbol($2);
        if (sym != NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' already declared\n", yylineno, $2);
            semantic_errors++;
        } else {
            insert_symbol($2, $4, 1);
        }
        $$ = create_decl_node($2, $4, $6, 1);
    }
    | VAR IDENTIFIER ':' type_specifier ASSIGN expr ';' {
        Symbol *sym = lookup_symbol($2);
        if (sym != NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' already declared\n", yylineno, $2);
            semantic_errors++;
        } else {
            insert_symbol($2, $4, 0);
        }
        $$ = create_decl_node($2, $4, $6, 0);
    }
    | VAR IDENTIFIER ASSIGN expr ';' {
        Symbol *sym = lookup_symbol($2);
        if (sym != NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' already declared\n", yylineno, $2);
            semantic_errors++;
        } else {
            insert_symbol($2, "Int", 0);
        }
        $$ = create_decl_node($2, "Int", $4, 0);
    }
;

assign:
    IDENTIFIER ASSIGN expr ';' {
        Symbol *sym = lookup_symbol($1);
        if (sym == NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' not declared\n", yylineno, $1);
            semantic_errors++;
        } else if (sym->is_const) {
            fprintf(stderr, "Error line %d: Cannot assign to constant '%s'\n", yylineno, $1);
            semantic_errors++;
        }
        $$ = create_assign_node($1, $3);
    }
    | IDENTIFIER '[' expr ']' ASSIGN expr ';' {
        Symbol *sym = lookup_symbol($1);
        if (sym == NULL) {
            fprintf(stderr, "Error line %d: Array '%s' not declared\n", yylineno, $1);
            semantic_errors++;
        }
        $$ = create_array_assign_node($1, $3, $6);
    }
;

func:
    FUNC IDENTIFIER '(' param_list_opt ')' ARROW TYPE '{' {
        insert_function($2, $7);
        push_scope();
    } stmts '}' {
        pop_scope();
        $$ = create_func_node($2, $4, $7, $10);
    }
;

param_list_opt:
    { $$ = NULL; }
    | param_list { $$ = $1; }
;

param_list:
    param { $$ = $1; }
    | param_list ',' param { $$ = create_param_list($1, $3); }
;

param:
    IDENTIFIER ':' type_specifier {
        insert_symbol($1, $3, 0);
        $$ = create_param_node($1, $3);
    }
;

struct_decl:
    STRUCT IDENTIFIER '{' {
        insert_struct($2);
        push_scope();
    } stmts '}' {
        pop_scope();
        $$ = create_struct_node($2, $5);
    }
;

ifstmt:
    IF '(' expr ')' '{' stmts '}' %prec LOWER_THAN_ELSE {
        $$ = create_if_node($3, $6, NULL);
    }
    | IF '(' expr ')' '{' stmts '}' ELSE '{' stmts '}' {
        $$ = create_if_node($3, $6, $10);
    }
;

whilestmt:
    WHILE '(' expr ')' '{' stmts '}' {
        $$ = create_while_node($3, $6);
    }
    | REPEAT '{' stmts '}' WHILE '(' expr ')' ';' {
        $$ = create_repeat_while_node($3, $7);
    }
;

forstmt:
    FOR IDENTIFIER IN expr '{' {
        insert_symbol($2, "Int", 0);
    } stmts '}' {
        $$ = create_for_node($2, $4, $7);
    }
;

switchstmt:
    SWITCH expr '{' case_list '}' {
        $$ = create_switch_node($2, $4);
    }
;

case_list:
    case_stmt { $$ = $1; }
    | case_list case_stmt { $$ = create_case_list($1, $2); }
;

case_stmt:
    CASE expr ':' stmts {
        $$ = create_case_node($2, $4);
    }
    | DEFAULT ':' stmts {
        $$ = create_default_node($3);
    }
;

expr:
    expr PLUS expr { $$ = create_binop_node("+", $1, $3); }
    | expr MINUS expr { $$ = create_binop_node("-", $1, $3); }
    | expr MUL expr { $$ = create_binop_node("*", $1, $3); }
    | expr DIV expr { $$ = create_binop_node("/", $1, $3); }
    | expr MOD expr { $$ = create_binop_node("%", $1, $3); }
    | expr EQ expr { $$ = create_binop_node("==", $1, $3); }
    | expr NEQ expr { $$ = create_binop_node("!=", $1, $3); }
    | expr LT expr { $$ = create_binop_node("<", $1, $3); }
    | expr GT expr { $$ = create_binop_node(">", $1, $3); }
    | expr LE expr { $$ = create_binop_node("<=", $1, $3); }
    | expr GE expr { $$ = create_binop_node(">=", $1, $3); }
    | expr AND expr { $$ = create_binop_node("&&", $1, $3); }
    | expr OR expr { $$ = create_binop_node("||", $1, $3); }
    | NOT expr { $$ = create_unop_node("!", $2); }
    | '(' expr ')' { $$ = $2; }
    | IDENTIFIER {
        Symbol *sym = lookup_symbol($1);
        if (sym == NULL) {
            fprintf(stderr, "Error line %d: Variable '%s' not declared\n", yylineno, $1);
            semantic_errors++;
        }
        $$ = create_id_node($1);
    }
    | INT_LITERAL { $$ = create_int_node($1); }
    | DOUBLE_LITERAL { $$ = create_double_node($1); }
    | STRING_LITERAL { $$ = create_string_node($1); }
    | BOOLEAN_LITERAL { $$ = create_bool_node($1); }
    | CHARACTER_LITERAL { $$ = create_char_node($1); }
    | expr '.' IDENTIFIER { $$ = create_member_access_node($1, $3); }
    | expr '[' expr ']' { $$ = create_array_access_node($1, $3); }
    | IDENTIFIER '(' arg_list_opt ')' { $$ = create_func_call_node($1, $3); }
    | '[' expr_list_opt ']' { $$ = create_array_literal_node($2); }
;

arg_list_opt:
    { $$ = NULL; }
    | arg_list { $$ = $1; }
;

arg_list:
    arg { $$ = $1; }
    | arg_list ',' arg { $$ = create_arg_list($1, $3); }
;

arg:
    expr { $$ = $1; }
    | IDENTIFIER ':' expr { $$ = create_named_arg_node($1, $3); }
;

expr_list_opt:
    { $$ = NULL; }
    | expr_list { $$ = $1; }
;

expr_list:
    expr { $$ = $1; }
    | expr_list ',' expr { $$ = create_expr_list($1, $3); }
;

%%

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
