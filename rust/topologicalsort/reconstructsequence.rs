use std::collections::{HashMap, VecDeque};

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

pub fn can_construct(original_seq: &[i32], sequences: &[Vec<i32>]) -> bool {
    let mut sorted_order = Vec::new();
    if original_seq.is_empty() {
        return false;
    }

    // a. Initialize the graph
    // count of incoming edges for every vertex
    let mut in_degree: HashMap<i32, usize> = HashMap::new();
    // adjacency list graph
    let mut graph: HashMap<i32, Vec<i32>> = HashMap::new();
    for seq in sequences {
        for &num in seq {
            in_degree.entry(num).or_insert(0);
            graph.entry(num).or_default();
        }
    }

    // b. Build the graph
    for seq in sequences {
        for pair in seq.windows(2) {
            let (parent, child) = (pair[0], pair[1]);
            graph.get_mut(&parent).unwrap().push(child);
            *in_degree.get_mut(&child).unwrap() += 1;
        }
    }

    // if we don't have ordering rules for all the numbers we'll not able to
    // uniquely construct the sequence
    if in_degree.len() != original_seq.len() {
        return false;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    let mut sources = VecDeque::new();
    for (&key, &value) in &in_degree {
        if value == 0 {
            sources.push_back(key);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees if a child's in-degree becomes zero,
    // add it to sources queue
    while let Some(vertex) = sources.pop_front() {
        if !sources.is_empty() {
            // more than one sources mean, there is more than one way to
            // reconstruct the sequence
            return false;
        }

        if original_seq[sorted_order.len()] != vertex {
            // the next source (or number) is different from original sequence
            return false;
        }

        sorted_order.push(vertex);

        // get the node's children to decrement their in-degrees
        for child in &graph[&vertex] {
            let degree = in_degree.get_mut(child).unwrap();
            *degree -= 1;
            if *degree == 0 {
                sources.push_back(*child);
            }
        }
    }

    // if sorted_order's size is not equal to original sequence's size, there
    // is no unique way to construct
    sorted_order.len() == original_seq.len()
}
