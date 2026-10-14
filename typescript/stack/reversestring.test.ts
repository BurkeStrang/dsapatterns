import { describe, expect, test } from "vitest";

import { reverseString } from "./reversestring.ts";

describe("reverseString", () => {
  test.each([
    { name: "Example 1", input: "Hello, World!", want: "!dlroW ,olleH" },
    { name: "Example 2", input: "OpenAI", want: "IAnepO" },
    { name: "Example 3", input: "Stacks are fun!", want: "!nuf era skcatS" },
  ])("$name", ({ input, want }) => {
    expect(reverseString(input)).toBe(want);
  });
});
