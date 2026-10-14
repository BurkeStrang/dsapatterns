#include <string>
#include <unordered_map>

// Given a string and a pattern, find the smallest substring in the given string
// which has all the character occurrences of the given pattern.
//
// Example 1:
// Input: String="aabdec", Pattern="abc"
// Output: "abdec"
// Explanation: The smallest substring having all characters of the pattern is
// "abdec"
//
// Example 2:
// Input: String="aabdec", Pattern="abac"
// Output: "aabdec"
// Explanation: The smallest substring having all characters occurrences of the
// pattern is "aabdec"
//
// Example 3:
// Input: String="abdbca", Pattern="abc"
// Output: "bca"
// Explanation: The smallest substring having all characters of the pattern is
// "bca".
//
// Example 4:
// Input: String="adcad", Pattern="abc"
// Output: ""
// Explanation: No substring in the given string has all characters of the
// pattern
// Constraints:
//
// m == String.length
// n == Pattern.length
// 1 <= m, n <= 105
// String and Pattern consist of uppercase and lowercase English letters.

std::string find_substring(const std::string &s, const std::string &pattern)
{
    int window_start = 0;
    int matched = 0;
    int min_length = std::ssize(s) + 1;
    int sub_str_start = 0;
    std::unordered_map<char, int> char_frequency_map;
    for (char chr : pattern)
    {
        char_frequency_map[chr]++;
    }

    // try to extend the range [window_start, window_end]
    for (int window_end = 0; window_end < std::ssize(s); window_end++)
    {
        auto right = char_frequency_map.find(s[window_end]);
        if (right != char_frequency_map.end())
        {
            right->second--;
            if (right->second >= 0)
            {
                matched++;
            }
        }

        // shrink the window if we can, finish as soon as we remove a matched
        // character
        while (matched == std::ssize(pattern))
        {
            if (min_length > window_end - window_start + 1)
            {
                min_length = window_end - window_start + 1;
                sub_str_start = window_start;
            }

            char left_char = s[window_start];
            window_start++;
            auto left = char_frequency_map.find(left_char);
            if (left != char_frequency_map.end())
            {
                // note that we could have redundant matching characters,
                // therefore we'll decrement the matched count only when a
                // useful occurrence of a matched character is going out of the
                // window
                if (left->second == 0)
                {
                    matched--;
                }
                left->second++;
            }
        }
    }

    if (min_length > std::ssize(s))
    {
        return "";
    }
    return s.substr(sub_str_start, min_length);
}
