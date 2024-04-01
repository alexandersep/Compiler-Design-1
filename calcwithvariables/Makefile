# calcwithvariables 
calcwithvariables: calcwithvariables.l calcwithvariables.y
	bison -d calcwithvariables.y
	flex calcwithvariables.l
	cc -o $@ calcwithvariables.tab.c lex.yy.c -lfl

clean:
	rm calcwithvariables
