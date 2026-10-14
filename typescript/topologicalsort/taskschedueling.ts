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

export function isSchedulingPossible(
  tasks: number,
  prerequisites: [number, number][],
): boolean {
  const sortedOrder: number[] = [];
  if (tasks <= 0) {
    return false;
  }

  // Initialize the graph
  const inDegree = new Array<number>(tasks).fill(0); // count of incoming edges
  // adjacency list graph
  const graph: number[][] = Array.from({ length: tasks }, () => []);

  // Build the graph
  for (const [parent, child] of prerequisites) {
    graph[parent].push(child); // put the child into its parent's list
    inDegree[child]++; // increment child's inDegree
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
    // Get the node's children to decrement their in-degrees
    for (const child of graph[vertex]) {
      inDegree[child]--;
      if (inDegree[child] === 0) {
        sources.push(child);
      }
    }
  }

  // If sortedOrder doesn't contain all tasks, there is a cyclic dependency
  // between tasks, therefore, we will not be able to schedule all tasks
  return sortedOrder.length === tasks;
}
