import { describe, expect, test } from "vitest";

import { findSmallestSetOfVertices } from "./minnumreachallnodes.ts";

describe("findSmallestSetOfVertices", () => {
  test.each<{
    name: string;
    n: number;
    edges: [number, number][];
    want: number[];
  }>([
    {
      name: "Example 1",
      n: 6,
      edges: [
        [0, 1],
        [0, 2],
        [2, 5],
        [3, 4],
        [4, 2],
      ],
      want: [0, 3],
    },
    { name: "Single node", n: 1, edges: [], want: [0] },
    { name: "Disconnected nodes", n: 3, edges: [], want: [0, 1, 2] },
    {
      name: "All nodes connected in a chain",
      n: 4,
      edges: [
        [0, 1],
        [1, 2],
        [2, 3],
      ],
      want: [0],
    },
  ])("$name", ({ n, edges, want }) => {
    expect(findSmallestSetOfVertices(n, edges)).toEqual(want);
  });
});
