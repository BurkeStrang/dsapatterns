package topologicalsort

// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs, find out if it is possible to schedule all the tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: true
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: true
// Explanation: To execute task '1', task '0' needs to finish first. Similarly, task '1' needs to finish before '2' can be scheduled. One possible scheduling of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: false
// Explanation: The tasks have a cyclic dependency, therefore they cannot be scheduled.

type TaskScheduel struct{}

func (s *TaskScheduel) isSchedulingPossible(tasks int, prerequisites [][]int) bool {
	sortedOrder := []int{}
	if tasks <= 0 {
		return false
	}

	// Initialize the graph
	inDegree := make(map[int]int) // count of incoming edges for every vertex
	graph := make(map[int][]int)  // adjacency list graph
	for i := range tasks {
		inDegree[i] = 0
		graph[i] = []int{}
	}

	// Build the graph
	for i := range prerequisites {
		parent := prerequisites[i][0]
		child := prerequisites[i][1]
		graph[parent] = append(graph[parent], child) // put the child into its parent's list
		inDegree[child]++                            // increment child's inDegree
	}

	// Find all sources i.e., all vertices with 0 in-degrees
	sources := []int{}
	for vertex, degree := range inDegree {
		if degree == 0 {
			sources = append(sources, vertex)
		}
	}

	// For each source, add it to the sortedOrder and subtract one from all of its
	// children's in-degrees. If a child's in-degree becomes zero, add it to sources queue.
	for len(sources) > 0 {
		vertex := sources[0]
		sources = sources[1:]
		sortedOrder = append(sortedOrder, vertex)
		// Get the node's children to decrement their in-degrees
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
	return len(sortedOrder) == tasks
}
