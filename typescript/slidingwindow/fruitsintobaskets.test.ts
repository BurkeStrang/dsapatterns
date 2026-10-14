import { describe, expect, test } from "vitest";

import { maxFruit } from "./fruitsintobaskets.ts";

describe("maxFruit", () => {
  test.each([
    { name: "basic example", arr: ["A", "B", "C", "A", "C"], want: 3 },
    { name: "all same fruit", arr: ["A", "A", "A", "A"], want: 4 },
    {
      name: "two types alternating",
      arr: ["A", "B", "A", "B", "A", "B"],
      want: 6,
    },
    { name: "three types", arr: ["A", "B", "C", "B", "B", "C", "A"], want: 5 },
  ])("$name", ({ arr, want }) => {
    expect(maxFruit(arr)).toBe(want);
  });
});
