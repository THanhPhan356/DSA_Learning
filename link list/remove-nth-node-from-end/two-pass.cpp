#include "list-node.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* current = head;

        while (current != nullptr) {
            ++length;
            current = current->next;
        }

        // Removing the first node changes the head.
        if (n == length) {
            return head->next;
        }

        // Find the node immediately before the one to remove.
        ListNode* prev = head;

        for (int position = 1; position < length - n; ++position) {
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};
