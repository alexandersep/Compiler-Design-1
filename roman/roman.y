%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
void yyerror(char *s);
%}

/* declare tokens */

/* roman numerals */
%token ROMAN_NUMERAL 
/* End of line */
%token EOL
%%

calcnum: 
 | calcnum roman EOL { printf("%d\n", $2); }
 ;

roman: ROMAN_NUMERAL 
 | roman ROMAN_NUMERAL { $$ = $1 + $2; }
 ;

int main() {
    yyparse();
    return 0;
}

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
    exit(0);
}
