CC:=gcc
CXX:=g++
AR:=ar
LEX:=flex
SRC:=B103040012.l

LIB_HEADER:=symbol_table.h
LIB_DEP:=symbol_table.cpp
LIB_OBJ:=symbol_table.o
STATIC_LIB:=symbol_table.a

lex: ${SRC}
	${LEX} -o lex.c ${SRC}
	${CC} -c lex.c
	${CXX} lex.o ${STATIC_LIB} -lfl -o lex.elf

cxxlib: ${LIB_DEP} ${LIB_HEADER}
	${CXX} -c ${LIB_DEP}
	${AR} -r ${STATIC_LIB} ${LIB_DEP}

all: lex

.PHONY: clean
clean:
	-rm *.o
