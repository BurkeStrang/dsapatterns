import { describe, expect, test } from "vitest";

import { removeDuplicates } from "./removeadjacentdups.ts";

describe("removeDuplicates", () => {
  test.each([
    { name: "empty string", s: "", want: "" },
    { name: "no duplicates", s: "abcd", want: "abcd" },
    { name: "all removed", s: "abccba", want: "" },
    { name: "simple pair", s: "aabb", want: "" },
    { name: "single removal", s: "foobar", want: "fbar" },
    { name: "triple duplicate", s: "fooobar", want: "fobar" },
    { name: "nested removals", s: "azxxzy", want: "ay" },
    { name: "single char", s: "a", want: "a" },
    { name: "all same", s: "aaaa", want: "" },
  ])("$name", ({ s, want }) => {
    expect(removeDuplicates(s)).toBe(want);
  });
});
