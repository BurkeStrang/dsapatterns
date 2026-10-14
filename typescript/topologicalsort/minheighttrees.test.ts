import { describe, expect, test } from "vitest";

import { findTrees } from "./minheighttrees.ts";

describe("findTrees", () => {
  test.each<{
    name: string;
    nodes: number;
    edges: [number, number][];
    want: number[];
  }>([
    {
      name: "Example 1",
      nodes: 5,
      edges: [
        [0, 1],
        [1, 2],
        [1, 3],
        [2, 4],
      ],
      want: [1, 2],
    },
    {
      name: "Example 2",
      nodes: 4,
      edges: [
        [0, 1],
        [0, 2],
        [2, 3],
      ],
      want: [0, 2],
    },
    {
      name: "Example 3",
      nodes: 4,
      edges: [
        [0, 1],
        [1, 2],
        [1, 3],
      ],
      want: [1],
    },
    {
      name: "Star",
      nodes: 4,
      edges: [
        [1, 0],
        [1, 2],
        [1, 3],
      ],
      want: [1],
    },
    {
      name: "Two centres",
      nodes: 6,
      edges: [
        [0, 3],
        [1, 3],
        [2, 3],
        [4, 3],
        [5, 4],
      ],
      want: [3, 4],
    },
    { name: "One node", nodes: 1, edges: [], want: [0] },
    { name: "No nodes", nodes: 0, edges: [], want: [] },
  ])("$name", ({ nodes, edges, want }) => {
    // the roots can come back in any order
    expect(findTrees(nodes, edges).sort((a, b) => a - b)).toEqual(want);
  });
});
