package topkelements

import "testing"

func Test_findSumOfElements(t *testing.T) {
	tests := []struct {
		name string
		nums []int
		k1   int
		k2   int
		want int
	}{
		{
			name: "basic test",
			nums: []int{1, 3, 12, 5, 15, 11},
			k1:   3,
			k2:   6,
			want: 23,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSumOfElements(tt.nums, tt.k1, tt.k2)
			if got != tt.want {
				t.Errorf("findSumOfElements() = %v, want %v", got, tt.want)
			}
		})
	}
}
