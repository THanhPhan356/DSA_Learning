#include "list-node.h"

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return;

        // 1. Find the middle and split the list.
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = nullptr;

        // 2. Reverse the second half.
        ListNode* prev = nullptr;

        while (second != nullptr) {
            ListNode* next = second->next;
            second->next = prev;
            prev = second;
            second = next;
        }

        // 3. Interleave the two halves.
        ListNode* first = head;
        second = prev;

        while (second != nullptr) {
            ListNode* nextFirst = first->next;
            ListNode* nextSecond = second->next;

            first->next = second;
            second->next = nextFirst;

            first = nextFirst;
            second = nextSecond;
        }
    }
};
