import { describe, expect, test } from "vitest";

import { diffWaysToEvaluateExpression } from "./diffwaystoevaluate.ts";

describe("diffWaysToEvaluateExpression", () => {
  test.each([
    { name: "parentheses addition", input: "2+3*2", want: [8, 10] },
    {
      name: "parentheses multiple",
      input: "2*4-3*5",
      want: [-22, 10, -7, 10, 25],
    },
  ])("$name", ({ input, want }) => {
    expect(diffWaysToEvaluateExpression(input)).toEqual(want);
  });
});
