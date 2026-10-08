package reverselinkedlist

type ListNode struct {
	Val  int
	Next *ListNode
}

// Helper function to compare full list
func equalList(a, b *ListNode) bool {
	for a != nil && b != nil {
		if a.Val != b.Val {
			return false
		}
		a = a.Next
		b = b.Next
	}
	return a == nil && b == nil
}
