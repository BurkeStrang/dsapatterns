import { describe, expect, test } from "vitest";

import { searchNextLetter } from "./nextletter.ts";

const LETTERS = ["a", "c", "f", "h"];

describe("searchNextLetter", () => {
  test.each([
    { name: "key in middle of array", letters: LETTERS, key: "f", want: "h" },
    { name: "key before first element", letters: LETTERS, key: "b", want: "c" },
    { name: "key is smallest element", letters: LETTERS, key: "a", want: "c" },
    {
      name: "key is largest element - wraps around",
      letters: LETTERS,
      key: "h",
      want: "a",
    },
    {
      name: "key larger than all - wraps around",
      letters: LETTERS,
      key: "z",
      want: "a",
    },
    {
      name: "key smaller than all elements",
      letters: ["c", "f", "j"],
      key: "a",
      want: "c",
    },
    {
      name: "key between two adjacent elements",
      letters: LETTERS,
      key: "g",
      want: "h",
    },
    {
      name: "single element - wraps around",
      letters: ["m"],
      key: "m",
      want: "m",
    },
  ])("$name", ({ letters, key, want }) => {
    expect(searchNextLetter(letters, key)).toBe(want);
  });
});
