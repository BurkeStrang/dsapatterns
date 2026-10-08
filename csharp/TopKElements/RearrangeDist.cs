using System.Text;

namespace DsaPatterns.TopKElements;

// Given a string and a number ‘K’,
// find if the string can be rearranged such that the same characters are at
// least ‘K’ distance apart from each other.
//
// Example 1:
// Input: "mmpp", K=2
// Output: "mpmp" or "pmpm"
// Explanation: All same characters are 2 distance apart.
//
// Example 2:
// Input: "Programming", K=3
// Output: "rgmPrgmiano" or "gmringmrPoa" or "gmrPagimnor" and a few more
// Explanation: All same characters are 3 distance apart.
//
// Example 3:
// Input: "aab", K=2
// Output: "aba"
// Explanation: All same characters are 2 distance apart.
//
// Example 4:
// Input: "aappa", K=3
// Output: ""
// Explanation: We cannot find an arrangement of the string where any two 'a'
// are 3 distance apart.

internal record struct CharFreq(char Letter, int Frequency);

internal static class RearrangeDist
{
    internal static string ReorganizeString(string str, int k)
    {
        if (k <= 1)
        {
            return str;
        }

        Dictionary<char, int> charFrequencyMap = [];
        foreach (char chr in str)
        {
            charFrequencyMap[chr] = charFrequencyMap.GetValueOrDefault(chr) + 1;
        }

        // max heap of letters, ordered by frequency
        PriorityQueue<CharFreq, int> maxHeap = Shared.NewMaxHeap<CharFreq>();
        foreach ((char letter, int count) in charFrequencyMap)
        {
            maxHeap.Enqueue(new CharFreq(letter, count), count);
        }

        StringBuilder resultBuilder = new();
        Queue<CharFreq> queue = new();

        while (maxHeap.Count > 0)
        {
            CharFreq currentEntry = maxHeap.Dequeue();
            resultBuilder.Append(currentEntry.Letter);
            currentEntry.Frequency--;
            queue.Enqueue(currentEntry);

            if (queue.Count == k)
            {
                CharFreq entry = queue.Dequeue();
                if (entry.Frequency > 0)
                {
                    maxHeap.Enqueue(entry, entry.Frequency);
                }
            }
        }

        string resultString = resultBuilder.ToString();
        if (resultString.Length == str.Length)
        {
            return resultString;
        }

        return "";
    }
}
