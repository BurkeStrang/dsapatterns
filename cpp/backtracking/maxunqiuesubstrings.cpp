#include <algorithm>
#include <string>
#include <string_view>
#include <unordered_set>

// Given a string s,
// return the maximum number of unique substrings that the given string can be
// split into.
// You can split string s into any list of non-empty substrings,
// where the concatenation of the substrings forms the original string.
// However, you must split the substrings such that all of them are unique.
// A substring is a contiguous sequence of characters within a string.
//
// Example 1:
// Input: s = "aab"
// Output: 2
// Explanation: Two possible ways to split the given string into maximum unique
// substrings are:
// ['a', 'ab'] & ['aa', 'b'], both have 2 substrings;
// hence the maximum number of unique substrings in
// which the given string can be split is 2.
//
// Example 2:
// Input: s = "abcabc"
// Output: 4
// Explanation: Four possible ways to split into maximum unique substrings are:
// ['a', 'b', 'c', 'abc'] & ['a', 'b', 'cab', 'c'] &  ['a', 'bca', 'b', 'c'] &
// ['abc', 'a', 'b', 'c'],
// all have 4 substrings.
//
// Constraints:
// 1 <= s.length <= 16
// s contains only lower case English letters.

int split_and_count(std::string_view s, int start,
                    std::unordered_set<std::string_view> &set)
{
    if (start == std::ssize(s))
    {
        return std::ssize(set);
    }

    int count = 0;
    for (int i = start + 1; i <= std::ssize(s); i++)
    {
        std::string_view substr = s.substr(start, i - start);
        // insert reports false if the substring was already in the set
        if (set.insert(substr).second)
        {
            count = std::max(count, split_and_count(s, i, set));
            set.erase(substr);
        }
    }

    return count;
}

int max_unique_split(const std::string &s)
{
    std::unordered_set<std::string_view> set;
    return split_and_count(s, 0, set);
}
