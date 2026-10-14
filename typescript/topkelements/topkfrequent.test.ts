import { describe, expect, test } from "vitest";

import { findTopKFrequentNumbers } from "./topkfrequent.ts";

describe("findTopKFrequentNumbers", () => {
  // numbers with the same frequency may be picked in any order, so each case
  // lists every number that is allowed in the result
  test.each([
    {
      name: "Example 1",
      nums: [1, 3, 5, 12, 11, 12, 11],
      k: 2,
      valid: [11, 12],
    },
    {
      name: "Example 2",
      nums: [5, 12, 11, 3, 11],
      k: 2,
      valid: [11, 5, 12, 3],
    },
    {
      name: "Example 3",
      nums: [1, 1, 1, 3, 3, 3, 5, 5, 5, 12],
      k: 2,
      valid: [1, 3, 5],
    },
  ])("$name", ({ nums, k, valid }) => {
    const got = findTopKFrequentNumbers(nums, k);
    expect(got).toHaveLength(k);
    for (const v of got) {
      expect(valid).toContain(v);
    }
  });
});
