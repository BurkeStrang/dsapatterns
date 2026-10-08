namespace DsaPatterns.TopKElements;

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

internal static class RearrangeString
{
    internal static string Rearrange(string str)
    {
        Dictionary<char, int> charFrequencyMap = [];
        foreach (char chr in str)
        {
            charFrequencyMap[chr] = charFrequencyMap.GetValueOrDefault(chr) + 1;
        }

        List<(char Char, int Count)> charFrequencies = [];
        foreach ((char chr, int count) in charFrequencyMap)
        {
            charFrequencies.Add((chr, count));
        }

        charFrequencies.Sort((a, b) => b.Count.CompareTo(a.Count));

        char[] resultString = new char[str.Length];
        int index = 0;
        char previousChar = '\0';

        while (charFrequencies.Count > 0)
        {
            (char currentChar, int count) = charFrequencies[0];
            charFrequencies.RemoveAt(0);

            // Check if the previous character can be added back to the list
            if (previousChar != '\0' && charFrequencyMap[previousChar] > 0)
            {
                charFrequencies.Add(
                    (previousChar, charFrequencyMap[previousChar])
                );
            }

            // Append the current character to the result string and decrement
            // its count
            resultString[index] = currentChar;
            index++;
            charFrequencyMap[currentChar]--;
            previousChar = currentChar;

            // Sort the charFrequencies to maintain the heap property
            charFrequencies.Sort((a, b) => b.Count.CompareTo(a.Count));

            // If all characters are used up, break the loop
            if (count == 1 && charFrequencies.Count == 0)
            {
                break;
            }
        }

        // If we were successful in appending all the characters to the result
        // string, return it
        if (index == str.Length)
        {
            return new string(resultString);
        }

        return "";
    }
}
