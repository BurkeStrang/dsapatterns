"""
There are N tasks, labeled from 0 to 'N-1'.
Each task can have some prerequisite tasks which need to be completed before
it can be scheduled.

Given the number of tasks and a list of prerequisite pairs,
write a method to print all possible ordering of tasks meeting all
prerequisites.

Example 1:
Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
Output:
1) [3, 2, 0, 1]
2) [3, 2, 1, 0]
Explanation: There are two possible orderings of the tasks meeting all
prerequisites.

Example 2:
Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
Output: [0, 1, 2]
Explanation: There is only possible ordering of the tasks.

Example 3:
Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
Output:
1) [0, 1, 4, 3, 2, 5]
2) [0, 1, 3, 4, 2, 5]
3) [0, 1, 3, 2, 4, 5]
4) [0, 1, 3, 2, 5, 4]
5) [1, 0, 3, 4, 2, 5]
6) [1, 0, 3, 2, 4, 5]
7) [1, 0, 3, 2, 5, 4]
8) [1, 0, 4, 3, 2, 5]
9) [1, 3, 0, 2, 4, 5]
10) [1, 3, 0, 2, 5, 4]
11) [1, 3, 0, 4, 2, 5]
12) [1, 3, 2, 0, 5, 4]
13) [1, 3, 2, 0, 4, 5]
"""


def print_all_topological_sorts(
    graph: list[list[int]],
    in_degree: list[int],
    sources: list[int],
    sorted_order: list[int],
    orders: list[list[int]],
) -> None:
    for i, vertex in enumerate(sources):
        sorted_order.append(vertex)
        # Copy the sources for the next call, leaving out the current vertex
        sources_for_next_call = sources[:i] + sources[i + 1 :]
        children = graph[vertex]
        for child in children:
            in_degree[child] -= 1
            if in_degree[child] == 0:
                sources_for_next_call.append(child)

        print_all_topological_sorts(
            graph, in_degree, sources_for_next_call, sorted_order, orders
        )

        # Backtrack: take the vertex out again and restore the in-degrees
        sorted_order.pop()
        for child in children:
            in_degree[child] += 1

    # If sorted_order doesn't contain all tasks, either we've a cyclic
    # dependency between tasks, or we have not processed all the tasks in
    # this recursive call
    if len(sorted_order) == len(in_degree):
        orders.append(list(sorted_order))


def print_orders(
    tasks: int, prerequisites: list[tuple[int, int]]
) -> list[list[int]]:
    orders: list[list[int]] = []
    if tasks <= 0:
        return orders

    # a. Initialize the graph
    in_degree = [0] * tasks
    graph: list[list[int]] = [[] for _ in range(tasks)]

    # b. Build the graph
    for parent, child in prerequisites:
        graph[parent].append(child)
        in_degree[child] += 1

    # c. Find all sources i.e., all vertices with 0 in-degrees
    sources = [vertex for vertex in range(tasks) if in_degree[vertex] == 0]

    print_all_topological_sorts(graph, in_degree, sources, [], orders)
    return orders
