# Group Anagrams

**Problem:** [NeetCode – Group Anagrams](https://neetcode.io/problems/anagram-groups/question)  
**Solution:** [solution.cpp](solution.cpp)

## Approach

For each word, create a vector of 26 counters for lowercase English letters. Anagrams have identical frequency vectors, so use this vector as the key in a `map`. The value is a vector of words belonging to that group.

After counting each word, append it to the group with the matching key. Finally, collect the groups into the result.

**Time complexity:** O(nk + n log n), because `map` uses ordered lookups.  
**Space complexity:** O(nk + n), including the stored words and group keys.

Here, n is the number of words and k is the maximum word length; the alphabet size is fixed at 26.
