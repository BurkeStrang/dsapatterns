import { describe, expect, test } from "vitest";

import { countTrees } from "./countbst.ts";

describe("countTrees", () => {
  test.each([
    { name: "Example 1", n: 2, want: 2 },
    { name: "Example 2", n: 3, want: 5 },
  ])("$name", ({ n, want }) => {
    expect(countTrees(n)).toBe(want);
  });
});
