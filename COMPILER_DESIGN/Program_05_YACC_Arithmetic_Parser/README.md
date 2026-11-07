# Program 05: YACC Parser for Arithmetic Expressions (+, -, *, /)

## Aim
Build an LALR(1) parser using LEX and YACC that evaluates arithmetic expressions, applies correct operator precedence and associativity, and detects division by zero.

## Language and Tools Required
- **Language**: LEX / YACC (C)
- **Tools**: `flex` (Lexical Analyzer), `bison` (YACC compatible parser generator), `gcc` (C Compiler)

## Algorithm
1. **Tokenization (LEX)**:
   - Define a rule to recognize numbers `[0-9]+` and return the `NUMBER` token.
   - Pass the numeric value to the parser using `yylval`.
   - Ignore whitespace and return other characters (operators, parentheses) as themselves.
2. **Parsing (YACC)**:
   - Define operator precedence and associativity: `+` and `-` are lower precedence; `*` and `/` are higher. Both are left-associative.
   - Define the grammar for expressions:
     - `expr` can be an addition, subtraction, multiplication, division, or a parenthesized expression.
     - A `NUMBER` is the base case for an expression.
3. **Semantic Actions**:
   - For each production rule, perform the corresponding arithmetic operation using the values of the children (e.g., `$$ = $1 + $3`).
   - For division, check if the divisor is zero and report a runtime error if it is.
4. **Execution**: The `yyparse()` function drives the process, calling `yylex()` to get tokens.

## Source File Description
- `lexer.l`: The LEX specification for the arithmetic tokenizer.
- `parser.y`: The YACC specification for the grammar and evaluation logic.

## Compilation and Execution Commands
```bash
# 1. Generate the parser from the .y file
bison -dy parser.y

# 2. Generate the lexer from the .l file
flex lexer.l

# 3. Compile both generated C files
gcc y.tab.c lex.yy.c -o parser

# 4. Run the parser
./parser
```

## Sample Input
- `2+3*4`
- `10/0`
- `2+*3`

## Expected Output
```
Enter Expression:
2+3*4
Parsing Successful! Result = 14

Enter Expression:
10/0
Syntax Error: Execution Error: Division by Zero!

Enter Expression:
2+*3
Syntax Error: syntax error
```

## Explanation of Output
- `2+3*4` is evaluated as $2 + (3 \times 4) = 14$ due to higher precedence of `*`.
- `10/0` triggers the division-by-zero check in the semantic action.
- `2+*3` is a syntax error because two operators appear sequentially.

## Important Concepts Demonstrated
- **LALR(1) Parsing**: Bottom-up parsing approach used by YACC.
- **Precedence and Associativity**: Resolving shift-reduce conflicts in ambiguous grammars.
- **Semantic Actions**: Executing C code during the reduction of a production rule.

## Common Errors and Resolution
- **Error**: `y.tab.h: No such file or directory`
  - **Resolution**: Ensure you use the `-d` flag with `bison` or `yacc` to generate the header file containing token definitions.
