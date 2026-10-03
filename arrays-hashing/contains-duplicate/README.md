# Contains Duplicate

**Problem:** [NeetCode – Contains Duplicate](https://neetcode.io/problems/duplicate-integer/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

## Approach

Sort the array so that equal values are next to each other. Then scan the array and compare each element with the one before it. Return `true` when two adjacent elements are equal; otherwise, return `false` after the scan.

**Time complexity:** O(n log n), mainly due to sorting.

**Note:** Sorting changes the order of the input array.