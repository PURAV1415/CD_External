#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *input;      /* the string being parsed */
int pos = 0;            /* current position (lookahead) */

int E(); int E_prime(); int T(); int T_prime(); int F();

/* F -> ( E ) | id */
int F()
{
    if (input[pos] == '(') {
        pos++;
        if (E()) {
            if (input[pos] == ')') { pos++; return 1; }
        }
        return 0;
    }
    else if (isalnum(input[pos])) {
        while (isalnum(input[pos])) pos++;   /* consume the name */
        return 1;
    }
    return 0;
}

/* T' -> * F T' | ε */
int T_prime()
{
    if (input[pos] == '*') {
        pos++;
        if (F()) return T_prime();
        return 0;
    }
    return 1;           /* ε */
}

/* T -> F T' */
int T()
{
    if (F()) return T_prime();
    return 0;
}

/* E' -> + T E' | ε */
int E_prime()
{
    if (input[pos] == '+') {
        pos++;
        if (T()) return E_prime();
        return 0;
    }
    return 1;           /* ε */
}

/* E -> T E' */
int E()
{
    if (T()) return E_prime();
    return 0;
}

int main()
{
    char *tests[] = {"a+b*c", "(a+b)*c", "a+*b", "(a+b"};
    for (int i = 0; i < 4; i++) {
        input = tests[i];
        pos = 0;
        if (E() && input[pos] == '\0')
            printf("Expression '%s' is VALID\n", input);
        else
            printf("Expression '%s' is INVALID\n", input);
    }
    return 0;
}
