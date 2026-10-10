# Container With Most Water

**Problem:** [NeetCode – Container With Most Water](https://neetcode.io/problems/max-water-container/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

Choose two vertical lines from `heights` to form a container and return its maximum water capacity. For indices `left < right`, the area is `(right - left) * min(heights[left], heights[right])`. Only the two chosen lines limit the water level; the lines between them do not affect this calculation.

## Approach: two pointers

1. Start with `left = 0` and `right = n - 1`.
2. Calculate the area for the current pair and update the largest area found.
3. Move the pointer at the shorter line inward. If the heights are equal, move either pointer; this implementation moves `left`.
4. Repeat while `left < right`, then return the largest area.

If the left line is shorter, keeping it and moving the right pointer inward makes the width smaller while the height remains at most `heights[left]`. Such pairs cannot improve the current area, so discarding the left line is safe. The same argument applies when the right line is shorter.

## C++ notes

- `currentArea` stores the area of the current pair; `area` stores the largest area seen so far.
- Update `area` before moving a pointer.
- Do not sort the input: the original positions determine the width.
- `static_cast<int>(heights.size()) - 1` converts the unsigned length before subtraction. An empty vector skips the loop and returns zero.
- Unlike Largest Rectangle in Histogram, this problem uses the distance between two lines, not the number of bars in a segment.

## Examples

| Input | Expected result | Reason |
| --- | --- | --- |
| `[1, 7, 2, 5, 4, 7, 3, 6]` | `36` | Indices 1 and 7 give width 6 and height 6 |
| `[4, 1, 4]` | `8` | The two outer lines hold water despite the shorter middle line |
| `[2, 1, 10, 10]` | `10` | Moving past a shorter neighboring line can reveal a better pair |
| `[2, 2, 2]` | `4` | The outer pair has width 2 and height 2 |
| `[0, 0]` | `0` | Zero-height lines cannot hold water |

## Complexity

**Time:** O(n), because each pointer moves only inward, with at most n - 1 moves in total.  
**Auxiliary space:** O(1), using only a few integer variables.

The function does not modify `heights`. Under the problem's bounds, the area fits in an `int`.

## Learning note

The learner started with the idea of two pointers and explored which endpoint can safely be discarded. The loop was completed with guidance. This commit preserves that approach and formats the supplied code to match the repository. Local checks compare it against an exhaustive pair search; no accepted online submission is recorded here.
