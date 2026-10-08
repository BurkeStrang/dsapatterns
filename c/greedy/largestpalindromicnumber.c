#include "common/strbuf.h"

// Given a string s containing 0 to 9 digits, create the largest possible
// palindromic number using the string characters.
// It should not contain leading zeroes.
// A palindromic number reads the same backward as forward.
// If it's not possible to form such a number using all digits of the given
// string, you can skip some of them.
//
// Example 1
// Input: s = "323211444"
// Expected Output: "432141234"
// Justification: This is the largest palindromic number that can be formed from
// the given digits.
//
// Example 2
// Input: s = "998877"
// Expected Output: "987789"
// Justification: "987789" is the largest palindrome that can be formed.
//
// Example 3
// Input: s = "54321"
// Expected Output: "5"
// Justification: Only "5" can form a valid palindromic number as other digits
// cannot be paired.

// The result is a new string that the caller must free.
char *largest_palindromic
(
    const char *s
)
{
    StrBuf first_half = {0}; // stores the first half of the palindrome
    int frequency[10] = {0}; // Frequency array for digits 0-9

    // Count the frequency of each digit in the input number
    for (const char *c = s; *c != '\0'; c++)
    {
        int val = *c - '0';
        frequency[val]++;
    }

    int middle = -1; // Variable to store the middle digit if needed

    // Iterate from the highest digit (9) to the lowest (0)
    for (int i = 9; i >= 0; i--)
    {
        if (frequency[i] != 0 && (i != 0 || first_half.len > 0))
        {
            int count = frequency[i];
            while (count > 1)
            {
                // Append the digit to first_half
                strbuf_push(&first_half, (char)(i + '0'));
                count -= 2; // Use two of the digit for the first half
            }
            if (count == 1 && middle == -1)
            {
                // Assign the middle digit if it's the largest odd-count digit
                middle = i;
            }
        }
    }

    // Append the middle digit if it exists, then the first half reversed
    int half_len = first_half.len;
    if (middle != -1)
    {
        strbuf_push(&first_half, (char)(middle + '0'));
    }
    for (int i = half_len - 1; i >= 0; i--)
    {
        strbuf_push(&first_half, first_half.data[i]);
    }

    if (first_half.len == 0)
    {
        strbuf_push(&first_half, '0');
    }
    return strbuf_take(&first_half); // Return the final palindrome or "0"
}
