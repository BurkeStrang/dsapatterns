namespace DsaPatterns.HashMaps;

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

internal static class MaxNumBalloons
{
    internal static int MaxNumberOfBalloons(string text)
    {
        Dictionary<char, int> freq = [];
        foreach (char letter in text)
        {
            freq[letter] = freq.GetValueOrDefault(letter) + 1;
        }

        int minResult = text.Length;
        char[] list = ['b', 'a', 'l', 'o', 'n'];

        foreach (char letter in list)
        {
            int count = freq.GetValueOrDefault(letter);
            if (letter == 'l' || letter == 'o')
            {
                minResult = Math.Min(minResult, count / 2);
            }
            else
            {
                minResult = Math.Min(minResult, count);
            }
        }

        return minResult;
    }
}
