
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* States: 0 = Start, 1 = Valid (accepting), -1 = Dead */
int simulate_dfa(const char *str)
{
    if (str == NULL || strlen(str) == 0)
        return 0;                       /* reject empty input */

    int state = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        switch (state) {
            case 0:                     /* first character */
                if (isalpha(c) || c == '_') state = 1;
                else                        state = -1;
                break;
            case 1:                     /* remaining characters */
                if (isalnum(c) || c == '_') state = 1;
                else                        state = -1;
                break;
            default:                    /* dead state: stay rejected */
                return 0;
        }
    }
    return (state == 1);                /* accept only in state 1 */
}

int main()
{
    char inputs[5][20] = {"var1", "_count", "99num", "a+b", ""};
    for (int i = 0; i < 5; i++) {
        printf("Input: '%s' -> %s\n", inputs[i],
               simulate_dfa(inputs[i]) ? "ACCEPTED" : "REJECTED");
    }
    return 0;
}
