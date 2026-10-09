# Valid Parentheses

**Problem:** [NeetCode – Valid Parentheses](https://neetcode.io/problems/validate-parentheses/question)  
**Solution:** [solution.cpp](solution.cpp)

## Approach

Use a stack to store opening brackets that have not yet been matched. The last opening bracket must be closed first.

1. For `(`, `[`, or `{`, push the character onto the stack.
2. For a closing bracket, return false if the stack is empty or its top is not the matching opening bracket.
3. If the brackets match, pop the opening bracket.
4. After scanning the string, return whether the stack is empty.

For `([)]`, the top is `[` when `)` arrives, so the string is invalid even though an earlier `(` exists.

## C++ notes

- `push(c)` adds an opening bracket.
- `top()` reads the most recently added unmatched opening bracket.
- `pop()` removes it after a successful match.
- Always check `empty()` before calling `top()` or `pop()`.
- The final empty-stack check detects opening brackets that were never closed.

## Examples

| Input | Expected result | Reason |
| --- | --- | --- |
| `()[]{}` | true | All pairs match |
| `([{}])` | true | Correct nesting |
| `([)]` | false | Wrong closing order |
| `)` | false | No opening bracket |
| `(()` | false | An opening bracket remains |

## Complexity

**Time:** O(n), because each character is visited once.  
**Space:** O(n), because all characters could be opening brackets.

The implementation assumes the problem's input contains only the six bracket characters.

## Learning note

The initial idea was to remove an opening bracket when its closing bracket appears. The discussion clarified that the closing bracket must match the most recent unmatched opening bracket. The C++ implementation was provided during the exercise; no accepted submission is recorded here.
