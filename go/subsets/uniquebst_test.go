package subsets

import (
	"reflect"
	"testing"
)

func Test_findUniqueTrees(t *testing.T) {
	tests := []struct {
		name string
		n    int
		want []*TreeNode
	}{
		{
			name: "Example 1",
			n:    2,
			want: []*TreeNode{
				{Val: 1, Right: &TreeNode{Val: 2}},
				{Val: 2, Left: &TreeNode{Val: 1}},
			},
		},
		{
			name: "Example 2",
			n:    3,
			want: []*TreeNode{
				{Val: 1, Right: &TreeNode{Val: 2, Right: &TreeNode{Val: 3}}},
				{Val: 1, Right: &TreeNode{Val: 3, Left: &TreeNode{Val: 2}}},
				{Val: 2, Left: &TreeNode{Val: 1}, Right: &TreeNode{Val: 3}},
				{Val: 3, Left: &TreeNode{Val: 1, Right: &TreeNode{Val: 2}}},
				{Val: 3, Left: &TreeNode{Val: 2, Left: &TreeNode{Val: 1}}},
			},
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findUniqueTrees(tt.n)

			if len(got) != len(tt.want) {
				t.Fatalf("expected %d trees, got %d", len(tt.want), len(got))
			}

			for i := range got {
				if !reflect.DeepEqual(got[i], tt.want[i]) {
					t.Errorf("tree %d mismatch\n got:  %#v\n want: %#v", i, got[i], tt.want[i])
				}
			}
		})
	}
}
