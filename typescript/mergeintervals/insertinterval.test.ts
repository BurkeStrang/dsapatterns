import { describe, expect, test } from "vitest";

import { insert } from "./insertinterval.ts";
import { intervals } from "./shared.ts";

describe("insert", () => {
  test.each([
    {
      name: "Example 1",
      input: intervals([
        [1, 3],
        [5, 7],
        [8, 12],
      ]),
      newInterval: { start: 4, end: 6 },
      want: intervals([
        [1, 3],
        [4, 7],
        [8, 12],
      ]),
    },
    {
      name: "Example 2",
      input: intervals([
        [1, 3],
        [5, 7],
        [8, 12],
      ]),
      newInterval: { start: 4, end: 10 },
      want: intervals([
        [1, 3],
        [4, 12],
      ]),
    },
    {
      name: "Example 3",
      input: intervals([
        [2, 3],
        [5, 7],
      ]),
      newInterval: { start: 1, end: 4 },
      want: intervals([
        [1, 4],
        [5, 7],
      ]),
    },
  ])("$name", ({ input, newInterval, want }) => {
    expect(insert(input, newInterval)).toEqual(want);
  });
});
