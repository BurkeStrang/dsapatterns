#include <array>
#include <optional>
#include <string>

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

std::string largest_palindromic(const std::string &s)
{
    std::string first_half;          // The first half of the palindrome
    std::array<int, 10> frequency{}; // Frequency array for digits 0-9

    // Count the frequency of each digit in the input number
    for (char digit : s)
    {
        frequency[digit - '0']++;
    }

    std::optional<char> middle; // The middle digit, if one is needed

    // Iterate from the highest digit (9) to the lowest (0)
    for (char digit = '9'; digit >= '0'; digit--)
    {
        int count = frequency[digit - '0'];
        // a number can't start with 0, so skip the zeros until there is
        // something in front of them
        if (count != 0 && (digit != '0' || !first_half.empty()))
        {
            while (count > 1)
            {
                first_half += digit; // Append the digit to first_half
                count -= 2;          // Use two of the digit for the two halves
            }
            if (count == 1 && !middle)
            {
                // The middle digit is the largest digit with an odd count
                middle = digit;
            }
        }
    }

    // Create second_half as a reversed copy of first_half
    std::string second_half(first_half.rbegin(), first_half.rend());

    // Append the middle digit if it exists
    std::string result = first_half;
    if (middle)
    {
        result += *middle;
    }
    result += second_half; // Append the reversed first half

    if (result.empty())
    {
        return "0";
    }
    return result; // Return the final palindrome
}
