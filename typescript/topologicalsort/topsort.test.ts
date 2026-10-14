import { describe, expect, test } from "vitest";

import { isTopologicalOrder } from "./shared.ts";
import { sort } from "./topsort.ts";

describe("sort", () => {
  test.each<{ name: string; vertices: number; edges: [number, number][] }>([
    {
      name: "Test Case 1",
      vertices: 6,
      edges: [
        [5, 2],
        [5, 0],
        [4, 0],
        [4, 1],
        [2, 3],
        [3, 1],
      ],
    },
    {
      name: "Test Case 2",
      vertices: 4,
      edges: [
        [0, 1],
        [1, 2],
        [2, 3],
      ],
    },
  ])("$name", ({ vertices, edges }) => {
    const got = sort(vertices, edges);
    expect(
      isTopologicalOrder(got, vertices, edges),
      `${JSON.stringify(got)} is not a topological order`,
    ).toBe(true);
  });

  test("A graph with a cycle has no order", () => {
    expect(
      sort(3, [
        [0, 1],
        [1, 2],
        [2, 0],
      ]),
    ).toEqual([]);
  });
});
