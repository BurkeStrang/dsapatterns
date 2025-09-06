package fastandslowpointers

type ListNode struct {
	Value int
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
	return a.Value == b.Value
}
