import { describe, expect, test } from "vitest";

import { sortStack } from "./sortingstack.ts";

describe("sortStack", () => {
  // the stacks are written with the bottom element first and the top last
  test.each([
    {
      name: "Example 1",
      input: [34, 3, 31, 98, 92, 23],
      want: [3, 23, 31, 34, 92, 98],
    },
    {
      name: "Example 2",
      input: [4, 3, 2, 10, 12, 1, 5, 6],
      want: [1, 2, 3, 4, 5, 6, 10, 12],
    },
    { name: "Example 3", input: [20, 10, -5, -1], want: [-5, -1, 10, 20] },
  ])("$name", ({ input, want }) => {
    expect(sortStack(input)).toEqual(want);
  });
});
