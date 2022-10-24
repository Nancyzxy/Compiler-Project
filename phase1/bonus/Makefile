CC=gcc
FLEX=flex
BISON=bison
splc:
	@mkdir bin
	$(BISON) -d -v -t --report all syntax_bonus.y
	$(FLEX) lex_bonus.l
	$(CC) syntax_bonus.tab.c -lfl -o bin/splc
	@chmod +x bin/splc
flex:
	$(FLEX) lex1.l
	$(CC) lex.yy.c -lfl -o bin/flex.out
clean:
	@rm -rf bin/
.PHONY: splc