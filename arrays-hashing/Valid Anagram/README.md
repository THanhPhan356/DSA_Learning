# Valid Anagram

**Problem:** [NeetCode – Valid Anagram](https://neetcode.io/problems/is-anagram/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

## Approach

If the strings have different lengths, return `false`. Use an array of 26 counters for lowercase English letters. For each position, increase the count of the character in `s` and decrease the count of the character in `t`. The strings are anagrams if every count is zero.

**Time complexity:** O(n)  
**Extra space:** O(1), because the array always has 26 elements.