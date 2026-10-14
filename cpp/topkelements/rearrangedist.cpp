#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Given a string and a number ‘K’,
// find if the string can be rearranged such that the same characters are at
// least ‘K’ distance apart from each other.
//
// Example 1:
// Input: "mmpp", K=2
// Output: "mpmp" or "pmpm"
// Explanation: All same characters are 2 distance apart.
//
// Example 2:
// Input: "Programming", K=3
// Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
// Explanation: All same characters are 3 distance apart.
//
// Example 3:
// Input: "aab", K=2
// Output: "aba"
// Explanation: All same characters are 2 distance apart.
//
// Example 4:
// Input: "aappa", K=3
// Output: ""
// Explanation: We cannot find an arrangement of the string where any two 'a'
// are 3 distance apart.

// MoreFrequentFirst orders (frequency, letter) pairs for a max heap: the most
// frequent letter is on top, and among letters with the same frequency the
// earlier letter comes first, so the result is always the same
struct MoreFrequentFirst
{
    bool operator()(std::pair<int, char> a, std::pair<int, char> b) const
    {
        return a.first < b.first || (a.first == b.first && a.second > b.second);
    }
};

std::string reorganize_string(const std::string &s, int k)
{
    if (k <= 1)
    {
        return s;
    }

    std::unordered_map<char, int> char_frequency_map;
    for (char chr : s)
    {
        char_frequency_map[chr]++;
    }

    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>,
                        MoreFrequentFirst>
        max_heap;
    for (auto [chr, count] : char_frequency_map)
    {
        max_heap.push({count, chr});
    }

    std::string result;
    std::queue<std::pair<int, char>> queue;

    while (!max_heap.empty())
    {
        auto [frequency, letter] = max_heap.top();
        max_heap.pop();
        // append the current character to the result string and decrement its
        // count
        result += letter;
        // the character has to wait for 'k' steps before it can be used again
        queue.push({frequency - 1, letter});

        if (std::ssize(queue) == k)
        {
            std::pair<int, char> entry = queue.front();
            queue.pop();
            if (entry.first > 0)
            {
                max_heap.push(entry);
            }
        }
    }

    // if we were successful in appending all the characters to the result
    // string, return it
    if (result.size() == s.size())
    {
        return result;
    }
    return "";
}
