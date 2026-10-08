#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> res(n);
        vector<int> left(n);
        vector<int> right(n);

        left[0] = 1;
        right[n - 1] = 1;

        for (int i = 1; i < n; ++i) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        for (int i = n - 2; i >= 0; --i) {
            right[i] = nums[i + 1] * right[i + 1];
        }
        for (int i = 0; i < n; ++i) {
            res[i] = right[i] * left[i];
        }
        return res;
    }
};
