package misc

import "testing"

func Test_isSubarray(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		sub  []int
		want bool
	}{
		{name: "Example 1", nums: []int{1, 2, 3}, sub: []int{2, 3}, want: true},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := isSubarray(tt.nums, tt.sub)
			if got != tt.want {
				t.Errorf("isSubarray() = %v, want %v", got, tt.want)
			}
		})
	}
}
