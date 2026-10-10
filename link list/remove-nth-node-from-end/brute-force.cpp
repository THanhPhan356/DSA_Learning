#include "list-node.h"
#include <vector>

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode*> nodes;

        for (ListNode* current = head; current != nullptr; current = current->next) {
            nodes.push_back(current);
        }

        int removeIndex = static_cast<int>(nodes.size()) - n;

        if (removeIndex == 0) {
            return head->next;
        }

        nodes[removeIndex - 1]->next = nodes[removeIndex]->next;

        return head;
    }
};
