import { describe, expect, test } from "vitest";

import { findLongestChain } from "./maxlengthpairchain.ts";

describe("findLongestChain", () => {
  test.each<{ name: string; pairs: [number, number][]; want: number }>([
    {
      name: "Example 1",
      pairs: [
        [1, 2],
        [3, 4],
        [2, 3],
      ],
      want: 2,
    },
    {
      name: "Example 2",
      pairs: [
        [5, 6],
        [1, 2],
        [8, 9],
        [2, 3],
      ],
      want: 3,
    },
    {
      name: "Example 3",
      pairs: [
        [7, 8],
        [5, 6],
        [1, 2],
        [3, 5],
        [4, 5],
        [2, 3],
      ],
      want: 3,
    },
  ])("$name", ({ pairs, want }) => {
    expect(findLongestChain(pairs)).toBe(want);
  });
});
