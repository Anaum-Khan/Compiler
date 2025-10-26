#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codegen.h"
#include "symtab.h"

static FILE *output_file;
static FILE *tac_file;
static int temp_count = 0;
static int label_count = 0;
static int tac_line = 1;

void init_codegen() {
    temp_count = 0;
    label_count = 0;
    tac_line = 1;
}

int get_temp_var() {
    return temp_count++;
}

int get_label() {
    return label_count++;
}

void emit_tac(const char *format, ...) {
    if (tac_file) {
        fprintf(tac_file, "%d: ", tac_line++);
        va_list args;
        va_start(args, format);
        vfprintf(tac_file, format, args);
        va_end(args);
        fprintf(tac_file, "\n");
    }
}

void generate_code(ASTNode *root) {
    output_file = fopen("output.c", "w");
    if (!output_file) {
        fprintf(stderr, "Error: Cannot create output file\n");
        return;
    }
    
    tac_file = fopen("three_address_code.txt", "w");
    if (tac_file) {
        fprintf(tac_file, "==== Three-Address Code ====\n");
    }
    
    fprintf(output_file, "#include <stdio.h>\n");
    fprintf(output_file, "#include <stdlib.h>\n");
    fprintf(output_file, "#include <string.h>\n\n");
    
    generate_functions_and_structs(root, output_file);
    
    fprintf(output_file, "int main() {\n");
    generate_main_stmts(root, output_file);
    fprintf(output_file, "return 0;\n");
    fprintf(output_file, "}\n");
    
    fclose(output_file);
    if (tac_file) {
        fclose(tac_file);
    }
}

void generate_functions_and_structs(ASTNode *node, FILE *fp) {
    if (node == NULL) return;
    
    if (node->type == NODE_STMT_LIST) {
        generate_functions_and_structs(node->data.list.first, fp);
        generate_functions_and_structs(node->data.list.second, fp);
    } else if (node->type == NODE_FUNC || node->type == NODE_STRUCT) {
        generate_stmt(node, fp);
    }
}

void generate_main_stmts(ASTNode *node, FILE *fp) {
    if (node == NULL) return;
    
    if (node->type == NODE_STMT_LIST) {
        generate_main_stmts(node->data.list.first, fp);
        generate_main_stmts(node->data.list.second, fp);
    } else if (node->type != NODE_FUNC && node->type != NODE_STRUCT) {
        generate_stmt(node, fp);
    }
}

void generate_stmt_list(ASTNode *node, FILE *fp) {
    if (node == NULL) return;
    
    if (node->type == NODE_STMT_LIST) {
        generate_stmt_list(node->data.list.first, fp);
        generate_stmt(node->data.list.second, fp);
    } else {
        generate_stmt(node, fp);
    }
}

void generate_struct_members(ASTNode *node, FILE *fp) {
    if (node == NULL) return;
    
    if (node->type == NODE_STMT_LIST) {
        generate_struct_members(node->data.list.first, fp);
        generate_struct_members(node->data.list.second, fp);
    } else if (node->type == NODE_DECL) {
        if (strcmp(node->data.decl.data_type, "Int") == 0) {
            fprintf(fp, "    int %s;\n", node->data.decl.name);
        } else if (strcmp(node->data.decl.data_type, "Double") == 0) {
            fprintf(fp, "    double %s;\n", node->data.decl.name);
        } else if (strcmp(node->data.decl.data_type, "Bool") == 0) {
            fprintf(fp, "    int %s;\n", node->data.decl.name);
        } else if (strcmp(node->data.decl.data_type, "String") == 0) {
            fprintf(fp, "    char *%s;\n", node->data.decl.name);
        } else {
            fprintf(fp, "    int %s;\n", node->data.decl.name);
        }
    }
}

void generate_stmt(ASTNode *node, FILE *fp) {
    if (node == NULL) return;
    
    switch (node->type) {
        case NODE_STMT_LIST:
            generate_stmt_list(node, fp);
            break;
            
        case NODE_DECL: {
            char *result = generate_expr_tac(node->data.decl.init, fp);
            emit_tac("%s = %s", node->data.decl.name, result);
            
            if (strcmp(node->data.decl.data_type, "Int") == 0) {
                fprintf(fp, "int %s = ", node->data.decl.name);
            } else if (strcmp(node->data.decl.data_type, "Double") == 0) {
                fprintf(fp, "double %s = ", node->data.decl.name);
            } else if (strcmp(node->data.decl.data_type, "Bool") == 0) {
                fprintf(fp, "int %s = ", node->data.decl.name);
            } else if (strcmp(node->data.decl.data_type, "String") == 0) {
                fprintf(fp, "char *%s = ", node->data.decl.name);
            } else if (strstr(node->data.decl.data_type, "[") != NULL) {
                fprintf(fp, "int %s[] = ", node->data.decl.name);
            } else {
                fprintf(fp, "int %s = ", node->data.decl.name);
            }
            generate_expr(node->data.decl.init, fp);
            fprintf(fp, ";\n");
            free(result);
            break;
        }
        
        case NODE_ASSIGN: {
            char *result = generate_expr_tac(node->data.assign.value, fp);
            emit_tac("%s = %s", node->data.assign.name, result);
            
            fprintf(fp, "%s = ", node->data.assign.name);
            generate_expr(node->data.assign.value, fp);
            fprintf(fp, ";\n");
            free(result);
            break;
        }
        
        case NODE_ARRAY_ASSIGN: {
            char *idx = generate_expr_tac(node->data.array_assign.index, fp);
            char *val = generate_expr_tac(node->data.array_assign.value, fp);
            emit_tac("%s[%s] = %s", node->data.array_assign.name, idx, val);
            
            fprintf(fp, "%s[", node->data.array_assign.name);
            generate_expr(node->data.array_assign.index, fp);
            fprintf(fp, "] = ");
            generate_expr(node->data.array_assign.value, fp);
            fprintf(fp, ";\n");
            free(idx);
            free(val);
            break;
        }
        
        case NODE_IF: {
            int label_else = get_label();
            int label_end = get_label();
            
            char *cond = generate_expr_tac(node->data.ifstmt.condition, fp);
            
            if (node->data.ifstmt.else_branch != NULL) {
                emit_tac("if %s == false goto L%d", cond, label_else);
                emit_tac("goto L%d", label_end);
                emit_tac("L%d:", label_else);
            } else {
                emit_tac("if %s == false goto L%d", cond, label_end);
            }
            
            fprintf(fp, "if (");
            generate_expr(node->data.ifstmt.condition, fp);
            fprintf(fp, ") {\n");
            
            if (node->data.ifstmt.else_branch != NULL) {
                emit_tac("L%d:", label_end);
            }
            
            generate_stmt(node->data.ifstmt.then_branch, fp);
            
            if (node->data.ifstmt.else_branch != NULL) {
                fprintf(fp, "} else {\n");
                generate_stmt(node->data.ifstmt.else_branch, fp);
            }
            fprintf(fp, "}\n");
            
            if (node->data.ifstmt.else_branch == NULL) {
                emit_tac("L%d:", label_end);
            }
            
            free(cond);
            break;
        }
        
        case NODE_WHILE: {
            int label_start = get_label();
            int label_end = get_label();
            
            emit_tac("L%d:", label_start);
            char *cond = generate_expr_tac(node->data.whilestmt.condition, fp);
            emit_tac("if %s == false goto L%d", cond, label_end);
            
            fprintf(fp, "while (");
            generate_expr(node->data.whilestmt.condition, fp);
            fprintf(fp, ") {\n");
            generate_stmt(node->data.whilestmt.body, fp);
            fprintf(fp, "}\n");
            
            emit_tac("goto L%d", label_start);
            emit_tac("L%d:", label_end);
            
            free(cond);
            break;
        }
        
        case NODE_REPEAT_WHILE: {
            int label_start = get_label();
            
            emit_tac("L%d:", label_start);
            
            fprintf(fp, "do {\n");
            generate_stmt(node->data.whilestmt.body, fp);
            fprintf(fp, "} while (");
            generate_expr(node->data.whilestmt.condition, fp);
            fprintf(fp, ");\n");
            
            char *cond = generate_expr_tac(node->data.whilestmt.condition, fp);
            emit_tac("if %s == true goto L%d", cond, label_start);
            free(cond);
            break;
        }
        
        case NODE_FOR: {
            int label_start = get_label();
            int label_end = get_label();
            
            emit_tac("%s = 0", node->data.forstmt.var);
            emit_tac("L%d:", label_start);
            char *range = generate_expr_tac(node->data.forstmt.range, fp);
            int temp = get_temp_var();
            emit_tac("t%d = %s < %s", temp, node->data.forstmt.var, range);
            emit_tac("if t%d == false goto L%d", temp, label_end);
            
            fprintf(fp, "for (int i = 0; i < ");
            generate_expr(node->data.forstmt.range, fp);
            fprintf(fp, "; i++) {\n");
            fprintf(fp, "int %s = i;\n", node->data.forstmt.var);
            generate_stmt(node->data.forstmt.body, fp);
            fprintf(fp, "}\n");
            
            emit_tac("%s = %s + 1", node->data.forstmt.var, node->data.forstmt.var);
            emit_tac("goto L%d", label_start);
            emit_tac("L%d:", label_end);
            
            free(range);
            break;
        }
        
        case NODE_SWITCH: {
            char *expr = generate_expr_tac(node->data.switchstmt.expr, fp);
            
            fprintf(fp, "switch (");
            generate_expr(node->data.switchstmt.expr, fp);
            fprintf(fp, ") {\n");
            generate_stmt(node->data.switchstmt.cases, fp);
            fprintf(fp, "}\n");
            
            free(expr);
            break;
        }
        
        case NODE_CASE: {
            char *case_val = generate_expr_tac(node->data.casestmt.expr, fp);
            emit_tac("case %s:", case_val);
            
            fprintf(fp, "case ");
            generate_expr(node->data.casestmt.expr, fp);
            fprintf(fp, ":\n");
            generate_stmt(node->data.casestmt.stmts, fp);
            fprintf(fp, "break;\n");
            
            free(case_val);
            break;
        }
        
        case NODE_DEFAULT:
            emit_tac("default:");
            fprintf(fp, "default:\n");
            generate_stmt(node->data.casestmt.stmts, fp);
            fprintf(fp, "break;\n");
            break;
            
        case NODE_FUNC: {
            emit_tac("func_%s:", node->data.func.name);
            
            if (strcmp(node->data.func.return_type, "Int") == 0) {
                fprintf(fp, "int ");
            } else if (strcmp(node->data.func.return_type, "Double") == 0) {
                fprintf(fp, "double ");
            } else if (strcmp(node->data.func.return_type, "Void") == 0) {
                fprintf(fp, "void ");
            } else {
                fprintf(fp, "int ");
            }
            
            fprintf(fp, "%s(", node->data.func.name);
            
            ASTNode *param = node->data.func.params;
            int first = 1;
            while (param != NULL) {
                if (param->type == NODE_STMT_LIST) {
                    ASTNode *p = param->data.list.second;
                    if (p && p->type == NODE_PARAM) {
                        if (!first) fprintf(fp, ", ");
                        if (strcmp(p->data.param.param_type, "Int") == 0) {
                            fprintf(fp, "int %s", p->data.param.name);
                        } else if (strcmp(p->data.param.param_type, "Double") == 0) {
                            fprintf(fp, "double %s", p->data.param.name);
                        } else {
                            fprintf(fp, "int %s", p->data.param.name);
                        }
                        first = 0;
                    }
                    param = param->data.list.first;
                } else if (param->type == NODE_PARAM) {
                    if (!first) fprintf(fp, ", ");
                    if (strcmp(param->data.param.param_type, "Int") == 0) {
                        fprintf(fp, "int %s", param->data.param.name);
                    } else if (strcmp(param->data.param.param_type, "Double") == 0) {
                        fprintf(fp, "double %s", param->data.param.name);
                    } else {
                        fprintf(fp, "int %s", param->data.param.name);
                    }
                    break;
                } else {
                    break;
                }
            }
            
            fprintf(fp, ") {\n");
            generate_stmt(node->data.func.body, fp);
            fprintf(fp, "}\n\n");
            
            emit_tac("end_func %s", node->data.func.name);
            break;
        }
        
        case NODE_STRUCT: {
            fprintf(fp, "struct %s {\n", node->data.structdef.name);
            generate_struct_members(node->data.structdef.members, fp);
            fprintf(fp, "};\n\n");
            break;
        }
        
        case NODE_RETURN: {
            char *result = generate_expr_tac(node->data.retstmt.expr, fp);
            emit_tac("return %s", result);
            
            fprintf(fp, "return ");
            generate_expr(node->data.retstmt.expr, fp);
            fprintf(fp, ";\n");
            free(result);
            break;
        }
        
        case NODE_PRINT: {
            char *result = generate_expr_tac(node->data.printstmt.expr, fp);
            emit_tac("print %s", result);
            
            fprintf(fp, "printf(\"%%d\\n\", ");
            generate_expr(node->data.printstmt.expr, fp);
            fprintf(fp, ");\n");
            free(result);
            break;
        }
        
        default:
            generate_expr(node, fp);
            fprintf(fp, ";\n");
            break;
    }
}

char* generate_expr_tac(ASTNode *node, FILE *fp) {
    if (node == NULL) {
        char *result = malloc(10);
        strcpy(result, "NULL");
        return result;
    }
    
    char *result = malloc(100);
    
    switch (node->type) {
        case NODE_BINOP: {
            char *left = generate_expr_tac(node->data.binop.left, fp);
            char *right = generate_expr_tac(node->data.binop.right, fp);
            int temp = get_temp_var();
            emit_tac("t%d = %s %s %s", temp, left, node->data.binop.op, right);
            sprintf(result, "t%d", temp);
            free(left);
            free(right);
            break;
        }
        
        case NODE_UNOP: {
            char *operand = generate_expr_tac(node->data.unop.operand, fp);
            int temp = get_temp_var();
            emit_tac("t%d = %s%s", temp, node->data.unop.op, operand);
            sprintf(result, "t%d", temp);
            free(operand);
            break;
        }
        
        case NODE_ID:
            sprintf(result, "%s", node->data.id.name);
            break;
            
        case NODE_INT:
            sprintf(result, "%d", node->data.ival.value);
            break;
            
        case NODE_DOUBLE:
            sprintf(result, "%f", node->data.fval.value);
            break;
            
        case NODE_STRING:
            sprintf(result, "%s", node->data.sval.value);
            break;
            
        case NODE_BOOL:
            sprintf(result, "%d", node->data.ival.value);
            break;
            
        case NODE_CHAR:
            sprintf(result, "%s", node->data.sval.value);
            break;
            
        case NODE_MEMBER_ACCESS: {
            char *obj = generate_expr_tac(node->data.member_access.object, fp);
            sprintf(result, "%s.%s", obj, node->data.member_access.member);
            free(obj);
            break;
        }
        
        case NODE_ARRAY_ACCESS: {
            char *arr = generate_expr_tac(node->data.array_access.array, fp);
            char *idx = generate_expr_tac(node->data.array_access.index, fp);
            int temp = get_temp_var();
            emit_tac("t%d = %s[%s]", temp, arr, idx);
            sprintf(result, "t%d", temp);
            free(arr);
            free(idx);
            break;
        }
        
        case NODE_FUNC_CALL: {
            int temp = get_temp_var();
            emit_tac("t%d = call %s", temp, node->data.func_call.name);
            sprintf(result, "t%d", temp);
            break;
        }
        
        case NODE_ARRAY_LITERAL: {
            sprintf(result, "{...}");
            break;
        }
        
        case NODE_NAMED_ARG:
            return generate_expr_tac(node->data.named_arg.expr, fp);
            
        default:
            sprintf(result, "unknown");
            break;
    }
    
    return result;
}

void generate_expr(ASTNode *node, FILE *fp) {
    if (node == NULL) return;
    
    switch (node->type) {
        case NODE_BINOP:
            fprintf(fp, "(");
            generate_expr(node->data.binop.left, fp);
            fprintf(fp, " %s ", node->data.binop.op);
            generate_expr(node->data.binop.right, fp);
            fprintf(fp, ")");
            break;
            
        case NODE_UNOP:
            fprintf(fp, "%s", node->data.unop.op);
            generate_expr(node->data.unop.operand, fp);
            break;
            
        case NODE_ID:
            fprintf(fp, "%s", node->data.id.name);
            break;
            
        case NODE_INT:
            fprintf(fp, "%d", node->data.ival.value);
            break;
            
        case NODE_DOUBLE:
            fprintf(fp, "%f", node->data.fval.value);
            break;
            
        case NODE_STRING:
            fprintf(fp, "%s", node->data.sval.value);
            break;
            
        case NODE_BOOL:
            fprintf(fp, "%d", node->data.ival.value);
            break;
            
        case NODE_CHAR:
            fprintf(fp, "%s", node->data.sval.value);
            break;
            
        case NODE_MEMBER_ACCESS:
            generate_expr(node->data.member_access.object, fp);
            fprintf(fp, ".%s", node->data.member_access.member);
            break;
            
        case NODE_ARRAY_ACCESS:
            generate_expr(node->data.array_access.array, fp);
            fprintf(fp, "[");
            generate_expr(node->data.array_access.index, fp);
            fprintf(fp, "]");
            break;
            
        case NODE_FUNC_CALL: {
            fprintf(fp, "%s(", node->data.func_call.name);
            ASTNode *arg = node->data.func_call.args;
            int first = 1;
            while (arg != NULL) {
                if (arg->type == NODE_STMT_LIST) {
                    if (!first) fprintf(fp, ", ");
                    generate_expr(arg->data.list.second, fp);
                    first = 0;
                    arg = arg->data.list.first;
                } else {
                    if (!first) fprintf(fp, ", ");
                    generate_expr(arg, fp);
                    break;
                }
            }
            fprintf(fp, ")");
            break;
        }
        
        case NODE_ARRAY_LITERAL: {
            fprintf(fp, "{");
            ASTNode *elem = node->data.list.first;
            int first = 1;
            while (elem != NULL) {
                if (elem->type == NODE_STMT_LIST) {
                    if (!first) fprintf(fp, ", ");
                    generate_expr(elem->data.list.second, fp);
                    first = 0;
                    elem = elem->data.list.first;
                } else {
                    if (!first) fprintf(fp, ", ");
                    generate_expr(elem, fp);
                    break;
                }
            }
            fprintf(fp, "}");
            break;
        }
        
        case NODE_NAMED_ARG:
            generate_expr(node->data.named_arg.expr, fp);
            break;
            
        default:
            break;
    }
}
