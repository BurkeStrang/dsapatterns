import { describe, expect, test } from "vitest";

import { countClosedIslands } from "./numofclosed.ts";

describe("countClosedIslands", () => {
  test.each([
    {
      name: "one simple closed island",
      matrix: [
        [1, 1, 1, 1, 1],
        [1, 0, 0, 0, 1],
        [1, 0, 1, 0, 1],
        [1, 0, 0, 0, 1],
        [1, 1, 1, 1, 1],
      ],
      want: 1,
    },
    {
      name: "two closed islands",
      matrix: [
        [1, 1, 0, 1, 0, 0],
        [1, 0, 1, 0, 0, 0],
        [1, 0, 1, 0, 1, 0],
        [1, 1, 0, 1, 0, 0],
      ],
      want: 2,
    },
    {
      name: "islands touching border are NOT closed",
      matrix: [
        [0, 1, 1, 1],
        [1, 0, 0, 1],
        [1, 1, 0, 1],
        [1, 1, 1, 1],
      ],
      want: 0,
    },
    {
      name: "all land, touching every border",
      matrix: [
        [1, 1, 1],
        [1, 1, 1],
        [1, 1, 1],
      ],
      want: 0,
    },
    {
      name: "no land at all",
      matrix: [
        [0, 0, 0],
        [0, 0, 0],
        [0, 0, 0],
      ],
      want: 0,
    },
    {
      name: "inner island next to one that reaches the border",
      matrix: [
        [1, 1, 1, 1, 1, 1],
        [1, 0, 0, 0, 0, 1],
        [1, 0, 1, 0, 0, 1],
        [0, 0, 0, 0, 1, 1],
        [1, 1, 1, 1, 1, 1],
      ],
      want: 1,
    },
    // the search goes down from the top-left 1 and hits the bottom edge
    // first; the rest of the island must still be marked visited or it is
    // counted again later as a closed island
    {
      name: "open island whose search reaches the border early",
      matrix: [
        [0, 0, 0, 0, 0],
        [0, 1, 0, 1, 0],
        [0, 1, 1, 1, 0],
        [0, 1, 0, 0, 0],
        [0, 1, 0, 0, 0],
      ],
      want: 0,
    },
  ])("$name", ({ matrix, want }) => {
    expect(countClosedIslands(matrix)).toBe(want);
  });
});
