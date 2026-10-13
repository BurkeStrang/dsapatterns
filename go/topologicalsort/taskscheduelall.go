package topologicalsort

// There are N tasks, labeled from 0 to 'N-1'.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
//
// Given the number of tasks and a list of prerequisite pairs,
// write a method to print all possible ordering of tasks meeting all
// prerequisites.
//
// Example 1:
// Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
// Output:
// 1) [3, 2, 0, 1]
// 2) [3, 2, 1, 0]
// Explanation: There are two possible orderings of the tasks meeting all
// prerequisites.
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: There is only possible ordering of the tasks.
//
// Example 3:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output:
// 1) [0, 1, 4, 3, 2, 5]
// 2) [0, 1, 3, 4, 2, 5]
// 3) [0, 1, 3, 2, 4, 5]
// 4) [0, 1, 3, 2, 5, 4]
// 5) [1, 0, 3, 4, 2, 5]
// 6) [1, 0, 3, 2, 4, 5]
// 7) [1, 0, 3, 2, 5, 4]
// 8) [1, 0, 4, 3, 2, 5]
// 9) [1, 3, 0, 2, 4, 5]
// 10) [1, 3, 0, 2, 5, 4]
// 11) [1, 3, 0, 4, 2, 5]
// 12) [1, 3, 2, 0, 5, 4]
// 13) [1, 3, 2, 0, 4, 5]

func printOrders(tasks int, prerequisites [][]int) [][]int {
	orders := make([][]int, 0)
	sortedOrder := make([]int, 0)
	if tasks <= 0 {
		return orders
	}

	// a. Initialize the graph
	inDegree := make(map[int]int)
	graph := make(map[int][]int)
	for i := range tasks {
		inDegree[i] = 0
		graph[i] = make([]int, 0)
	}

	// b. Build the graph
	for i := range prerequisites {
		parent, child := prerequisites[i][0], prerequisites[i][1]
		graph[parent] = append(graph[parent], child)
		inDegree[child]++
	}

	// c. Find all sources i.e., all vertices with 0 in-degrees
	sources := make([]int, 0)
	for vertex := range tasks {
		if inDegree[vertex] == 0 {
			sources = append(sources, vertex)
		}
	}

	printAllTopologicalSorts(graph, inDegree, sources, sortedOrder, &orders)

	return orders
}

func printAllTopologicalSorts(
	graph map[int][]int,
	inDegree map[int]int,
	sources []int,
	sortedOrder []int,
	orders *[][]int,
) {
	for i, vertex := range sources {
		sortedOrder = append(sortedOrder, vertex)

		// Copy the sources for the next call, leaving out the current vertex
		sourcesForNextCall := make([]int, 0, len(sources))
		sourcesForNextCall = append(sourcesForNextCall, sources[:i]...)
		sourcesForNextCall = append(sourcesForNextCall, sources[i+1:]...)

		children := graph[vertex]
		for _, child := range children {
			inDegree[child]--
			if inDegree[child] == 0 {
				sourcesForNextCall = append(sourcesForNextCall, child)
			}
		}

		printAllTopologicalSorts(
			graph, inDegree, sourcesForNextCall, sortedOrder, orders,
		)

		// Backtrack: take the vertex out again and restore the in-degrees
		sortedOrder = sortedOrder[:len(sortedOrder)-1]
		for _, child := range children {
			inDegree[child]++
		}
	}

	// If sortedOrder doesn't contain all tasks, either we've a cyclic
	// dependency between tasks, or we have not processed all the tasks in
	// this recursive call
	if len(sortedOrder) == len(inDegree) {
		order := make([]int, len(sortedOrder))
		copy(order, sortedOrder)
		*orders = append(*orders, order)
	}
}
