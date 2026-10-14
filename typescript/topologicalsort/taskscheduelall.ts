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

export function printAllTopologicalSorts(
  graph: number[][],
  inDegree: number[],
  sources: number[],
  sortedOrder: number[],
  orders: number[][],
): void {
  sources.forEach((vertex, i) => {
    sortedOrder.push(vertex);
    // Copy the sources for the next call, leaving out the current vertex
    const sourcesForNextCall = sources.filter((_, j) => j !== i);
    const children = graph[vertex];
    for (const child of children) {
      inDegree[child]--;
      if (inDegree[child] === 0) {
        sourcesForNextCall.push(child);
      }
    }

    printAllTopologicalSorts(
      graph,
      inDegree,
      sourcesForNextCall,
      sortedOrder,
      orders,
    );

    // Backtrack: take the vertex out again and restore the in-degrees
    sortedOrder.pop();
    for (const child of children) {
      inDegree[child]++;
    }
  });

  // If sortedOrder doesn't contain all tasks, either we've a cyclic
  // dependency between tasks, or we have not processed all the tasks in this
  // recursive call
  if (sortedOrder.length === inDegree.length) {
    orders.push([...sortedOrder]);
  }
}

export function printOrders(
  tasks: number,
  prerequisites: [number, number][],
): number[][] {
  const orders: number[][] = [];
  if (tasks <= 0) {
    return orders;
  }

  // a. Initialize the graph
  const inDegree = new Array<number>(tasks).fill(0);
  const graph: number[][] = Array.from({ length: tasks }, () => []);

  // b. Build the graph
  for (const [parent, child] of prerequisites) {
    graph[parent].push(child);
    inDegree[child]++;
  }

  // c. Find all sources i.e., all vertices with 0 in-degrees
  const sources: number[] = [];
  for (let vertex = 0; vertex < tasks; vertex++) {
    if (inDegree[vertex] === 0) {
      sources.push(vertex);
    }
  }

  printAllTopologicalSorts(graph, inDegree, sources, [], orders);
  return orders;
}
