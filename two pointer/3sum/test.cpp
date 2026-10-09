#include <cassert>
#include <iostream>
#include "solution.cpp"

void check(std::vector<int> nums, std::vector<std::vector<int>> expected) {
    Solution solution;
    auto actual = solution.threeSum(nums);
    std::sort(actual.begin(), actual.end());
    std::sort(expected.begin(), expected.end());
    assert(actual == expected);
}

int main() {
    check({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2}, {-1, 0, 1}});
    check({0, 0, 0, 0}, {{0, 0, 0}});
    check({-2, 0, 0, 2, 2}, {{-2, 0, 2}});
    check({-2, 0, 1, 1, 2}, {{-2, 0, 2}, {-2, 1, 1}});
    check({0, 1, 1}, {});
    check({-1, -1, 2}, {{-1, -1, 2}});
    check({}, {});
    check({1, 2, 3}, {});
    check({-100000, 0, 100000}, {{-100000, 0, 100000}});
    std::cout << "PASS: 9 cases\n";
}
