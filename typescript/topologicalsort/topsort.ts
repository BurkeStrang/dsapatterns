// Topological Sort of a directed graph (a graph with unidirectional edges) is
// a linear ordering of its vertices such that for every directed edge (U, V)
// from vertex U to vertex V, U comes before V in the ordering.
//
// Given a directed graph, find the topological ordering of its vertices.
// Returns an empty list if the graph has a cycle.

export function sort(vertices: number, edges: [number, number][]): number[] {
  const sortedOrder: number[] = [];

  // a. Initialize the graph
  // count of incoming edges
  const inDegree = new Array<number>(vertices).fill(0);
  // adjacency list graph
  const graph: number[][] = Array.from({ length: vertices }, () => []);

  // b. Build the graph
  for (const [parent, child] of edges) {
    graph[parent].push(child); // put the child into its parent's list
    inDegree[child]++; // increment child's inDegree
  }

  // c. Find all sources i.e., all vertices with 0 in-degrees
  const sources: number[] = [];
  for (let vertex = 0; vertex < vertices; vertex++) {
    if (inDegree[vertex] === 0) {
      sources.push(vertex);
    }
  }

  // d. For each source, add it to the sortedOrder and subtract one from all
  // of its children's in-degrees if a child's in-degree becomes zero, add it
  // to sources queue. A for-of loop over an array also visits the items
  // pushed onto it while the loop runs, so the array works as the queue.
  for (const vertex of sources) {
    sortedOrder.push(vertex);
    // get the node's children to decrement their in-degrees
    for (const child of graph[vertex]) {
      inDegree[child]--;
      if (inDegree[child] === 0) {
        sources.push(child);
      }
    }
  }

  // if topological sort is not possible as the graph has a cycle
  if (sortedOrder.length !== vertices) {
    return [];
  }

  return sortedOrder;
}
