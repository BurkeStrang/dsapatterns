import { describe, expect, test } from "vitest";

import { findAverages } from "./avg.ts";

describe("findAverages", () => {
  test.each([
    {
      name: "basic case",
      k: 5,
      arr: [1, 3, 2, 6, -1, 4, 1, 8, 2],
      want: [2.2, 2.8, 2.4, 3.6, 2.8],
    },
    { name: "window size 1", k: 1, arr: [5, 10, 15], want: [5.0, 10.0, 15.0] },
    {
      name: "window size equals array length",
      k: 4,
      arr: [2, 4, 6, 8],
      want: [5.0],
    },
  ])("$name", ({ k, arr, want }) => {
    const got = findAverages(k, arr);
    expect(got).toHaveLength(want.length);
    got.forEach((value, i) => {
      expect(value).toBeCloseTo(want[i], 9);
    });
  });
});
