#include "common/list.h"
#include "common/strbuf.h"

// Given a non-negative integer represented as a string num and an integer k,
// delete k digits from num to obtain the smallest possible integer.
// Return this minimum possible integer as a string.
//
// Examples
//
// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: The digits removed are 4, 3, and 2 forming the new number 1219
// which is the smallest.
//
// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Removing the leading 1 forms the smallest number 200.
//
// Input: num = "1901042", k = 4
// Output: "2"
// Explanation: Removing 1, 9, 1, and 4 forms the number 2 which is the smallest
// possible.
//
// Constraints:
// 1 <= k <= num.length <= 105
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

// The result is a new string that the caller must free.
char *remove_k_digits
(
    const char *num,
    int k
)
{
    StrBuf stack = {0}; // a string buffer used as a stack of digits

    for (const char *digit = num; *digit != '\0'; digit++)
    {
        while (k > 0 && stack.len > 0 && stack.data[stack.len - 1] > *digit)
        {
            strbuf_pop(&stack);
            k--;
        }
        strbuf_push(&stack, *digit);
    }

    // Truncate the remaining K digits
    for (int i = 0; i < k; i++)
    {
        strbuf_pop(&stack);
    }

    // Convert Stack to String
    char *digits = strbuf_take(&stack);

    // Remove any leading zeros
    const char *result = digits;
    while (strlen(result) > 1 && result[0] == '0')
    {
        result++;
    }

    // If the String is empty return "0"
    char *answer = str_copy(strlen(result) == 0 ? "0" : result);
    free(digits);
    return answer;
}
