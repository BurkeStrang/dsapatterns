namespace DsaPatterns.SlidingWindow;

// Given a string and a pattern, find the smallest substring in the given
// string which has all the character occurrences of the given pattern.
//
// Example 1:
// Input: String="aabdec", Pattern="abc"
// Output: "abdec"
// Explanation: The smallest substring having all characters of the pattern is
// "abdec"
//
// Example 2:
// Input: String="aabdec", Pattern="abac"
// Output: "aabdec"
// Explanation: The smallest substring having all characters occurrences of the
// pattern is "aabdec"
//
// Example 3:
// Input: String="abdbca", Pattern="abc"
// Output: "bca"
// Explanation: The smallest substring having all characters of the pattern is
// "bca".
//
// Example 4:
// Input: String="adcad", Pattern="abc"
// Output: ""
// Explanation: No substring in the given string has all characters of the
// pattern
// Constraints:
//
// m == String.length
// n == Pattern.length
// 1 <= m, n <= 105
// String and Pattern consist of uppercase and lowercase English letters.

internal static class SmallestWindowSubstring
{
    internal static string FindSubstring(string str, string pattern)
    {
        int windowStart = 0;
        int matched = 0;
        int minLength = str.Length + 1;
        int subStrStart = 0;
        Dictionary<char, int> charFrequencyMap = [];

        foreach (char chr in pattern)
        {
            charFrequencyMap[chr] = charFrequencyMap.GetValueOrDefault(chr) + 1;
        }

        // try to extend the range [windowStart, windowEnd]
        for (int windowEnd = 0; windowEnd < str.Length; windowEnd++)
        {
            char rightChar = str[windowEnd];
            if (charFrequencyMap.TryGetValue(rightChar, out int rightCount))
            {
                charFrequencyMap[rightChar] = rightCount - 1;
                if (charFrequencyMap[rightChar] >= 0)
                {
                    matched++;
                }
            }

            // shrink the window if we can, finish as soon as we remove a
            // matched character
            while (matched == pattern.Length)
            {
                if (minLength > windowEnd - windowStart + 1)
                {
                    minLength = windowEnd - windowStart + 1;
                    subStrStart = windowStart;
                }

                char leftChar = str[windowStart];
                windowStart++;
                if (charFrequencyMap.TryGetValue(leftChar, out int leftCount))
                {
                    // note that we could have redundant matching characters,
                    // therefore we'll decrement the matched count only when a
                    // useful occurrence of a matched character is going out of
                    // the window
                    if (leftCount == 0)
                    {
                        matched--;
                    }

                    charFrequencyMap[leftChar] = leftCount + 1;
                }
            }
        }

        if (minLength > str.Length)
        {
            return "";
        }

        return str.Substring(subStrStart, minLength);
    }
}
