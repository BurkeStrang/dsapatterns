// We are given an undirected graph that has the characteristics of a k-ary
// tree.
// In such a graph,
// we can choose any node as the root to make a k-ary tree.
// The root (or the tree) with the minimum height will be called Minimum Height
// Tree (MHT).
// There can be multiple MHTs for a graph.
// In this problem, we need to find all those roots which give us MHTs.
// Write a method to find all MHTs of the given graph and return a list of their
// roots.
//
// Example 1:
// Input: vertices: 5, Edges: [[0, 1], [1, 2], [1, 3], [2, 4]]
// Output:[1, 2]
// Explanation: Choosing '1' or '2' as roots give us MHTs.
// In the below diagram,
// we can see that the height of the trees with roots '1' or '2' is three which
// is the minimum.
//
// Example 2:
// Input: vertices: 4, Edges: [[0, 1], [0, 2], [2, 3]]
// Output:[0, 2]
// Explanation: Choosing '0' or '2' as roots give us MHTs.
// In the below diagram, we can see that the height of the trees with roots '0'
// or '2' is three which is minimum.
//
// Example 3:
// Input: vertices: 4, Edges: [[0, 1], [1, 2], [1, 3]]
// Output:[1]
//
// Constraints:
// 1 <= vertices <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated
// edges.

export function findTrees(nodes: number, edges: [number, number][]): number[] {
  if (nodes <= 0) {
    return [];
  }

  // with only one node, since its in-degree will be 0, therefore, we need to
  // handle it separately
  if (nodes === 1) {
    return [0];
  }

  // a. Initialize the graph
  const inDegree = new Array<number>(nodes).fill(0); // count of incoming edges
  // adjacency list graph
  const graph: number[][] = Array.from({ length: nodes }, () => []);

  // b. Build the graph
  for (const [n1, n2] of edges) {
    // since this is an undirected graph, therefore, add a link for both the
    // nodes
    graph[n1].push(n2);
    graph[n2].push(n1);
    // increment the in-degrees of both the nodes
    inDegree[n1]++;
    inDegree[n2]++;
  }

  // c. Find all leaves i.e., all nodes with only 1 in-degree
  let leaves: number[] = [];
  for (let vertex = 0; vertex < nodes; vertex++) {
    if (inDegree[vertex] === 1) {
      leaves.push(vertex);
    }
  }

  // d. Remove leaves level by level and subtract each leave's children's
  // in-degrees. Repeat this until we are left with 1 or 2 nodes, which will
  // be our answer. Any node that has already been a leaf cannot be the root
  // of a minimum height tree, because its adjacent non-leaf node will always
  // be a better candidate.
  let totalNodes = nodes;
  while (totalNodes > 2) {
    totalNodes -= leaves.length;
    const nextLeaves: number[] = [];
    for (const vertex of leaves) {
      for (const child of graph[vertex]) {
        inDegree[child]--;
        // if the child has become a leaf
        if (inDegree[child] === 1) {
          nextLeaves.push(child);
        }
      }
    }
    leaves = nextLeaves;
  }

  return leaves;
}
