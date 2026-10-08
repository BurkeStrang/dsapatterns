package slidingwindow

import "testing"

func Test_findMaxSumSubArray(t *testing.T) {
	tests := []struct {
		name string
		k    int
		arr  []int
		want int
	}{
		{
			name: "basic case",
			k:    3,
			arr:  []int{2, 1, 5, 1, 3, 2},
			want: 9,
		},
		{
			name: "single element window",
			k:    1,
			arr:  []int{4, 2, 7, 1},
			want: 7,
		},
		{
			name: "window equals array length",
			k:    4,
			arr:  []int{1, 2, 3, 4},
			want: 10,
		},
		{
			name: "empty array",
			k:    3,
			arr:  []int{},
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMaxSumSubArray(tt.k, tt.arr)
			if got != tt.want {
				t.Errorf("findMaxSumSubArray() = %v, want %v", got, tt.want)
			}
		})
	}
}
