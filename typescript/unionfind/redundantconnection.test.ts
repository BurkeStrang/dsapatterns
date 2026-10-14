import { describe, expect, test } from "vitest";

import { findRedundantConnection } from "./redundantconnection.ts";

describe("findRedundantConnection", () => {
  test.each<{ name: string; edges: [number, number][]; want: number[] }>([
    {
      name: "Example 1",
      edges: [
        [1, 2],
        [1, 3],
        [3, 4],
        [1, 4],
        [1, 5],
      ],
      want: [1, 4],
    },
    {
      name: "Example 2",
      edges: [
        [1, 2],
        [2, 3],
        [3, 1],
        [3, 4],
      ],
      want: [3, 1],
    },
    {
      name: "Example 3",
      edges: [
        [1, 2],
        [2, 3],
        [3, 4],
        [4, 2],
        [5, 6],
      ],
      want: [4, 2],
    },
  ])("$name", ({ edges, want }) => {
    expect(findRedundantConnection(edges)).toEqual(want);
  });
});
