import { describe, expect, test } from "vitest";

import { dailyTemperatures } from "./dailytemp.ts";

describe("dailyTemperatures", () => {
  test.each([
    {
      name: "Example 1",
      temperatures: [70, 73, 75, 71, 69, 72, 76, 73],
      want: [1, 1, 4, 2, 1, 1, 0, 0],
    },
    { name: "Example 2", temperatures: [73, 72, 71, 70], want: [0, 0, 0, 0] },
    { name: "Example 3", temperatures: [70, 71, 72, 73], want: [1, 1, 1, 0] },
    { name: "All same", temperatures: [60, 60, 60], want: [0, 0, 0] },
    { name: "Single element", temperatures: [80], want: [0] },
  ])("$name", ({ temperatures, want }) => {
    expect(dailyTemperatures(temperatures)).toEqual(want);
  });
});
