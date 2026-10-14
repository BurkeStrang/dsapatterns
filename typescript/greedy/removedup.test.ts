import { describe, expect, test } from "vitest";

import { removeDuplicateLetters } from "./removedup.ts";

describe("removeDuplicateLetters", () => {
  test.each([
    { name: "Example 1", s: "babac", want: "abc" },
    { name: "Example 2", s: "zabccde", want: "zabcde" },
    { name: "Example 3", s: "mnopmn", want: "mnop" },
  ])("$name", ({ s, want }) => {
    expect(removeDuplicateLetters(s)).toBe(want);
  });
});
