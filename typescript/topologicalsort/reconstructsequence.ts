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

export function canConstruct(
  originalSeq: number[],
  sequences: number[][],
): boolean {
  const sortedOrder: number[] = [];
  if (originalSeq.length === 0) {
    return false;
  }

  // a. Initialize the graph
  const inDegree = new Map<number, number>(); // count of incoming edges
  const graph = new Map<number, number[]>(); // adjacency list graph
  for (const seq of sequences) {
    for (const num of seq) {
      inDegree.set(num, 0);
      graph.set(num, []);
    }
  }

  // b. Build the graph
  for (const seq of sequences) {
    for (let i = 1; i < seq.length; i++) {
      const parent = seq[i - 1];
      const child = seq[i];
      graph.get(parent)?.push(child);
      inDegree.set(child, (inDegree.get(child) ?? 0) + 1);
    }
  }

  // if we don't have ordering rules for all the numbers we'll not able to
  // uniquely construct the sequence
  if (inDegree.size !== originalSeq.length) {
    return false;
  }

  // c. Find all sources i.e., all vertices with 0 in-degrees
  let sources: number[] = [];
  for (const [key, value] of inDegree) {
    if (value === 0) {
      sources.push(key);
    }
  }

  // d. For each source, add it to the sortedOrder and subtract one from all
  // of its children's in-degrees if a child's in-degree becomes zero, add it
  // to sources queue
  while (sources.length > 0) {
    if (sources.length > 1) {
      // more than one sources mean, there is more than one way to
      // reconstruct the sequence
      return false;
    }
    const vertex = sources[0];
    sources = [];
    if (originalSeq[sortedOrder.length] !== vertex) {
      // the next source (or number) is different from original sequence
      return false;
    }
    sortedOrder.push(vertex);
    // get the node's children to decrement their in-degrees
    for (const child of graph.get(vertex) ?? []) {
      const degree = (inDegree.get(child) ?? 0) - 1;
      inDegree.set(child, degree);
      if (degree === 0) {
        sources.push(child);
      }
    }
  }

  // if sortedOrder's size is not equal to original sequence's size, there is
  // no unique way to construct
  return sortedOrder.length === originalSeq.length;
}
