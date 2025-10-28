package graphs

// There are n cities. Some of them are connected in a network.
// If City A is directly connected to City B,
// and City B is directly connected to City C,
// city A is indirectly connected to City C.
//
// If a group of cities are connected directly or indirectly,
// they form a province.
// Given an n x n matrix isConnected where isConnected[i][j] = 1
// if the ith city and the jth city are directly connected,
// and isConnected[i][j] = 0 otherwise, determine the total number of provinces.
//
// Example 1:
// Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
// Expected Output: 2
// Justification: Here, city 1 and 2 form a single provenance, and city 3 is one province itself.
//
// Example 2:
// Input: isConnected = [1,0,0],[0,1,0],[0,0,1]]
// Expected Output: 3
// Justification: In this scenario, no cities are connected to each other, so each city forms its own province.
//
// Example 3:
// Input: isConnected = [[1,0,0,1],[0,1,1,0],[0,1,1,0],[1,0,0,1]]
// Expected Output: 2
// Justification: Cities 1 and 4 form a province, and cities 2 and 3 form another province,
// resulting in a total of 2 provinces.
//
// Constraints:
// 1 <= n <= 200
// n == isConnected.length
// n == isConnected[i].length
// isConnected[i][j] is 1 or 0.
// isConnected[i][i] == 1
// isConnected[i][j] == isConnected[j][i]

type UnionFind struct {
	parent []int
	rank   []int
}

func NewUnionFind(size int) *UnionFind {
	parent := make([]int, size)
	rank := make([]int, size)
	for i := range size {
		parent[i] = i
		println(parent[i], "parent")
		println(rank[i], "rank")
	}
	return &UnionFind{parent, rank}
}

func (uf *UnionFind) Find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.Find(uf.parent[x]) // Path compression
	}
	return uf.parent[x]
}

func (uf *UnionFind) UnionSet(x, y int) {
	rootX := uf.Find(x)
	rootY := uf.Find(y)

	// If they are in the same set, do nothing.
	if rootX == rootY {
		return
	}

	// Union by rank
	if uf.rank[rootX] < uf.rank[rootY] {
		uf.parent[rootX] = rootY
	} else if uf.rank[rootX] > uf.rank[rootY] {
		uf.parent[rootY] = rootX
	} else {
		uf.parent[rootY] = rootX
		uf.rank[rootX]++
	}
}

func findProvinces(isConnected [][]int) int {
	n := len(isConnected)
	uf := NewUnionFind(n)
	numberOfProvinces := n

	// Iterate over each pair of nodes and union the sets if there is a connection.
	for i := range n {
		for j := i + 1; j < n; j++ {
			if isConnected[i][j] == 1 && uf.Find(i) != uf.Find(j) {
				numberOfProvinces--
				uf.UnionSet(i, j)
			}
		}
	}
	return numberOfProvinces
}
