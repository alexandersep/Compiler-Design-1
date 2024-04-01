# Roman Numeral
roman: roman.l roman.y
	bison -d -Wcounterexamples roman.y
	flex roman.l
	cc -o $@ roman.tab.c lex.yy.c -lfl
