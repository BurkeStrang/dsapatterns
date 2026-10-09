namespace DsaPatterns.TopologicalSort;
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
// Explanation: The sequences [1, 2], [2, 3], and [3, 4] can uniquely reconstruct
// [1, 2, 3, 4], in other words, all the given sequences uniquely define the order of numbers
// in the 'originalSeq'.
//
// Example 2:
// Input: originalSeq: [1, 2, 3, 4], seqs: [[1, 2], [2, 3], [2, 4]]
// Output: false
// Explanation: The sequences [1, 2], [2, 3], and [2, 4] cannot uniquely reconstruct
// [1, 2, 3, 4]. There are two possible sequences we can construct from the given sequences:
// 1) [1, 2, 3, 4]
// 2) [1, 2, 4, 3]
//
// Example 3:
// Input: originalSeq: [3, 1, 4, 2, 5], seqs: [[3, 1, 5], [1, 4, 2, 5]]
// Output: true
// Explanation: The sequences [3, 1, 5] and [1, 4, 2, 5] can uniquely reconstruct
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

internal static class ReconstructSequence
{
    internal static bool CanConstruct(int[] originalSeq, int[][] sequences)
    {
        List<int> sortedOrder = [];
        if (originalSeq.Length <= 0)
            return false;

        // a. Initialize the graph
        Dictionary<int, int> inDegree = []; // count of incoming edges for every vertex
        Dictionary<int, List<int>> graph = []; // adjacency list graph
        foreach (int[] seq in sequences)
        {
            for (int i = 0; i < seq.Length; i++)
            {
                if (!inDegree.ContainsKey(seq[i]))
                    inDegree[seq[i]] = 0;

                if (!graph.ContainsKey(seq[i]))
                    graph[seq[i]] = [];
            }
        }

        // b. Build the graph
        foreach (int[] seq in sequences)
        {
            for (int i = 1; i < seq.Length; i++)
            {
                int parent = seq[i - 1], child = seq[i];
                graph[parent].Add(child);
                inDegree[child] = inDegree[child] + 1;
            }
        }

        // if we don't have ordering rules for all the numbers we'll not able to uniquely
        // construct the sequence
        if (inDegree.Count != originalSeq.Length)
            return false;

        // c. Find all sources i.e., all vertices with 0 in-degrees
        Queue<int> sources = new();
        foreach (KeyValuePair<int, int> entry in inDegree)
        {
            if (entry.Value == 0)
                sources.Enqueue(entry.Key);
        }

        // d. For each source, add it to the sortedOrder and subtract one from all of its
        // children's in-degrees if a child's in-degree becomes zero, add it to sources queue
        while (sources.Count > 0)
        {
            if (sources.Count > 1)
                return false; // more than one sources mean, there is more than one way to
                              // reconstruct the sequence
            if (originalSeq[sortedOrder.Count] != sources.Peek())
                return false; // the next source (or number) is different from original sequence
            int vertex = sources.Dequeue();
            sortedOrder.Add(vertex);
            // get the node's children to decrement their in-degrees
            List<int> children = graph[vertex];
            foreach (int child in children)
            {
                inDegree[child] = inDegree[child] - 1;
                if (inDegree[child] == 0)
                    sources.Enqueue(child);
            }
        }

        // if sortedOrder's size is not equal to original sequence's size, there is no
        // unique way to construct
        return sortedOrder.Count == originalSeq.Length;
    }
}
