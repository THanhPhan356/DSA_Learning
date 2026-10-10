#include <algorithm>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& heights) {
        int left = 0;
        int right = static_cast<int>(heights.size()) - 1;
        int area = 0;

        while (left < right) {
            int currentArea = (right - left)
                            * std::min(heights[left], heights[right]);

            area = std::max(area, currentArea);

            if (heights[left] <= heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return area;
    }
};
