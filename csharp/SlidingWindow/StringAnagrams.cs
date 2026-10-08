namespace DsaPatterns.SlidingWindow;

// Given a string and a pattern, find all anagrams of the pattern in the given
// string.
// Every anagram is a permutation of a string.
// As we know, when we are not allowed to repeat characters while finding
// permutations of a string,
// we get  permutations (or anagrams) of a string having  characters. For
// example, here are the six anagrams of the string abc:
//
// abc
// acb
// bac
// bca
// cab
// cba
//
// Write a function to return a list of starting indices of the anagrams of the
// pattern in the given string.
//
// Example 1:
// Input: str="ppqp", pattern="pq"
// Output: [1, 2]
// Explanation: The two anagrams of the pattern in the given string are "pq"
// and "qp".
//
// Example 2:
// Input: str="abbcabc", pattern="abc"
// Output: [2, 3, 4]
// Explanation: The three anagrams of the pattern in the given string are
// "bca", "cab", and "abc".
//
// Constraints:
// 1 <= s.length, p.length <= 3 * 104
// str and pattern consist of lowercase English letters.

internal static class StringAnagrams
{
    internal static List<int> FindStringAnagrams(string str, string pattern)
    {
        int windowStart = 0;
        int matched = 0;
        Dictionary<char, int> charFrequencyMap = [];
        foreach (char chr in pattern)
        {
            charFrequencyMap[chr] = charFrequencyMap.GetValueOrDefault(chr) + 1;
        }

        List<int> resultIndices = [];
        // our goal is to match all the characters from the map with the
        // current window
        for (int windowEnd = 0; windowEnd < str.Length; windowEnd++)
        {
            char rightChar = str[windowEnd];
            // decrement the frequency of the matched character
            if (charFrequencyMap.TryGetValue(rightChar, out int rightCount))
            {
                charFrequencyMap[rightChar] = rightCount - 1;
                if (charFrequencyMap[rightChar] == 0)
                {
                    matched++;
                }
            }

            if (matched == charFrequencyMap.Count) // have we found an anagram?
            {
                resultIndices.Add(windowStart);
            }

            if (windowEnd >= pattern.Length - 1) // shrink the window
            {
                char leftChar = str[windowStart];
                windowStart++;
                if (charFrequencyMap.TryGetValue(leftChar, out int leftCount))
                {
                    if (leftCount == 0)
                    {
                        // before putting the character back, decrement the
                        // matched count
                        matched--;
                    }

                    // put the character back
                    charFrequencyMap[leftChar] = leftCount + 1;
                }
            }
        }

        return resultIndices;
    }
}
