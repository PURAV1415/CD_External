# Compiler Design Lab Collection

This project contains 17 independently executable programs for the Compiler Design syllabus.

## 🚀 Quick Start Guide

### Tool Requirements
- **GCC**: For all `.c` files.
- **Flex**: For `.l` files.
- **Bison**: For `.y` files.

### Execution Patterns
- **C Programs**: `gcc filename.c -o output && ./output`
- **LEX Programs**: `flex scanner.l && gcc lex.yy.c -o scanner && ./scanner`
- **YACC Programs**: `bison -dy parser.y && flex lexer.l && gcc y.tab.c lex.yy.c -o parser && ./parser`

## 📂 Program Index
- **Prog 01**: LEX Token Recognizer (LEX/C)
- **Prog 02**: RE to DFA (C)
- **Prog 03**: DFA Simulator (C)
- **Prog 04**: Recursive Descent Parser (C)
- **Prog 05**: YACC Arithmetic Parser (LEX/YACC/C)
- **Prog 06**: LL(1) Table Generator (C)
- **Prog 07**: Infix to Postfix (C)
- **Prog 08**: TAC Generator (C)
- **Prog 09**: Type Checker (C)
- **Prog 10**: Symbol Table (C)
- **Prog 11**: Declaration Checker (C)
- **Prog 12**: Activation Record Simulator (C)
- **Prog 13**: Control Flow TAC (C)
- **Prog 14**: Code Optimizer (C)
- **Prog 15**: 8086 Generator (C)
- **Prog 16**: Regex to DFA (C)
- **Prog 17**: LL(1) vs LR(1) (C)

Check individual folder READMEs for sample inputs and expected outputs.
