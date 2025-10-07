package fastandslowpointers

import "testing"


func Test_findMiddle(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		head *ListNode
		want *ListNode
	}{
		{
			name: "odd length list",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}}},
			want: &ListNode{Val: 3},
		},
		{
			name: "even length list",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4}}}},
			want: &ListNode{Val: 3},
		},
		{
			name: "single node",
			head: &ListNode{Val: 1},
			want: &ListNode{Val: 1},
		},
		{
			name: "two nodes",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
			want: &ListNode{Val: 2},
		},
		{
			name: "nil list",
			head: nil,
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findMiddle(tt.head)
			if !equalListNode(got, tt.want) {
				t.Errorf("findMiddle() = %v, want %v", got, tt.want)
			}
		})
	}
}

