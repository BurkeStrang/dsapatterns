import { describe, expect, test } from "vitest";

import { searchTriplets } from "./tripletessumzero.ts";

describe("searchTriplets", () => {
  test.each([
    {
      name: "Example 1",
      arr: [-3, 0, 1, 2, -1, 1, -2],
      want: [
        [-3, 1, 2],
        [-2, 0, 2],
        [-2, 1, 1],
        [-1, 0, 1],
      ],
    },
    {
      name: "Example 2",
      arr: [-5, 2, -1, -2, 3],
      want: [
        [-5, 2, 3],
        [-2, -1, 3],
      ],
    },
    { name: "No triplets", arr: [1, 2, 3], want: [] },
  ])("$name", ({ arr, want }) => {
    // the triplets may come back in any order
    const got = searchTriplets(arr);
    expect(got).toEqual(expect.arrayContaining(want));
    expect(got).toHaveLength(want.length);
  });
});
