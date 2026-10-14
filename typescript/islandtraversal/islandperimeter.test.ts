import { describe, expect, test } from "vitest";

import { findIslandPerimeter } from "./islandperimeter.ts";

describe("findIslandPerimeter", () => {
  test.each([
    // shape is a plus sign → perimeter = 12
    {
      name: "plus sign island",
      matrix: [
        [0, 1, 0],
        [1, 1, 1],
        [0, 1, 0],
      ],
      want: 12,
    },
    { name: "single land cell", matrix: [[1]], want: 4 },
    // ends (3 sides + 3 sides) + middle (2 + 2)
    { name: "single row island", matrix: [[1, 1, 1, 1]], want: 10 },
    // 2x2 block perimeter = 8
    {
      name: "one big solid block",
      matrix: [
        [1, 1],
        [1, 1],
      ],
      want: 8,
    },
    // Shape:
    // 1 .
    // 1 1
    {
      name: "L-shaped island",
      matrix: [
        [1, 0],
        [1, 1],
      ],
      want: 8,
    },
    {
      name: "island touching border",
      matrix: [
        [1, 1, 0],
        [1, 0, 0],
        [1, 1, 1],
      ],
      want: 14,
    },
    // A hollow square → perimeter counts both outer and inner edges
    // outer = 12, inner hole = 4 → total = 16
    {
      name: "island with a hole inside",
      matrix: [
        [1, 1, 1],
        [1, 0, 1],
        [1, 1, 1],
      ],
      want: 16,
    },
  ])("$name", ({ matrix, want }) => {
    expect(findIslandPerimeter(matrix)).toBe(want);
  });
});
