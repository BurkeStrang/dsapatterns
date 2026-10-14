import { describe, expect, test } from "vitest";

import { searchQuadruplets } from "./quadruplesumtotarget.ts";

describe("searchQuadruplets", () => {
  test.each([
    {
      name: "Example 1",
      arr: [4, 1, 2, -1, 1, -3],
      target: 1,
      want: [
        [-3, -1, 1, 4],
        [-3, 1, 1, 2],
      ],
    },
    {
      name: "Example 2",
      arr: [2, 0, -1, 1, -2, 2],
      target: 2,
      want: [
        [-2, 0, 2, 2],
        [-1, 0, 1, 2],
      ],
    },
  ])("$name", ({ arr, target, want }) => {
    // the quadruplets may come back in any order
    const got = searchQuadruplets(arr, target);
    expect(got).toEqual(expect.arrayContaining(want));
    expect(got).toHaveLength(want.length);
  });
});
