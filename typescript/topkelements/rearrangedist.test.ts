import { describe, expect, test } from "vitest";

import { reorganizeString } from "./rearrangedist.ts";

describe("reorganizeString", () => {
  test.each([
    { name: "Example 1", s: "mmpp", k: 2, want: "mpmp" },
    { name: "Example 2", s: "Programming", k: 3, want: "gmrPagimnor" },
    { name: "Example 3", s: "aab", k: 2, want: "aba" },
    { name: "Example 4: not possible", s: "aappa", k: 3, want: "" },
    { name: "k of 1 changes nothing", s: "aab", k: 1, want: "aab" },
  ])("$name", ({ s, k, want }) => {
    expect(reorganizeString(s, k)).toBe(want);
  });
});
