%%
\"([^"]|\n)*\" { ECHO; }
\{([^}]|\n)*\}
\*\*.*
%%

int main()
{
    yylex();
    return 0;
}
