# Top K Frequent Elements

**Problem:** [NeetCode – Top K Frequent Elements](https://neetcode.io/problems/top-k-elements-in-list/question)  
**Solution:** [solution.cpp](solution.cpp)  
**Reference:** [NeetCode explanation and reference code](https://neetcode.io/solutions/top-k-frequent-elements)

## Approach

Count each number's frequency with an `unordered_map`, then group numbers by frequency in buckets. Visit the buckets from highest frequency to lowest and collect numbers until the result contains exactly `k` values. Output order does not matter.

For `nums = [4, 4, 1, 1, 1, 2]`:

- Frequencies: `4 -> 2`, `1 -> 3`, `2 -> 1`.
- Buckets: `freq[1] = {2}`, `freq[2] = {4}`, `freq[3] = {1}`.
- With `k = 2`, return `{1, 4}`.

## C++ notes

- `vector<vector<int>> freq(n + 1)` creates `n + 1` empty vectors. Each inner vector holds numbers with the same frequency.
- `count[n]` starts at zero when the key does not exist.
- `const auto& entry` reads a key–value pair without copying it. `entry.first` is the number; `entry.second` is its frequency.
- `push_back(x)` appends `x` to the end of a vector.
- The nested loops visit each stored number at most once. A `return` inside them ends the entire function.

## Complexity

**Time:** O(n) on average, assuming average O(1) hash-map operations.  
**Space:** O(n).

Here, `n` is the input size. Bucket indices range from zero to `n`; bucket zero is unused. Hash collisions can make the worst-case runtime O(n²).

## Learning note

This implementation was adapted from the reference code studied during the exercise.
