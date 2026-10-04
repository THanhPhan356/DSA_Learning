# Two Sum

**Problem:** [NeetCode – Two Sum](https://neetcode.io/problems/two-integer-sum/question)

## Approach

Use a hash map to store each number already seen as a key and its index as the value. For each `nums[i]`, calculate the number needed to reach the target: `target - nums[i]`.

If that number is already in the map, return its saved index and `i`. Otherwise, save `nums[i]` with index `i` and continue. Check the map before saving the current number so the same element is not used twice.

**Average time complexity:** O(n)  
**Extra space:** O(n)
