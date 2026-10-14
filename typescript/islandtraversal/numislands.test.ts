import { describe, expect, test } from "vitest";

import { countIslands } from "./numislands.ts";

describe("countIslands", () => {
  test.each([
    {
      name: "three islands",
      matrix: [
        [1, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 0, 1, 0],
        [0, 0, 0, 1],
      ],
      want: 3,
    },
    {
      name: "no islands",
      matrix: [
        [0, 0, 0],
        [0, 0, 0],
      ],
      want: 0,
    },
    {
      name: "all land",
      matrix: [
        [1, 1],
        [1, 1],
      ],
      want: 1,
    },
  ])("$name", ({ matrix, want }) => {
    expect(countIslands(matrix)).toBe(want);
  });
});
