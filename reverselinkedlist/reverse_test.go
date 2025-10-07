package reverselinkedlist

import "testing"

func Test_reverse(t *testing.T) {
	tests := []struct {
		name string
		head *ListNode
		want *ListNode
	}{
		{
			name: "multiple nodes",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
			want: &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 1}}},
		},
		{
			name: "single node",
			head: &ListNode{Val: 1},
			want: &ListNode{Val: 1},
		},
		{
			name: "empty list",
			head: nil,
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := reverse(tt.head)
			if !equalList(got,tt.want) {
				t.Errorf("reverse() = %v, want %v", got, tt.want)
			}
		})
	}
}

