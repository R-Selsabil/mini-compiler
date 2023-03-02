Commandes pour compiler le projet : 

gcc -o tableSymboles.o -c tableSymboles.c

gcc -o quadruplet.o -c quadruplet.c

gcc -o helperSemantic.o -c helperSemantic.c

flex scanner.l

win_bison -d parser.y

gcc -w lex.yy.c parser.tab.c TableSymboles.o quadruplet.o helperSemantic.o -o test 

./test