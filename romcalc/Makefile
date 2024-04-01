# Roman Numeral
romcalc: romcalc.l romcalc.y
	bison -d -Wcounterexamples romcalc.y
	flex romcalc.l
	cc -o $@ romcalc.tab.c lex.yy.c -lfl
