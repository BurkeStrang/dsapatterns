"""
Topological Sort of a directed graph (a graph with unidirectional edges) is
a linear ordering of its vertices such that for every directed edge (U, V)
from vertex U to vertex V, U comes before V in the ordering.

Given a directed graph, find the topological ordering of its vertices.
Returns an empty list if the graph has a cycle.
"""

from collections import deque


def sort(vertices: int, edges: list[tuple[int, int]]) -> list[int]:
    sorted_order: list[int] = []

    # a. Initialize the graph
    in_degree = [0] * vertices  # count of incoming edges
    graph: list[list[int]] = [[] for _ in range(vertices)]  # adjacency list

    # b. Build the graph
    for parent, child in edges:
        graph[parent].append(child)  # put the child into its parent's list
        in_degree[child] += 1  # increment child's in_degree

    # c. Find all sources i.e., all vertices with 0 in-degrees
    sources = deque(v for v in range(vertices) if in_degree[v] == 0)

    # d. For each source, add it to the sorted_order and subtract one from
    # all of its children's in-degrees if a child's in-degree becomes zero,
    # add it to sources queue
    while sources:
        vertex = sources.popleft()
        sorted_order.append(vertex)
        # get the node's children to decrement their in-degrees
        for child in graph[vertex]:
            in_degree[child] -= 1
            if in_degree[child] == 0:
                sources.append(child)

    # if topological sort is not possible as the graph has a cycle
    if len(sorted_order) != vertices:
        return []

    return sorted_order
