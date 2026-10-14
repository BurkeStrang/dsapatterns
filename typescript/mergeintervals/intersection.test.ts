import { describe, expect, test } from "vitest";

import { intersectingIntervals } from "./intersection.ts";
import { intervals } from "./shared.ts";

describe("intersectingIntervals", () => {
  test.each([
    {
      name: "Example 1",
      arr1: intervals([
        [1, 3],
        [5, 6],
        [7, 9],
      ]),
      arr2: intervals([
        [2, 3],
        [5, 7],
      ]),
      want: intervals([
        [2, 3],
        [5, 6],
        [7, 7],
      ]),
    },
    {
      name: "Example 2",
      arr1: intervals([
        [1, 3],
        [5, 7],
        [9, 12],
      ]),
      arr2: intervals([[5, 10]]),
      want: intervals([
        [5, 7],
        [9, 10],
      ]),
    },
  ])("$name", ({ arr1, arr2, want }) => {
    expect(intersectingIntervals(arr1, arr2)).toEqual(want);
  });
});
