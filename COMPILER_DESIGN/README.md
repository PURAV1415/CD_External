# Compiler Design Lab Collection

This project contains a complete set of 17 independently executable programs covering the Compiler Design syllabus (Subject Code: 24PC5CS10).

## 📂 Project Structure

The programs are organized numerically:

### Module I: Lexical Analysis
- [Program 01: LEX Token Recognizer](./Program_01_LEX_Token_Recognizer/) - Recognizes keywords, identifiers, numbers, and operators. (LEX/C)
- [Program 02: RE to DFA Subset Construction](./Program_02_RE_to_DFA_Subset_Construction/) - Converts NFA to DFA. (C)
- [Program 03: DFA Identifier Simulator](./Program_03_DFA_Identifier_Simulator/) - Simulates a DFA for valid identifiers. (C)
- [Program 16: Complete RE to NFA to DFA](./Program_16_RE_to_NFA_to_DFA_Complete/) - Full regex conversion pipeline. (C)

### Module II: Syntax Analysis
- [Program 04: Recursive Descent Parser](./Program_04_Recursive_Descent_Parser/) - Top-down parser for expressions. (C)
- [Program 05: YACC Arithmetic Parser](./Program_05_YACC_Arithmetic_Parser/) - Bottom-up parser using LEX/YACC. (LEX/YACC/C)
- [Program 06: LL(1) Table Generator](./Program_06_LL1_Table_Generator/) - Computes FIRST/FOLLOW and LL(1) table. (C)
- [Program 17: LL(1) vs LR(1) Comparison](./Program_17_LL1_vs_LR1_Comparison/) - Comparison of top-down and bottom-up tables. (C)

### Module III: Syntax Directed Translation
- [Program 07: Infix to Postfix](./Program_07_Infix_To_Postfix/) - Shunting-yard algorithm implementation. (C)
- [Program 08: Three Address Code Generator](./Program_08_Three_Address_Code/) - Generates TAC from postfix. (C)
- [Program 09: Attribute-Based Type Checker](./Program_09_Attribute_Based_Type_Checker/) - Static type validation for assignments. (C)

### Module IV: Symbol Tables & Memory
- [Program 10: Multi-Scope Symbol Table](./Program_10_Multi_Scope_Symbol_Table/) - Nested scopes and shadowing. (C)
- [Program 11: Static Declaration Type Checker](./Program_11_Static_Declaration_Type_Checker/) - Validates variable/array declarations. (C)
- [Program 12: Activation Record Simulator](./Program_12_Activation_Record_Simulator/) - Simulates call stack frames. (C)

### Module V: Code Generation & Optimization
- [Program 13: Control Flow TAC](./Program_13_Control_Flow_TAC/) - TAC for if-else and while loops. (C)
- [Program 14: Code Optimizer](./Program_14_Code_Optimizer/) - CSE and Dead Code Elimination. (C)
- [Program 15: 8086 Assembly Generator](./Program_15_8086_Assembly_Generator/) - Translates TAC to 8086 assembly. (C)

## 🛠️ Prerequisites & Installation

### Tools Required
- **GCC**: For all `.c` files.
- **Flex**: For `.l` files.
- **Bison**: For `.y` files.

### Installation (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install gcc flex bison
```

## 🚀 How to Run

Each program folder contains its own `README.md` with specific compilation and execution commands. 

**General Patterns:**
- **C**: `gcc filename.c -o output && ./output`
- **LEX**: `flex scanner.l && gcc lex.yy.c -o scanner && ./scanner`
- **YACC**: `bison -dy parser.y && flex lexer.l && gcc y.tab.c lex.yy.c -o parser && ./parser`

## 🧪 Verification
To verify the collection:
1. Navigate to a program folder.
2. Follow the commands in the `README.md`.
3. Compare the output with the "Expected Output" section in the README.
