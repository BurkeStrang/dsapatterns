using System.Text;

namespace DsaPatterns.TopologicalSort;

// There is a dictionary containing words from an alien language
// for which we don't know the ordering of the letters.
// Given a list of strings words from the alien language's dictionary.
// All strings in words are sorted lexicographically by the rules of this new language.
// Return a string of the unique letters in the new alien language
// sorted in lexicographically increasing order by the new language's rules.
// It is given that the input is a valid dictionary and there exists an ordering among its letters.
//
// Example 1:
// Input: Words: ["ba", "bc", "ac", "cab"]
// Output: bac
// Explanation: Given that the words are sorted lexicographically by the rules of the alien language, so
// from the given words we can conclude the following ordering among its characters:
// 1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
// 2. From "bc" and "ac", we can conclude that 'b' comes before 'a'
// From the above two points, we can conclude that the correct character order is: "bac"
//
// Example 2:
// Input: Words: ["cab", "aaa", "aab"]
// Output: cab
// Explanation: From the given words we can conclude the following ordering among its characters:
// 1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
// 2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
// From the above two points, we can conclude that the correct character order is: "cab"
//
// Example 3:
// Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
// Output: ywxz
// Explanation: From the given words we can conclude the following ordering among its characters:
// 1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
// 2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
// 3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
// 4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
// 5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'
//
// From the above five points, we can conclude that the correct character order is: "ywxz"
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.


internal static class AlienDiction
{
    public static string FindOrder(string[] words)
    {
        if (words == null || words.Length == 0)
            return "";

        // a. Initialize the graph
        Dictionary<char, int> inDegree = [];
        Dictionary<char, List<char>> graph = [];
        foreach (string word in words)
        {
            foreach (char character in word)
            {
                if (!inDegree.ContainsKey(character))
                {
                    inDegree[character] = 0;
                }

                if (!graph.ContainsKey(character))
                {
                    graph[character] = [];
                }
            }
        }

        // b. Build the graph
        for (int i = 0; i < words.Length - 1; i++)
        {
            // find ordering of characters from adjacent words
            string w1 = words[i], w2 = words[i + 1];
            bool foundDifference = false;
            for (int j = 0; j < Math.Min(w1.Length, w2.Length); j++)
            {
                char parent = w1[j], child = w2[j];
                if (parent != child)
                {
                    graph[parent].Add(child);
                    inDegree[child] += 1;
                    foundDifference = true;
                    break;
                }
            }
            // a word cannot come before one of its own prefixes: "abc" before "ab"
            // is not a valid dictionary, so no letter ordering can explain it
            if (!foundDifference && w1.Length > w2.Length) return "";
        }

        // c. Find all sources i.e., all vertices with 0 in-degrees
        Queue<char> sources = new();
        foreach (KeyValuePair<char, int> entry in inDegree)
        {
            if (entry.Value == 0)
                sources.Enqueue(entry.Key);
        }

        // d. For each source, add it to the sortedOrder and subtract one from all of its
        // children's in-degrees if a child's in-degree becomes zero, add it to sources queue
        StringBuilder sortedOrder = new();
        while (sources.Count > 0)
        {
            char vertex = sources.Dequeue();
            sortedOrder.Append(vertex);
            List<char> children = graph[vertex];
            foreach (char child in children)
            {
                inDegree[child] -= 1;
                if (inDegree[child] == 0)
                    sources.Enqueue(child);
            }
        }

        // if sortedOrder doesn't contain all characters, there is a cyclic dependency
        // between characters, therefore, we will not be able to find the correct ordering
        // of the characters
        if (sortedOrder.Length != inDegree.Count)
            return "";

        return sortedOrder.ToString();
    }
}
