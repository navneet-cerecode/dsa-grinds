# DSA Mistake Log

## Summary by category

| Category | Count | Recurring? |
|---|---:|---|
| Syntax mistake | 3 | Yes |
| Implementation mistake | 2 | Yes |
| Wrong data structure usage | 2 | Yes |
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

### Two Sum — diagnosis

- Pattern: Hash map / complement lookup
- Reasoning: Derived the brute-force approach and understood the optimized idea with guidance.
- Current diagnosis: The algorithm is understood conceptually; translating map semantics into valid C++ needs practice.
- Corrective action: trace `key -> value` before each lookup, compile after small edits, and check matching delimiters.
