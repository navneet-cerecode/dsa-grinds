# DSA Mistake Log

## Summary by category

| Category | Count | Recurring? |
|---|---:|---|
| Syntax mistake | 5 | Yes |
| Implementation mistake | 10 | Yes |
| Wrong data structure usage | 4 | Yes |
| Edge-case mistake | 0 | No |
| Wrong pattern | 0 | No |
| Complexity issue | 0 | No |
| Mathematical reasoning | 0 | No |
| Could not derive solution | 0 | No |
| Knew solution but could not implement | 1 | Not yet |
| Time management | 0 | No |

## Entries

| Problem | Attempt | Line(s) at review | Category | Mistake |
|---|---:|---:|---|---|
| Two Sum | 1 | 14 | Syntax mistake | Left an unresolved `__` placeholder and omitted the statement semicolon. |
| Two Sum | 1 | 16 | Syntax mistake | Omitted the semicolon after the map assignment. |
| Two Sum | 1 | 14 | Implementation mistake | Did not retrieve the previously stored complement index. |
| Two Sum | 2 | 14 | Wrong data structure usage | Used current index `i` as a map key instead of the complement value. |
| Two Sum | 2 | 16 | Syntax mistake | Placed the assignment semicolon after the closing brace. |
| Two Sum | 3 | 14 | Syntax mistake | Mismatched square and curly delimiters in the return statement. |
| Two Sum | 3 | 14 | Wrong data structure usage | Looked up the current array value instead of the complement. |
| Valid Parentheses | 1 | 14, 18, 22, 26 | Syntax mistake | Compared `char` values with string literals using double quotes instead of character literals using single quotes. |
| Valid Parentheses | 1 | 13 | Wrong data structure usage | Called `top()` without first checking whether the stack was empty. |
| Valid Parentheses | 1 | 13 | Implementation mistake | Read `newest` before processing the current character, so it could be invalid or stale. |
| Valid Parentheses | 1 | 18–28 | Implementation mistake | Popped matching closers but did not reject a closing bracket that mismatched the stack top. |
| Valid Parentheses | 2 | 19 | Wrong data structure usage | Still called `top()` for a closing bracket without first checking whether the stack was empty; input `"]"` terminates the program. |
| Valid Parentheses | 2 | 21–31 | Implementation mistake | Still ignored mismatched closing brackets instead of returning `false`; for example, `"([)])"` would incorrectly be accepted. |
| Valid Parentheses | 3 | 24–34 | Implementation mistake | Used three independent `if/else` statements. After one bracket type matched, the next unrelated `if` failed and its `else` returned `false`, rejecting every non-empty valid input. |
| Binary Search | 1 | 15 | Implementation mistake | Used `left < right`, so a one-element search range was never inspected; for example, `[5]` with target `5` returned `-1`. |
| Binary Search | 1 | 22 | Implementation mistake | Set `left = middle`, which may leave the boundary unchanged and cause an infinite loop when two elements remain. |
| Move Zeroes | 1 | 25 | Syntax mistake | Returned `nums` from a function declared `void`; an in-place function modifies the referenced vector and returns no value. |
| Move Zeroes | 1 | 14–19 | Implementation mistake | Declared a `read` pointer but never advanced it; the loop variable `i` changed while every check still read `nums[0]`. |
| Move Zeroes | 1 | 16 | Implementation mistake | Wrote `0` at the write position instead of copying the non-zero value currently being read. |

### Two Sum — diagnosis

- Pattern: Hash map / complement lookup
- Reasoning: Derived the brute-force approach and understood the optimized idea with guidance.
- Current diagnosis: The algorithm is understood conceptually; translating map semantics into valid C++ needs practice.
- Corrective action: trace `key -> value` before each lookup, compile after small edits, and check matching delimiters.
