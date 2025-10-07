package reverselinkedlist


type ListNode struct {
	Val int
	Next  *ListNode
}

// Helper function to compare two ListNodes by value only (not full list)
func equalListNode(a, b *ListNode) bool {
	if a == nil && b == nil {
		return true
	}
	if a == nil || b == nil {
		return false
	}
	return a.Val == b.Val
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
