package twopointers

import "testing"

func Test_minSort(t *testing.T) {
	tests := []struct {
		name string
		arr  []int
		want int
	}{
		{
			name: "Example 1",
			arr:  []int{1, 2, 5, 3, 7, 10, 9, 12},
			want: 5,
		},
		{
			name: "Example 2",
			arr:  []int{1, 3, 2, 0, -1, 7, 10},
			want: 5,
		},
		{
			name: "Example 3",
			arr:  []int{1, 2, 3},
			want: 0,
		},
		{
			name: "Example 4",
			arr:  []int{3, 2, 1},
			want: 3,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := minSort(tt.arr)
			if got != tt.want {
				t.Errorf("minSort() = %v, want %v", got, tt.want)
			}
		})
	}
}
