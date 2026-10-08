#include <stdbool.h>
#include <string.h>

// Given string s,
// determine whether it's possible to make a given string palindrome by removing
// at most one character.
// A palindrome is a word or phrase that reads the same backward as forward.
//
// Example 1:
// Input: "racecar"
// Expected Output: true
// Justification: The string is already a palindrome, so no removals are needed.
//
// Example 2:
// Input: "abeccdeba"
// Expected Output: true
// Justification: Removing the character 'd' forms the palindrome "abccba".
//
// Example 3:
// Input: "abcdef"
// Expected Output: false
// Justification: No single character removal will make this string a
// palindrome.

// is_palindrome checks if a substring is a palindrome
bool is_palindrome
(
    const char *input,
    int left,
    int right
)
{
    while (left < right)
    {
        if (input[left] != input[right])
        {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool is_palindrome_possible
(
    const char *input
)
{
    int left = 0;
    int right = (int)strlen(input) - 1;

    while (left < right)
    {
        if (input[left] != input[right])
        {
            // Check if either substring is a palindrome
            return is_palindrome(input, left + 1, right) ||
                   is_palindrome(input, left, right - 1);
        }
        left++;
        right--;
    }
    return true; // String is already a palindrome
}
