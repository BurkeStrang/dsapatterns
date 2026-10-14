#include <algorithm>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

// Given a string s and an array of words words.
// Break string s into multiple non-overlapping substrings such that each
// substring should be part of the words.
// There are some characters left which are not part of any substring.
// Return the minimum number of remaining characters in s,
// which are not part of any substring after string break-up.
//
// Example 1:
// Input: s = "amazingracecar", dictionary = ["race", "car"]
// Expected Output: 7
// Justification: The string s can be rearranged to form "racecar", leaving 'a',
// 'm', 'a', 'z', 'i', 'n', 'g' as extra.
//
// Example 2:
// Input: s = "bookkeeperreading", dictionary = ["keep", "read"]
// Expected Output: 9
// Justification: The words "keep" and "read" can be formed from s, but 'b',
// 'o', 'o', 'k', 'e', 'r', 'i', 'n', 'g' are extra.
//
// Example 3:
// Input: s = "thedogbarksatnight", dictionary = ["dog", "bark", "night"]
// Expected Output: 6
// Justification: The words "dog", "bark", and "night" can be formed, leaving
// 't', 'h', 'e', 's', 'a', 't' as extra characters.
//
// Constraints:
// 1 <= str.length <= 50
// 1 <= dictionary.length <= 50
// 1 <= dictionary[i].length <= 50
// dictionary[i] and s consists of only lowercase English letters
// dictionary contains distinct words

int solve(int index, std::string_view s,
          const std::unordered_set<std::string_view> &word_set,
          std::vector<std::optional<int>> &memo)
{
    // Base case: when we reach the end of the string
    if (index == std::ssize(s))
    {
        return 0;
    }

    // Return the cached result if already computed
    if (memo[index])
    {
        return *memo[index];
    }

    // Count the current character as an extra character
    int min_extra = solve(index + 1, s, word_set, memo) + 1;

    // Try forming substrings starting from the current index
    for (int end = index; end < std::ssize(s); end++)
    {
        std::string_view substring = s.substr(index, end - index + 1);
        // Check if the substring is in the dictionary
        if (word_set.contains(substring))
        {
            // Update minimum extra characters
            min_extra = std::min(min_extra, solve(end + 1, s, word_set, memo));
        }
    }

    // Store the result in the memo and return
    memo[index] = min_extra;
    return min_extra;
}

int min_extra_char(const std::string &s,
                   const std::vector<std::string> &dictionary)
{
    // No answer has been worked out yet, for any index
    std::vector<std::optional<int>> memo(s.size());
    // Populate a set with the dictionary words
    std::unordered_set<std::string_view> word_set(dictionary.begin(),
                                                  dictionary.end());
    return solve(0, s, word_set, memo);
}
