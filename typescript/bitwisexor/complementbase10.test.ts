import { describe, expect, test } from "vitest";

import { bitwiseComplement } from "./complementbase10.ts";

describe("bitwiseComplement", () => {
  test.each([
    // number: 5 (binary 101) -> complement: 2 (binary 010)
    { name: "Example 1", num: 5, want: 2 },
    // number: 7 (binary 111) -> complement: 0 (binary 000)
    { name: "Example 2", num: 7, want: 0 },
    // number: 10 (binary 1010) -> complement: 5 (binary 0101)
    { name: "Example 3", num: 10, want: 5 },
  ])("$name", ({ num, want }) => {
    expect(bitwiseComplement(num)).toBe(want);
  });
});
