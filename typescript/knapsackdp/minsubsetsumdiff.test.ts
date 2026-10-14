import { describe, expect, test } from "vitest";

import { canPartitionMin } from "./minsubsetsumdiff.ts";

describe("canPartitionMin", () => {
  test.each([
    { name: "Example 1", num: [1, 2, 3, 9], want: 3 },
    { name: "Example 2", num: [1, 2, 7, 1, 5], want: 0 },
    { name: "Example 3", num: [1, 3, 100, 4], want: 92 },
  ])("$name", ({ num, want }) => {
    expect(canPartitionMin(num)).toBe(want);
  });
});
