#include <algorithm>
#include <string>
#include <unordered_map>

// Given a string, determine the maximum number of times the word "balloon" can
// be formed using the characters from the string.
// Each character in the string can be used only once.
//
// Example 1:
// Input: "balloonballoon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice from the given string.
//
// Example 2:
// Input: "bbaall"
// Expected Output: 0
// Justification: The word "balloon" cannot be formed from the given string as
// we are missing the character 'o' twice.
//
// Example 3:
// Input: "balloonballoooon"
// Expected Output: 2
// Justification: The word "balloon" can be formed twice, even though there are
// extra 'o' characters.
//
// Constraints:
// 1 <= text.length <= 104
// text consists of lower case English letters only.

int max_number_of_balloons(const std::string &text)
{
    std::unordered_map<char, int> freq;
    for (char letter : text)
    {
        freq[letter]++;
    }

    int min_result = std::ssize(text);
    for (char letter : {'b', 'a', 'l', 'o', 'n'})
    {
        int count = freq[letter];
        if (letter == 'l' || letter == 'o')
        {
            min_result = std::min(min_result, count / 2);
        }
        else
        {
            min_result = std::min(min_result, count);
        }
    }
    return min_result;
}
