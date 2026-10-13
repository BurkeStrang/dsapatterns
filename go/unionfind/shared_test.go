package unionfind

import "testing"

func Test_unionFind(t *testing.T) {
	uf := newUnionFind(5)
	if uf.connected(0, 1) {
		t.Errorf("connected(0, 1) = true before any union, want false")
	}

	uf.union(0, 1)
	uf.union(3, 4)
	uf.union(1, 1)
	if !uf.connected(0, 1) {
		t.Errorf("connected(0, 1) = false after union(0, 1), want true")
	}
	if uf.connected(1, 3) {
		t.Errorf("connected(1, 3) = true, want false")
	}

	uf.union(1, 4)
	if !uf.connected(0, 3) {
		t.Errorf("connected(0, 3) = false after joining both sets, want true")
	}
	if uf.connected(2, 0) {
		t.Errorf("connected(2, 0) = true, want false")
	}
}
