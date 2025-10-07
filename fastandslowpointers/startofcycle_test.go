package fastandslowpointers

import "testing"

func Test_findCycleStart(t *testing.T) {
	tests := []struct {
		name string
		head *ListNode
		want *ListNode
	}{
		func() struct {
			name string
			head *ListNode
			want *ListNode
		} {
			n1 := &ListNode{Val: 1}
			n2 := &ListNode{Val: 2}
			n3 := &ListNode{Val: 3}
			n4 := &ListNode{Val: 4}
			n1.Next = n2
			n2.Next = n3
			n3.Next = n4
			n4.Next = n2 // cycle starts at n2
			return struct {
				name string
				head *ListNode
				want *ListNode
			}{
				name: "cycle at node 2",
				head: n1,
				want: n2,
			}
		}(),
		{
			name: "no cycle",
			head: func() *ListNode {
				n1 := &ListNode{Val: 1}
				n2 := &ListNode{Val: 2}
				n3 := &ListNode{Val: 3}
				n1.Next = n2
				n2.Next = n3
				return n1
			}(),
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findCycleStart(tt.head)
			if got != tt.want {
				t.Errorf("findCycleStart() = %v, want %v", got, tt.want)
			}
		})
	}
}
