import { describe, expect, test } from "vitest";

import { minimumEffortPath } from "./pathmineffort.ts";

describe("minimumEffortPath", () => {
  test.each([
    {
      name: "Example 1",
      heights: [
        [1, 2, 3],
        [3, 8, 4],
        [5, 3, 5],
      ],
      want: 1,
    },
    {
      name: "Example 2",
      heights: [
        [1, 2, 2],
        [3, 3, 3],
        [5, 3, 1],
      ],
      want: 2,
    },
    {
      name: "Example 3",
      heights: [
        [1, 1, 1],
        [1, 1, 1],
        [1, 1, 1],
      ],
      want: 0,
    },
    { name: "One cell", heights: [[7]], want: 0 },
  ])("$name", ({ heights, want }) => {
    expect(minimumEffortPath(heights)).toBe(want);
  });
});
