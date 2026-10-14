import { describe, expect, test } from "vitest";

import { findMinimumMeetingRooms } from "./minmeetingrooms.ts";
import { intervals } from "./shared.ts";

describe("findMinimumMeetingRooms", () => {
  // a meeting has a start and an end, like an interval
  test.each([
    {
      name: "Example 1: overlapping meetings",
      meetings: intervals([
        [1, 4],
        [2, 5],
        [7, 9],
      ]),
      want: 2,
    },
    {
      name: "Example 2: non-overlapping meetings",
      meetings: intervals([
        [6, 7],
        [2, 4],
        [8, 12],
      ]),
      want: 1,
    },
    {
      name: "Example 3: overlapping meetings",
      meetings: intervals([
        [1, 4],
        [2, 3],
        [3, 6],
      ]),
      want: 2,
    },
    {
      name: "Example 4: complex overlaps",
      meetings: intervals([
        [4, 5],
        [2, 3],
        [2, 4],
        [3, 5],
      ]),
      want: 2,
    },
  ])("$name", ({ meetings, want }) => {
    expect(findMinimumMeetingRooms(meetings)).toBe(want);
  });
});
