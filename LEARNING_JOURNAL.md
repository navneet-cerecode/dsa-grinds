# DSA Learning Journal

This file records what has been learned from each completed problem. It is separate from `MISTAKE_LOG.md`, which records errors and corrective actions.

## Progress summary

| Problem | Main pattern | Result | Confidence |
|---|---|---|---|
| Two Sum | One-pass hashing / complement lookup | Solved with substantial hints | Weak |
| Valid Parentheses | Stack / LIFO matching | Solved after explanation | Weak |

## 1. Two Sum

### What I learned

- A brute-force solution checks every distinct pair and takes `O(n^2)` time.
- For a current value `x`, the required partner is `target - x`; this is called the complement.
- An `unordered_map` can store `number -> index` and usually supports lookup in `O(1)` time.
- Check whether the complement exists before storing the current number. This prevents using the same array element twice.
- Once the complement is found, return its stored index and the current index.

### Pattern

One-pass hashing / complement lookup.

### Recognition signals

- Find two values that satisfy a target.
- Repeatedly need to know whether a related value appeared earlier.
- Need faster lookup than scanning the earlier portion of the array.
- Need to preserve original indices.
- A required counterpart can be calculated from the current value.

### Mental trigger

> Can I store what I have already seen so I do not search through it again?

### Complexity

- Time: `O(n)` average
- Space: `O(n)`

### C++ learned

```cpp
unordered_map<int, int> seen;
seen[value] = index;
seen.find(value) != seen.end();
seen[value];
```

### Retrospective

- The map remembers which value appeared at which index.
- Lookup must use the complement as the key.
- Checking before inserting prevents the current element from matching itself.
- More independent practice is required before this pattern can be considered retained.

## 2. Valid Parentheses

### What I learned

- Nested brackets must close in reverse order: the newest opening bracket closes first.
- A stack models this Last In, First Out ordering.
- Push opening brackets and compare each closing bracket with the stack top.
- Check `empty()` before calling `top()` or `pop()`.
- A mismatched closing bracket makes the string invalid immediately.
- The stack must be empty after processing the entire string.
- C++ character literals use single quotes, such as `'('`; double quotes create strings.

### Pattern

Stack / LIFO matching.

### Recognition signals

- Nested structures must close in reverse order.
- Need to remember the most recent unmatched item.
- Opening and closing symbols must be paired.
- Only the newest unresolved item matters at each step.

### Mental trigger

> Do I need to process or match the most recently seen unresolved item first?

### Complexity

- Time: `O(n)`
- Space: `O(n)` in the worst case

### C++ learned

```cpp
stack<char> brackets;
brackets.push(value);
brackets.top();
brackets.pop();
brackets.empty();
```

### Retrospective

- `top()` and `pop()` are unsafe on an empty stack.
- Independent `if/else` statements are not interchangeable with one combined decision.
- More independent stack practice is needed before this pattern is retained.
