import { describe, expect, test } from "vitest";

import { findNextInterval, type Interval } from "./nextinterval.ts";

// intervals turns [start, end] pairs into intervals.
function intervals(pairs: [number, number][]): Interval[] {
  return pairs.map(([start, end]) => ({ start, end }));
}

describe("findNextInterval", () => {
  test.each([
    {
      name: "basic non-overlapping",
      input: intervals([
        [2, 3],
        [3, 4],
        [5, 6],
      ]),
      want: [1, 2, -1],
    },
    {
      name: "overlapping intervals",
      input: intervals([
        [3, 4],
        [1, 5],
        [4, 6],
      ]),
      want: [2, -1, -1],
    },
    { name: "single interval", input: intervals([[1, 2]]), want: [-1] },
    {
      name: "self as next interval",
      input: intervals([
        [1, 1],
        [3, 4],
      ]),
      want: [0, -1],
    },
    {
      name: "no next interval for identical",
      input: intervals([
        [1, 2],
        [1, 2],
        [1, 2],
      ]),
      want: [-1, -1, -1],
    },
    {
      name: "start equals end",
      input: intervals([
        [1, 2],
        [2, 3],
        [3, 4],
      ]),
      want: [1, 2, -1],
    },
  ])("$name", ({ input, want }) => {
    expect(findNextInterval(input)).toEqual(want);
  });
});
