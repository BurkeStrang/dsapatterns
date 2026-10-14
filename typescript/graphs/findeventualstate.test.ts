import { describe, expect, test } from "vitest";

import { eventualSafeNodes } from "./findeventualstate.ts";

describe("eventualSafeNodes", () => {
  test.each([
    {
      name: "Example 1: [3,4,5,6]",
      graph: [[1, 2], [2, 3], [2], [], [5], [6], []],
      want: [3, 4, 5, 6],
    },
    {
      name: "Example 2: [2,4,5,6]",
      graph: [[1, 2], [2, 3], [5], [0], [], [], [4]],
      want: [2, 4, 5, 6],
    },
    {
      name: "Example 3: [0,1,2,3,4]",
      graph: [[1, 2, 3], [2, 3], [3], [], [0, 1, 2]],
      want: [0, 1, 2, 3, 4],
    },
  ])("$name", ({ graph, want }) => {
    expect(eventualSafeNodes(graph)).toEqual(want);
  });
});
