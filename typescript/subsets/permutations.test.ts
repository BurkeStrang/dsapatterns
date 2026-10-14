import { describe, expect, test } from "vitest";

import { findPermutations } from "./permutations.ts";
import { compareLists } from "./shared.ts";

describe("findPermutations", () => {
  test.each([
    {
      name: "3 elements",
      nums: [1, 2, 3],
      want: [
        [1, 2, 3],
        [1, 3, 2],
        [2, 1, 3],
        [2, 3, 1],
        [3, 1, 2],
        [3, 2, 1],
      ],
    },
  ])("$name", ({ nums, want }) => {
    // the permutations may come back in any order
    expect(findPermutations(nums).sort(compareLists)).toEqual(want);
  });
});
