%{
int answer = 0;
%}

%%
[0-9]*[02468][ \t\n] { answer++; }
[.\n]
%%

int main() {
    yylex();
    printf("%d\n", answer);
    return 0;
}
