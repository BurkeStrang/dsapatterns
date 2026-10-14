import { describe, expect, test } from "vitest";

import { findMaximumCapital } from "./maxcapital.ts";

describe("findMaximumCapital", () => {
  test.each([
    {
      name: "basic example",
      capital: [0, 1, 2],
      profits: [1, 2, 3],
      numberOfProjects: 2,
      initialCapital: 1,
      want: 6,
    },
    {
      name: "not enough capital for any project",
      capital: [5, 10, 15],
      profits: [1, 2, 3],
      numberOfProjects: 3,
      initialCapital: 0,
      want: 0,
    },
    {
      name: "all projects affordable from start",
      capital: [0, 0, 0],
      profits: [1, 2, 3],
      numberOfProjects: 2,
      initialCapital: 0,
      want: 5,
    },
    {
      name: "single project",
      capital: [0],
      profits: [5],
      numberOfProjects: 1,
      initialCapital: 0,
      want: 5,
    },
    {
      name: "chain of unlocking projects",
      capital: [0, 1, 2, 3],
      profits: [1, 1, 1, 1],
      numberOfProjects: 4,
      initialCapital: 0,
      want: 4,
    },
  ])(
    "$name",
    ({ capital, profits, numberOfProjects, initialCapital, want }) => {
      expect(
        findMaximumCapital(capital, profits, numberOfProjects, initialCapital),
      ).toBe(want);
    },
  );
});
