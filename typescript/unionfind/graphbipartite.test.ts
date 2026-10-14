import { describe, expect, test } from "vitest";

import { isBipartite } from "./graphbipartite.ts";

describe("isBipartite", () => {
  test.each([
    {
      name: "Example 1",
      graph: [
        [1, 3],
        [0, 2],
        [1, 3],
        [0, 2],
      ],
      want: true,
    },
    { name: "Example 2", graph: [[1], [0], [3], [2]], want: true },
    {
      name: "Example 3",
      graph: [
        [1, 2, 3],
        [0, 2],
        [0, 1, 3],
        [0, 2],
      ],
      want: false,
    },
    { name: "No edges", graph: [[], [], []], want: true },
  ])("$name", ({ graph, want }) => {
    expect(isBipartite(graph)).toBe(want);
  });
});
