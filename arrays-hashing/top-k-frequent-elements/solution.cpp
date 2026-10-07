#include <unordered_map>
#include <vector>
using namespace std;

// Reference: https://neetcode.io/solutions/top-k-frequent-elements
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        // Count how often each number appears.
        for (int n : nums) {
            count[n] = 1 + count[n];
        }

        // freq[f] stores all numbers that appear f times.
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        // Visit the highest frequencies first.
        for (int i = static_cast<int>(freq.size()) - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == static_cast<size_t>(k)) {
                    return res;
                }
            }
        }
        return res;
    }
};
