import { describe, expect, test } from "vitest";

import { removeDuplicatesII } from "./removeadjactentdupsii.ts";

describe("removeDuplicatesII", () => {
  test.each([
    { name: "remove bbb then aaa", s: "abbbaaca", k: 3, want: "ca" },
    { name: "no removal possible", s: "abbaccaa", k: 3, want: "abbaccaa" },
    { name: "remove ccc then aaa", s: "abbacccaa", k: 3, want: "abb" },
    { name: "all removed", s: "aaa", k: 3, want: "" },
    { name: "single char, k=2", s: "a", k: 2, want: "a" },
    { name: "multiple removals", s: "deeedbbcccbdaa", k: 3, want: "aa" },
  ])("$name", ({ s, k, want }) => {
    expect(removeDuplicatesII(s, k)).toBe(want);
  });
});
