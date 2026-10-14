// Helpers shared by the topological sort tests.

// isTopologicalOrder reports whether order lists every vertex once, with
// each edge's parent before its child. A graph usually has more than one
// valid order, so the tests check the order this way instead of comparing it
// with a fixed answer.
export function isTopologicalOrder(
  order: number[],
  vertices: number,
  edges: [number, number][],
): boolean {
  if (order.length !== vertices) {
    return false;
  }
  // position[v] is where vertex 'v' sits in the order, or -1
  const position = new Array<number>(vertices).fill(-1);
  for (let i = 0; i < order.length; i++) {
    const vertex = order[i];
    if (vertex < 0 || vertex >= vertices || position[vertex] !== -1) {
      return false;
    }
    position[vertex] = i;
  }
  return edges.every(([parent, child]) => position[parent] < position[child]);
}
