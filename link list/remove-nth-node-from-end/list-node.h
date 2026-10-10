#pragma once

struct ListNode {
    int val;
    ListNode* next;

    explicit ListNode(int value = 0, ListNode* nextNode = nullptr)
        : val(value), next(nextNode) {}
};
