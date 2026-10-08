// Package islandtraversal
package islandtraversal

// Defensive deep copy so tests are not mutated during flood fill
func copyMatrix(m [][]int) [][]int {
	cp := make([][]int, len(m))
	for i := range m {
		cp[i] = append([]int(nil), m[i]...)
	}
	return cp
}
