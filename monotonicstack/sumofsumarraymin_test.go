package monotonicstack

import "testing"

func Test_sumSubarrayMins(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want int
	}{
		{
			name: "Example 1",
			arr:  []int{3, 1, 2, 4, 5},
			want: 30,
		},
		{
			name: "Example 2",
			arr:  []int{2, 6, 5, 4},
			want: 36,
		},
		{
			name: "Example 3",
			arr:  []int{7, 3, 8},
			want: 27,
		},
		{
			name: "Single element",
			arr:  []int{5},
			want: 5,
		},
		{
			name: "All same elements",
			arr:  []int{2, 2, 2},
			want: 12,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := sumSubarrayMins(tt.arr)
			if got != tt.want {
				t.Errorf("sumSubarrayMins() = %v, want %v", got, tt.want)
			}
		})
	}
}

