// Package unionfind is for union find (disjoint set) related problems
package unionfind

// unionFind keeps track of which set every element belongs to. Each set is a
// tree, and the root of the tree stands for the whole set.
type unionFind struct {
	parent []int
	rank   []int
}

// newUnionFind makes size sets, each holding one element.
func newUnionFind(size int) *unionFind {
	uf := &unionFind{
		parent: make([]int, size),
		rank:   make([]int, size),
	}
	for i := range size {
		uf.parent[i] = i
	}
	return uf
}

// find returns the root of the set that x belongs to.
func (uf *unionFind) find(x int) int {
	if uf.parent[x] != x {
		uf.parent[x] = uf.find(uf.parent[x]) // Path compression
	}
	return uf.parent[x]
}

// union merges the sets that x and y belong to.
func (uf *unionFind) union(x, y int) {
	rootX := uf.find(x)
	rootY := uf.find(y)

	if rootX == rootY {
		return
	}

	// Union by rank: hang the shorter tree under the taller one
	switch {
	case uf.rank[rootX] < uf.rank[rootY]:
		uf.parent[rootX] = rootY
	case uf.rank[rootX] > uf.rank[rootY]:
		uf.parent[rootY] = rootX
	default:
		uf.parent[rootY] = rootX
		uf.rank[rootX]++
	}
}

// connected reports whether x and y are in the same set.
func (uf *unionFind) connected(x, y int) bool {
	return uf.find(x) == uf.find(y)
}
