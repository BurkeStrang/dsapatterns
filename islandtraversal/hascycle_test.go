package islandtraversal

import "testing"

func Test_hasCycle(t *testing.T) {
	tests := []struct {
		name string
		matrix [][]rune
		want   bool
	}{
		{
			name: "no cycle",
			matrix: [][]rune{
				{'A', 'B', 'C'},
				{'D', 'E', 'F'},
				{'G', 'H', 'I'},
			},
			want: false,
		},
		{
			name: "simple cycle",
			matrix: [][]rune{
				{'A', 'A', 'A'},
				{'A', 'B', 'A'},
				{'A', 'A', 'A'},
			},
			want: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := hasCycle(tt.matrix)
			if got != tt.want {
				t.Errorf("hasCycle() = %v, want %v", got, tt.want)
			}
		})
	}
}

