import { describe, expect, test } from "vitest";

import { findDistinctIslandsDfs } from "./distinctislands.ts";

describe("findDistinctIslandsDfs", () => {
  test.each([
    {
      name: "two distinct islands",
      matrix: [
        [1, 1, 0, 0, 0],
        [1, 0, 0, 1, 1],
        [0, 0, 0, 1, 1],
      ],
      want: 2,
    },
    {
      name: "all islands same shape",
      matrix: [
        [1, 0, 1, 0],
        [1, 0, 1, 0],
      ],
      want: 1,
    },
    {
      name: "no islands",
      matrix: [
        [0, 0],
        [0, 0],
      ],
      want: 0,
    },
    {
      name: "single island",
      matrix: [
        [1, 1],
        [1, 1],
      ],
      want: 1,
    },
  ])("$name", ({ matrix, want }) => {
    expect(findDistinctIslandsDfs(matrix)).toBe(want);
  });
});
