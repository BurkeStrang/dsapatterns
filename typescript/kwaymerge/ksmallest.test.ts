import { describe, expect, test } from "vitest";

import { findKthSmallest } from "./ksmallest.ts";

describe("findKthSmallest", () => {
  test.each([
    {
      name: "Example 1",
      lists: [
        [2, 6, 8],
        [3, 6, 7],
        [1, 3, 4],
      ],
      k: 5,
      want: 4,
    },
    {
      name: "Example 2",
      lists: [
        [5, 8, 9],
        [1, 7],
      ],
      k: 3,
      want: 7,
    },
  ])("$name", ({ lists, k, want }) => {
    expect(findKthSmallest(lists, k)).toBe(want);
  });
});
