import { describe, expect, test } from "vitest";

import { validPath } from "./findpath.ts";

describe("validPath", () => {
  test.each<{
    name: string;
    n: number;
    edges: [number, number][];
    start: number;
    end: number;
    want: boolean;
  }>([
    {
      name: "path exists simple",
      n: 4,
      edges: [
        [0, 1],
        [1, 2],
        [2, 3],
      ],
      start: 0,
      end: 3,
      want: true,
    },
    {
      name: "no path between disconnected components",
      n: 4,
      edges: [
        [0, 1],
        [2, 3],
      ],
      start: 0,
      end: 3,
      want: false,
    },
    {
      name: "no path with isolated nodes",
      n: 5,
      edges: [
        [0, 1],
        [3, 4],
      ],
      start: 0,
      end: 4,
      want: false,
    },
    {
      name: "single node graph",
      n: 1,
      edges: [],
      start: 0,
      end: 0,
      want: true,
    },
  ])("$name", ({ n, edges, start, end, want }) => {
    expect(validPath(n, edges, start, end)).toBe(want);
  });
});
