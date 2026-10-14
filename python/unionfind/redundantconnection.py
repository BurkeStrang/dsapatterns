"""
Given an undirected graph containing 1  to n nodes.
The graph is represented by a 2D array of edges,
where edges[i] = [ai, bi], represents an edge between ai, and bi.
Identify one edge that, if removed, will turn the graph into a tree.
A tree is a graph that is connected and has no cycles.
Assume that the graph is always reducible to a tree by removing just one
edge.
If there are multiple answers, return the edge that occurs last in the input.

Example 1:
Input: [[1,2], [1,3], [3,4], [1,4], [1,5]]
Expected Output: [1,4]
Justification: The edge [1,4] is redundant
because removing it will eliminate the cycle 1-3-4-1 while keeping the graph
connected.

Example 2:
Input: [[1,2], [2,3], [3,1], [3,4]]
Expected Output: [3,1]
Justification: The edge [3,1] creates a cycle 1-2-3-1.
Removing it leaves a tree with no cycles.

Example 3:
Input: [[1,2], [2,3], [3,4], [4,2], [5,6]]
Expected Output: [4,2]
Justification: The edge [4,2] adds a cycle 2-3-4-2 in one part of the graph.
Removing this edge breaks the cycle, and the remaining graph is a tree.
Constraints:

n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai, bi <= edges.length
ai != bi
There are no repeated edges.
The given graph is connected, so removing one edge always leaves a tree.
"""


def find_root(parent: list[int], node: int) -> int:
    if node != parent[node]:
        parent[node] = find_root(parent, parent[node])  # Path compression
    return parent[node]


def union_roots(parent: list[int], node1: int, node2: int) -> None:
    root1 = find_root(parent, node1)
    root2 = find_root(parent, node2)
    parent[root1] = root2  # Union the two sets


def find_redundant_connection(
    edges: list[tuple[int, int]],
) -> list[int] | None:
    # nodes are numbered from 1, so index 0 is not used
    parent = list(range(len(edges) + 1))

    for node1, node2 in edges:
        if find_root(parent, node1) == find_root(parent, node2):
            return [node1, node2]  # Redundant connection found
        union_roots(parent, node1, node2)

    return None  # Should not reach here as per problem statement
