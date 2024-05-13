CXX:=g++
AR:=ar

SYM_TAB_LIB_HEADER:=symbol_table.h
SYM_TAB_LIB_DEP:=symbol_table.cpp
SYM_TAB_LIB_OBJ:=symbol_table.o
SYM_TAB_STATIC_LIB:=symbol_table.a

EXP_STK_LIB_HEADER:=expression_stack.h
EXP_STK_LIB_DEP:=expression_stack.cpp
EXP_STK_LIB_OBJ:=expression_stack.o
EXP_STK_STATIC_LIB:=expression_stack.a

PAR_TYPE_LIB_HEADER:=parsing_type.h
PAR_TYPE_LIB_DEP:=parsing_type.cpp
PAR_TYPE_LIB_OBJ:=parsing_type.o
PAR_TYPE_STATIC_LIB:=parsing_type.a

all:	clean y.tab.c lex.yy.c
	gcc -c y.tab.c
	gcc -c lex.yy.c
	g++ lex.yy.o y.tab.o -lfl -ly ${SYM_TAB_LIB_OBJ} ${EXP_STK_LIB_OBJ} ${PAR_TYPE_LIB_OBJ} -o B103040012.elf

y.tab.c:
	bison -y -d B103040012.y -Wno-yacc -v

lex.yy.c:
	flex -i B103040012.l

cxxlib: ${SYM_TAB_LIB_DEP} ${SYM_TAB_LIB_HEADER} ${EXP_STK_LIB_DEP} ${EXP_STK_LIB_HEADER} ${PAR_TYPE_LIB_HEADER} ${PAR_TYPE_LIB_DEP}
	${CXX} -c ${SYM_TAB_LIB_DEP}
	${AR} -r ${SYM_TAB_STATIC_LIB} ${SYM_TAB_LIB_DEP}
	${CXX} -c ${EXP_STK_LIB_DEP}
	${AR} -r ${EXP_STK_STATIC_LIB} ${EXP_STK_LIB_DEP}
	${CXX} -c ${PAR_TYPE_LIB_DEP}
	${AR} -r ${PAR_TYPE_STATIC_LIB} ${PAR_TYPE_LIB_DEP}

clean:
	-rm -rf *.elf lex.yy.c y.tab.c y.tab.h
