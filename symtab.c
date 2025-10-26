#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

Symbol *symbol_table = NULL;
Function *function_table = NULL;
Struct *struct_table = NULL;
Symbol *scope_stack[100];
int scope_level = 0;

void init_symbol_table() {
    symbol_table = NULL;
    function_table = NULL;
    struct_table = NULL;
    scope_level = 0;
}

void push_scope() {
    scope_stack[scope_level++] = symbol_table;
}

void pop_scope() {
    if (scope_level > 0) {
        Symbol *current = symbol_table;
        Symbol *scope_start = scope_stack[--scope_level];
        
        while (current != scope_start) {
            Symbol *temp = current;
            current = current->next;
            free(temp->name);
            free(temp->type);
            free(temp);
        }
        symbol_table = scope_start;
    }
}

void insert_symbol(char *name, char *type, int is_const) {
    Symbol *sym = (Symbol *)malloc(sizeof(Symbol));
    sym->name = strdup(name);
    sym->type = strdup(type);
    sym->is_const = is_const;
    sym->next = symbol_table;
    symbol_table = sym;
}

Symbol *lookup_symbol(char *name) {
    Symbol *sym = symbol_table;
    while (sym != NULL) {
        if (strcmp(sym->name, name) == 0) {
            return sym;
        }
        sym = sym->next;
    }
    return NULL;
}

void insert_function(char *name, char *return_type) {
    Function *func = (Function *)malloc(sizeof(Function));
    func->name = strdup(name);
    func->return_type = strdup(return_type);
    func->next = function_table;
    function_table = func;
}

Function *lookup_function(char *name) {
    Function *func = function_table;
    while (func != NULL) {
        if (strcmp(func->name, name) == 0) {
            return func;
        }
        func = func->next;
    }
    return NULL;
}

void insert_struct(char *name) {
    Struct *str = (Struct *)malloc(sizeof(Struct));
    str->name = strdup(name);
    str->next = struct_table;
    struct_table = str;
}

Struct *lookup_struct(char *name) {
    Struct *str = struct_table;
    while (str != NULL) {
        if (strcmp(str->name, name) == 0) {
            return str;
        }
        str = str->next;
    }
    return NULL;
}

void print_symbol_table() {
    printf("\nSymbol Table Contents:\n");
    printf("----------------------\n");
    
    if (symbol_table == NULL) {
        printf("  (empty)\n");
        return;
    }
    
    Symbol *sym = symbol_table;
    while (sym != NULL) {
        printf("  Name: %-15s Type: %-10s Kind: %s\n", 
               sym->name, 
               sym->type, 
               sym->is_const ? "constant" : "variable");
        sym = sym->next;
    }
    
    if (function_table != NULL) {
        printf("\nFunctions:\n");
        Function *func = function_table;
        while (func != NULL) {
            printf("  Name: %-15s Return Type: %s\n", 
                   func->name, 
                   func->return_type);
            func = func->next;
        }
    }
    
    if (struct_table != NULL) {
        printf("\nStructures:\n");
        Struct *str = struct_table;
        while (str != NULL) {
            printf("  Name: %s\n", str->name);
            str = str->next;
        }
    }
}

void print_three_address_code() {
    FILE *tac = fopen("three_address_code.txt", "r");
    if (tac) {
        char line[256];
        while (fgets(line, sizeof(line), tac)) {
            printf("%s", line);
        }
        fclose(tac);
    } else {
        printf("\nThree-Address Code:\n");
        printf("-------------------\n");
        printf("Generated intermediate representation in three_address_code.txt\n");
    }
}

ASTNode *create_node(NodeType type) {
    ASTNode *node = (ASTNode *)malloc(sizeof(ASTNode));
    node->type = type;
    return node;
}

ASTNode *create_stmt_list(ASTNode *list, ASTNode *stmt) {
    ASTNode *node = create_node(NODE_STMT_LIST);
    node->data.list.first = list;
    node->data.list.second = stmt;
    return node;
}

ASTNode *create_decl_node(char *name, char *type, ASTNode *init, int is_const) {
    ASTNode *node = create_node(NODE_DECL);
    node->data.decl.name = strdup(name);
    node->data.decl.data_type = strdup(type);
    node->data.decl.init = init;
    node->data.decl.is_const = is_const;
    return node;
}

ASTNode *create_assign_node(char *name, ASTNode *value) {
    ASTNode *node = create_node(NODE_ASSIGN);
    node->data.assign.name = strdup(name);
    node->data.assign.value = value;
    return node;
}

ASTNode *create_array_assign_node(char *name, ASTNode *index, ASTNode *value) {
    ASTNode *node = create_node(NODE_ARRAY_ASSIGN);
    node->data.array_assign.name = strdup(name);
    node->data.array_assign.index = index;
    node->data.array_assign.value = value;
    return node;
}

ASTNode *create_binop_node(char *op, ASTNode *left, ASTNode *right) {
    ASTNode *node = create_node(NODE_BINOP);
    node->data.binop.op = strdup(op);
    node->data.binop.left = left;
    node->data.binop.right = right;
    return node;
}

ASTNode *create_unop_node(char *op, ASTNode *operand) {
    ASTNode *node = create_node(NODE_UNOP);
    node->data.unop.op = strdup(op);
    node->data.unop.operand = operand;
    return node;
}

ASTNode *create_id_node(char *name) {
    ASTNode *node = create_node(NODE_ID);
    node->data.id.name = strdup(name);
    return node;
}

ASTNode *create_int_node(int value) {
    ASTNode *node = create_node(NODE_INT);
    node->data.ival.value = value;
    return node;
}

ASTNode *create_double_node(double value) {
    ASTNode *node = create_node(NODE_DOUBLE);
    node->data.fval.value = value;
    return node;
}

ASTNode *create_string_node(char *value) {
    ASTNode *node = create_node(NODE_STRING);
    node->data.sval.value = strdup(value);
    return node;
}

ASTNode *create_bool_node(int value) {
    ASTNode *node = create_node(NODE_BOOL);
    node->data.ival.value = value;
    return node;
}

ASTNode *create_char_node(char *value) {
    ASTNode *node = create_node(NODE_CHAR);
    node->data.sval.value = strdup(value);
    return node;
}

ASTNode *create_if_node(ASTNode *cond, ASTNode *then_branch, ASTNode *else_branch) {
    ASTNode *node = create_node(NODE_IF);
    node->data.ifstmt.condition = cond;
    node->data.ifstmt.then_branch = then_branch;
    node->data.ifstmt.else_branch = else_branch;
    return node;
}

ASTNode *create_while_node(ASTNode *cond, ASTNode *body) {
    ASTNode *node = create_node(NODE_WHILE);
    node->data.whilestmt.condition = cond;
    node->data.whilestmt.body = body;
    return node;
}

ASTNode *create_repeat_while_node(ASTNode *body, ASTNode *cond) {
    ASTNode *node = create_node(NODE_REPEAT_WHILE);
    node->data.whilestmt.body = body;
    node->data.whilestmt.condition = cond;
    return node;
}

ASTNode *create_for_node(char *var, ASTNode *range, ASTNode *body) {
    ASTNode *node = create_node(NODE_FOR);
    node->data.forstmt.var = strdup(var);
    node->data.forstmt.range = range;
    node->data.forstmt.body = body;
    return node;
}

ASTNode *create_switch_node(ASTNode *expr, ASTNode *cases) {
    ASTNode *node = create_node(NODE_SWITCH);
    node->data.switchstmt.expr = expr;
    node->data.switchstmt.cases = cases;
    return node;
}

ASTNode *create_case_node(ASTNode *expr, ASTNode *stmts) {
    ASTNode *node = create_node(NODE_CASE);
    node->data.casestmt.expr = expr;
    node->data.casestmt.stmts = stmts;
    return node;
}

ASTNode *create_default_node(ASTNode *stmts) {
    ASTNode *node = create_node(NODE_DEFAULT);
    node->data.casestmt.expr = NULL;
    node->data.casestmt.stmts = stmts;
    return node;
}

ASTNode *create_case_list(ASTNode *list, ASTNode *case_stmt) {
    ASTNode *node = create_node(NODE_STMT_LIST);
    node->data.list.first = list;
    node->data.list.second = case_stmt;
    return node;
}

ASTNode *create_func_node(char *name, ASTNode *params, char *return_type, ASTNode *body) {
    ASTNode *node = create_node(NODE_FUNC);
    node->data.func.name = strdup(name);
    node->data.func.params = params;
    node->data.func.return_type = strdup(return_type);
    node->data.func.body = body;
    return node;
}

ASTNode *create_struct_node(char *name, ASTNode *members) {
    ASTNode *node = create_node(NODE_STRUCT);
    node->data.structdef.name = strdup(name);
    node->data.structdef.members = members;
    return node;
}

ASTNode *create_return_node(ASTNode *expr) {
    ASTNode *node = create_node(NODE_RETURN);
    node->data.retstmt.expr = expr;
    return node;
}

ASTNode *create_print_node(ASTNode *expr) {
    ASTNode *node = create_node(NODE_PRINT);
    node->data.printstmt.expr = expr;
    return node;
}

ASTNode *create_member_access_node(ASTNode *object, char *member) {
    ASTNode *node = create_node(NODE_MEMBER_ACCESS);
    node->data.member_access.object = object;
    node->data.member_access.member = strdup(member);
    return node;
}

ASTNode *create_array_access_node(ASTNode *array, ASTNode *index) {
    ASTNode *node = create_node(NODE_ARRAY_ACCESS);
    node->data.array_access.array = array;
    node->data.array_access.index = index;
    return node;
}

ASTNode *create_func_call_node(char *name, ASTNode *args) {
    ASTNode *node = create_node(NODE_FUNC_CALL);
    node->data.func_call.name = strdup(name);
    node->data.func_call.args = args;
    return node;
}

ASTNode *create_array_literal_node(ASTNode *elements) {
    ASTNode *node = create_node(NODE_ARRAY_LITERAL);
    node->data.list.first = elements;
    node->data.list.second = NULL;
    return node;
}

ASTNode *create_param_node(char *name, char *type) {
    ASTNode *node = create_node(NODE_PARAM);
    node->data.param.name = strdup(name);
    node->data.param.param_type = strdup(type);
    return node;
}

ASTNode *create_param_list(ASTNode *list, ASTNode *param) {
    ASTNode *node = create_node(NODE_STMT_LIST);
    node->data.list.first = list;
    node->data.list.second = param;
    return node;
}

ASTNode *create_arg_list(ASTNode *list, ASTNode *arg) {
    ASTNode *node = create_node(NODE_STMT_LIST);
    node->data.list.first = list;
    node->data.list.second = arg;
    return node;
}

ASTNode *create_named_arg_node(char *name, ASTNode *expr) {
    ASTNode *node = create_node(NODE_NAMED_ARG);
    node->data.named_arg.name = strdup(name);
    node->data.named_arg.expr = expr;
    return node;
}

ASTNode *create_expr_list(ASTNode *list, ASTNode *expr) {
    ASTNode *node = create_node(NODE_STMT_LIST);
    node->data.list.first = list;
    node->data.list.second = expr;
    return node;
}
