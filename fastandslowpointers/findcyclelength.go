package fastandslowpointers

// Given the head of a LinkedList with a cycle, find the length of the cycle.

func findCycleLength(head *ListNode) int {
	slow := head
	fast := head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			return calcCycleDistance(slow)
		}
	}
	return 0
}

func calcCycleDistance(slow *ListNode) int {
	current := slow.Next
	currentCount := 1
	for current != slow {
		current = current.Next
		currentCount++
	}
	return currentCount
}
