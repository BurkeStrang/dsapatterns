import { describe, expect, test } from "vitest";

import { isSchedulingPossible } from "./taskschedueling.ts";

describe("isSchedulingPossible", () => {
  test.each<{
    name: string;
    tasks: number;
    prerequisites: [number, number][];
    want: boolean;
  }>([
    {
      name: "Test Case 1",
      tasks: 3,
      prerequisites: [
        [0, 1],
        [1, 2],
      ],
      want: true,
    },
    {
      name: "Test Case 2",
      tasks: 3,
      prerequisites: [
        [0, 1],
        [1, 2],
        [2, 0],
      ],
      want: false,
    },
    {
      name: "Test Case 3",
      tasks: 4,
      prerequisites: [
        [0, 1],
        [1, 2],
        [2, 3],
      ],
      want: true,
    },
  ])("$name", ({ tasks, prerequisites, want }) => {
    expect(isSchedulingPossible(tasks, prerequisites)).toBe(want);
  });
});
