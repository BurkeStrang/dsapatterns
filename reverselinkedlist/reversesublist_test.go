package reverselinkedlist

import "testing"

func Test_reversesub(t *testing.T) {
	tests := []struct {
		name string
		head *ListNode
		p    int
		q    int
		want *ListNode
	}{
		{
			name: "reverse middle sublist",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}}},
			p:    2,
			q:    4,
			want: &ListNode{Val: 1, Next: &ListNode{Val: 4, Next: &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 5}}}}},
		},
		{
			name: "reverse entire list",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
			p:    1,
			q:    3,
			want: &ListNode{Val: 3, Next: &ListNode{Val: 2, Next: &ListNode{Val: 1}}},
		},
		{
			name: "reverse single node (no change)",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
			p:    2,
			q:    2,
			want: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
		},
		{
			name: "reverse head only",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
			p:    1,
			q:    1,
			want: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
		},
		{
			name: "reverse tail only",
			head: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
			p:    2,
			q:    2,
			want: &ListNode{Val: 1, Next: &ListNode{Val: 2}},
		},
		{
			name: "empty list",
			head: nil,
			p:    1,
			q:    1,
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := reversesub(tt.head, tt.p, tt.q)
			if !equalList(got,tt.want) {
				t.Errorf("reversesub() = %v, want %v", got, tt.want)
			}
		})
	}
}
