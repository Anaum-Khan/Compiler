#ifndef SYMTAB_H
#define SYMTAB_H

typedef struct Symbol {
    char *name;
    char *type;
    int is_const;
    struct Symbol *next;
} Symbol;

typedef struct Function {
    char *name;
    char *return_type;
    struct Function *next;
} Function;

typedef struct Struct {
    char *name;
    struct Struct *next;
} Struct;

typedef enum {
    NODE_PROGRAM,
    NODE_STMT_LIST,
    NODE_DECL,
    NODE_ASSIGN,
    NODE_ARRAY_ASSIGN,
    NODE_FUNC,
    NODE_STRUCT,
    NODE_IF,
    NODE_WHILE,
    NODE_REPEAT_WHILE,
    NODE_FOR,
    NODE_SWITCH,
    NODE_CASE,
    NODE_DEFAULT,
    NODE_RETURN,
    NODE_PRINT,
    NODE_BINOP,
    NODE_UNOP,
    NODE_ID,
    NODE_INT,
    NODE_DOUBLE,
    NODE_STRING,
    NODE_BOOL,
    NODE_CHAR,
    NODE_MEMBER_ACCESS,
    NODE_ARRAY_ACCESS,
    NODE_FUNC_CALL,
    NODE_ARRAY_LITERAL,
    NODE_PARAM,
    NODE_ARG,
    NODE_NAMED_ARG
} NodeType;

typedef struct ASTNode {
    NodeType type;
    union {
        struct {
            char *name;
            char *data_type;
            struct ASTNode *init;
            int is_const;
        } decl;
        struct {
            char *name;
            struct ASTNode *value;
        } assign;
        struct {
            char *name;
            struct ASTNode *index;
            struct ASTNode *value;
        } array_assign;
        struct {
            char *op;
            struct ASTNode *left;
            struct ASTNode *right;
        } binop;
        struct {
            char *op;
            struct ASTNode *operand;
        } unop;
        struct {
            char *name;
        } id;
        struct {
            int value;
        } ival;
        struct {
            double value;
        } fval;
        struct {
            char *value;
        } sval;
        struct {
            struct ASTNode *condition;
            struct ASTNode *then_branch;
            struct ASTNode *else_branch;
        } ifstmt;
        struct {
            struct ASTNode *condition;
            struct ASTNode *body;
        } whilestmt;
        struct {
            char *var;
            struct ASTNode *range;
            struct ASTNode *body;
        } forstmt;
        struct {
            struct ASTNode *expr;
            struct ASTNode *cases;
        } switchstmt;
        struct {
            struct ASTNode *expr;
            struct ASTNode *stmts;
        } casestmt;
        struct {
            char *name;
            struct ASTNode *params;
            char *return_type;
            struct ASTNode *body;
        } func;
        struct {
            char *name;
            struct ASTNode *members;
        } structdef;
        struct {
            struct ASTNode *expr;
        } retstmt;
        struct {
            struct ASTNode *expr;
        } printstmt;
        struct {
            struct ASTNode *object;
            char *member;
        } member_access;
        struct {
            struct ASTNode *array;
            struct ASTNode *index;
        } array_access;
        struct {
            char *name;
            struct ASTNode *args;
        } func_call;
        struct {
            char *name;
            char *param_type;
        } param;
        struct {
            char *name;
            struct ASTNode *expr;
        } named_arg;
        struct {
            struct ASTNode *first;
            struct ASTNode *second;
        } list;
    } data;
} ASTNode;

void init_symbol_table();
void insert_symbol(char *name, char *type, int is_const);
Symbol *lookup_symbol(char *name);
void insert_function(char *name, char *return_type);
Function *lookup_function(char *name);
void insert_struct(char *name);
Struct *lookup_struct(char *name);
void push_scope();
void pop_scope();
void print_symbol_table();
void print_three_address_code();

ASTNode *create_stmt_list(ASTNode *list, ASTNode *stmt);
ASTNode *create_decl_node(char *name, char *type, ASTNode *init, int is_const);
ASTNode *create_assign_node(char *name, ASTNode *value);
ASTNode *create_array_assign_node(char *name, ASTNode *index, ASTNode *value);
ASTNode *create_binop_node(char *op, ASTNode *left, ASTNode *right);
ASTNode *create_unop_node(char *op, ASTNode *operand);
ASTNode *create_id_node(char *name);
ASTNode *create_int_node(int value);
ASTNode *create_double_node(double value);
ASTNode *create_string_node(char *value);
ASTNode *create_bool_node(int value);
ASTNode *create_char_node(char *value);
ASTNode *create_if_node(ASTNode *cond, ASTNode *then_branch, ASTNode *else_branch);
ASTNode *create_while_node(ASTNode *cond, ASTNode *body);
ASTNode *create_repeat_while_node(ASTNode *body, ASTNode *cond);
ASTNode *create_for_node(char *var, ASTNode *range, ASTNode *body);
ASTNode *create_switch_node(ASTNode *expr, ASTNode *cases);
ASTNode *create_case_node(ASTNode *expr, ASTNode *stmts);
ASTNode *create_default_node(ASTNode *stmts);
ASTNode *create_case_list(ASTNode *list, ASTNode *case_stmt);
ASTNode *create_func_node(char *name, ASTNode *params, char *return_type, ASTNode *body);
ASTNode *create_struct_node(char *name, ASTNode *members);
ASTNode *create_return_node(ASTNode *expr);
ASTNode *create_print_node(ASTNode *expr);
ASTNode *create_member_access_node(ASTNode *object, char *member);
ASTNode *create_array_access_node(ASTNode *array, ASTNode *index);
ASTNode *create_func_call_node(char *name, ASTNode *args);
ASTNode *create_array_literal_node(ASTNode *elements);
ASTNode *create_param_node(char *name, char *type);
ASTNode *create_param_list(ASTNode *list, ASTNode *param);
ASTNode *create_arg_list(ASTNode *list, ASTNode *arg);
ASTNode *create_named_arg_node(char *name, ASTNode *expr);
ASTNode *create_expr_list(ASTNode *list, ASTNode *expr);

#endif
