# Reverse Linked List

**Problem:** [NeetCode – Reverse Linked List](https://neetcode.io/problems/reverse-a-linked-list/question?list=neetcode150)

Reverse the links in a singly linked list and return its new head. Both approaches reuse the existing nodes.

```text
Before: 1 → 2 → 3 → null
After:  3 → 2 → 1 → null
```

## 1. Iterative — using a loop

**Code:** [iterative.cpp](iterative.cpp)

Use three pointer variables:

- `prev`: the head of the reversed portion, initially `nullptr`.
- `current`: the node being processed, initially `head`.
- `next`: saves the next node before its incoming link is changed.

Perform these steps in each iteration:

1. `next = current->next`: keep access to the unprocessed portion.
2. `current->next = prev`: reverse the current node's link.
3. `prev = current`: update the head of the reversed portion.
4. `current = next`: move to the next node.

Example with `1 → 2 → 3`:

| Step | Reversed portion (`prev`) | Unprocessed portion (`current`) |
| --- | --- | --- |
| Initialization | `null` | `1 → 2 → 3 → null` |
| Process node 1 | `1 → null` | `2 → 3 → null` |
| Process node 2 | `2 → 1 → null` | `3 → null` |
| Process node 3 | `3 → 2 → 1 → null` | `null` |

When `current == nullptr`, return `prev`. Save `next` before changing `current->next`; otherwise, access to the remaining nodes is lost.

## 2. Recursive — using recursion

**Code:** [recursive.cpp](recursive.cpp)

1. If the list is empty or contains one node, return `head`.
2. Call `reverseList(head->next)` to reverse the remaining list and obtain `newHead`.
3. `head->next->next = head`: make the original next node point back to the current node.
4. `head->next = nullptr`: remove the old forward link to prevent a cycle.
5. Return `newHead` through the recursive calls.

For example, when processing node 1, the remaining list `2 → 3` has already become `3 → 2 → null`. The pointer `head->next` still points to node 2, so `head->next->next = head` creates the link `2 → 1`. Setting `head->next = nullptr` then produces `3 → 2 → 1 → null`.

## Complexity comparison

| Approach | Time | Auxiliary space |
| --- | --- | --- |
| Iterative | O(n) | O(1) |
| Recursive | O(n) | O(n), due to the call stack |

The iterative approach is useful when memory is limited or the list is very long. The recursive approach illustrates how to break down the problem, but its call depth grows with the number of nodes.

## Cases to check

| Input | Expected output |
| --- | --- |
| `[]` | `[]` |
| `[1]` | `[1]` |
| `[1, 2]` | `[2, 1]` |
| `[1, 2, 3]` | `[3, 2, 1]` |
| `[2, 2, 1]` | `[1, 2, 2]` |

The new tail must point to `nullptr`. Preserve the original nodes and their values; only change their links.

## Using the code

The two C++ files are independent alternatives, each defining a `Solution` class. Choose one approach for submission. NeetCode provides `ListNode`, so copy only the `Solution` class when submitting. The [list-node.h](list-node.h) file supplies the node definition for local compilation.
