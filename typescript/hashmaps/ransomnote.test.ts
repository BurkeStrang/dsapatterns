import { describe, expect, test } from "vitest";

import { canConstruct } from "./ransomnote.ts";

describe("canConstruct", () => {
  test.each([
    {
      name: "can construct hello from hellworld",
      ransomNote: "hello",
      magazine: "hellworld",
      want: true,
    },
    {
      name: "can construct notes from stoned",
      ransomNote: "notes",
      magazine: "stoned",
      want: true,
    },
    {
      name: "cannot construct apple from pale",
      ransomNote: "apple",
      magazine: "pale",
      want: false,
    },
    { name: "exact match", ransomNote: "abc", magazine: "abc", want: true },
    {
      name: "not enough letters",
      ransomNote: "aabb",
      magazine: "ab",
      want: false,
    },
    {
      name: "empty ransom note",
      ransomNote: "",
      magazine: "anything",
      want: true,
    },
    { name: "empty magazine", ransomNote: "a", magazine: "", want: false },
  ])("$name", ({ ransomNote, magazine, want }) => {
    expect(canConstruct(ransomNote, magazine)).toBe(want);
  });
});
