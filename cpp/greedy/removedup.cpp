#include <string>
#include <unordered_map>
#include <unordered_set>

// Given a string s,
// remove all duplicate letters from the input string while maintaining the
// original order of the letters.
// Additionally,
// the returned string should be the smallest in lexicographical order among all
// possible results.
// A string is in the smallest lexicographical order if it appears first in a
// dictionary.
// For example, "abc" is smaller than "acb" because "abc" comes first
// alphabetically.
//
// Example 1
// Input: "babac"
// Expected Output: "abc"
// Justification:
// After removing 1 b and 1 a from the input string, we can get bac, and abc
// strings.
// The final answer is 'abc', which is the smallest lexicographical string
// without duplicate letters.
//
// Example 2
// Input: "zabccde"
// Expected Output: "zabcde"
// Justification: Removing one of the 'c's forms 'zabcde', the smallest string
// in lexicographical order without duplicates.
//
// Example 3
// Input: "mnopmn"
// Expected Output: "mnop"
// Justification: Removing the second 'm' and 'n' gives 'mnop', which is the
// smallest possible string without duplicate characters.

std::string remove_duplicate_letters(const std::string &s)
{
    std::unordered_map<char, int> count;
    std::unordered_set<char> present;
    // a string works as a stack of characters: push and pop work on its end
    std::string result;

    // Count the frequency of each character
    for (char c : s)
    {
        count[c]++;
    }

    for (char c : s)
    {
        if (!present.contains(c))
        {
            // Ensure smallest lexicographical order based off conditions of:
            // Has Result
            // Is Smaller
            // Can Remove Last
            while (!result.empty() && c < result.back() &&
                   count[result.back()] > 0)
            {
                present.erase(result.back());
                result.pop_back();
            }

            result += c;
            present.insert(c);
        }
        count[c]--; // Decrease the frequency
    }

    return result;
}
