#include "solution.cpp"
#include <cassert>
#include <iostream>

void check(vector<int> nums, const vector<int>& expected) {
    assert(Solution{}.productExceptSelf(nums) == expected);
}

int main() {
    check({1, 2, 4, 6}, {48, 24, 12, 8});
    check({2, 3, 4, 5}, {60, 40, 30, 24});
    check({-1, 0, 1, 2, 3}, {0, -6, 0, 0, 0});
    check({0, 0, 3}, {0, 0, 0});
    check({0, 5}, {5, 0});
    check({-2, -3}, {-3, -2});
    check(vector<int>(100000, 1), vector<int>(100000, 1));
    std::cout << "Passed 7 checks\n";
}
