#include "common/list.hpp"

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

ListNode *reverse(ListNode *head)
{
    ListNode *prev = nullptr;
    while (head != nullptr)
    {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool is_palindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    // find middle of the LinkedList
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *head_second_half = reverse(slow); // reverse the second half
    // store the head of reversed part to revert back later
    ListNode *copy_head_second_half = head_second_half;

    // compare the first and the second half
    while (head != nullptr && head_second_half != nullptr)
    {
        if (head->value != head_second_half->value)
        {
            break; // not a palindrome
        }
        head = head->next;
        head_second_half = head_second_half->next;
    }

    reverse(copy_head_second_half); // revert the reverse of the second half

    // if both halves match, one of them ran out
    return head == nullptr || head_second_half == nullptr;
}
