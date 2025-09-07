package fastandslowpointers

// Given the head of a Singly LinkedList, write a method to check if the LinkedList is a palindrome or not.
//
// Your algorithm should use constant space and the input LinkedList should be in the original form once the algorithm is finished.
// The algorithm should have O(N) time complexity where ‘N’ is the number of nodes in the LinkedList.
//
// Example 1:
//
// Input: 2 -> 4 -> 6 -> 4 -> 2 -> null
// Output: true
// Example 2:
//
// Input: 2 -> 4 -> 6 -> 4 -> 2 -> 2 -> null
// Output: false
// Constraints:
//
// The number of nodes in the list is in the range [].
// 0 <= Node.val <= 9

func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true

	}

	// find middle of the LinkedList
	slow := head
	fast := head
	for fast != nil && fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
	}

	headSecondHalf := reverse(slow) // reverse the second half
	// store the head of reversed part to revert back later
	copyHeadSecondHalf := headSecondHalf

	// compare the first and the second half
	for head != nil && headSecondHalf != nil {
		if head.Value != headSecondHalf.Value {
			break // not a palindrome
		}
		head = head.Next
		headSecondHalf = headSecondHalf.Next
	}

	reverse(copyHeadSecondHalf)               // revert the reverse of the second half
	if head == nil || headSecondHalf == nil { // if both halves match
		return true
	}
	return false
}

func reverse(head *ListNode) *ListNode {
	var prev *ListNode
	for head != nil {
		Next := head.Next
		head.Next = prev
		prev = head
		head = Next
	}
	return prev
}
