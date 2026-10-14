import { describe, expect, test } from "vitest";

import { makeSquares } from "./squareasortedarray.ts";

describe("makeSquares", () => {
  test.each([
    { name: "Example 1", arr: [-2, -1, 0, 2, 3], want: [0, 1, 4, 4, 9] },
    { name: "Example 2", arr: [-3, -1, 0, 1, 2], want: [0, 1, 1, 4, 9] },
    { name: "zero", arr: [0], want: [0] },
    { name: "single negative", arr: [-1], want: [1] },
    { name: "all positive", arr: [1, 2, 3], want: [1, 4, 9] },
    { name: "all negative", arr: [-4, -3, -2, -1], want: [1, 4, 9, 16] },
  ])("$name", ({ arr, want }) => {
    expect(makeSquares(arr)).toEqual(want);
  });
});
