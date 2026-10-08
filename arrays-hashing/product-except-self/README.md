# Product of Array Except Self

**Problem:** [NeetCode – Products of Array Except Self](https://neetcode.io/problems/products-of-array-discluding-self/question)  
**Solution:** [solution.cpp](solution.cpp)

## Approach

Build two arrays that exclude the current element:

- `left[i]` is the product of all elements before index `i`.
- `right[i]` is the product of all elements after index `i`.

Initialize `left[0]` and `right[n - 1]` to 1: an empty product has value 1. Build the left products from left to right and the right products from right to left. Then compute `res[i] = left[i] * right[i]`.

Example:

```text
nums  = [2, 3, 4, 5]
left  = [1, 2, 6, 24]
right = [60, 20, 5, 1]
res   = [60, 40, 30, 24]
```

No division is used, so zero values are handled naturally.

## Complexity

**Time:** O(n).  
**Auxiliary space:** O(n) for the left and right arrays, plus O(n) for the output.

This implementation follows the two-array approach developed during the exercise. An O(1) auxiliary-space version can reuse the output for left products and keep the right product in a single variable.

## C++ notes

- Valid indices are `0` through `n - 1`; loops must use `i < n`, not `i <= n`.
- A signed `int n` avoids mixing unsigned container sizes with a descending loop.
- The solution assumes the problem's constraints: at least two elements and products that fit in a 32-bit integer.

## Run the check

From this folder, using a C++17 compiler:

```sh
g++ -std=c++17 -Wall -Wextra -Werror test.cpp -o test
./test
```

On Windows, run `test.exe`. Checks cover the examples, zero values, negative values, two-element input, and the maximum input length.
