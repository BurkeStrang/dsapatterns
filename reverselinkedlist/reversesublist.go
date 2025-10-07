package reverselinkedlist

// Given the head of a LinkedList and two positions ‘p’ and ‘q’,
// reverse the LinkedList from position ‘p’ to ‘q’.

func reversesub(head *ListNode, p int, q int) *ListNode {
	if p == q {
		return head
	}

	// after skipping 'p-1' nodes, current will point to 'p'th node
	var current, previous *ListNode = head, nil
	for i := 0; current != nil && i < p-1; i++ {
		previous = current
		current = current.Next
	}

	// we are interested in three parts of the LinkedList, part before index 'p', part
	// between 'p' and 'q', and the part after index 'q'
	lastNodeOfFirstPart := previous // points to the node at index 'p-1'
	// after reversing the LinkedList 'current' will become the last node of the sub-list
	lastNodeOfSubList := current
	var next *ListNode // will be used to temporarily store the next node
	// reverse nodes between 'p' and 'q'
	for i := 0; current != nil && i < q-p+1; i++ {
		next = current.Next
		current.Next = previous
		previous = current
		current = next
	}

	// connect with the first part
	if lastNodeOfFirstPart != nil {
		// 'previous' is now the first node of the sub-list
		lastNodeOfFirstPart.Next = previous
	} else {
		// this means p == 1 i.e., we are changing the first node (head) of the LinkedList
		head = previous
	}

	// connect with the last part
	lastNodeOfSubList.Next = current

	return head
}
