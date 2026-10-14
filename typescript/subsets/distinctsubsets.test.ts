import { describe, expect, test } from "vitest";

import { findSubsets } from "./distinctsubsets.ts";
import { sortedSubsets } from "./shared.ts";

describe("findSubsets", () => {
  test.each([
    {
      name: "example test case 1",
      nums: [1, 3],
      want: [[], [1], [3], [1, 3]],
    },
    {
      name: "example test case 2",
      nums: [1, 2, 3],
      want: [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]],
    },
  ])("$name", ({ nums, want }) => {
    expect(sortedSubsets(findSubsets(nums))).toEqual(sortedSubsets(want));
  });
});
