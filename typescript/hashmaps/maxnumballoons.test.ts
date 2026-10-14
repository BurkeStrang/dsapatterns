import { describe, expect, test } from "vitest";

import { maxNumberOfBalloons } from "./maxnumballoons.ts";

describe("maxNumberOfBalloons", () => {
  test.each([
    { name: "Example 1", text: "balloonballoon", want: 2 },
    { name: "Example 2", text: "bbaall", want: 0 },
    { name: "Example 3", text: "balloonballoooon", want: 2 },
  ])("$name", ({ text, want }) => {
    expect(maxNumberOfBalloons(text)).toBe(want);
  });
});
