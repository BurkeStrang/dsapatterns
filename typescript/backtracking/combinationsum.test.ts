import { describe, expect, test } from "vitest";

import { combinationSum } from "./combinationsum.ts";

describe("combinationSum", () => {
  test.each([
    {
      name: "test1",
      candidates: [2, 3, 6, 7],
      target: 7,
      want: [[2, 2, 3], [7]],
    },
    {
      name: "test2",
      candidates: [2, 4, 6, 8],
      target: 10,
      want: [
        [2, 2, 2, 2, 2],
        [2, 2, 2, 4],
        [2, 2, 6],
        [2, 4, 4],
        [2, 8],
        [4, 6],
      ],
    },
    { name: "test3", candidates: [2], target: 1, want: [] },
  ])("$name", ({ candidates, target, want }) => {
    expect(combinationSum(candidates, target)).toEqual(want);
  });
});
