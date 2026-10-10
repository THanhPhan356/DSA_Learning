#include <algorithm>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_prof = 0;
        int buy_px = prices[0];

        for (int i = 1; i < static_cast<int>(prices.size()); ++i) {
            max_prof = std::max(prices[i] - buy_px, max_prof);
            buy_px = std::min(prices[i], buy_px);
        }

        return max_prof;
    }
};
