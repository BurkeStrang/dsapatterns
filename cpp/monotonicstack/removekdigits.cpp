#include <string>

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

std::string remove_kdigits(const std::string &num, int k)
{
    // A string works as a stack of characters: push and pop work on its end
    std::string stack;

    for (char digit : num)
    {
        while (k > 0 && !stack.empty() && stack.back() > digit)
        {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }

    // Truncate the remaining K digits
    for (; k > 0 && !stack.empty(); k--)
    {
        stack.pop_back();
    }

    // Remove any leading zeros
    std::size_t first_non_zero = stack.find_first_not_of('0');

    // If the string is empty return "0"
    if (first_non_zero == std::string::npos)
    {
        return "0";
    }

    return stack.substr(first_non_zero);
}
