package fastandslowpointers

// Given the head of a Singly LinkedList, write a function to determine if the LinkedList has a cycle in it or not.

func hasCycle(head *ListNode) bool {
	slow := head;
	fast := head;
	for fast != nil && fast.Next != nil {
		fast = fast.Next.Next
		slow = slow.Next
		if slow == fast {
			return true
		}
	}
	return false
}
