#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> result;
        int n = static_cast<int>(nums.size());

        for (int i = 0; i + 2 < n; ++i) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    ++left;
                    --right;

                    while (left < right && nums[left] == nums[left - 1])
                        ++left;

                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                }
            }
        }

        return result;
    }
};
