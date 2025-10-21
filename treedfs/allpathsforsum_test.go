package treedfs

import "testing"

func Test_findPaths(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		sum  int
		want [][]int
	}{
		{
			name: "Example 1",
			root: makeTree([]*int{intPtr(1), intPtr(2), intPtr(3), intPtr(4), intPtr(5), intPtr(6), intPtr(7)}),
			sum:  10,
			want: [][]int{{1, 3, 6}},
		},
		{
			name: "Example 2",
			root: makeTree([]*int{intPtr(12), intPtr(7), intPtr(1), intPtr(9), nil, intPtr(10), intPtr(5)}),
			sum:  23,
			want: [][]int{{12, 1, 10}},
		},
		{
			name: "No path",
			root: makeTree([]*int{intPtr(5), intPtr(4), intPtr(8), intPtr(11), nil, intPtr(13), intPtr(4), intPtr(7), intPtr(2), nil, nil, intPtr(5), intPtr(1)}),
			sum:  100,
			want: [][]int{},
		},
		{
			name: "Empty tree",
			root: nil,
			sum:  0,
			want: [][]int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findPaths(tt.root, tt.sum)
			if !equal(got, tt.want) {
				t.Errorf("findPaths() = %v, want %v", got, tt.want)
			}
		})
	}
}
