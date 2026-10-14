#include <optional>
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Given a string,
// find if its letters can be rearranged in such a way that no two same
// characters come next to each other.
//
// Example 1:
// Input: "aappp"
// Output: "papap"
// Explanation: In "papap", none of the repeating characters come next to each
// other.
//
// Example 2:
// Input: "Programming"
// Output: "rgmrgmPiano" or "gmringmrPoa" or "gmrPagimnor", etc.
// Explanation: None of the repeating characters come next to each other.
//
// Example 3:
// Input: "aapa"
// Output: ""
// Explanation: In all arrangements of "aapa", atleast two 'a' will come
// together e.g., "apaa", "paaa".

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

std::string rearrange_string(const std::string &s)
{
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
    // the character used in the previous step, kept out of the heap for one
    // step so that it can't be picked twice in a row
    std::optional<std::pair<int, char>> previous;

    while (!max_heap.empty())
    {
        auto [count, current_char] = max_heap.top();
        max_heap.pop();
        // the previous character can be added back to the heap now, if there
        // is any of it left
        if (previous && previous->first > 0)
        {
            max_heap.push(*previous);
        }

        // append the current character to the result string and decrement its
        // count
        result += current_char;
        previous = {count - 1, current_char};
    }

    // if we were successful in appending all the characters to the result
    // string, return it
    if (result.size() == s.size())
    {
        return result;
    }
    return "";
}
