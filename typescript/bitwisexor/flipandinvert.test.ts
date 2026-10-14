import { describe, expect, test } from "vitest";

import { flipAndInvertImage } from "./flipandinvert.ts";

describe("flipAndInvertImage", () => {
  test.each([
    {
      name: "Example 1",
      arr: [
        [1, 0, 1],
        [1, 1, 1],
        [0, 1, 1],
      ],
      want: [
        [0, 1, 0],
        [0, 0, 0],
        [0, 0, 1],
      ],
    },
    {
      name: "Example 2",
      arr: [
        [1, 1, 0, 0],
        [1, 0, 0, 1],
        [0, 1, 1, 1],
        [1, 0, 1, 0],
      ],
      want: [
        [1, 1, 0, 0],
        [0, 1, 1, 0],
        [0, 0, 0, 1],
        [1, 0, 1, 0],
      ],
    },
    { name: "Single row", arr: [[1, 0, 0, 1]], want: [[0, 1, 1, 0]] },
  ])("$name", ({ arr, want }) => {
    flipAndInvertImage(arr);
    expect(arr).toEqual(want);
  });
});
