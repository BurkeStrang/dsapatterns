package cyclicalsort

import "testing"

func Test_findDups(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		want []int
	}{
		{
			name: "Example 1",
			nums: []int{3, 4, 4, 5, 5},
			want: []int{4, 5},
		},
		{
			name: "Example 2",
			nums: []int{5, 4, 7, 2, 3, 5, 3},
			want: []int{5, 3},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findDups(tt.nums)
			if !equal(got,tt.want) {
				t.Errorf("findDups() = %v, want %v", got, tt.want)
			}
		})
	}
}

