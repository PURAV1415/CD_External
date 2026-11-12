#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define NON_TERMINAL_BASE 100
#define NON_TERMINAL_COUNT 5
#define TERMINAL_COUNT 7
#define TABLE_TERMINAL_COUNT 6
#define MAX_RHS 4
#define EPSILON 6

enum {
    ID,
    OPEN_PAREN,
    CLOSE_PAREN,
    PLUS,
    STAR,
    END_MARKER
};

typedef struct {
    int lhs;
    int rhs[MAX_RHS];
    int length;
} Production;

static const char *const non_terminal_names[NON_TERMINAL_COUNT] = {
    "E", "E'", "T", "T'", "F"
};

static const char *const terminal_names[TERMINAL_COUNT] = {
    "id", "(", ")", "+", "*", "$", "epsilon"
};

static const Production productions[] = {
    {0, {NON_TERMINAL_BASE + 2, NON_TERMINAL_BASE + 1}, 2},
    {1, {PLUS, NON_TERMINAL_BASE + 2, NON_TERMINAL_BASE + 1}, 3},
    {1, {EPSILON}, 1},
    {2, {NON_TERMINAL_BASE + 4, NON_TERMINAL_BASE + 3}, 2},
    {3, {STAR, NON_TERMINAL_BASE + 4, NON_TERMINAL_BASE + 3}, 3},
    {3, {EPSILON}, 1},
    {4, {OPEN_PAREN, NON_TERMINAL_BASE + 0, CLOSE_PAREN}, 3},
    {4, {ID}, 1}
};

#define PRODUCTION_COUNT ((int)(sizeof(productions) / sizeof(productions[0])))

static bool is_non_terminal(int symbol)
{
    return symbol >= NON_TERMINAL_BASE &&
           symbol < NON_TERMINAL_BASE + NON_TERMINAL_COUNT;
}

static int non_terminal_index(int symbol)
{
    return symbol - NON_TERMINAL_BASE;
}

static void first_of_sequence(const int *sequence, int length,
                              bool first[NON_TERMINAL_COUNT][TERMINAL_COUNT],
                              bool result[TERMINAL_COUNT])
{
    bool can_be_empty = true;

    memset(result, 0, sizeof(bool) * TERMINAL_COUNT);
    for (int i = 0; i < length && can_be_empty; i++) {
        int symbol = sequence[i];

        if (is_non_terminal(symbol)) {
            int index = non_terminal_index(symbol);
            for (int terminal = 0; terminal < TERMINAL_COUNT; terminal++) {
                if (terminal != EPSILON && first[index][terminal]) {
                    result[terminal] = true;
                }
            }
            can_be_empty = first[index][EPSILON];
        } else if (symbol == EPSILON) {
            result[EPSILON] = true;
            can_be_empty = true;
        } else {
            result[symbol] = true;
            can_be_empty = false;
        }
    }

    if (can_be_empty) {
        result[EPSILON] = true;
    }
}

static void print_symbol(int symbol)
{
    printf("%s", terminal_names[symbol]);
}

static void print_production(int production_index)
{
    const Production *production = &productions[production_index];

    printf("%s ->", non_terminal_names[production->lhs]);
    if (production->length == 1 && production->rhs[0] == EPSILON) {
        printf(" epsilon");
    } else {
        for (int i = 0; i < production->length; i++) {
            printf(" ");
            if (is_non_terminal(production->rhs[i])) {
                printf("%s", non_terminal_names[
                    non_terminal_index(production->rhs[i])]);
            } else {
                print_symbol(production->rhs[i]);
            }
        }
    }
}

int main(void)
{
    bool first[NON_TERMINAL_COUNT][TERMINAL_COUNT] = {{false}};
    bool follow[NON_TERMINAL_COUNT][TERMINAL_COUNT] = {{false}};
    int table[NON_TERMINAL_COUNT][TABLE_TERMINAL_COUNT];
    bool changed;
    bool conflict = false;

    for (int row = 0; row < NON_TERMINAL_COUNT; row++) {
        for (int column = 0; column < TABLE_TERMINAL_COUNT; column++) {
            table[row][column] = -1;
        }
    }

    do {
        changed = false;
        for (int i = 0; i < PRODUCTION_COUNT; i++) {
            bool result[TERMINAL_COUNT];
            first_of_sequence(productions[i].rhs, productions[i].length,
                              first, result);
            for (int terminal = 0; terminal < TERMINAL_COUNT; terminal++) {
                if (result[terminal] && !first[productions[i].lhs][terminal]) {
                    first[productions[i].lhs][terminal] = true;
                    changed = true;
                }
            }
        }
    } while (changed);

    follow[0][END_MARKER] = true;
    do {
        changed = false;
        for (int i = 0; i < PRODUCTION_COUNT; i++) {
            const Production *production = &productions[i];
            for (int position = 0; position < production->length; position++) {
                int symbol = production->rhs[position];
                bool result[TERMINAL_COUNT];

                if (!is_non_terminal(symbol)) {
                    continue;
                }
                first_of_sequence(&production->rhs[position + 1],
                                  production->length - position - 1,
                                  first, result);
                for (int terminal = 0; terminal < TABLE_TERMINAL_COUNT;
                     terminal++) {
                    if (result[terminal] &&
                        !follow[non_terminal_index(symbol)][terminal]) {
                        follow[non_terminal_index(symbol)][terminal] = true;
                        changed = true;
                    }
                }
                if (result[EPSILON]) {
                    for (int terminal = 0; terminal < TABLE_TERMINAL_COUNT;
                         terminal++) {
                        if (follow[production->lhs][terminal] &&
                            !follow[non_terminal_index(symbol)][terminal]) {
                            follow[non_terminal_index(symbol)][terminal] = true;
                            changed = true;
                        }
                    }
                }
            }
        }
    } while (changed);

    printf("FIRST sets:\n");
    for (int non_terminal = 0; non_terminal < NON_TERMINAL_COUNT;
         non_terminal++) {
        printf("  FIRST(%s) = {", non_terminal_names[non_terminal]);
        bool first_item = true;
        for (int terminal = 0; terminal < TERMINAL_COUNT; terminal++) {
            if (first[non_terminal][terminal]) {
                printf("%s%s", first_item ? "" : ", ",
                       terminal_names[terminal]);
                first_item = false;
            }
        }
        printf("}\n");
    }

    printf("\nFOLLOW sets:\n");
    for (int non_terminal = 0; non_terminal < NON_TERMINAL_COUNT;
         non_terminal++) {
        printf("  FOLLOW(%s) = {", non_terminal_names[non_terminal]);
        bool first_item = true;
        for (int terminal = 0; terminal < TABLE_TERMINAL_COUNT; terminal++) {
            if (follow[non_terminal][terminal]) {
                printf("%s%s", first_item ? "" : ", ",
                       terminal_names[terminal]);
                first_item = false;
            }
        }
        printf("}\n");
    }

    for (int i = 0; i < PRODUCTION_COUNT; i++) {
        bool result[TERMINAL_COUNT];
        first_of_sequence(productions[i].rhs, productions[i].length,
                          first, result);
        for (int terminal = 0; terminal < TABLE_TERMINAL_COUNT; terminal++) {
            bool selected = result[terminal] ||
                            (result[EPSILON] &&
                             follow[productions[i].lhs][terminal]);
            if (!selected) {
                continue;
            }
            if (table[productions[i].lhs][terminal] != -1) {
                conflict = true;
            }
            table[productions[i].lhs][terminal] = i;
        }
    }

    printf("\n=== LL(1) PARSING TABLE ===\n");
    for (int non_terminal = 0; non_terminal < NON_TERMINAL_COUNT;
         non_terminal++) {
        for (int terminal = 0; terminal < TABLE_TERMINAL_COUNT; terminal++) {
            int production = table[non_terminal][terminal];
            if (production != -1) {
                printf("  M[%s, %s] = ", non_terminal_names[non_terminal],
                       terminal_names[terminal]);
                print_production(production);
                printf("\n");
            }
        }
    }

    printf("\n%s\n", conflict ? "Conflict found: NOT LL(1)"
                                : "Grammar is LL(1)");
    return conflict ? 1 : 0;
}
