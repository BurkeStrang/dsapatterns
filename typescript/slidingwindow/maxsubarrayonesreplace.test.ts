import { describe, expect, test } from "vitest";

import { maxOnesLength } from "./maxsubarrayonesreplace.ts";

describe("maxOnesLength", () => {
  test.each([
    {
      name: "Example 1",
      arr: [0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1],
      k: 2,
      want: 6,
    },
    {
      name: "Example 2",
      arr: [0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1],
      k: 3,
      want: 9,
    },
    { name: "Example 3", arr: [1, 0, 0, 1, 1, 0, 1, 1], k: 2, want: 6 },
  ])("$name", ({ arr, k, want }) => {
    expect(maxOnesLength(arr, k)).toBe(want);
  });
});
