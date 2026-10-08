package treedfs

import "testing"

func Test_hasPath(t *testing.T) {
	tests := []struct {
		name string
		root *TreeNode
		sum  int
		want bool
	}{
		{
			name: "Example 1",
			root: makeTree([]*int{intPtr(1), intPtr(2), intPtr(3), intPtr(4), intPtr(5), intPtr(6), intPtr(7)}),
			sum:  10,
			want: true,
		},
		{
			name: "Example 2",
			root: makeTree([]*int{intPtr(12), intPtr(7), intPtr(1), intPtr(9), nil, intPtr(10), intPtr(5)}),
			sum:  23,
			want: true,
		},
		{
			name: "Example 3",
			root: makeTree([]*int{intPtr(12), intPtr(7), intPtr(1), intPtr(9), nil, intPtr(10), intPtr(5)}),
			sum:  16,
			want: false,
		},
		{
			name: "Empty tree",
			root: nil,
			sum:  0,
			want: false,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := hasPath(tt.root, tt.sum)
			if got != tt.want {
				t.Errorf("hasPath() = %v, want %v", got, tt.want)
			}
		})
	}
}
