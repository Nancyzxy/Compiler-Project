CC=gcc
FLEX=flex
test:
	$(FLEX) textlex.l
	$(CC) lex.yy.c -lfl -o t.out
clean:
	@rm -f lex.yy.c *.out
