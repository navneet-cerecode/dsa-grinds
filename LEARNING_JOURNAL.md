# DSA Learning Journal

This file records what has been learned from each completed problem. It is separate from `MISTAKE_LOG.md`, which records errors and corrective actions.

## Progress summary

| Problem | Main pattern | Result | Confidence |
|---|---|---|---|
| Two Sum | One-pass hashing / complement lookup | Solved with substantial hints | Weak |

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
