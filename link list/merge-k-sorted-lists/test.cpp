#include "solution.cpp"
#include <algorithm>
#include <iostream>
#include <unordered_set>

bool check(const std::vector<std::vector<int>>& input) {
    std::vector<std::vector<ListNode>> storage(input.size());
    std::vector<ListNode*> heads;
    std::vector<int> expected;
    std::unordered_set<ListNode*> remaining;

    for (std::size_t i = 0; i < input.size(); ++i) {
        auto& nodes = storage[i];
        nodes.reserve(input[i].size());
        for (int value : input[i]) {
            nodes.emplace_back(value);
            expected.push_back(value);
        }
        for (std::size_t j = 0; j < nodes.size(); ++j) {
            nodes[j].next = j + 1 < nodes.size() ? &nodes[j + 1] : nullptr;
            remaining.insert(&nodes[j]);
        }
        heads.push_back(nodes.empty() ? nullptr : &nodes[0]);
    }

    std::sort(expected.begin(), expected.end());
    Solution solution;
    ListNode* result = solution.mergeKLists(heads);
    for (int value : expected) {
        if (!result || remaining.erase(result) != 1 || result->val != value)
            return false;
        result = result->next;
    }
    if (result != nullptr || !remaining.empty()) return false;
    for (std::size_t i = 0; i < input.size(); ++i)
        for (std::size_t j = 0; j < input[i].size(); ++j)
            if (storage[i][j].val != input[i][j]) return false;
    return true;
}

int main() {
    std::vector<std::vector<std::vector<int>>> cases = {
        {}, {{}}, {{}, {}, {}}, {{1, 2, 3}},
        {{1, 4, 5}, {1, 3, 4}, {2, 6}},
        {{1, 2, 4, 6}, {1, 2, 3, 5}, {2, 4, 5, 7}},
        {{}, {-5, 0}, {}, {-3, 0, 8}, {}},
        {{1, 1}, {1}, {1, 1}, {1}},
        {{-8}, {-7, -2}, {0}, {1, 3}, {4}, {5, 9}, {10}}
    };
    for (int k = 0; k <= 10; ++k) {
        std::vector<std::vector<int>> lists(k);
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < i % 5; ++j)
                lists[i].push_back(-10 + i + j * 3);
        cases.push_back(lists);
    }
    for (std::size_t i = 0; i < cases.size(); ++i) {
        if (!check(cases[i])) {
            std::cerr << "Failed case " << i << '\n';
            return 1;
        }
    }
    std::cout << "Passed " << cases.size() << " cases\n";
}
