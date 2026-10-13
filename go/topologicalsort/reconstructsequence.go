package topologicalsort

// Given a sequence originalSeq and an array of sequences,
// write a method to find if originalSeq can be uniquely
// reconstructed from the array of sequences.
// Unique reconstruction means that we need to find if
// originalSeq is the only sequence such that all
// sequences in the array are subsequences of it.
//
// Example 1:
// Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
// Output: true
// Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct
// [1, 2, 3, 4], in other words, all the given sequences uniquely define the order of numbers
// in the 'originalSeq'.
//
// Example 2:
// Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
// Output: false
// Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct
// [1, 2, 3, 4]. There are two possible sequences we can construct from the given sequences:
// 1) [1, 2, 3, 4]
// 2) [1, 2, 4, 3]
//
// Example 3:
// Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
// Output: true
// Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct
// [3, 1, 4, 2, 5].
//
// Constraints:
// n == originalSeq.length
// 1 <= n <= 104
// originalSeq is a permutation of all the integers in the range [1, n].
// 1 <= seqs.length <= 104
// 1 <= seqs[i].length <= 104
// 1 <= sum(seqs[i].length) <= 105
// 1 <= seqs[i][j] <= n
// All the arrays of sequences are unique.
// seqs[i] is a subsequence of nums.

func canConstruct(originalSeq []int, sequences [][]int) bool {
	sortedOrder := make([]int, 0)
	if len(originalSeq) == 0 {
		return false
	}

	// a. Initialize the graph
	inDegree := make(map[int]int) // count of incoming edges for every vertex
	graph := make(map[int][]int)  // adjacency list graph
	for _, seq := range sequences {
		for i := range seq {
			if _, ok := inDegree[seq[i]]; !ok {
				inDegree[seq[i]] = 0
				graph[seq[i]] = make([]int, 0)
			}
		}
	}

	// b. Build the graph
	for _, seq := range sequences {
		for i := 1; i < len(seq); i++ {
			parent, child := seq[i-1], seq[i]
			graph[parent] = append(graph[parent], child)
			inDegree[child]++
		}
	}

	// if we don't have ordering rules for all the numbers we'll not able to uniquely
	// construct the sequence
	if len(inDegree) != len(originalSeq) {
		return false
	}

	// c. Find all sources i.e., all vertices with 0 in-degrees
	sources := make([]int, 0)
	for key, value := range inDegree {
		if value == 0 {
			sources = append(sources, key)
		}
	}

	// d. For each source, add it to the sortedOrder and subtract one from all of its
	// children's in-degrees if a child's in-degree becomes zero, add it to sources queue
	for len(sources) > 0 {
		if len(sources) > 1 {
			// more than one sources mean, there is more than one way to
			// reconstruct the sequence
			return false
		}
		if originalSeq[len(sortedOrder)] != sources[0] {
			// the next source (or number) is different from original sequence
			return false
		}
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

	// if sortedOrder's size is not equal to original sequence's size, there is no
	// unique way to construct
	return len(sortedOrder) == len(originalSeq)
}
