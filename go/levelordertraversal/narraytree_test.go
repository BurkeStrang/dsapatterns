package levelordertraversal

import "testing"

func Test_levelOrder(t *testing.T) {
	tests := []struct {
		name string
		root *NAryNode
		want [][]int
	}{
		{
			name: "Example 1: [1,null,2,3,4,null,5,6]",
			root: &NAryNode{Val: 1, Children: []*NAryNode{
				{Val: 2, Children: []*NAryNode{
					{Val: 5},
					{Val: 6},
				}},
				{Val: 3},
				{Val: 4},
			}},
			want: [][]int{{1}, {2, 3, 4}, {5, 6}},
		},
		{
			name: "Single node",
			root: &NAryNode{Val: 42},
			want: [][]int{{42}},
		},
		{
			name: "Empty tree",
			root: nil,
			want: [][]int{},
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := levelOrder(tt.root)
			if !equal(got, tt.want) {
				t.Errorf("levelOrder() = %v, want %v", got, tt.want)
			}
		})
	}
}
