# Program 01: LEX Token Recognizer

## Aim
Classify the characters of a source file into tokens: keywords, identifiers, numbers, and operators.

## Language and Tools Required
- **Language**: LEX / C
- **Tools**: `flex` (Fast Lexical Analyzer), `gcc` (GNU Compiler Collection)

## Algorithm
1. Define rules for tokens in the LEX specification file.
2. **Rule Order**: Keywords are defined before identifiers to ensure that keywords (which match the identifier pattern) are recognized as keywords first.
3. **Longest Match**: LEX automatically uses the longest match principle to avoid splitting tokens (e.g., `interest` is one identifier, not `int` + `erest`).
4. **Line Tracking**: Increment a `line_num` counter on every newline character (`\n`).
5. **Filtering**: Ignore white space and single-line comments (`//`).
6. **Error Handling**: Any character not matching the defined rules is reported as `UNKNOWN`.

## Source File Description
- `scanner.l`: The LEX specification file containing the token rules and C driver code.

## Compilation and Execution Commands
```bash
# 1. Generate the C scanner code from the .l file
flex scanner.l

# 2. Compile the generated C code with gcc
gcc lex.yy.c -o scanner

# 3. Run the scanner with an input file
./scanner input.txt
```

## Sample Input
```c
int x = 10;
// a comment
float y = x + 2.5;
if (x >= 5) return y;
```

## Expected Output
```
Line 1: [KEYWORD   ] int
Line 1: [IDENTIFIER] x
Line 1: [OPERATOR  ] =
Line 1: [NUMBER    ] 10
Line 1: [UNKNOWN   ] ;
Line 3: [KEYWORD   ] float
Line 3: [IDENTIFIER] y
Line 3: [OPERATOR  ] =
Line 3: [IDENTIFIER] x
Line 3: [OPERATOR  ] +
Line 3: [NUMBER    ] 2.5
Line 3: [UNKNOWN   ] ;
Line 4: [KEYWORD   ] if
Line 4: [UNKNOWN   ] (
Line 4: [IDENTIFIER] x
Line 4: [OPERATOR  ] >=
Line 4: [NUMBER    ] 5
Line 4: [UNKNOWN   ] )
Line 4: [KEYWORD   ] return
Line 4: [IDENTIFIER] y
Line 4: [UNKNOWN   ] ;
```

## Explanation of Output
The scanner reads the input line by line. It matches characters against the regular expressions in the rules section. For example, `int` matches the keyword rule, while `x` matches the identifier rule. Characters like `;` and `(` do not match any specific token rule, so they fall through to the `.` (wildcard) rule and are marked as `UNKNOWN`.

## Important Concepts Demonstrated
- **Regular Expressions**: Used to define token patterns.
- **Tokenization**: The process of breaking a stream of characters into meaningful tokens.
- **Lexical Analysis**: The first phase of a compiler.

## Common Errors and Resolution
- **Error**: `flex: command not found`
  - **Resolution**: Install Flex using `sudo apt-get install flex` (on Linux) or through WinFlexBison (on Windows).
- **Error**: `undefined reference to 'yywrap'`
  - **Resolution**: Ensure the `yywrap()` function is implemented in the `.l` file or compile with `-lfl`.
