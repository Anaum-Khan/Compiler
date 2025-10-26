Swift Compiler - Part 3 (Complete Compiler)
This is a complete compiler for a subset of Swift language that performs lexical analysis, parsing, semantic analysis, and code generation.

Files Included
lexer.l - Lexical analyzer (tokenizes Swift code)
parser.y - Parser with semantic analysis (builds AST and checks semantics)
symtab.h - Symbol table header
symtab.c - Symbol table implementation (manages variables, functions, structs)
codegen.h - Code generator header
codegen.c - Code generator implementation (generates C code)
Makefile - Build automation
test_input.swift - Sample Swift test file
Features
Lexical Analysis
Tokenizes keywords (let, var, if, else, for, while, func, struct, etc.)
Identifies operators, literals, and identifiers
Handles integers, doubles, strings, characters, and booleans
Parsing
Builds Abstract Syntax Tree (AST)
Handles declarations, assignments, expressions
Supports control structures (if-else, while, repeat-while, for-in, switch)
Parses function and struct definitions
Semantic Analysis
Symbol table management
Variable declaration checking
Constant assignment prevention
Type checking
Scope management
Error reporting with line numbers
Code Generation
Generates equivalent C code
Translates Swift constructs to C
Produces compilable output
Compilation Steps
Step 1: Build the Compiler
bash
make
This will:

Generate lexer from lexer.l
Generate parser from parser.y
Compile all source files
Create the compiler executable
Step 2: Run the Compiler
bash
./compiler test_input.swift
This will:

Perform lexical analysis
Parse the input
Check semantics
Generate C code in output.c
Step 3: Compile and Run Generated Code
bash
gcc -o test_output output.c
./test_output
Or use the shortcut:

bash
make test
Example Usage
bash
make clean
make
./compiler test_input.swift
gcc -o test_output output.c
./test_output
Supported Swift Features
Variables: let (constants) and var (variables)
Data Types: Int, Double, Bool, String, Character, Arrays
Operators: Arithmetic (+, -, *, /, %), Comparison (==, !=, <, >, <=, >=), Logical (&&, ||, !)
Control Flow: if-else, while, repeat-while, for-in, switch-case
Functions: Declaration with parameters and return types
Structs: Basic struct definitions with members
Arrays: Array literals and indexing
Print: Output statements
Error Handling
The compiler detects:

Undeclared variables
Duplicate declarations
Assignment to constants
Type mismatches
Syntax errors
Output
The compiler generates:

Compilation status messages
Semantic error messages (if any)
C code output (output.c)
Example Output
Starting compilation...

Lexical Analysis: STARTED
Parsing: STARTED

Semantic Analysis: PASSED

Generating Code...

Code Generation: COMPLETE

Compilation: SUCCESS
Output written to output.c
Cleaning Up
bash
make clean
Removes all generated files including the compiler executable and output files.

Notes
The compiler translates Swift-like syntax to C
Generated C code is human-readable
Symbol table tracks all declarations
Semantic checks prevent common errors
Line numbers are provided for error messages

