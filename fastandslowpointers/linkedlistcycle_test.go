package fastandslowpointers

import "testing"

func Test_hasCycle(t *testing.T) {
	tests := []struct {
		name string
		head *ListNode
		want bool
	}{
		{
			name: "no cycle",
			head: &ListNode{Value: 1, Next: &ListNode{Value: 2, Next: &ListNode{Value: 3}}},
			want: false,
		},
		{
			name: "cycle exists",
			head: func() *ListNode {
				n1 := &ListNode{Value: 1}
				n2 := &ListNode{Value: 2}
				n3 := &ListNode{Value: 3}
				n1.Next = n2
				n2.Next = n3
				n3.Next = n1 // cycle here
				return n1
			}(),
			want: true,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := hasCycle(tt.head)
			if got != tt.want {
				t.Errorf("hasCycle() = %v, want %v", got, tt.want)
			}
		})
	}
}
