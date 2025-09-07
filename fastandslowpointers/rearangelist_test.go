package fastandslowpointers

import "testing"

func equalList(a, b *ListNode) bool {
	for a != nil && b != nil {
		if a.Value != b.Value {
			return false
		}
		a = a.Next
		b = b.Next
	}
	return a == nil && b == nil
}

func Test_rearangeList(t *testing.T) {
	tests := []struct {
		name string // description of this test case
		// Named input parameters for target function.
		head *ListNode
		want *ListNode
	}{
		{
			name: "even length list",
			head: &ListNode{Value: 1, Next: &ListNode{Value: 2, Next: &ListNode{Value: 3, Next: &ListNode{Value: 4}}}},
			want: &ListNode{Value: 1, Next: &ListNode{Value: 4, Next: &ListNode{Value: 2, Next: &ListNode{Value: 3}}}},
		},
		{
			name: "odd length list",
			head: &ListNode{Value: 1, Next: &ListNode{Value: 2, Next: &ListNode{Value: 3}}},
			want: &ListNode{Value: 1, Next: &ListNode{Value: 3, Next: &ListNode{Value: 2}}},
		},
		{
			name: "single node",
			head: &ListNode{Value: 1},
			want: &ListNode{Value: 1},
		},
		{
			name: "empty list",
			head: nil,
			want: nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := rearangeList(tt.head)
			if !equalList(got, tt.want) {
				t.Errorf("rearangeList() = %v, want %v", got, tt.want)
			}
		})
	}
}
