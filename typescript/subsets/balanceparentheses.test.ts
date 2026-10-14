import { describe, expect, test } from "vitest";

import { generateValidParentheses } from "./balanceparentheses.ts";

describe("generateValidParentheses", () => {
  test.each([
    { name: "example 1", num: 2, want: ["(())", "()()"] },
    {
      name: "example 2",
      num: 3,
      want: ["((()))", "(()())", "(())()", "()(())", "()()()"],
    },
  ])("$name", ({ num, want }) => {
    expect(generateValidParentheses(num)).toEqual(want);
  });
});
