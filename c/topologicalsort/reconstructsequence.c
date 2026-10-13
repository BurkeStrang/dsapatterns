#include "common/list.h"
#include "common/queue.h"

#include <stdbool.h>

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

bool can_construct
(
    const int *original_seq,
    int original_len,
    const IntMatrix *sequences
)
{
    if (original_len <= 0)
    {
        return false;
    }

    // a. Initialize the graph
    // original_seq is a permutation of 1..n, so the numbers index straight
    // into arrays (index 0 is not used)
    int n = original_len;
    // which numbers have an ordering rule
    bool *present = calloc((size_t)n + 1, sizeof(bool));
    int present_count = 0;
    // count of incoming edges for every vertex
    int *in_degree = calloc((size_t)n + 1, sizeof(int));
    // adjacency list graph
    IntList *graph = calloc((size_t)n + 1, sizeof(IntList));

    // b. Build the graph
    bool possible = true;
    for (int s = 0; possible && s < sequences->len; s++)
    {
        const IntList *seq = &sequences->rows[s];
        for (int i = 0; i < seq->len; i++)
        {
            int number = seq->items[i];
            if (number < 1 || number > n)
            {
                // a number that isn't part of the original sequence
                possible = false;
                break;
            }
            if (!present[number])
            {
                present[number] = true;
                present_count++;
            }
            if (i > 0)
            {
                int parent = seq->items[i - 1];
                intlist_push(&graph[parent], number);
                in_degree[number]++;
            }
        }
    }

    // if we don't have ordering rules for all the numbers we'll not able to
    // uniquely construct the sequence
    if (present_count != n)
    {
        possible = false;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    Queue sources = queue_new(sizeof(int));
    for (int number = 1; possible && number <= n; number++)
    {
        if (in_degree[number] == 0)
        {
            int_queue_push(&sources, number);
        }
    }

    // d. For each source, add it to the sorted order and subtract one from
    // all of its children's in-degrees. If a child's in-degree becomes zero,
    // add it to sources queue.
    int sorted_len = 0;
    while (possible && sources.len > 0)
    {
        if (sources.len > 1)
        {
            // more than one sources mean, there is more than one way to
            // reconstruct the sequence
            possible = false;
            break;
        }
        int vertex = int_queue_pop(&sources);
        if (original_seq[sorted_len] != vertex)
        {
            // the next source (or number) is different from the original
            // sequence
            possible = false;
            break;
        }
        sorted_len++;
        // get the node's children to decrement their in-degrees
        for (int c = 0; c < graph[vertex].len; c++)
        {
            int child = graph[vertex].items[c];
            in_degree[child]--;
            if (in_degree[child] == 0)
            {
                int_queue_push(&sources, child);
            }
        }
    }

    queue_free(&sources);
    for (int i = 0; i <= n; i++)
    {
        intlist_free(&graph[i]);
    }
    free(graph);
    free(in_degree);
    free(present);

    // if the sorted order's size is not equal to original sequence's size,
    // there is no unique way to construct
    return possible && sorted_len == original_len;
}
