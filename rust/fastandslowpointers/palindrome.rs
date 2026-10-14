use super::shared::{Link, next};

// Given the head of a Singly LinkedList, write a method to check if the
// LinkedList is a palindrome or not.
//
// Your algorithm should use constant space and the input LinkedList should be
// in the original form once the algorithm is finished.
// The algorithm should have O(N) time complexity where ‘N’ is the number of
// nodes in the LinkedList.
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

pub fn is_palindrome(head: &Link) -> bool {
    if head.is_none() || next(head).is_none() {
        return true;
    }

    // find middle of the LinkedList
    let mut slow = head.clone();
    let mut fast = head.clone();
    while fast.is_some() && next(&fast).is_some() {
        slow = next(&slow);
        fast = next(&next(&fast));
    }

    let mut head_second_half = reverse(slow); // reverse the second half
    // store the head of reversed part to revert back later
    let copy_head_second_half = head_second_half.clone();

    // compare the first and the second half
    let mut head = head.clone();
    while let (Some(first), Some(second)) = (&head, &head_second_half) {
        if first.borrow().val != second.borrow().val {
            break; // not a palindrome
        }
        let (next_first, next_second) = (next(&head), next(&head_second_half));
        head = next_first;
        head_second_half = next_second;
    }

    reverse(copy_head_second_half); // revert the reverse of the second half

    // if both halves match, one of them ran out
    head.is_none() || head_second_half.is_none()
}

fn reverse(mut head: Link) -> Link {
    let mut prev = None;
    while let Some(node) = head {
        head = node.borrow_mut().next.take();
        node.borrow_mut().next = prev;
        prev = Some(node);
    }
    prev
}
