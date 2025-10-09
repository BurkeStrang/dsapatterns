package monotonicstack

import "testing"

func Test_nextGreaterElement(t *testing.T) {
	tests := []struct {
		name string
		nums1 []int
		nums2 []int
		want  []int
	}{
		{
			name:  "Example 1",
			nums1: []int{4, 2, 6},
			nums2: []int{6, 2, 4, 5, 3, 7},
			want:  []int{5, 4, 7},
		},
		{
			name:  "Example 2",
			nums1: []int{9, 7, 1},
			nums2: []int{1, 7, 9, 5, 4, 3},
			want:  []int{-1, 9, 7},
		},
		{
			name:  "Example 3",
			nums1: []int{5, 12, 3},
			nums2: []int{12, 3, 5, 4, 10, 15},
			want:  []int{10, 15, 5},
		},
		{
			name:  "No greater element",
			nums1: []int{8},
			nums2: []int{8, 7, 6},
			want:  []int{-1},
		},
		{
			name:  "All increasing",
			nums1: []int{1, 2, 3},
			nums2: []int{1, 2, 3, 4},
			want:  []int{2, 3, 4},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := nextGreaterElement(tt.nums1, tt.nums2)
			if !equal(got, tt.want) {
				t.Errorf("nextGreaterElement() = %v, want %v", got, tt.want)
			}
		})
	}
}

