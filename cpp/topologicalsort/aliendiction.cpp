#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

// There is a dictionary containing words from an alien language
// for which we don't know the ordering of the letters.
// Given a list of strings words from the alien language's dictionary.
// All strings in words are sorted lexicographically by the rules of this new
// language.
// Return a string of the unique letters in the new alien language
// sorted in lexicographically increasing order by the new language's rules.
// It is given that the input is a valid dictionary and there exists an ordering
// among its letters.
//
// Example 1:
// Input: Words: ["ba", "bc", "ac", "cab"]
// Output: bac
// Explanation: Given that the words are sorted lexicographically by the rules
// of the alien language, so
// from the given words we can conclude the following ordering among its
// characters:
// 1. From "ba" and "bc", we can conclude that 'a' comes before 'c'.
// 2. From "bc" and "ac", we can conclude that 'b' comes before 'a'
// From the above two points, we can conclude that the correct character order
// is: "bac"
//
// Example 2:
// Input: Words: ["cab", "aaa", "aab"]
// Output: cab
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "cab" and "aaa", we can conclude that 'c' comes before 'a'.
// 2. From "aaa" and "aab", we can conclude that 'a' comes before 'b'
// From the above two points, we can conclude that the correct character order
// is: "cab"
//
// Example 3:
// Input: Words: ["ywx", "wz", "xww", "xz", "zyy", "zwz"]
// Output: ywxz
// Explanation: From the given words we can conclude the following ordering
// among its characters:
// 1. From "ywx" and "wz", we can conclude that 'y' comes before 'w'.
// 2. From "wz" and "xww", we can conclude that 'w' comes before 'x'.
// 3. From "xww" and "xz", we can conclude that 'w' comes before 'z'
// 4. From "xz" and "zyy", we can conclude that 'x' comes before 'z'
// 5. From "zyy" and "zwz", we can conclude that 'y' comes before 'w'
//
// From the above five points, we can conclude that the correct character order
// is: "ywxz"
// Constraints:
// 1 <= words.length <= 100
// 1 <= words[i].length <= 100
// words[i] consists of only lowercase English letters.

std::string find_alien_order(const std::vector<std::string> &words)
{
    if (words.empty())
    {
        return "";
    }

    // a. Initialize the graph
    std::unordered_map<char, int> in_degree;
    std::unordered_map<char, std::vector<char>> graph;
    // letters in the order they first appear, so the sources are always
    // visited in the same order
    std::vector<char> letters;
    for (const std::string &word : words)
    {
        for (char character : word)
        {
            if (!graph.contains(character))
            {
                letters.push_back(character);
                graph[character] = {};
                in_degree[character] = 0;
            }
        }
    }

    // b. Build the graph
    for (std::size_t i = 0; i + 1 < words.size(); i++)
    {
        // find ordering of characters from adjacent words
        const std::string &w1 = words[i];
        const std::string &w2 = words[i + 1];
        bool found_difference = false;
        for (std::size_t j = 0; j < std::min(w1.size(), w2.size()); j++)
        {
            char parent = w1[j];
            char child = w2[j];
            if (parent != child)
            {
                graph[parent].push_back(child);
                in_degree[child]++;
                found_difference = true;
                break;
            }
        }

        // a word cannot come before one of its own prefixes: "abc" before
        // "ab" is not a valid dictionary, so no letter ordering can explain
        // it
        if (!found_difference && w1.size() > w2.size())
        {
            return "";
        }
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    std::queue<char> sources;
    for (char letter : letters)
    {
        if (in_degree[letter] == 0)
        {
            sources.push(letter);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees if a child's in-degree becomes zero,
    // add it to sources queue
    std::string sorted_order;
    while (!sources.empty())
    {
        char vertex = sources.front();
        sources.pop();
        sorted_order += vertex;
        for (char child : graph[vertex])
        {
            if (--in_degree[child] == 0)
            {
                sources.push(child);
            }
        }
    }

    // if sorted_order doesn't contain all characters, there is a cyclic
    // dependency between characters, therefore, we will not be able to find
    // the correct ordering of the characters
    if (sorted_order.size() != in_degree.size())
    {
        return "";
    }

    return sorted_order;
}
