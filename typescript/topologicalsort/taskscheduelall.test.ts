import { describe, expect, test } from "vitest";

import { printOrders } from "./taskscheduelall.ts";

describe("printOrders", () => {
  // want lists every valid ordering; they can come back in any order
  test.each<{
    name: string;
    tasks: number;
    prerequisites: [number, number][];
    want: number[][];
  }>([
    {
      name: "Example 1: two orderings",
      tasks: 4,
      prerequisites: [
        [3, 2],
        [3, 0],
        [2, 0],
        [2, 1],
      ],
      want: [
        [3, 2, 0, 1],
        [3, 2, 1, 0],
      ],
    },
    {
      name: "Example 2: one ordering",
      tasks: 3,
      prerequisites: [
        [0, 1],
        [1, 2],
      ],
      want: [[0, 1, 2]],
    },
    {
      name: "Example 3: thirteen orderings",
      tasks: 6,
      prerequisites: [
        [2, 5],
        [0, 5],
        [0, 4],
        [1, 4],
        [3, 2],
        [1, 3],
      ],
      want: [
        [0, 1, 4, 3, 2, 5],
        [0, 1, 3, 4, 2, 5],
        [0, 1, 3, 2, 4, 5],
        [0, 1, 3, 2, 5, 4],
        [1, 0, 3, 4, 2, 5],
        [1, 0, 3, 2, 4, 5],
        [1, 0, 3, 2, 5, 4],
        [1, 0, 4, 3, 2, 5],
        [1, 3, 0, 2, 4, 5],
        [1, 3, 0, 2, 5, 4],
        [1, 3, 0, 4, 2, 5],
        [1, 3, 2, 0, 5, 4],
        [1, 3, 2, 0, 4, 5],
      ],
    },
    {
      name: "No prerequisites: every arrangement",
      tasks: 3,
      prerequisites: [],
      want: [
        [0, 1, 2],
        [0, 2, 1],
        [1, 0, 2],
        [1, 2, 0],
        [2, 0, 1],
        [2, 1, 0],
      ],
    },
    {
      name: "Cyclic prerequisites: no ordering",
      tasks: 3,
      prerequisites: [
        [0, 1],
        [1, 2],
        [2, 0],
      ],
      want: [],
    },
    { name: "No tasks", tasks: 0, prerequisites: [], want: [] },
  ])("$name", ({ tasks, prerequisites, want }) => {
    const got = printOrders(tasks, prerequisites);
    expect(got).toEqual(expect.arrayContaining(want));
    expect(got).toHaveLength(want.length);
  });
});
