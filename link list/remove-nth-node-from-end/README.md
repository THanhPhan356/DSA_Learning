# Remove Nth Node From End of List

**Problem:** [NeetCode – Remove Nth Node From End of List](https://neetcode.io/problems/remove-node-from-end-of-linked-list/question?list=blind75)

Remove the nth node counted from the end, starting at 1, and return the updated head. The input is a non-empty list and `1 <= n <= length`.

```text
Before: 1 → 2 → 3 → 4 → 5 → null, n = 2
After:  1 → 2 → 3 → 5 → null
```

All three approaches unlink the selected node by connecting its predecessor to its successor. They preserve the remaining nodes and values.

## 1. Brute force — store node pointers

**Code:** [brute-force.cpp](brute-force.cpp)

1. Traverse the list and store each node's address in a vector.
2. Calculate the zero-based removal index: `length - n`.
3. If the index is zero, return `head->next`.
4. Otherwise, connect `nodes[removeIndex - 1]` to `nodes[removeIndex]->next` and return `head`.

The vector gives direct access to the node and its predecessor. It stores pointers to the original nodes; it does not copy their values or rebuild the list.

## 2. Iteration — two passes

**Code:** [two-pass.cpp](two-pass.cpp)

1. Traverse the list to count `length`.
2. The node to remove is at position `length - n + 1` when counting from 1.
3. If `n == length`, remove the head by returning `head->next`.
4. Otherwise, traverse again to the predecessor at position `length - n`.
5. Set `prev->next = prev->next->next` and return `head`.

For a list of length 5 with `n = 2`, the target is position 4 and its predecessor is position 3. No additional node is needed for this approach.

## 3. Two pointers — maintain a fixed gap

**Code:** [two-pointers.cpp](two-pointers.cpp)

1. Create a local dummy node pointing to `head`. Start `slow` at the dummy and `fast` at `head`.
2. Move `fast` forward n steps.
3. Move both pointers one step at a time until `fast == nullptr`.
4. Now `slow->next` is the target. Skip it with `slow->next = slow->next->next`.
5. Return `dummy.next`.

The gap is n links between `slow->next` and `fast`, or n + 1 links between `slow` and `fast`. This gap stays fixed while both pointers move. When `fast` reaches null, `slow` is immediately before the nth node from the end. Both pointers move at the same speed after the initial lead.

Example with `[1, 2, 3, 4, 5]` and `n = 2`:

| Step | slow | fast |
| --- | --- | --- |
| After fast advances n steps | dummy | 3 |
| Move together | 1 | 4 |
| Move together | 2 | 5 |
| Move together | 3 | null |

The dummy handles removal of the first node without a separate branch.

## Complexity comparison

Let L be the list length; n is the removal position from the end.

| Approach | Time | Auxiliary space |
| --- | --- | --- |
| Brute force | O(L) | O(L), for node pointers |
| Two passes | O(L) | O(1) |
| Two pointers | O(L) | O(1) |

Both constant-space approaches have the same asymptotic complexity. Two pointers avoid counting the length first.

## Cases to check

| Input | n | Expected result |
| --- | --- | --- |
| `[1, 2, 3, 4, 5]` | `2` | `[1, 2, 3, 5]` |
| `[1, 2, 3]` | `1` | `[1, 2]` |
| `[1, 2, 3]` | `3` | `[2, 3]` |
| `[5]` | `1` | `[]` |
| `[7, 7, 7]` | `2` | `[7, 7]` |

Removing the head changes the returned pointer; removing the tail must leave the new tail pointing to `nullptr`.

## Using the code

Each C++ file is an independent alternative defining a `Solution` class. Choose one approach for submission. NeetCode provides `ListNode`; for brute force, also include `<vector>` and keep the `std::` qualification. The [list-node.h](list-node.h) file supplies the node definition for local compilation.

These implementations bypass the removed node without deleting its allocation. Memory ownership remains with the caller or test runner.

## Learning note

The learner proposed counting the length, calculating the target position, and reconnecting the neighboring nodes. The discussion confirmed the two-pass approach and compared it with storing node pointers and maintaining a fixed pointer gap. The implementations were provided during the exercise. Local tests cover every valid n for lengths 1 through 30 and verify original node identities, unchanged values, and null termination; no accepted online submission is recorded here.
