all:lexer.o
	gcc -g driver.c lexer.o -o icc

#driver.o:driver.c
#	gcc -c driver.c

lexer.o:lexer.c lexer.h
	gcc -c -g lexer.c

clean:
	rm -rf driver.o lexer.o icc
tags:
	ctags -R *
