// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs,
// write a method to find the ordering of tasks we should pick to finish all
// tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: [0 1 4 3 2 5]
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: To execute task '1', task '0' needs to finish first.
// Similarly, task '1' needs to finish before '2' can be scheduled.
// A possible scheduling of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: []
// Explanation: The tasks have a cyclic dependency, therefore they cannot be
// scheduled.

export function findOrder(
  tasks: number,
  prerequisites: [number, number][],
): number[] {
  const sortedOrder: number[] = [];

  // Initialize the graph
  const inDegree = new Array<number>(tasks).fill(0);
  const graph: number[][] = Array.from({ length: tasks }, () => []);

  // Build the graph
  for (const [parent, child] of prerequisites) {
    graph[parent].push(child);
    inDegree[child]++;
  }

  // Find all sources i.e., all vertices with 0 in-degrees
  const sources: number[] = [];
  for (let vertex = 0; vertex < tasks; vertex++) {
    if (inDegree[vertex] === 0) {
      sources.push(vertex);
    }
  }

  // For each source, add it to the sortedOrder and subtract one from all of
  // its children's in-degrees. If a child's in-degree becomes zero, add it to
  // sources queue. A for-of loop over an array also visits the items pushed
  // onto it while the loop runs, so the array works as the queue.
  for (const vertex of sources) {
    sortedOrder.push(vertex);
    for (const child of graph[vertex]) {
      inDegree[child]--;
      if (inDegree[child] === 0) {
        sources.push(child);
      }
    }
  }

  // If sortedOrder doesn't contain all tasks, there is a cyclic dependency
  // between tasks, therefore, we will not be able to schedule all tasks
  if (sortedOrder.length !== tasks) {
    return [];
  }

  return sortedOrder;
}
