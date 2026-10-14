import { describe, expect, test } from "vitest";

import { moveElements } from "./findnonduplicates.ts";

describe("moveElements", () => {
  test.each([
    { name: "Example 1", arr: [2, 3, 3, 3, 6, 9, 9], want: [2, 3, 6, 9] },
    { name: "Example 2", arr: [2, 2, 2, 11], want: [2, 11] },
    { name: "duplicate at the end", arr: [1, 2, 2], want: [1, 2] },
    {
      name: "many duplicates",
      arr: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
      want: [0, 1, 2, 3, 4],
    },
    { name: "single element", arr: [1], want: [1] },
    { name: "no duplicates", arr: [1, 2, 3], want: [1, 2, 3] },
  ])("$name", ({ arr, want }) => {
    const got = moveElements(arr);
    expect(arr.slice(0, got)).toEqual(want);
  });
});
