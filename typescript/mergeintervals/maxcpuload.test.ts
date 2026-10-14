import { describe, expect, test } from "vitest";

import { findMaxCpuLoad, type Job } from "./maxcpuload.ts";

// jobs turns [start, end, cpu load] triples into jobs.
function jobs(rows: [number, number, number][]): Job[] {
  return rows.map(([start, end, cpuLoad]) => ({ start, end, cpuLoad }));
}

describe("findMaxCpuLoad", () => {
  test.each([
    {
      name: "Example 1: overlapping jobs",
      input: jobs([
        [1, 4, 3],
        [2, 5, 4],
        [7, 9, 6],
      ]),
      want: 7,
    },
    {
      name: "Example 2: non-overlapping jobs",
      input: jobs([
        [6, 7, 10],
        [2, 4, 11],
        [8, 12, 15],
      ]),
      want: 15,
    },
    {
      name: "Example 3: all overlap",
      input: jobs([
        [1, 4, 2],
        [2, 4, 1],
        [3, 6, 5],
      ]),
      want: 8,
    },
  ])("$name", ({ input, want }) => {
    expect(findMaxCpuLoad(input)).toBe(want);
  });
});
