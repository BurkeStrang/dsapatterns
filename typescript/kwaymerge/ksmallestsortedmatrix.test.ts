import { describe, expect, test } from "vitest";

import { findKthSmallestPoint } from "./ksmallestsortedmatrix.ts";

describe("findKthSmallestPoint", () => {
  test.each([
    {
      name: "Example 1",
      matrix: [
        [2, 6, 8],
        [3, 7, 10],
        [5, 7, 8],
      ],
      k: 5,
      want: 7,
    },
    {
      name: "Smaller numbers further down",
      matrix: [
        [1, 20, 30],
        [2, 21, 31],
        [3, 22, 32],
      ],
      k: 3,
      want: 3,
    },
  ])("$name", ({ matrix, k, want }) => {
    expect(findKthSmallestPoint(matrix, k)).toBe(want);
  });
});
