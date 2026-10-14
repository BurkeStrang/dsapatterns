import { describe, expect, test } from "vitest";

import { factors } from "./numfactors.ts";

describe("factors", () => {
  test.each([
    { name: "Example 1", n: 4, want: 4 },
    { name: "Example 2", n: 5, want: 6 },
  ])("$name", ({ n, want }) => {
    expect(factors(n)).toBe(want);
  });
});
