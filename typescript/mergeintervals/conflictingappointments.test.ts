import { describe, expect, test } from "vitest";

import { canAttendAllAppointments } from "./conflictingappointments.ts";
import { intervals } from "./shared.ts";

describe("canAttendAllAppointments", () => {
  test.each([
    {
      name: "Example 1: overlapping intervals",
      input: intervals([
        [1, 4],
        [2, 5],
        [7, 9],
      ]),
      want: false,
    },
    {
      name: "Example 2: non-overlapping intervals",
      input: intervals([
        [6, 7],
        [2, 4],
        [13, 14],
        [8, 12],
        [45, 47],
      ]),
      want: true,
    },
    {
      name: "Example 3: overlapping intervals",
      input: intervals([
        [4, 5],
        [2, 3],
        [3, 6],
      ]),
      want: false,
    },
  ])("$name", ({ input, want }) => {
    expect(canAttendAllAppointments(input)).toBe(want);
  });
});
