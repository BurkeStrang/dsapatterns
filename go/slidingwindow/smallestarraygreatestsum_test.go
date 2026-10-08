package slidingwindow

import "testing"

func Test_findMinSubArray(t *testing.T) {
	tests := []struct {
		name string
		S    int
		arr  []int
		want int
	}{
		{
			name: "Example 1",
			S:    7,
			arr:  []int{2, 1, 5, 2, 3, 2},
			want: 2,
		},
		{
			name: "Example 2",
			S:    7,
			arr:  []int{2, 1, 5, 2, 8},
			want: 1,
		},
		{
			name: "Example 3",
			S:    8,
			arr:  []int{3, 4, 1, 1, 6},
			want: 3,
		},
		{
			name: "No subarray meets S",
			S:    20,
			arr:  []int{1, 2, 3, 4},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMinSubArray(tt.S, tt.arr)
			if got != tt.want {
				t.Errorf("findMinSubArray() = %v, want %v", got, tt.want)
			}
		})
	}
}
