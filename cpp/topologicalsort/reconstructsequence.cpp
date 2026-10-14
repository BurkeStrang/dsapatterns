#include <queue>
#include <unordered_map>
#include <vector>

// Given a sequence originalSeq and an array of sequences,
// write a method to find if originalSeq can be uniquely
// reconstructed from the array of sequences.
// Unique reconstruction means that we need to find if
// originalSeq is the only sequence such that all
// sequences in the array are subsequences of it.
//
// Example 1:
// Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [3, 4]]
// Output: true
// Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely
// reconstruct
// [1, 2, 3, 4], in other words, all the given sequences uniquely define the
// order of numbers
// in the 'originalSeq'.
//
// Example 2:
// Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
// Output: false
// Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely
// reconstruct
// [1, 2, 3, 4]. There are two possible sequences we can construct from the
// given sequences:
// 1) [1, 2, 3, 4]
// 2) [1, 2, 4, 3]
//
// Example 3:
// Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
// Output: true
// Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely
// reconstruct
// [3, 1, 4, 2, 5].
//
// Constraints:
// n == originalSeq.length
// 1 <= n <= 104
// originalSeq is a permutation of all the integers in the range [1, n].
// 1 <= seqs.length <= 104
// 1 <= seqs[i].length <= 104
// 1 <= sum(seqs[i].length) <= 105
// 1 <= seqs[i][j] <= n
// All the arrays of sequences are unique.
// seqs[i] is a subsequence of nums.

bool can_construct(const std::vector<int> &original_seq,
                   const std::vector<std::vector<int>> &sequences)
{
    std::vector<int> sorted_order;
    if (original_seq.empty())
    {
        return false;
    }

    // a. Initialize the graph
    // count of incoming edges for every vertex
    std::unordered_map<int, int> in_degree;
    // adjacency list graph
    std::unordered_map<int, std::vector<int>> graph;
    for (const std::vector<int> &seq : sequences)
    {
        for (int num : seq)
        {
            in_degree[num] += 0;
            graph[num];
        }
    }

    // b. Build the graph
    for (const std::vector<int> &seq : sequences)
    {
        for (std::size_t i = 1; i < seq.size(); i++)
        {
            int parent = seq[i - 1];
            int child = seq[i];
            graph[parent].push_back(child);
            in_degree[child]++;
        }
    }

    // if we don't have ordering rules for all the numbers we'll not able to
    // uniquely construct the sequence
    if (in_degree.size() != original_seq.size())
    {
        return false;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    std::queue<int> sources;
    for (auto [key, value] : in_degree)
    {
        if (value == 0)
        {
            sources.push(key);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees if a child's in-degree becomes zero,
    // add it to sources queue
    while (!sources.empty())
    {
        if (sources.size() > 1)
        {
            // more than one sources mean, there is more than one way to
            // reconstruct the sequence
            return false;
        }

        int vertex = sources.front();
        sources.pop();
        if (original_seq[sorted_order.size()] != vertex)
        {
            // the next source (or number) is different from original sequence
            return false;
        }

        sorted_order.push_back(vertex);

        // get the node's children to decrement their in-degrees
        for (int child : graph[vertex])
        {
            if (--in_degree[child] == 0)
            {
                sources.push(child);
            }
        }
    }

    // if sorted_order's size is not equal to original sequence's size, there
    // is no unique way to construct
    return sorted_order.size() == original_seq.size();
}
