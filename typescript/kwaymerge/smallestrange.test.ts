import { describe, expect, test } from "vitest";

import { findSmallestRange } from "./smallestrange.ts";

describe("findSmallestRange", () => {
  test.each([
    {
      name: "Example 1",
      lists: [
        [1, 5, 8],
        [4, 12],
        [7, 8, 10],
      ],
      want: [4, 7],
    },
    {
      name: "Example 2",
      lists: [
        [1, 9],
        [4, 12],
        [7, 10, 16],
      ],
      want: [9, 12],
    },
  ])("$name", ({ lists, want }) => {
    expect(findSmallestRange(lists)).toEqual(want);
  });
});
