package reverselinkedlist

import "testing"

func Test_rotate(t *testing.T) {
	tests := []struct {
		name      string
		head      *ListNode
		rotations int
		want      *ListNode
	}{
		{
			name:      "rotate by 2",
			head:      &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 4, Next: &ListNode{Val: 5}}}}},
			rotations: 2,
			want:      &ListNode{Val: 4, Next: &ListNode{Val: 5, Next: &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}}}},
		},
		{
			name:      "rotate by 0 (no change)",
			head:      &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
			rotations: 0,
			want:      &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
		},
		{
			name:      "rotate by length (no change)",
			head:      &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
			rotations: 3,
			want:      &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
		},
		{
			name:      "rotate by more than length",
			head:      &ListNode{Val: 1, Next: &ListNode{Val: 2, Next: &ListNode{Val: 3}}},
			rotations: 5,
			want:      &ListNode{Val: 2, Next: &ListNode{Val: 3, Next: &ListNode{Val: 1}}},
		},
		{
			name:      "single node",
			head:      &ListNode{Val: 1},
			rotations: 1,
			want:      &ListNode{Val: 1},
		},
		{
			name:      "empty list",
			head:      nil,
			rotations: 3,
			want:      nil,
		},
	}
	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			got := rotate(tt.head, tt.rotations)
			if !equalList(got, tt.want) {
				t.Errorf("rotate() = %v, want %v", got, tt.want)
			}
		})
	}
}
