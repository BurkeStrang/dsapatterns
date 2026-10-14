use super::shared::UnionFind;

// Given a 2D array graph[][],
// representing the undirected graph,
// where graph[u] is an array of nodes that are connected with node u.
// Determine whether a given undirected graph is a bipartite graph.
// The graph is a bipartite graph,
// if we can split the set of nodes into two distinct subsets such that
// no two nodes within the same subset are adjacent
// (i.e., no edge exists between any two nodes within a single subset).
//
// Example 1:
// Input: graph = [[1,3], [0,2], [1,3], [0,2]]
// Expected Output: true
// Justification: The nodes can be divided into two groups: {0, 2} and {1, 3}.
// No two nodes within each group are adjacent, thus the graph is bipartite.
//
// Example 2:
// Input: graph = [[1], [0], [3], [2]]
// Expected Output: true
// Justification: The graph is a simple chain of 4 nodes.
// It's clearly bipartite as we can have {0, 2} and {1, 3} as the two subsets.
//
// Example 3:
// Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
// Expected Output: false
// Justification: We found that edges (1, 2), (0, 3), and (2, 3) connect nodes
// within the same set,
// which violates the condition for a bipartite graph where each edge must
// connect nodes in different subsets.
// Thus, there's no way to divide this graph into two subsets that satisfy the
// bipartite condition.
//
// Constraints:
// graph.length == n
// 1 <= n <= 100
// 0 <= graph[u].length < n
// 0 <= graph[u][i] <= n - 1
// graph[u] does not contain u.
// All the values of graph[u] are unique.
// If graph[u] contains v, then graph[v] contains u.

pub fn is_bipartite(graph: &[Vec<usize>]) -> bool {
    let mut uf = UnionFind::new(graph.len());

    for u in 0..graph.len() {
        let Some(&first_neighbor) = graph[u].first() else {
            continue;
        };
        for &v in &graph[u] {
            // a node in the same set as one of its neighbors breaks the rule
            if uf.connected(u, v) {
                return false;
            }
            // all the neighbors of a node belong in the same set
            uf.union(first_neighbor, v);
        }
    }

    true
}
