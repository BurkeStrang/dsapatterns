package subsets

import "testing"

func Test_countTrees(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want int
	}{
		{
			name: "Example 1",
			n:    2,
			want: 2,
		},
		{
			name: "Example 2",
			n:    3,
			want: 5,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := countTrees(tt.n)
			if got != tt.want {
				t.Errorf("countTrees() = %v, want %v", got, tt.want)
			}
		})
	}
}
