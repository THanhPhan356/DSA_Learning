# 3Sum

**Problem:** [NeetCode – 3Sum](https://neetcode.io/problems/three-integer-sum/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)  
**Local tests:** [test.cpp](test.cpp)

Return all unique triplets whose sum is zero. Each triplet must use three different indices, but its values may be equal if the input contains enough copies. The order of the results does not matter.

## Approach: sorting and two pointers

1. Sort the array in ascending order.
2. Fix an index `i`, skipping repeated values of `nums[i]`. Stop if `nums[i] > 0`, since all remaining values are positive.
3. Set `left = i + 1` and `right = n - 1`.
4. Compare `nums[i] + nums[left] + nums[right]` with zero:
   - If the sum is negative, increase `left`.
   - If the sum is positive, decrease `right`.
   - If the sum is zero, save the triplet, move both pointers inward, and skip repeated values.
5. Repeat for the next fixed index.

With `i` fixed, a negative sum means that even the largest available value at `right` is too small when paired with `left`. Every smaller right value also fails, so advancing `left` is safe. A positive sum means every larger left value also fails with the current `right`, so decreasing `right` is safe.

The indices always satisfy `i < left < right`, so a single position is never reused.

## Avoiding duplicate triplets

- Skip `i` when its value equals the previous fixed value.
- After finding a triplet, skip repeated left and right values.
- Repeated input values are still allowed in a triplet: `[-1, -1, 2]` uses two different occurrences of `-1`.

## Examples

| Input | Expected output |
| --- | --- |
| `[-1, 0, 1, 2, -1, -4]` | `[[-1, -1, 2], [-1, 0, 1]]` |
| `[0, 0, 0, 0]` | `[[0, 0, 0]]` |
| `[-2, 0, 0, 2, 2]` | `[[-2, 0, 2]]` |
| `[0, 1, 1]` | `[]` |

## Complexity and side effects

**Time:** O(n²). Sorting takes O(n log n), and each fixed index requires at most a linear scan.  
**Auxiliary space:** O(1) for the pointer scan; typical `std::sort` implementations additionally use O(log n) stack space.  
**Output space:** O(k), where k is the number of returned triplets, which can be O(n²).

The function sorts `nums` in place. Under the problem's value bounds, the sum of three values fits in an `int`.

## Running the local tests

From this folder, compile and run the test file:

```sh
g++ -std=c++17 -Wall -Wextra -Werror test.cpp -o test
./test
```

On Windows, run `test.exe` after compiling. The nine cases check duplicates, multiple answers, no answer, and boundary values. The empty-array case also verifies the implementation outside the problem's minimum-length constraint.

## Learning note

The initial idea was to fix both endpoints and scan the middle. The discussion explored why a negative minimum sum or a positive maximum sum alone cannot justify discarding an endpoint. The final approach fixes one value and uses two pointers for the remaining pair. The implementation was provided during the exercise; local tests passed, but no accepted online submission is recorded here.
