using System.Text;

namespace DsaPatterns.TopKElements;

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

internal static class FrequencySort
{
    internal static string SortCharacterByFrequency(string str)
    {
        // Find the frequency of each character
        Dictionary<char, int> characterFrequencyMap = [];
        foreach (char chr in str)
        {
            characterFrequencyMap[chr] =
                characterFrequencyMap.GetValueOrDefault(chr) + 1;
        }

        // Create a list of character-frequency pairs for sorting
        List<(char Character, int Frequency)> characterFrequencyPairs = [];
        foreach ((char chr, int freq) in characterFrequencyMap)
        {
            characterFrequencyPairs.Add((chr, freq));
        }

        // Sort the character-frequency pairs by frequency in descending order
        characterFrequencyPairs.Sort(
            (a, b) => b.Frequency.CompareTo(a.Frequency)
        );

        // Build a string, appending the most occurring characters first
        StringBuilder sortedString = new(str.Length);
        foreach ((char character, int frequency) in characterFrequencyPairs)
        {
            sortedString.Append(character, frequency);
        }

        return sortedString.ToString();
    }
}
