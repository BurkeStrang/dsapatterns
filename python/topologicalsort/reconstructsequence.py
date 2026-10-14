"""
Given a sequence originalSeq and an array of sequences,
write a method to find if originalSeq can be uniquely
reconstructed from the array of sequences.
Unique reconstruction means that we need to find if
originalSeq is the only sequence such that all
sequences in the array are subsequences of it.

Example 1:
Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
Output: true
Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely
reconstruct
[1, 2, 3, 4], in other words, all the given sequences uniquely define the
order of numbers
in the 'originalSeq'.

Example 2:
Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
Output: false
Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely
reconstruct
[1, 2, 3, 4]. There are two possible sequences we can construct from the
given sequences:
1) [1, 2, 3, 4]
2) [1, 2, 4, 3]

Example 3:
Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
Output: true
Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely
reconstruct
[3, 1, 4, 2, 5].

Constraints:
n == originalSeq.length
1 <= n <= 104
originalSeq is a permutation of all the integers in the range [1, n].
1 <= seqs.length <= 104
1 <= seqs[i].length <= 104
1 <= sum(seqs[i].length) <= 105
1 <= seqs[i][j] <= n
All the arrays of sequences are unique.
seqs[i] is a subsequence of nums.
"""

import itertools
from collections import deque


def can_construct(original_seq: list[int], sequences: list[list[int]]) -> bool:
    sorted_order: list[int] = []
    if not original_seq:
        return False

    # a. Initialize the graph
    in_degree: dict[int, int] = {}  # count of incoming edges for every vertex
    graph: dict[int, list[int]] = {}  # adjacency list graph
    for seq in sequences:
        for num in seq:
            in_degree.setdefault(num, 0)
            graph.setdefault(num, [])

    # b. Build the graph
    for seq in sequences:
        for parent, child in itertools.pairwise(seq):
            graph[parent].append(child)
            in_degree[child] += 1

    # if we don't have ordering rules for all the numbers we'll not able to
    # uniquely construct the sequence
    if len(in_degree) != len(original_seq):
        return False

    # c. Find all sources i.e., all vertices with 0 in-degrees
    sources = deque(key for key, value in in_degree.items() if value == 0)

    # d. For each source, add it to the sorted_order and subtract one from
    # all of its children's in-degrees if a child's in-degree becomes zero,
    # add it to sources queue
    while sources:
        if len(sources) > 1:
            # more than one sources mean, there is more than one way to
            # reconstruct the sequence
            return False
        vertex = sources.popleft()
        if original_seq[len(sorted_order)] != vertex:
            # the next source (or number) is different from original sequence
            return False
        sorted_order.append(vertex)
        # get the node's children to decrement their in-degrees
        for child in graph[vertex]:
            in_degree[child] -= 1
            if in_degree[child] == 0:
                sources.append(child)

    # if sorted_order's size is not equal to original sequence's size, there
    # is no unique way to construct
    return len(sorted_order) == len(original_seq)
