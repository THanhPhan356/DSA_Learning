#include <algorithm>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Each entry stores {start index, height}.
        stack<pair<int, int>> st;
        int maxArea = 0;
        int n = static_cast<int>(heights.size());

        for (int i = 0; i < n; i++) {
            int start = i;

            while (!st.empty() && st.top().second > heights[i]) {
                auto [left, height] = st.top();
                st.pop();

                int width = i - left;
                maxArea = max(maxArea, height * width);

                // The shorter incoming bar can extend to this start.
                start = left;
            }

            // Equal heights keep the existing, earlier start.
            if (st.empty() || st.top().second < heights[i]) {
                st.push({start, heights[i]});
            }
        }

        // Remaining rectangles extend to the end of the histogram.
        while (!st.empty()) {
            auto [left, height] = st.top();
            st.pop();

            int width = n - left;
            maxArea = max(maxArea, height * width);
        }

        return maxArea;
    }
};
