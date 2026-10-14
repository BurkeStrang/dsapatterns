use std::collections::VecDeque;

// Topological Sort of a directed graph (a graph with unidirectional edges) is
// a linear ordering of its vertices such that for every directed edge (U, V)
// from vertex U to vertex V, U comes before V in the ordering.
//
// Given a directed graph, find the topological ordering of its vertices.
// Returns an empty list if the graph has a cycle.

pub fn sort(vertices: usize, edges: &[[usize; 2]]) -> Vec<usize> {
    let mut sorted_order = Vec::new();

    // a. Initialize the graph
    let mut in_degree = vec![0; vertices]; // count of incoming edges
    let mut graph = vec![Vec::new(); vertices]; // adjacency list graph

    // b. Build the graph
    for &[parent, child] in edges {
        graph[parent].push(child); // put the child into its parent's list
        in_degree[child] += 1; // increment child's in_degree
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    let mut sources = VecDeque::new();
    for vertex in 0..vertices {
        if in_degree[vertex] == 0 {
            sources.push_back(vertex);
        }
    }

    // d. For each source, add it to the sorted_order and subtract one from
    // all of its children's in-degrees if a child's in-degree becomes zero,
    // add it to sources queue
    while let Some(vertex) = sources.pop_front() {
        sorted_order.push(vertex);
        // get the node's children to decrement their in-degrees
        for &child in &graph[vertex] {
            in_degree[child] -= 1;
            if in_degree[child] == 0 {
                sources.push_back(child);
            }
        }
    }

    // if topological sort is not possible as the graph has a cycle
    if sorted_order.len() != vertices {
        return Vec::new();
    }

    sorted_order
}
