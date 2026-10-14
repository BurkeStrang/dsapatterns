#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// Given a string, sort it based on the decreasing frequency of its characters.
//
// Example 1:
// Input: "Programming"
// Output: "rrggmmPiano"
// Explanation: 'r', 'g', and 'm' appeared twice, so they need to appear before
// any other character.
//
// Example 2:
// Input: "abcbab"
// Output: "bbbaac"
// Explanation: 'b' appeared three times, 'a' appeared twice, and 'c' appeared
// only once.

std::string sort_character_by_frequency(const std::string &s)
{
    // Find the frequency of each character
    std::unordered_map<char, int> character_frequency_map;
    for (char chr : s)
    {
        character_frequency_map[chr]++;
    }

    // Create a list of character-frequency pairs for sorting
    std::vector<std::pair<char, int>> character_frequency_pairs(
        character_frequency_map.begin(), character_frequency_map.end());

    // Sort the character-frequency pairs by frequency in descending order
    std::ranges::sort(character_frequency_pairs, std::greater<>{},
                      &std::pair<char, int>::second);

    // Build a string, appending the most occurring characters first
    std::string sorted_string;
    for (auto [character, frequency] : character_frequency_pairs)
    {
        sorted_string.append(frequency, character);
    }

    return sorted_string;
}
