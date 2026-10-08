package monotonicstack

import "testing"

func Test_removeNodes(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		head *ListNode
		want *ListNode
	}{
		{
			name: "Example 1",
			head: buildList([]int{5, 3, 7, 4, 2, 1}),
			want: buildList([]int{7, 4, 2, 1}),
		},
		{
			name: "Example 2",
			head: buildList([]int{1, 2, 3, 4, 5}),
			want: buildList([]int{5}),
		},
		{
			name: "Example 3",
			head: buildList([]int{5, 4, 3, 2, 1}),
			want: buildList([]int{5, 4, 3, 2, 1}),
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := removeNodes(tt.head)
			if !equalList(got, tt.want) {
				t.Errorf("removeNodes() = %v, want %v", listToSlice(got), listToSlice(tt.want))
			}
		})
	}
}
