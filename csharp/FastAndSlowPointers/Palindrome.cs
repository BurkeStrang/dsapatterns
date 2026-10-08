namespace DsaPatterns.FastAndSlowPointers;

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

internal static class Palindrome
{
    internal static bool IsPalindrome(ListNode? head)
    {
        if (head == null || head.Next == null)
        {
            return true;
        }

        // find middle of the LinkedList
        ListNode? slow = head;
        ListNode? fast = head;
        while (fast != null && fast.Next != null)
        {
            slow = slow!.Next;
            fast = fast.Next.Next;
        }

        ListNode? headSecondHalf = Reverse(slow); // reverse the second half
        // store the head of reversed part to revert back later
        ListNode? copyHeadSecondHalf = headSecondHalf;

        // compare the first and the second half
        while (head != null && headSecondHalf != null)
        {
            if (head.Val != headSecondHalf.Val)
            {
                break; // not a palindrome
            }

            head = head.Next;
            headSecondHalf = headSecondHalf.Next;
        }

        Reverse(copyHeadSecondHalf); // revert the reverse of the second half
        if (head == null || headSecondHalf == null) // if both halves match
        {
            return true;
        }

        return false;
    }

    private static ListNode? Reverse(ListNode? head)
    {
        ListNode? prev = null;
        while (head != null)
        {
            ListNode? next = head.Next;
            head.Next = prev;
            prev = head;
            head = next;
        }

        return prev;
    }
}
