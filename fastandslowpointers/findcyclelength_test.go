package fastandslowpointers

import "testing"

func Test_findCycleLength(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		head *ListNode
		want int
	}{
 		{
			name: "cycle of length 3",
			head: func() *ListNode {
				n1 := &ListNode{Val: 1}
				n2 := &ListNode{Val: 2}
				n3 := &ListNode{Val: 3}
				n4 := &ListNode{Val: 4}
				n1.Next = n2
				n2.Next = n3
				n3.Next = n4
				n4.Next = n2 // cycle starts at n2, length 3
				return n1
			}(),
			want: 3,
		},
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
			want: 0,
		},
		{
			name: "cycle of length 1 (self loop)",
			head: func() *ListNode {
				n1 := &ListNode{Val: 1}
				n1.Next = n1
				return n1
			}(),
			want: 1,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := findCycleLength(tt.head)
 			if got != tt.want {
 				t.Errorf("findCycleLength() = %v, want %v", got, tt.want)
 			}
		})
	}
}

