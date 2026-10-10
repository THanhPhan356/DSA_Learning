# Linked List Cycle Detection

**Problem:** [NeetCode – Linked List Cycle Detection](https://neetcode.io/problems/linked-list-cycle-detection/question?list=neetcode150)  
**Solution:** [solution.cpp](solution.cpp)

Return `true` if following the `next` pointers from `head` eventually revisits the same node. Return `false` if the list ends at `nullptr`. A repeated value alone does not indicate a cycle.

```text
No cycle: 1 → 2 → 3 → null
Cycle:    1 → 2 → 3 → 4
              ↑       │
              └───────┘
```

## Approach: Floyd's cycle detection

1. Initialize `slow` and `fast` at `head`.
2. While `fast` and `fast->next` are non-null, move `slow` one node and `fast` two nodes.
3. After moving, compare the pointers. If `slow == fast`, they reference the same node and a cycle exists.
4. If the fast pointer cannot continue, return `false`.

When both pointers enter a cycle, the fast pointer gains one position per iteration relative to the slow pointer. Within at most one full cycle of these iterations, it catches the slow pointer. In an acyclic list, the fast pointer reaches the end instead.

## C++ notes

- Compare `slow == fast`, not `slow->val == fast->val`: different nodes may contain the same value.
- Move before comparing because both pointers start at `head`.
- `fast != nullptr && fast->next != nullptr` safely checks whether the two-step move is possible. C++ short-circuits `&&`, so `fast->next` is accessed only when `fast` is non-null.
- An empty list or a single node pointing to `nullptr` skips the loop and returns `false`.
- The `index` shown in problem examples is used by the test runner to connect the tail to a node. The function receives only `head`.

## Examples

| Node values | Tail connects to index | Expected result |
| --- | --- | --- |
| `[1, 2, 3, 4]` | `1` | `true` |
| `[1, 2]` | `-1` (null) | `false` |
| `[]` | `-1` | `false` |
| `[7]` | `0` (itself) | `true` |
| `[7]` | `-1` | `false` |
| `[7, 7, 7]` | `-1` | `false` |

## Complexity and side effects

**Time:** O(n), where n is the number of distinct reachable nodes.  
**Auxiliary space:** O(1), using two pointers.

The function does not modify node values or links and does not allocate new nodes.

## Using the code

NeetCode provides `ListNode`, so copy only the `Solution` class when submitting. The [list-node.h](list-node.h) file supplies the node definition for local compilation.

## Learning note

The learner proposed a fast pointer and a slow pointer that detect a cycle when they meet. The discussion clarified the one-step and two-step moves, checking after moving, and comparing node addresses. The implementation was provided during the exercise. Local tests check acyclic lists, self-loops, every cycle entry in short lists, repeated values, and unchanged links; no accepted online submission is recorded here.
