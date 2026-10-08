package slidingwindow

import "testing"

func Test_maxOnesLength(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		k    int
		want int
	}{
		{
			name: "Example 1",
			arr:  []int{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
			k:    2,
			want: 6,
		},
		{
			name: "Example 2",
			arr:  []int{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1},
			k:    3,
			want: 9,
		},
		{
			name: "Example 3",
			arr:  []int{1, 0, 0, 1, 1, 0, 1, 1},
			k:    2,
			want: 6,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := maxOnesLength(tt.arr, tt.k)
			if got != tt.want {
				t.Errorf("maxOnesLength() = %v, want %v", got, tt.want)
			}
		})
	}
}
