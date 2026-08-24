# DSA Learning Journal

This file records what has been learned from each completed problem. It is separate from `MISTAKE_LOG.md`, which records errors and corrective actions.

## Progress summary

| Problem | Main pattern | Result | Confidence |
|---|---|---|---|
| Two Sum | One-pass hashing / complement lookup | Solved with substantial hints | Weak |
| Valid Parentheses | Stack / LIFO matching | Solved after explanation | Weak |
| Binary Search | Binary search / search-space reduction | Solved with hints | Weak |
| Move Zeroes | Two pointers / read-write positions | Solved with hints | Weak |

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

## 3. Binary Search

### What I learned

- A sorted array allows half of the remaining search space to be discarded after one comparison.
- Use inclusive `left` and `right` boundaries and continue while `left <= right`.
- If the middle value is smaller than the target, move `left` to `middle + 1`.
- If the middle value is larger than the target, move `right` to `middle - 1`.
- The `+1` and `-1` ensure that an already inspected middle index is discarded and the loop makes progress.
- If `left > right`, the target is absent.

### Pattern

Binary search / search-space reduction.

### Recognition signals

- The input is sorted or has a monotonic property.
- A comparison can eliminate an entire half of the possibilities.
- The task asks to find a value, boundary, first occurrence, or last occurrence.

### Mental trigger

> Can one comparison prove that half of the remaining search space is impossible?

### Complexity

- Time: `O(log n)`
- Space: `O(1)`

### Retrospective

- A one-element range is valid, so the loop condition is `left <= right`.
- Every update must exclude `middle`; otherwise, the loop may never progress.
- Boundary direction still needs independent practice.

## 4. Move Zeroes

### What I learned

- A read pointer scans every element while a write pointer marks where the next retained value belongs.
- Copy each non-zero value to the write position and advance `write` only after a copy.
- After compacting the non-zero values, fill positions from `write` to the end with zero.
- A `void` in-place function changes its reference argument and does not return the vector.
- A pointer must advance consistently; declaring a pointer without updating it repeatedly reads the same element.

### Pattern

Two pointers / read-write positions.

### Recognition signals

- Modify an array in place.
- Preserve the relative order of selected elements.
- One position scans input while another tracks the next output position.
- Extra array space is disallowed or unnecessary.

### Mental trigger

> Can one pointer read every item while another marks where the next valid item belongs?

### Complexity

- Time: `O(n)`
- Extra space: `O(1)`

### Retrospective

- The read pointer decides which value to copy.
- The write pointer decides where that value belongs.
- This pattern needs independent revision before confidence can increase.
