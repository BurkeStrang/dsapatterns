import { describe, expect, test } from "vitest";

import { countMinJumps } from "./minjumps.ts";

describe("countMinJumps", () => {
  test.each([
    { name: "Example 1", jumps: [2, 1, 1, 1, 4], want: 3 },
    { name: "Example 2", jumps: [1, 1, 3, 6, 9, 3, 0, 1, 3], want: 4 },
    { name: "Blocked by a zero", jumps: [1, 0, 2], want: null },
    { name: "Single element", jumps: [0], want: 0 },
  ])("$name", ({ jumps, want }) => {
    expect(countMinJumps(jumps)).toBe(want);
  });
});
