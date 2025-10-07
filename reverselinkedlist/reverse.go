package reverselinkedlist

// Given the head of a Singly LinkedList, reverse the LinkedList.
// Write a function to return the new head of the reversed LinkedList.

func reverse(head *ListNode) *ListNode {
	var Previous *ListNode
	curr := head
	for curr != nil {
		temp := curr.Next
		curr.Next = Previous
		Previous = curr
		curr = temp
	}
	return Previous
}
