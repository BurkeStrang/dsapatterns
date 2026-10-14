import { describe, expect, test } from "vitest";

import { rearrangeString } from "./rearrangestring.ts";

describe("rearrangeString", () => {
  test.each([
    { name: "Example 1", s: "aappp", want: "papap" },
    { name: "Example 2", s: "Programming", want: "gmrPagimnor" },
    { name: "Example 3", s: "aapa", want: "" },
    { name: "Single character", s: "a", want: "a" },
  ])("$name", ({ s, want }) => {
    expect(rearrangeString(s)).toBe(want);
  });
});
