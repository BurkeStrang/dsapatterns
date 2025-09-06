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
			head: &ListNode{Value: 1, Next: &ListNode{Value: 2, Next: &ListNode{Value: 3, Next: &ListNode{Value: 4, Next: &ListNode{Value: 5}}}}},
			want: &ListNode{Value: 3},
		},
		{
			name: "even length list",
			head: &ListNode{Value: 1, Next: &ListNode{Value: 2, Next: &ListNode{Value: 3, Next: &ListNode{Value: 4}}}},
			want: &ListNode{Value: 3},
		},
		{
			name: "single node",
			head: &ListNode{Value: 1},
			want: &ListNode{Value: 1},
		},
		{
			name: "two nodes",
			head: &ListNode{Value: 1, Next: &ListNode{Value: 2}},
			want: &ListNode{Value: 2},
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

