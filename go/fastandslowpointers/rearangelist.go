package fastandslowpointers

func rearangeList(head *ListNode) *ListNode {

	if head == nil {
		return nil
	}

	// find middle
	slow := head
	fast := head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}
	// reverse second half
	curr := slow
	var prev *ListNode
	for curr != nil {
		Next := curr.Next
		curr.Next = prev
		prev = curr
		curr = Next
	}
	// set every other one as the reverse second half
	first, second := head, prev
	for second.Next != nil {
		tmp1 := first.Next
		tmp2 := second.Next

		first.Next = second
		second.Next = tmp1

		first = tmp1
		second = tmp2
	}

	return head
}
