package topologicalsort

type topsort struct{}

func (s topsort) sort(vertices int, edges [][]int) []int {
	sortedOrder := []int{}
	if vertices <= 0 {
		return sortedOrder
	}

	// a. Initialize the graph
	inDegree := make(map[int]int) // count of incoming edges for every vertex
	graph := make(map[int][]int)  // adjacency list graph
	for i := range vertices {
		inDegree[i] = 0
		graph[i] = []int{}
	}

	// b. Build the graph
	for i := range edges {
		parent, child := edges[i][0], edges[i][1]
		graph[parent] = append(graph[parent], child) // put the child into its parent's list
		inDegree[child]++                            // increment child's inDegree
	}

	// c. Find all sources i.e., all vertices with 0 in-degrees
	sources := []int{}
	for key, value := range inDegree {
		if value == 0 {
			sources = append(sources, key)
		}
	}

	// d. For each source, add it to the sortedOrder and subtract one from all of its
	// children's in-degrees if a child's in-degree becomes zero, add it to sources queue
	for len(sources) > 0 {
		vertex := sources[0]
		sources = sources[1:]
		sortedOrder = append(sortedOrder, vertex)
		// get the node's children to decrement their in-degrees
		children := graph[vertex]
		for _, child := range children {
			inDegree[child]--
			if inDegree[child] == 0 {
				sources = append(sources, child)
			}
		}
	}

	// if topological sort is not possible as the graph has a cycle
	if len(sortedOrder) != vertices {
		return []int{}
	}

	return sortedOrder
}
