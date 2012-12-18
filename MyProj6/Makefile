comp: compiler.tab.o lex.yy.o
	gcc -o comp lex.yy.o compiler.tab.o

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

lex.yy.c: compiler.l
	flex compiler.l

compiler.tab.o: compiler.y
	bison -d compiler.y
	gcc -c compiler.tab.c

compute: c.asm
	nasm -f win32 --prefix _ c.asm
	gcc -o compute c.obj
#	nasm -f elf c.asm
#	gcc -o compute c.o
clean:
	rm -f lex.yy.*
	rm -f compiler.tab.*
	rm -f comp
	rm -f compute.exe
	rm -f c.*

