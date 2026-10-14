import { describe, expect, test } from "vitest";

import { compare } from "./comparingstringsbackslash.ts";

describe("compare", () => {
  test.each([
    { name: "Example 1", str1: "xy#z", str2: "xzz#", want: true },
    { name: "Example 2", str1: "xy#z", str2: "xyz#", want: false },
    { name: "Example 3", str1: "xp#", str2: "xyz##", want: true },
    { name: "Example 4", str1: "xywrrmp", str2: "xywrrmu#p", want: true },
  ])("$name", ({ str1, str2, want }) => {
    expect(compare(str1, str2)).toBe(want);
  });
});
