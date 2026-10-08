#include "common/list.h"
#include "common/strbuf.h"

// Given a positive integer n, write a function that returns its binary
// equivalent as a string.
// The function should not use any in-built binary conversion function.
//
// Example 1:
// Input: 2
// Output: "10"
// Explanation: The binary equivalent of 2 is 10.
//
// Example 2:
// Input: 7
// Output: "111"
// Explanation: The binary equivalent of 7 is 111.
//
// Example 3:
// Input: 18
// Output: "10010"
// Explanation: The binary equivalent of 18 is 10010.
//
// Constraints:
// 1 <= n <= 10^9

// The result is a new string that the caller must free.
char *decimal_to_binary
(
    int num
)
{
    IntList stack = {0}; // Create an empty stack to store binary digits.
    StrBuf sb = {0};     // Initialize an empty string to build the result.

    // Convert the decimal number to binary using a stack.
    while (num > 0)
    {
        // Push the remainder of num%2 (binary digit) onto the stack.
        intlist_push(&stack, num % 2);
        num /= 2; // Update num by dividing it by 2 (integer division).
    }

    // Pop binary digits from the stack and build the binary string.
    while (stack.len > 0)
    {
        int pop = intlist_pop(&stack); // Pop the top element from the stack.
        // Append the popped binary digit to the result string.
        strbuf_push(&sb, (char)('0' + pop));
    }

    intlist_free(&stack);
    return strbuf_take(&sb); // Return the binary representation as a string.
}
