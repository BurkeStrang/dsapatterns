use std::collections::VecDeque;

// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs, find out if it is
// possible to schedule all the tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: true
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: true
// Explanation: To execute task '1', task '0' needs to finish first. Similarly,
// task '1' needs to finish before '2' can be scheduled. One possible scheduling
// of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: false
// Explanation: The tasks have a cyclic dependency, therefore they cannot be
// scheduled.

pub fn is_scheduling_possible(
    tasks: usize,
    prerequisites: &[[usize; 2]],
) -> bool {
    let mut sorted_order = Vec::new();
    if tasks == 0 {
        return false;
    }

    // Initialize the graph
    let mut in_degree = vec![0; tasks]; // count of incoming edges
    let mut graph = vec![Vec::new(); tasks]; // adjacency list graph

    // Build the graph
    for &[parent, child] in prerequisites {
        graph[parent].push(child); // put the child into its parent's list
        in_degree[child] += 1; // increment child's in_degree
    }

    // Find all sources i.e., all vertices with 0 in-degrees
    let mut sources = VecDeque::new();
    for vertex in 0..tasks {
        if in_degree[vertex] == 0 {
            sources.push_back(vertex);
        }
    }

    // For each source, add it to the sorted_order and subtract one from all
    // of its children's in-degrees. If a child's in-degree becomes zero, add
    // it to sources queue.
    while let Some(vertex) = sources.pop_front() {
        sorted_order.push(vertex);

        // Get the node's children to decrement their in-degrees
        for &child in &graph[vertex] {
            in_degree[child] -= 1;
            if in_degree[child] == 0 {
                sources.push_back(child);
            }
        }
    }

    // If sorted_order doesn't contain all tasks, there is a cyclic dependency
    // between tasks, therefore, we will not be able to schedule all tasks
    sorted_order.len() == tasks
}
