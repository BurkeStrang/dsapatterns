package treedfs

import "testing"

func Test_findSumOfPathNumbers(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		want int
	}{
		{
			name: "Example 1",
			root: makeTree([]*int{intPtr(1), intPtr(2), intPtr(3)}),
			want: 25, // Paths: 12, 13 => 12+13=25
		},
		{
			name: "Example 2",
			root: makeTree([]*int{intPtr(1), intPtr(0), intPtr(1), intPtr(1), intPtr(6), nil, intPtr(5)}),
			want: 322, // Paths: 101, 106, 115 => 101+106+115=332
			//                       1
			//                     /   \
			//                    0     1
			//                   / \     \
			//                  1   6     5
		},
		{
			name: "Single node",
			root: makeTree([]*int{intPtr(5)}),
			want: 5,
		},
		{
			name: "Empty tree",
			root: nil,
			want: 0,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findSumOfPathNumbers(tt.root)
			if got != tt.want {
				t.Errorf("findSumOfPathNumbers() = %v, want %v", got, tt.want)
			}
		})
	}
}

