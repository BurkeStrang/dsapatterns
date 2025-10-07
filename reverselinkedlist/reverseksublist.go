package reverselinkedlist

// Given the head of a LinkedList and a number ‘k’,
// reverse every ‘k’ sized sub-list starting from the head.
//
// If, in the end, you are left with a sub-list with less than ‘k’ elements,
// reverse it too.

func reverseksub(head *ListNode, k int) *ListNode {
	if k <= 1 || head == nil {
		return head
	}

	var current, previous *ListNode = head, nil
	for {
		lastNodeOfPreviousPart := previous
		// after reversing the LinkedList 'current' will become the last node of the sub-list
		lastNodeOfSubList := current
		var next *ListNode // will be used to temporarily store the next node
		// reverse 'k' nodes
		for i := 0; current != nil && i < k; i++ {
			next = current.Next
			current.Next = previous
			previous = current
			current = next
		}

		// connect with the previous part
		if lastNodeOfPreviousPart != nil {
			// 'previous' is now the first node of the sub-list
			lastNodeOfPreviousPart.Next = previous
		} else { // this means we are changing the first node (head) of the LinkedList
			head = previous
		}

		// connect with the next part
		lastNodeOfSubList.Next = current

		if current == nil { // break, if we've reached the end of the LinkedList
			break
		}
		// prepare for the next sub-list
		previous = lastNodeOfSubList
	}

	return head
}
