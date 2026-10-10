# Merge k Sorted Lists

**Problem:** [LeetCode 23](https://leetcode.com/problems/merge-k-sorted-lists/)  
**Solution:** [solution.cpp](solution.cpp)

Merge k sorted linked lists into one sorted linked list, preserving every node and duplicate value.

## Approach: iterative pairwise merging

Use `mergeTwoLists` to combine two sorted lists. Compare their current heads, attach the smaller node to a moving tail, and advance the chosen input. When one input ends, attach the other input's remaining chain.

Then merge groups in rounds:

| Round | `step` | Pairs of starting positions |
| --- | --- | --- |
| 1 | 1 | (0, 1), (2, 3), (4, 5), ... |
| 2 | 2 | (0, 2), (4, 6), ... |
| 3 | 4 | (0, 4), ... |

Store each merged group's head at its first position. `step` is the distance between group starting positions in the vector; it doubles because each round doubles the group size. Positions inside a group are skipped in later rounds.

`i += 2 * step` moves to the next pair. `i + step < k` ensures that the right group exists. An unpaired group waits until a later round. No recursion is needed.

## Three-list example

```text
L0: 1 -> 2 -> 4 -> 6
L1: 1 -> 2 -> 3 -> 5
L2: 2 -> 4 -> 5 -> 7

step = 1: merge L0 and L1; store at lists[0]
          1 -> 1 -> 2 -> 2 -> 3 -> 4 -> 5 -> 6
          L2 waits because index 3 does not exist.

step = 2: merge lists[0] and L2; store at lists[0]
          1 -> 1 -> 2 -> 2 -> 2 -> 3 -> 4 -> 4 -> 5 -> 5 -> 6 -> 7

step = 4: stop because step >= k (3).
```

## Complexity and side effects

- **Time:** O(N log k) for k >= 2, where N is the total number of nodes. Each round processes at most N nodes, and there are ceil(log2 k) rounds.
- **Auxiliary space:** O(1). Both merging functions use iteration and reuse existing nodes.
- The function changes the vector entries and the links in the original lists. Values are unchanged. Inputs must be sorted, acyclic lists with separate nodes.

## Using and checking the code

LeetCode provides `ListNode`; copy the `Solution` class when submitting. [list-node.h](list-node.h) defines the node for local compilation.

Run the local tests from this directory:

```sh
g++ -std=c++17 -Wall -Wextra -pedantic test.cpp -o merge-k-test
./merge-k-test
```

The tests check empty inputs, one list, odd/even list counts, duplicates, negative values, the example above, original node identities, and termination.

## Learning note

This exercise used a provided implementation and a walkthrough of pairwise merging. The discussion focused on reusing `mergeTwoLists`, the meaning of `step`, vector indices, and keeping an unpaired list for a later round. Local tests are recorded here; an accepted online submission has not been verified.
