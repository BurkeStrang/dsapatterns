package fastandslowpointers

import (
	"testing"
)

func buildList(vals []int) *ListNode {
	if len(vals) == 0 {
		return nil
	}
	head := &ListNode{Value: vals[0]}
	curr := head
	for _, v := range vals[1:] {
		curr.Next = &ListNode{Value: v}
		curr = curr.Next
	}
	return head
}

func TestIsPalindrome(t *testing.T) {
	tests := []struct {
		input    []int
		expected bool
	}{
		{[]int{2, 4, 6, 4, 2}, true},
		{[]int{2, 4, 6, 4, 2, 2}, false},
		{[]int{}, true},
		{[]int{1}, true},
	}

	for _, tt := range tests {
		head := buildList(tt.input)
		if got := isPalindrome(head); got != tt.expected {
			t.Errorf("isPalindrome(%v) = %v, want %v", tt.input, got, tt.expected)
		}
	}
}
