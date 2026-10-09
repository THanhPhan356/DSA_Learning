# Longest Consecutive Sequence

**Problem:** [NeetCode – Longest Consecutive Sequence](https://neetcode.io/problems/longest-consecutive-sequence/question)  
**Solution:** [solution.cpp](solution.cpp)

## Task

Return the length of the longest run of consecutive integer values present in the input. Their positions and order in the input do not matter. Duplicate values do not increase the length.

For `[4, 3, 2, 3, 4, 5, 6, 7]`, the run is `[2, 3, 4, 5, 6, 7]`, so the answer is `6`. An empty input returns `0`.

## Approach

Use an unordered set to store distinct input values. A number `num` starts a run only if `num - 1` is absent. From that start, look for successive values until the first missing number.

Only starting at the beginning of each run avoids counting suffixes repeatedly.

## Reading the code

- `numSet` stores values, not key–value pairs.
- `for (int num : numSet)` visits each distinct number; iteration order is unspecified.
- `find(num - 1) == end()` means the predecessor is absent, so this is a run's start.
- `length = 1` counts the starting number.
- `find(num + length) != end()` checks the next expected value.
- `length++` counts that value and advances the next lookup; `num` stays fixed.
- `max(longest, length)` retains the longest run seen so far.

For a run starting at `1` in `{1, 2, 3, 4, 8, 9}`:

| Length before lookup | Value to find | Result |
| --- | --- | --- |
| 1 | 2 | Found; length becomes 2 |
| 2 | 3 | Found; length becomes 3 |
| 3 | 4 | Found; length becomes 4 |
| 4 | 5 | Missing; stop |

The other run starts at `8` and has length `2`. The answer remains `4`.

## Complexity

**Expected time:** O(n), assuming average O(1) hash operations. Each distinct value belongs to one run, counted from its start. Hash collisions can cause O(n²) worst-case time.  
**Space:** O(n).

The integer arithmetic follows the problem's bounds (values between -10⁹ and 10⁹). It is not intended for arbitrary values including INT_MIN or INT_MAX.

## Learning notes

This implementation was supplied as reference code during the exercise. The discussion explored a presence array, key–value storage, and recognizing run boundaries before explaining the set-based code. Reading the reference is recorded separately from independently solving or receiving an accepted submission.
