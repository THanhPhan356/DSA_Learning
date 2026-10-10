# Merge Two Sorted Linked Lists

**Problem:** [NeetCode – Merge Two Sorted Linked Lists](https://neetcode.io/problems/merge-two-sorted-linked-lists/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

Merge two singly linked lists sorted in non-decreasing order and return the head of the combined sorted list. Reuse the original nodes by changing their links.

```text
List 1: 1 → 2 → 4 → null
List 2: 1 → 3 → 5 → null
Result: 1 → 1 → 2 → 3 → 4 → 5 → null
```

## Approach: iteration with a dummy node

1. Create a dummy node and set `tail` to its address.
2. While both lists still have nodes, compare `l1->val` with `l2->val`.
3. Connect the smaller current node to `tail->next` and advance that list's pointer. For equal values, choose the node from `l1`.
4. Move `tail` to the node just connected.
5. When one list ends, attach the other list's remaining chain to `tail->next`.
6. Return `dummy.next`, the first actual node of the result.

The smallest remaining value must be at one of the two current heads because both lists are already sorted. Repeatedly taking the smaller head keeps the result sorted. Once a list is exhausted, the other chain is already sorted and can be attached directly.

## Understanding the pointers

- `l1` and `l2` point to existing nodes; they do not create new nodes.
- Compare `val`, the integer stored in a node. `next` is a pointer to the following node.
- `tail->next = l1` connects a node to the result.
- `l1 = l1->next` advances in the first input list.
- `tail = tail->next` moves the result's tail to the newly connected node.
- `dummy` stays in place while `tail` moves. Returning `dummy.next` excludes the dummy node.

The final expression:

```cpp
tail->next = (l1 != nullptr) ? l1 : l2;
```

chooses `l1` if it still has nodes; otherwise it chooses `l2`. If both are empty, it assigns `nullptr`.

## Examples

| List 1 | List 2 | Expected result |
| --- | --- | --- |
| `[1, 2, 4]` | `[1, 3, 5]` | `[1, 1, 2, 3, 4, 5]` |
| `[]` | `[1, 2]` | `[1, 2]` |
| `[1, 2]` | `[]` | `[1, 2]` |
| `[]` | `[]` | `[]` |
| `[1, 1]` | `[1, 1]` | `[1, 1, 1, 1]` |
| `[-3, 0, 4]` | `[-2, 0, 5]` | `[-3, -2, 0, 0, 4, 5]` |

## Complexity and side effects

**Time:** O(n + m) in the worst case, where n and m are the input lengths.  
**Auxiliary space:** O(1), using one dummy node and a few pointers.

The function changes links in the original lists. It does not allocate result nodes or change their values. The dummy node is local; all returned nodes belong to the inputs.

## Using the code

NeetCode provides `ListNode`, so copy only the `Solution` class when submitting. The [list-node.h](list-node.h) file supplies the node definition for local compilation.

## Learning note

The learner proposed comparing the two current lists and connecting the smaller node to a third head. The discussion clarified comparing node values, keeping a fixed dummy head with a moving tail, and attaching the remaining chain. The implementation was provided during the exercise. Local tests verify order, original node identities, unchanged values, and termination; no accepted online submission is recorded here.
