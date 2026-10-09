# Largest Rectangle in Histogram

**Problem:** [NeetCode – Largest Rectangle in Histogram](https://neetcode.io/problems/largest-rectangle-in-histogram/question)  
**Solution:** [solution.cpp](solution.cpp) (C++17)  


## Approach

A rectangle spans adjacent bars in their original order. Its height cannot exceed the shortest bar in that span.

Keep a stack of `{start, height}` pairs with strictly increasing heights. Each pair represents a rectangle whose right boundary is still unknown.

For a bar at position `i`:

1. Start with `start = i`.
2. While the top is taller than the incoming bar, pop it. Its rectangle ends at `i - 1`, so its width is `i - left`.
3. Update `maxArea` using `height * width`. Give the shorter incoming bar the popped rectangle's start, allowing it to extend left.
4. Push the incoming bar. If the top has the same height, keep the existing entry with its earlier start.
5. After scanning all bars, pop remaining entries using width `n - left`.

For `[7, 6, 7, 6, 5, 8, 2]`, a rectangle of height `5` spans the first six bars, giving area `5 * 6 = 30`. Encountering the final `2` closes that rectangle.

## Run the animation

After fetching/pulling the repository in GitHub Desktop, open this folder and double-click `visualization.html`. You can also download the HTML file from GitHub and open it in a browser; GitHub's file view shows the source rather than running it.

The HTML is self-contained and requires no installation, account, or network connection.

- Play/pause, move backward/forward, or scrub the timeline.
- Change input and playback speed.
- Inspect `i`, `start`, `maxArea`, stack entries, and highlighted code.
- Orange shows the rectangle just calculated; the green outline shows the best rectangle so far.
- Presets include decreasing heights, equal heights, and the example studied in the discussion.
- Inputs support 1–40 bars, with integer heights from 0 to 10000, to keep the chart readable.

## Complexity

**Time:** O(n). Each stack entry is pushed and popped at most once.  
**Space:** O(n).

## Learning notes

The discussion focused on why popping determines a rectangle's right boundary, why a shorter bar inherits the earliest popped start, and why equal heights can be merged. The code was provided and explained during the exercise.

The animation's results were checked against a brute-force oracle for 19,537 arrays. Browser checks covered controls, input validation, playback, and mobile layout. These checks validate the animation; no C++ compilation or accepted submission is claimed.
