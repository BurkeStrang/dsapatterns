import { describe, expect, test } from "vitest";

import { isHappy } from "./happynum.ts";

describe("isHappy", () => {
  test.each([
    { name: "Happy number 19", num: 19, want: true },
    { name: "Happy number 1", num: 1, want: true },
    { name: "Unhappy number 2", num: 2, want: false },
    { name: "Unhappy number 4", num: 4, want: false },
  ])("$name", ({ num, want }) => {
    expect(isHappy(num)).toBe(want);
  });
});
