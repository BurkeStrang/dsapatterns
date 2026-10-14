import { describe, expect, test } from "vitest";

import { merge } from "./mergeintervals.ts";
import { intervals } from "./shared.ts";

describe("merge", () => {
  test.each([
    {
      name: "Example 1",
      input: intervals([
        [1, 4],
        [2, 5],
        [7, 9],
      ]),
      want: intervals([
        [1, 5],
        [7, 9],
      ]),
    },
    {
      name: "Example 2",
      input: intervals([
        [6, 7],
        [2, 4],
        [5, 9],
      ]),
      want: intervals([
        [2, 4],
        [5, 9],
      ]),
    },
    {
      name: "Example 3",
      input: intervals([
        [1, 4],
        [2, 6],
        [3, 5],
      ]),
      want: intervals([[1, 6]]),
    },
    {
      name: "No overlap",
      input: intervals([
        [1, 2],
        [3, 4],
        [5, 6],
      ]),
      want: intervals([
        [1, 2],
        [3, 4],
        [5, 6],
      ]),
    },
    {
      name: "Single interval",
      input: intervals([[1, 10]]),
      want: intervals([[1, 10]]),
    },
  ])("$name", ({ input, want }) => {
    expect(merge(input)).toEqual(want);
  });
});
