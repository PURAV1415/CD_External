# Program 06: LL(1) Table Generator (FIRST, FOLLOW and Parsing Table)

## Aim
Implement a program that automatically computes the FIRST and FOLLOW sets for a given context-free grammar and constructs the LL(1) parsing table.

## Language and Tools Required
- **Language**: Python 3
- **Tools**: Python 3 Interpreter

## Algorithm
1. **FIRST Computation**:
   - For a terminal $a$, $\text{FIRST}(a) = \{a\}$.
   - For a production $A \to X_1 X_2 \dots X_k$:
     - Add $\text{FIRST}(X_1) \setminus \{\epsilon\}$ to $\text{FIRST}(A)$.
     - If $X_1$ can derive $\epsilon$, add $\text{FIRST}(X_2)$, and so on.
     - If all $X_1 \dots X_k$ can derive $\epsilon$, add $\epsilon$ to $\text{FIRST}(A)$.
   - Repeat until no more changes occur (fixed-point iteration).
2. **FOLLOW Computation**:
   - Place the end-of-input marker $\$$ in $\text{FOLLOW}(\text{Start Symbol})$.
   - For a production $A \to \alpha B \beta$:
     - Add $\text{FIRST}(\beta) \setminus \{\epsilon\}$ to $\text{FOLLOW}(B)$.
     - If $\beta$ is empty or can derive $\epsilon$, add $\text{FOLLOW}(A)$ to $\text{FOLLOW}(B)$.
   - Repeat until no more changes occur.
3. **Table Construction**:
   - For each production $A \to \alpha$:
     - For each terminal $a$ in $\text{FIRST}(\alpha)$, add $A \to \alpha$ to the table at $M[A, a]$.
     - If $\epsilon \in \text{FIRST}(\alpha)$, for each terminal $b$ in $\text{FOLLOW}(A)$, add $A \to \alpha$ to $M[A, b]$.
4. **Conflict Detection**: If any cell in the table receives multiple productions, the grammar is not LL(1).

## Source File Description
- `ll1_table.py`: Python implementation of the FIRST, FOLLOW, and Table generation algorithms.

## Compilation and Execution Commands
```bash
python ll1_table.py
```

## Sample Input
An expression grammar is hardcoded:
- $E \to T E'$
- $E' \to + T E' \mid \epsilon$
- $T \to F T'$
- $T' \to * F T' \mid \epsilon$
- $F \to ( E ) \mid \text{id}$

## Expected Output
```
FIRST sets:
  FIRST(E)  = ['(', 'id']
  FIRST(E')  = ['+', 'ε']
  FIRST(T)  = ['(', 'id']
  FIRST(T')  = ['*', 'ε']
  FIRST(F)  = ['(', 'id']
FOLLOW sets:
  FOLLOW(E) = ['$', ')']
  FOLLOW(E') = ['$', ')']
  FOLLOW(T) = ['$', ')', '+']
  FOLLOW(T') = ['$', ')', '+']
  FOLLOW(F) = ['$', ')', '*', '+']

=== LL(1) PARSING TABLE ===
  M[E, (] = E -> T E'
  M[E, id] = E -> T E'
  M[E', $] = E' -> ε
  M[E', )] = E' -> ε
  M[E', +] = E' -> + T E'
  M[F, (] = F -> ( E )
  M[F, id] = F -> id
  M[T, (] = T -> F T'
  M[T, id] = T -> F T'
  M[T', $] = T' -> ε
  M[T', )] = T' -> ε
  M[T', *] = T' -> * F T'
  M[T', +] = T' -> ε

Grammar is LL(1)
```

## Explanation of Output
The output lists the FIRST and FOLLOW sets for each non-terminal. The parsing table shows which production rule to apply based on the current non-terminal and the lookahead terminal. Since no cell contains multiple rules, the grammar is confirmed as LL(1).

## Important Concepts Demonstrated
- **Predictive Parsing**: Using a table to decide the next production rule.
- **Set Theory**: Using unions and differences to compute FIRST and FOLLOW.
- **Grammar Analysis**: Detecting conflicts to determine if a grammar is LL(1).

## Common Errors and Resolution
- **Error**: Infinite loop in FIRST/FOLLOW computation.
  - **Resolution**: This happens if the grammar has cycles. Ensure the grammar is simplified and lacks direct or indirect left recursion.
