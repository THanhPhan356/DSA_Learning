#include "list-node.h"
#include <vector>

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (a != nullptr && b != nullptr) {
            if (a->val <= b->val) {
                tail->next = a;
                a = a->next;
            } else {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }

        tail->next = (a != nullptr) ? a : b;
        return dummy.next;
    }

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        int k = static_cast<int>(lists.size());
        if (k == 0) return nullptr;

        // Merge groups of 1, 2, 4, ... original lists.
        for (int step = 1; step < k; step *= 2) {
            for (int i = 0; i + step < k; i += 2 * step) {
                lists[i] = mergeTwoLists(lists[i], lists[i + step]);
            }
        }

        return lists[0];
    }
};
