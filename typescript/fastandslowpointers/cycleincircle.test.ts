import { describe, expect, test } from "vitest";

import { loopExists } from "./cycleincircle.ts";

describe("loopExists", () => {
  test.each([
    { name: "Example 1", arr: [1, 2, -1, 2, 2], want: true },
    { name: "Example 2", arr: [2, 2, -1, 2], want: true },
    { name: "Example 3", arr: [2, 1, -1, -2], want: false },
    {
      name: "No cycle, alternating directions",
      arr: [1, -1, 1, -1],
      want: false,
    },
    { name: "Simple cycle", arr: [3, 1, 2], want: true },
  ])("$name", ({ arr, want }) => {
    expect(loopExists(arr)).toBe(want);
  });
});
