import { describe, expect, test } from "vitest";

import { solveKnapsack } from "./knapsack01.ts";

describe("solveKnapsack", () => {
  test.each([
    {
      name: "Example",
      profits: [4, 5, 3, 7],
      weights: [2, 3, 1, 4],
      capacity: 5,
      want: 10,
    },
    {
      name: "Second example",
      profits: [1, 6, 10, 16],
      weights: [1, 2, 3, 5],
      capacity: 7,
      want: 22,
    },
    {
      name: "Nothing fits",
      profits: [4, 5],
      weights: [3, 4],
      capacity: 2,
      want: 0,
    },
  ])("$name", ({ profits, weights, capacity, want }) => {
    expect(solveKnapsack(profits, weights, capacity)).toBe(want);
  });
});
