# Best Time to Buy and Sell Stock

**Problem:** [NeetCode – Best Time to Buy and Sell Stock](https://neetcode.io/problems/buy-and-sell-crypto/question?list=neetcode150)\
**Solution:** [solution.cpp](solution.cpp)

Given daily prices, return the largest profit from buying once and selling on a later day. If no profitable transaction exists, return zero. The result is the profit, rather than the indices of the buying and selling days.

## Approach: minimum price so far

For each day, ask: if I sell today, what was the cheapest buying price on a previous day?

1. Initialize `max_prof = 0` and `buy_px = prices[0]`.
2. Iterate from index 1, considering each day as the selling day.
3. Calculate `prices[i] - buy_px` and keep the larger of this profit and `max_prof`.
4. Update `buy_px` to the smaller of the current price and the previous minimum, for future selling days.
5. Return `max_prof`.

Before each iteration, `buy_px` is the minimum price strictly before the current day. For a fixed selling price, subtracting the smallest earlier buying price gives the largest possible profit. Taking the maximum over all selling days therefore gives the answer.

## Walkthrough

For `[7, 1, 5, 3, 6, 4]`, initially `buy_px = 7` and `max_prof = 0`. Perform step 1 before step 2 in every row.

| Day (index) | Price | Step 1: compare today's profit with the best profit | Step 2: compare today's price with the minimum buying price |
| --- | --- | --- | --- |
| 1 | 1 | `1 - 7 = -6`; `max(-6, 0) = 0` | `min(1, 7) = 1` |
| 2 | 5 | `5 - 1 = 4`; `max(4, 0) = 4` | `min(5, 1) = 1` |
| 3 | 3 | `3 - 1 = 2`; `max(2, 4) = 4` | `min(3, 1) = 1` |
| 4 | 6 | `6 - 1 = 5`; `max(5, 4) = 5` | `min(6, 1) = 1` |
| 5 | 4 | `4 - 1 = 3`; `max(3, 5) = 5` | `min(4, 1) = 1` |

The answer is `5`: buy at index 1 for `1`, then sell at index 4 for `6`.

## C++ notes

- `std::max(a, b)` returns the larger value; `std::min(a, b)` returns the smaller value. Both are declared in `<algorithm>`.
- `std::vector<int>& prices` receives the input by reference, avoiding a copy.
- Update `max_prof` before `buy_px`, so each evaluated transaction buys on an earlier day.
- Starting `max_prof` at zero keeps the answer zero when every possible transaction loses money.
- The problem guarantees a nonempty input, so `prices[0]` is valid. A single price skips the loop and returns zero.
- Preserve the original order of prices because it determines which transactions are possible.

## Examples

| Input | Expected result | Reason |
| --- | --- | --- |
| `[7, 1, 5, 3, 6, 4]` | `5` | Buy for 1 and later sell for 6 |
| `[7, 6, 4, 3, 1]` | `0` | Every later price is lower |
| `[1, 2, 3, 4, 5]` | `4` | Buy at the first day and sell at the last |
| `[5]` | `0` | There is no later selling day |
| `[3, 3, 3]` | `0` | Equal prices produce zero profit |
| `[3, 8, 1, 4]` | `5` | The best transaction occurs before the global minimum |

## Complexity

**Time:** O(n), because each price is visited once.\
**Auxiliary space:** O(1), using only a few integer variables.

The function does not modify `prices`.

## Learning note

The learner derived the idea of keeping the cheapest previous price and the maximum profit, then reviewed a reference implementation and traced its comparisons. This solution preserves those two variables and follows the repository's C++ format. Local checks compare it with an exhaustive search over all valid buying and selling pairs; no accepted online submission is recorded here.
