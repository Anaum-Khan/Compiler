CC = gcc
CFLAGS = -Wall -g
LEX = flex
YACC = bison

OBJS = lex.yy.o parser.tab.o symtab.o codegen.o

all: compiler

compiler: $(OBJS)
	$(CC) $(CFLAGS) -o compiler $(OBJS) -lfl

parser.tab.c parser.tab.h: parser.y
	$(YACC) -d parser.y

lex.yy.c: lexer.l parser.tab.h
	$(LEX) lexer.l

lex.yy.o: lex.yy.c parser.tab.h
	$(CC) $(CFLAGS) -c lex.yy.c

parser.tab.o: parser.tab.c symtab.h codegen.h
	$(CC) $(CFLAGS) -c parser.tab.c

symtab.o: symtab.c symtab.h
	$(CC) $(CFLAGS) -c symtab.c

codegen.o: codegen.c codegen.h symtab.h
	$(CC) $(CFLAGS) -c codegen.c

clean:
	rm -f compiler $(OBJS) lex.yy.c parser.tab.c parser.tab.h output.c

test: compiler
	./compiler test_input.swift
	gcc -o test_output output.c
	./test_output

.PHONY: all clean test
