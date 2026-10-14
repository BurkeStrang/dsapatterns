import { describe, expect, test } from "vitest";

import { nextLargerElement } from "./nextgreaterelement.ts";

describe("nextLargerElement", () => {
  test.each([
    { name: "Example 1", arr: [4, 5, 2, 25], want: [5, 25, 25, -1] },
    { name: "Example 2", arr: [13, 7, 6, 12], want: [-1, 12, 12, -1] },
    { name: "Example 3", arr: [1, 2, 3, 4, 5], want: [2, 3, 4, 5, -1] },
  ])("$name", ({ arr, want }) => {
    expect(nextLargerElement(arr)).toEqual(want);
  });
});
