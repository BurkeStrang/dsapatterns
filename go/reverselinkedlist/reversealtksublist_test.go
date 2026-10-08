package reverselinkedlist

import "testing"

func Test_reverseAlt(t *testing.T) {
	tests := []struct {
		name string
		head *ListNode
		k    int
		want *ListNode
	}{
		{
			name: "reverse every alternate 2 nodes",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5, Next: &ListNode{Val: 6}}}}}},
			k:    2,
			want: &ListNode{Val: 2, Next: &ListNode{Val: 1, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 6, Next: &ListNode{Val: 5}}}}}},
		},
		{
			name: "reverse every alternate 3 nodes",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5, Next: &ListNode{Val: 6, Next: &ListNode{Val: 7}}}}}}},
			k:    3,
			want: &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 1, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5, Next: &ListNode{Val: 6, Next: &ListNode{Val: 7}}}}}}},
		},
		{
			name: "k greater than length",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
			k:    5,
			want: &ListNode{Val: 2, Next: &ListNode{Val: 1}},
		},
		{
			name: "single node",
			head: &ListNode{Val: 1},
			k:    2,
			want: &ListNode{Val: 1},
		},
		{
			name: "empty list",
			head: nil,
			k:    2,
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := reverseAlt(tt.head, tt.k)
			if !equalList(got, tt.want) {
				t.Errorf("reverseAlt() = %v, want %v", got, tt.want)
			}
		})
	}
}
