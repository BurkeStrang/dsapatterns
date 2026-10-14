#include <string>
#include <unordered_map>
#include <vector>

// Given a string and a pattern, find all anagrams of the pattern in the given
// string.
// Every anagram is a permutation of a string.
// As we know, when we are not allowed to repeat characters while finding
// permutations of a string,
// we get  permutations (or anagrams) of a string having  characters. For
// example, here are the six anagrams of the string abc:
//
// abc
// acb
// bac
// bca
// cab
// cba
//
// Write a function to return a list of starting indices of the anagrams of the
// pattern in the given string.
//
// Example 1:
// Input: str="ppqp", pattern="pq"
// Output: [1, 2]
// Explanation: The two anagrams of the pattern in the given string are "pq" and
// "qp".
//
// Example 2:
// Input: str="abbcabc", pattern="abc"
// Output: [2, 3, 4]
// Explanation: The three anagrams of the pattern in the given string are "bca",
// "cab", and "abc".
//
// Constraints:
// 1 <= s.length, p.length <= 3 * 104
// str and pattern consist of lowercase English letters.

std::vector<int> find_string_anagrams(const std::string &s,
                                      const std::string &pattern)
{
    int window_start = 0;
    int matched = 0;
    std::unordered_map<char, int> char_frequency_map;
    for (char chr : pattern)
    {
        char_frequency_map[chr]++;
    }

    std::vector<int> result_indices;
    // our goal is to match all the characters from the map with the current
    // window
    for (int window_end = 0; window_end < std::ssize(s); window_end++)
    {
        // decrement the frequency of the matched character
        auto right = char_frequency_map.find(s[window_end]);
        if (right != char_frequency_map.end())
        {
            right->second--;
            if (right->second == 0)
            {
                matched++;
            }
        }

        if (matched == std::ssize(char_frequency_map))
        {
            // have we found an anagram?
            result_indices.push_back(window_start);
        }

        if (window_end >= std::ssize(pattern) - 1)
        {
            // shrink the window
            char left_char = s[window_start];
            window_start++;
            auto left = char_frequency_map.find(left_char);
            if (left != char_frequency_map.end())
            {
                if (left->second == 0)
                {
                    // before putting the character back, decrement the
                    // matched count
                    matched--;
                }
                // put the character back
                left->second++;
            }
        }
    }
    return result_indices;
}
