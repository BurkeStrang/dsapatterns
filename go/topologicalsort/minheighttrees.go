package topologicalsort

// We are given an undirected graph that has the characteristics of a k-ary tree.
// In such a graph,
// we can choose any node as the root to make a k-ary tree.
// The root (or the tree) with the minimum height will be called Minimum Height Tree (MHT).
// There can be multiple MHTs for a graph.
// In this problem, we need to find all those roots which give us MHTs.
// Write a method to find all MHTs of the given graph and return a list of their roots.
//
// Example 1:
// Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
// Output:[1, 2]
// Explanation: Choosing '1' or '2' as roots give us MHTs.
// In the below diagram,
// we can see that the height of the trees with roots '1' or '2' is three which is the minimum.
//
// Example 2:
// Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
// Output:[0, 2]
// Explanation: Choosing '0' or '2' as roots give us MHTs.
// In the below diagram, we can see that the height of the trees with roots '0' or '2' is three which is minimum.
//
// Example 3:
// Input: vertices: 4, Edges: [[0, 1], [1, 2], [1, 3]]
// Output:[1]
//
// Constraints:
// 1 <= vertices <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated edges.

func findTrees(nodes int, edges [][]int) []int {
	minHeightTrees := make([]int, 0)
	if nodes <= 0 {
		return minHeightTrees
	}

	// with only one node, since its in-degree will be 0, therefore, we need to handle
	// it separately
	if nodes == 1 {
		minHeightTrees = append(minHeightTrees, 0)
		return minHeightTrees
	}

	// a. Initialize the graph
	inDegree := make(map[int]int) // count of incoming edges for every vertex
	graph := make(map[int][]int)  // adjacency list graph
	for i := range nodes {
		inDegree[i] = 0
		graph[i] = make([]int, 0)
	}

	// b. Build the graph
	for i := range edges {
		n1, n2 := edges[i][0], edges[i][1]
		// since this is an undirected graph, therefore, add a link for both the nodes
		graph[n1] = append(graph[n1], n2)
		graph[n2] = append(graph[n2], n1)
		// increment the in-degrees of both the nodes
		inDegree[n1]++
		inDegree[n2]++
	}

	// c. Find all leaves i.e., all nodes with only 1 in-degree
	leaves := make([]int, 0)
	for vertex := range nodes {
		if inDegree[vertex] == 1 {
			leaves = append(leaves, vertex)
		}
	}

	// d. Remove leaves level by level and subtract each leave's children's in-degrees.
	// Repeat this until we are left with 1 or 2 nodes, which will be our answer.
	// Any node that has already been a leaf cannot be the root of a minimum height tree,
	// because its adjacent non-leaf node will always be a better candidate.
	totalNodes := nodes
	for totalNodes > 2 {
		leavesSize := len(leaves)
		totalNodes -= leavesSize
		for range leavesSize {
			vertex := leaves[0]
			leaves = leaves[1:]
			children := graph[vertex]
			for _, child := range children {
				inDegree[child]--
				if inDegree[child] == 1 { // if the child has become a leaf
					leaves = append(leaves, child)
				}
			}
		}
	}

	minHeightTrees = append(minHeightTrees, leaves...)
	return minHeightTrees
}
