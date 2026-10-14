import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { isPalindrome } from "./palindrome.ts";

describe("isPalindrome", () => {
  test.each([
    { name: "odd length palindrome", values: [2, 4, 6, 4, 2], want: true },
    { name: "not a palindrome", values: [2, 4, 6, 4, 2, 2], want: false },
    { name: "empty list", values: [], want: true },
    { name: "single node", values: [1], want: true },
  ])("$name", ({ values, want }) => {
    const head = buildList(values);
    expect(isPalindrome(head)).toBe(want);
    // the list must be put back the way it was
    expect(listValues(head)).toEqual(values);
  });
});
