#include <string.h>

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

int max_number_of_balloons
(
    const char *text
)
{
    int freq[256] = {0};
    for (const char *c = text; *c != '\0'; c++)
    {
        freq[(unsigned char)*c]++;
    }

    int min_result = (int)strlen(text);
    const char *list = "balon";

    for (const char *letter = list; *letter != '\0'; letter++)
    {
        int count = freq[(unsigned char)*letter];
        if (*letter == 'l' || *letter == 'o')
        {
            count /= 2;
        }
        if (count < min_result)
        {
            min_result = count;
        }
    }

    return min_result;
}
