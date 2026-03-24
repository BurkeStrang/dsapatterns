package kwaymerge

import "testing"

func Test_findKthSmallest(t *testing.T) {
	tests := []struct {
		name  string
		lists [][]int
		k     int
		want  int
	}{
		{name: "Example 1", lists: [][]int{{2, 6, 8}, {3, 6, 7}, {1, 3, 4}}, k: 5, want: 4},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findKthSmallest(tt.lists, tt.k)
			if got != tt.want {
				t.Errorf("findKthSmallest() = %v, want %v", got, tt.want)
			}
		})
	}
}
