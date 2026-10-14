import { describe, expect, test } from "vitest";

import { search } from "./pairwithtargetsum.ts";

describe("search", () => {
  test.each([
    { name: "Example 1", arr: [1, 2, 3, 4, 6], target: 6, want: [1, 3] },
    { name: "Example 2", arr: [2, 5, 9, 11], target: 11, want: [0, 2] },
    { name: "No pair", arr: [1, 2, 3, 4, 5], target: 10, want: null },
  ])("$name", ({ arr, target, want }) => {
    expect(search(arr, target)).toEqual(want);
  });
});
