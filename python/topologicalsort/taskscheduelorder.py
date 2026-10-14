"""
There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
Each task can have some prerequisite tasks which need to be completed before
it can be scheduled.
Given the number of tasks and a list of prerequisite pairs,
write a method to find the ordering of tasks we should pick to finish all
tasks.

Example 1:
Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
Output: [0 1 4 3 2 5]
Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]

Example 2:
Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: [0, 1, 2]
Explanation: To execute task '1', task '0' needs to finish first.
Similarly, task '1' needs to finish before '2' can be scheduled.
A possible scheduling of tasks is: [0, 1, 2]

Example 3:
Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
Output: []
Explanation: The tasks have a cyclic dependency, therefore they cannot be
scheduled.
"""

from collections import deque


def find_order(tasks: int, prerequisites: list[tuple[int, int]]) -> list[int]:
    sorted_order: list[int] = []

    # Initialize the graph
    in_degree = [0] * tasks
    graph: list[list[int]] = [[] for _ in range(tasks)]

    # Build the graph
    for parent, child in prerequisites:
        graph[parent].append(child)
        in_degree[child] += 1

    # Find all sources i.e., all vertices with 0 in-degrees
    sources = deque(vertex for vertex in range(tasks) if in_degree[vertex] == 0)

    # For each source, add it to the sorted_order and subtract one from all
    # of its children's in-degrees. If a child's in-degree becomes zero, add
    # it to sources queue.
    while sources:
        vertex = sources.popleft()
        sorted_order.append(vertex)
        for child in graph[vertex]:
            in_degree[child] -= 1
            if in_degree[child] == 0:
                sources.append(child)

    # If sorted_order doesn't contain all tasks, there is a cyclic dependency
    # between tasks, therefore, we will not be able to schedule all tasks
    if len(sorted_order) != tasks:
        return []

    return sorted_order
