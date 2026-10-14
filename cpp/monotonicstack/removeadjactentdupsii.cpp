#include <string>
#include <vector>

// You are given a string s and an integer k. Your task is to remove groups of
// identical,
// consecutive characters from the string such that each group has exactly k
// characters.
// The removal of groups should continue until it's no longer possible to make
// any more removals.
// The result should be the final version of the string after all possible
// removals have been made.
//
// Examples
//
// Input: s = "abbbaaca", k = 3
// Output: "ca"
// Explanation: First, we remove "bbb" to get "aaaca". Then, we remove "aaa" to
// get "ca".
//
// Input: s = "abbaccaa", k = 3
// Output: "abbaccaa"
// Explanation: There are no instances of 3 adjacent characters being the same.
//
// Input: s = "abbacccaa", k = 3
// Output: "abb"
// Explanation: First, we remove "ccc" to get "abbaaa". Then, we remove "aaa" to
// get "abb".
//
// Constraints:
// 1 <= s.length <= 105
// 2 <= k <= 104
// s only contains lowercase English letters.

struct StackElement
{
    char c;
    int count;
};

std::string remove_duplicates_ii(const std::string &s, int k)
{
    // An empty stack to track characters and their counts.
    std::vector<StackElement> stack;

    // Iterate through each character in the input string 's'.
    for (char c : s)
    {
        if (!stack.empty() && stack.back().c == c)
        {
            // If the stack is not empty and the current character is the same
            // as the top of the stack, increment the count of the top
            // character in the stack.
            stack.back().count++;
        }
        else
        {
            // Otherwise, push a new character-count pair onto the stack.
            stack.push_back({c, 1});
        }

        // If the count of the top character in the stack reaches 'k'.
        if (stack.back().count == k)
        {
            stack.pop_back(); // Remove it from the stack.
        }
    }

    // Rebuild the string from the characters remaining in the stack.
    std::string result;
    for (const StackElement &element : stack)
    {
        result.append(element.count, element.c);
    }

    return result;
}
