package cyclicalsort

import "testing"

func Test_sort(t *testing.T) {
	tests := []struct {
		name string
		Nums []int
		want []int
	}{
		{
			name: "Example 1",
			Nums: []int{3, 1, 5, 4, 2},
			want: []int{1, 2, 3, 4, 5},
		},
		{
			name: "Example 2",
			Nums: []int{2, 6, 4, 3, 1, 5},
			want: []int{1, 2, 3, 4, 5, 6},
		},
		{
			name: "Example 3",
			Nums: []int{1, 5, 6, 4, 3, 2},
			want: []int{1, 2, 3, 4, 5, 6},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := sort(tt.Nums)
			if !equal(got, tt.want) {
				t.Errorf("sort() = %v, want %v", got, tt.want)
			}
		})
	}
}

func equal(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}
	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}
	return true
}
