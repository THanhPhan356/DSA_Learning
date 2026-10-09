# Valid Palindrome

**Problem:** [NeetCode – Valid Palindrome](https://neetcode.io/problems/is-palindrome/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

Check whether a string reads the same forward and backward, ignoring letter case and all characters except letters and digits. The problem uses printable ASCII input.

## Approach

1. Build a filtered string `s1`, keeping only alphanumeric characters and converting letters to lowercase.
2. Place `start` at the beginning and `end` at the last character of `s1`.
3. Compare the two characters. If they differ, return `false`.
4. Move both indices toward the center and repeat while `start < end`.
5. Return `true` if every compared pair matches.

For example, `"A man, a plan, a canal: Panama"` becomes `"amanaplanacanalpanama"`, which is a palindrome. A filtered string containing zero or one character also returns `true`.

## C++ notes

- `std::isalnum(c)` checks whether a character is a letter or digit.
- `std::tolower(c)` converts an uppercase letter to lowercase.
- The loop uses `unsigned char` to supply valid character values to these functions.
- `static_cast<int>(s1.size()) - 1` converts the unsigned length before subtracting. For an empty string, `end` is `-1` and the comparison loop is skipped.
- A separate check for a one-character string is unnecessary because the loop already handles it.

## Examples

| Input | Expected result | Reason |
| --- | --- | --- |
| `"A man, a plan, a canal: Panama"` | `true` | Filtered string is a palindrome |
| `"race a car"` | `false` | `raceacar` is not a palindrome |
| `"., "` | `true` | No alphanumeric characters remain |
| `"Aa"` | `true` | Comparison ignores case |
| `"0P"` | `false` | Digits are kept and `0` differs from `p` |

## Complexity

**Time:** O(n), for filtering the input and comparing pairs.  
**Auxiliary space:** O(n), because the filtered string stores up to n characters. The by-value input parameter also copies the input when called with an lvalue.

To achieve O(1) auxiliary space, compare directly in the input string with two indices, skip non-alphanumeric characters during traversal, and avoid copying the input by accepting a const reference.

## Learning note

The original solution was written by the learner. The revision removed a redundant one-character check and converted the filtered length before subtraction. Local tests verify this implementation; no accepted online submission is recorded here.
