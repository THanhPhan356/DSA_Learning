# Reorder Linked List

**Problem:** [NeetCode – Reorder Linked List](https://neetcode.io/problems/reorder-linked-list/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

Reorder the existing nodes by alternating between the beginning and end of the list: `L0 → L(n-1) → L1 → L(n-2) → ...`. Change the `next` links without changing node values. The function updates the list in place and returns nothing.

```text
Before: 1 → 2 → 3 → 4 → 5 → null
After:  1 → 5 → 2 → 4 → 3 → null
```

## Approach: split, reverse, and interleave

1. Return immediately for an empty list or a single node.
2. Set `slow = head` and `fast = head->next`. Move `slow` one node and `fast` two nodes until the fast pointer cannot continue.
3. Start the second half at `slow->next`, then set `slow->next = nullptr` to separate the halves. The first half contains the middle node when the length is odd.
4. Reverse the second half using the iterative linked-list reversal technique.
5. Alternate nodes from the first half and the reversed second half until the second half is exhausted.

```text
Split:       1 → 2 → 3 → null    4 → 5 → null
Reverse:     1 → 2 → 3 → null    5 → 4 → null
Interleave:  1 → 5 → 2 → 4 → 3 → null
```

Reversing the second half gives access to the original last, second-last, and subsequent nodes by following `next`. Interleaving then produces the required order. The first half is at least as long as the second, so an odd-length list finishes with its original middle node.

## Understanding the pointers

- A singly linked list cannot move backward directly from its tail.
- `slow->next = nullptr` disconnects the two halves before any reversal or interleaving.
- During reversal, save the original next node before replacing `second->next`.
- After reversal, `prev` points to the new head of the second half.
- During interleaving, save `nextFirst` and `nextSecond` before changing either link, then advance to the saved nodes.
- The two halves reuse the original nodes; no second set of nodes is allocated.

## Examples

| Input | Expected result |
| --- | --- |
| `[1]` | `[1]` |
| `[1, 2]` | `[1, 2]` |
| `[1, 2, 3]` | `[1, 3, 2]` |
| `[1, 2, 3, 4]` | `[1, 4, 2, 3]` |
| `[1, 2, 3, 4, 5]` | `[1, 5, 2, 4, 3]` |
| `[1, 2, 3, 4, 5, 6]` | `[1, 6, 2, 5, 3, 4]` |

## Complexity and side effects

**Time:** O(n), using linear passes to find the middle, reverse the second half, and interleave.  
**Auxiliary space:** O(1), using only a few pointers.

The function changes the original nodes' links, preserves their values, and keeps the original head. The final tail points to `nullptr`.

## Using the code

NeetCode provides `ListNode`, so copy only the `Solution` class when submitting. The [list-node.h](list-node.h) file supplies the node definition for local compilation.

## Learning note

The learner suggested pointers at both ends and recognized that reversing a list would help traverse from the original tail. The discussion refined this to reversing only the second half, disconnecting the halves, and interleaving them. The implementation was provided during the exercise. Local tests verify the required node order, preserved node identities and values, and null termination for odd and even lengths; no accepted online submission is recorded here.
