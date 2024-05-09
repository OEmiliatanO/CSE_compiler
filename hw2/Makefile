CXX:=g++
AR:=ar
LIB_HEADER:=symbol_table.h
LIB_DEP:=symbol_table.cpp
LIB_OBJ:=symbol_table.o
STATIC_LIB:=symbol_table.a

all:	clean y.tab.c lex.yy.c
	gcc -c y.tab.c
	gcc -c lex.yy.c
	g++ lex.yy.o y.tab.o -lfl -ly ${LIB_OBJ} -o B103040012.elf

y.tab.c:
	bison -y -d B103040012.y -Wno-yacc

lex.yy.c:
	flex -i B103040012.l

cxxlib: ${LIB_DEP} ${LIB_HEADER}
	${CXX} -c ${LIB_DEP}
	${AR} -r ${STATIC_LIB} ${LIB_DEP}

clean:
	-rm -rf *.elf lex.yy.c y.tab.c y.tab.h
