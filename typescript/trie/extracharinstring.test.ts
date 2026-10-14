import { describe, expect, test } from "vitest";

import { minExtraChar } from "./extracharinstring.ts";

describe("minExtraChar", () => {
  test.each([
    {
      name: "Test Case 1",
      s: "amazingracecar",
      dictionary: ["race"],
      want: 10,
    },
    {
      name: "Test Case 2",
      s: "amazingracecar",
      dictionary: ["race", "car"],
      want: 7,
    },
    {
      name: "Test Case 3",
      s: "bookkeeperreading",
      dictionary: ["keep", "read"],
      want: 9,
    },
  ])("$name", ({ s, dictionary, want }) => {
    expect(minExtraChar(s, dictionary)).toBe(want);
  });
});
