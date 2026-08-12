package topologicalsort

// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs,
// write a method to find the ordering of tasks we should pick to finish all tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: [0 1 4 3 2 5]
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: To execute task '1', task '0' needs to finish first.
// Similarly, task '1' needs to finish before '2' can be scheduled.
// A possible scheduling of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: []
// Explanation: The tasks have a cyclic dependency, therefore they cannot be scheduled.

func findOrder(tasks int, prerequisites [][]int) []int {
	sortedOrder := make([]int, 0)
	if tasks <= 0 {
		return sortedOrder
	}

	// Initialize the graph
	inDegree := make(map[int]int)
	graph := make(map[int][]int)
	for i := range tasks {
		inDegree[i] = 0
		graph[i] = make([]int, 0)
	}

	// Build the graph
	for i := range prerequisites {
		parent, child := prerequisites[i][0], prerequisites[i][1]
		graph[parent] = append(graph[parent], child)
		inDegree[child]++
	}

	// Find all sources i.e., all vertices with 0 in-degrees
	sources := make([]int, 0)
	for key, value := range inDegree {
		if value == 0 {
			sources = append(sources, key)
		}
	}

	// For each source, add it to the sortedOrder and subtract one from all of its
	// children's in-degrees. If a child's in-degree becomes zero, add it to sources queue.
	for len(sources) > 0 {
		vertex := sources[0]
		sources = sources[1:]
		sortedOrder = append(sortedOrder, vertex)
		children := graph[vertex]
		for _, child := range children {
			inDegree[child]--
			if inDegree[child] == 0 {
				sources = append(sources, child)
			}
		}
	}

	// If sortedOrder doesn't contain all tasks, there is a cyclic dependency between
	// tasks, therefore, we will not be able to schedule all tasks
	if len(sortedOrder) != tasks {
		return []int{}
	}

	return sortedOrder
}
