import { describe, expect, test } from "vitest";

import { getFactors } from "./factorcombinations.ts";

describe("getFactors", () => {
  test.each([
    {
      name: "Example 1",
      n: 8,
      want: [
        [2, 2, 2],
        [2, 4],
      ],
    },
    {
      name: "Example 2",
      n: 20,
      want: [
        [2, 2, 5],
        [2, 10],
        [4, 5],
      ],
    },
    { name: "A prime has none", n: 7, want: [] },
  ])("$name", ({ n, want }) => {
    // the combinations may come back in any order
    const got = getFactors(n);
    expect(got).toEqual(expect.arrayContaining(want));
    expect(got).toHaveLength(want.length);
  });
});
