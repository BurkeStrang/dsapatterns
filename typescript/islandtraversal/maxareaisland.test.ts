import { describe, expect, test } from "vitest";

import { maxAreaOfIsland } from "./maxareaisland.ts";

describe("maxAreaOfIsland", () => {
  test.each([
    {
      name: "two islands",
      matrix: [
        [0, 1, 0, 0],
        [1, 1, 0, 0],
        [0, 0, 1, 1],
        [0, 0, 1, 1],
      ],
      want: 4,
    },
    {
      name: "no island",
      matrix: [
        [0, 0, 0],
        [0, 0, 0],
      ],
      want: 0,
    },
    {
      name: "multiple islands",
      matrix: [
        [1, 0, 0, 1],
        [0, 1, 1, 0],
        [0, 0, 0, 1],
      ],
      want: 2,
    },
  ])("$name", ({ matrix, want }) => {
    expect(maxAreaOfIsland(matrix)).toBe(want);
  });
});
