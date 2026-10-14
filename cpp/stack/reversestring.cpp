#include <string>
#include <vector>

// Given a string, write a function that uses a stack to reverse the string. The
// function should return the reversed string.
//
// Example 1:
// Input: "Hello, World!"
// Output: "!dlroW ,olleH"
//
// Example 2:
// Input: "OpenAI"
// Output: "IAnepO"
//
// Example 3:
// Input: "Stacks are fun!"
// Output: "!nuf era skcatS"
// Constraints:
//
// 1 <= s.length <= 105
// s[i] is a printable ascii character.

std::string reverse_string(const std::string &input)
{
    std::string reverse_list;
    std::vector<char> stack(input.begin(), input.end());

    // pop all letters from stack to reverse_list
    while (!stack.empty())
    {
        reverse_list += stack.back();
        stack.pop_back();
    }

    return reverse_list;
}
