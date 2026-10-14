import { describe, expect, test } from "vitest";

import { findEmployeeFreeTime } from "./employeefreetime.ts";
import { intervals } from "./shared.ts";

describe("findEmployeeFreeTime", () => {
  test.each([
    {
      name: "Example 1: two employees, one free interval",
      schedule: [
        intervals([
          [1, 3],
          [5, 6],
        ]),
        intervals([
          [2, 3],
          [6, 8],
        ]),
      ],
      want: intervals([[3, 5]]),
    },
    {
      name: "Example 2: three employees, two free intervals",
      schedule: [
        intervals([
          [1, 3],
          [9, 12],
        ]),
        intervals([[2, 4]]),
        intervals([[6, 8]]),
      ],
      want: intervals([
        [4, 6],
        [8, 9],
      ]),
    },
    {
      name: "Example 3: three employees, one free interval",
      schedule: [
        intervals([[1, 3]]),
        intervals([[2, 4]]),
        intervals([
          [3, 5],
          [7, 9],
        ]),
      ],
      want: intervals([[5, 7]]),
    },
  ])("$name", ({ schedule, want }) => {
    expect(findEmployeeFreeTime(schedule)).toEqual(want);
  });
});
