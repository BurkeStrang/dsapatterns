package reverselinkedlist

// Given the head of a LinkedList and a number ‘k’,
// reverse every alternating ‘k’ sized sub-list starting from the head.
// If, in the end, you are left with a sub-list with less than ‘k’ elements, reverse it too.
//
// Constraints:
// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000

func reverseAlt(head *ListNode, k int) *ListNode {
	if k <= 1 || head == nil {
		return head
	}

	var Current, Previous *ListNode = head, nil
	for Current != nil { // break if we've reached the end of the list
		LastNodeOfPreviousPart := Previous
		// after reversing the LList 'Current' will become the last node of the sub-list
		LastNodeOfSubList := Current
		var Next *ListNode // will be used to temporarily store the next node
		// reverse 'k' nodes
		for i := 0; Current != nil && i < k; i++ {
			Next = Current.Next
			Current.Next = Previous
			Previous = Current
			Current = Next
		}

		// connect with the previous part
		if LastNodeOfPreviousPart != nil {
			// 'Previous' is now the first node of the sub-list
			LastNodeOfPreviousPart.Next = Previous
		} else { // this means we are changing the first node (head) of the LinkedList
			head = Previous
		}

		// connect with the next part
		LastNodeOfSubList.Next = Current

		// skip 'k' nodes
		for i := 0; Current != nil && i < k; i++ {
			Previous = Current
			Current = Current.Next
		}
	}

	return head
}
