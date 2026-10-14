import { describe, expect, test } from "vitest";

import { floodFill } from "./floodfill.ts";

describe("floodFill", () => {
  test.each([
    {
      name: "basic flood fill",
      matrix: [
        [1, 1, 1],
        [1, 1, 0],
        [1, 0, 1],
      ],
      x: 1,
      y: 1,
      newColor: 2,
      want: [
        [2, 2, 2],
        [2, 2, 0],
        [2, 0, 1],
      ],
    },
    {
      name: "starting point already new color",
      matrix: [
        [0, 0],
        [0, 1],
      ],
      x: 1,
      y: 1,
      newColor: 1,
      want: [
        [0, 0],
        [0, 1],
      ],
    },
    {
      name: "no fill when starting outside bounds",
      matrix: [
        [1, 1],
        [1, 1],
      ],
      x: 3, // outside grid
      y: 0,
      newColor: 5,
      want: [
        [1, 1],
        [1, 1],
      ],
    },
    {
      name: "single cell matrix",
      matrix: [[1]],
      x: 0,
      y: 0,
      newColor: 9,
      want: [[9]],
    },
  ])("$name", ({ matrix, x, y, newColor, want }) => {
    floodFill(matrix, x, y, newColor);
    expect(matrix).toEqual(want);
  });
});
