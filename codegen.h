#ifndef CODEGEN_H
#define CODEGEN_H

#include "symtab.h"
#include <stdarg.h>

void init_codegen();
void generate_code(ASTNode *root);
void generate_stmt(ASTNode *node, FILE *fp);
void generate_expr(ASTNode *node, FILE *fp);
void generate_functions_and_structs(ASTNode *node, FILE *fp);
void generate_main_stmts(ASTNode *node, FILE *fp);
void generate_struct_members(ASTNode *node, FILE *fp);
int get_temp_var();
int get_label();
void emit_tac(const char *format, ...);
char* generate_expr_tac(ASTNode *node, FILE *fp);

#endif
