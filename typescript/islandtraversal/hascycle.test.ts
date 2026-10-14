import { describe, expect, test } from "vitest";

import { hasCycle } from "./hascycle.ts";

describe("hasCycle", () => {
  // each row is written as a string, one letter per cell
  test.each([
    { name: "no cycle", rows: ["ABC", "DEF", "GHI"], want: false },
    { name: "simple cycle", rows: ["AAA", "ABA", "AAA"], want: true },
  ])("$name", ({ rows, want }) => {
    const matrix = rows.map((row) => Array.from(row));
    expect(hasCycle(matrix)).toBe(want);
  });
});
