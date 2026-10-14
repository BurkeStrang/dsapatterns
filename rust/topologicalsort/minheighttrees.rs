use std::collections::VecDeque;

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

pub fn find_trees(nodes: usize, edges: &[[usize; 2]]) -> Vec<usize> {
    if nodes == 0 {
        return Vec::new();
    }

    // with only one node, since its in-degree will be 0, therefore, we need
    // to handle it separately
    if nodes == 1 {
        return vec![0];
    }

    // a. Initialize the graph
    let mut in_degree = vec![0usize; nodes]; // count of incoming edges
    let mut graph = vec![Vec::new(); nodes]; // adjacency list graph

    // b. Build the graph
    for &[n1, n2] in edges {
        // since this is an undirected graph, therefore, add a link for both
        // the nodes
        graph[n1].push(n2);
        graph[n2].push(n1);
        // increment the in-degrees of both the nodes
        in_degree[n1] += 1;
        in_degree[n2] += 1;
    }

    // c. Find all leaves i.e., all nodes with only 1 in-degree
    let mut leaves = VecDeque::new();
    for vertex in 0..nodes {
        if in_degree[vertex] == 1 {
            leaves.push_back(vertex);
        }
    }

    // d. Remove leaves level by level and subtract each leave's children's
    // in-degrees. Repeat this until we are left with 1 or 2 nodes, which will
    // be our answer. Any node that has already been a leaf cannot be the root
    // of a minimum height tree, because its adjacent non-leaf node will
    // always be a better candidate.
    let mut total_nodes = nodes;
    while total_nodes > 2 {
        let leaves_size = leaves.len();
        total_nodes -= leaves_size;
        for _ in 0..leaves_size {
            let vertex = leaves.pop_front().unwrap();
            for &child in &graph[vertex] {
                in_degree[child] -= 1;
                // if the child has become a leaf
                if in_degree[child] == 1 {
                    leaves.push_back(child);
                }
            }
        }
    }

    leaves.into()
}
