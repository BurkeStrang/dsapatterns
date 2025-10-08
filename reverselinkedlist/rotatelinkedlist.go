package reverselinkedlist

// Given the head of a Singly LinkedList and a number ‘k’,
// rotate the LinkedList to the right by ‘k’ nodes.

// Constraints:
//
// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 10^9


func  rotate(head *ListNode, rotations int) *ListNode {
    // base cases
    if head == nil || head.Next == nil || rotations <= 0 {
        return head
    }

    // find the length and the last node of the list
    lastNode := head
    listLength := 1
    for lastNode.Next != nil {
        lastNode = lastNode.Next
        listLength++
    }

    lastNode.Next = head // connect the last node with the head to a circular list
    rotations %= listLength // no need to do rotations more than the length of the list
    skipLength := listLength - rotations
    lastNodeOfRotatedList := head
    for i := 0; i < skipLength-1; i++ {
        lastNodeOfRotatedList = lastNodeOfRotatedList.Next
    }

    // 'lastNodeOfRotatedList.Next' is pointing to the sub-list of 'k' ending nodes
    head = lastNodeOfRotatedList.Next
    lastNodeOfRotatedList.Next = nil
    return head
}
