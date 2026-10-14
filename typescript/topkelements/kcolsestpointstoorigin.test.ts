import { describe, expect, test } from "vitest";

import { findClosestPoints, type Point } from "./kcolsestpointstoorigin.ts";

// points turns [x, y] pairs into points.
function points(pairs: [number, number][]): Point[] {
  return pairs.map(([x, y]) => ({ x, y }));
}

describe("findClosestPoints", () => {
  test.each([
    {
      name: "Example 1",
      input: points([
        [1, 2],
        [1, 3],
      ]),
      k: 1,
      want: points([[1, 2]]),
    },
    {
      name: "Example 2",
      input: points([
        [1, 3],
        [3, 4],
        [2, -1],
      ]),
      k: 2,
      want: points([
        [1, 3],
        [2, -1],
      ]),
    },
    {
      name: "Example 3",
      input: points([
        [1, 2],
        [3, 4],
        [1, -1],
      ]),
      k: 2,
      want: points([
        [1, -1],
        [1, 2],
      ]),
    },
    {
      name: "Example 4",
      input: points([
        [3, 3],
        [5, -1],
        [-2, 4],
      ]),
      k: 2,
      want: points([
        [-2, 4],
        [3, 3],
      ]),
    },
    {
      name: "All points are the same",
      input: points([
        [1, 1],
        [1, 1],
        [1, 1],
      ]),
      k: 2,
      want: points([
        [1, 1],
        [1, 1],
      ]),
    },
  ])("$name", ({ input, k, want }) => {
    // the points may come back in any order
    const got = findClosestPoints(input, k).sort(
      (a, b) => a.x - b.x || a.y - b.y,
    );
    expect(got).toEqual(want);
  });
});
