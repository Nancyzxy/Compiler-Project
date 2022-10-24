CC=gcc
FLEX=flex
test:
	$(FLEX) lex.l
	$(CC) lex.yy.c -o a.out
clean:
	@rm -f lex.yy.c *.out