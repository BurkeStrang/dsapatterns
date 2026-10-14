import { describe, expect, test } from "vitest";

import { KthLargest } from "./kthlargestnuminstream.ts";

describe("KthLargest.add", () => {
  test.each([
    { name: "Example 1", nums: [3, 1, 5, 12, 2, 11], k: 4, num: 6, want: 5 },
    { name: "Example 2", nums: [3, 1, 5, 12, 2, 11], k: 4, num: 13, want: 5 },
    { name: "Example 3", nums: [3, 1, 5, 12, 2, 11], k: 4, num: 4, want: 4 },
  ])("$name", ({ nums, k, num, want }) => {
    expect(new KthLargest(nums, k).add(num)).toBe(want);
  });
});
