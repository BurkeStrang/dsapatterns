// There are N tasks, labeled from 0 to 'N-1'.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
//
// Given the number of tasks and a list of prerequisite pairs,
// write a method to print all possible ordering of tasks meeting all
// prerequisites.
//
// Example 1:
// Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
// Output:
// 1) [3, 2, 0, 1]
// 2) [3, 2, 1, 0]
// Explanation: There are two possible orderings of the tasks meeting all
// prerequisites.
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: There is only possible ordering of the tasks.
//
// Example 3:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output:
// 1) [0, 1, 4, 3, 2, 5]
// 2) [0, 1, 3, 4, 2, 5]
// 3) [0, 1, 3, 2, 4, 5]
// 4) [0, 1, 3, 2, 5, 4]
// 5) [1, 0, 3, 4, 2, 5]
// 6) [1, 0, 3, 2, 4, 5]
// 7) [1, 0, 3, 2, 5, 4]
// 8) [1, 0, 4, 3, 2, 5]
// 9) [1, 3, 0, 2, 4, 5]
// 10) [1, 3, 0, 2, 5, 4]
// 11) [1, 3, 0, 4, 2, 5]
// 12) [1, 3, 2, 0, 5, 4]
// 13) [1, 3, 2, 0, 4, 5]

pub fn print_orders(
    tasks: usize,
    prerequisites: &[[usize; 2]],
) -> Vec<Vec<usize>> {
    let mut orders = Vec::new();
    if tasks == 0 {
        return orders;
    }

    // a. Initialize the graph
    let mut in_degree = vec![0; tasks];
    let mut graph = vec![Vec::new(); tasks];

    // b. Build the graph
    for &[parent, child] in prerequisites {
        graph[parent].push(child);
        in_degree[child] += 1;
    }

    // c. Find all sources i.e., all vertices with 0 in-degrees
    let mut sources = Vec::new();
    for vertex in 0..tasks {
        if in_degree[vertex] == 0 {
            sources.push(vertex);
        }
    }

    let mut sorted_order = Vec::new();
    print_all_topological_sorts(
        &graph,
        &mut in_degree,
        &sources,
        &mut sorted_order,
        &mut orders,
    );
    orders
}

fn print_all_topological_sorts(
    graph: &[Vec<usize>],
    in_degree: &mut [usize],
    sources: &[usize],
    sorted_order: &mut Vec<usize>,
    orders: &mut Vec<Vec<usize>>,
) {
    for (i, &vertex) in sources.iter().enumerate() {
        sorted_order.push(vertex);

        // Copy the sources for the next call, leaving out the current vertex
        let mut sources_for_next_call = sources.to_vec();
        sources_for_next_call.remove(i);

        let children = &graph[vertex];
        for &child in children {
            in_degree[child] -= 1;
            if in_degree[child] == 0 {
                sources_for_next_call.push(child);
            }
        }

        print_all_topological_sorts(
            graph,
            in_degree,
            &sources_for_next_call,
            sorted_order,
            orders,
        );

        // Backtrack: take the vertex out again and restore the in-degrees
        sorted_order.pop();
        for &child in children {
            in_degree[child] += 1;
        }
    }

    // If sorted_order doesn't contain all tasks, either we've a cyclic
    // dependency between tasks, or we have not processed all the tasks in
    // this recursive call
    if sorted_order.len() == in_degree.len() {
        orders.push(sorted_order.clone());
    }
}
