import { describe, expect, test } from "vitest";

import { searchTriplet } from "./tripletsumclosetotarget.ts";

describe("searchTriplet", () => {
  test.each([
    { name: "Example 1", arr: [-1, 0, 2, 3], target: 3, want: 2 },
    { name: "Example 2", arr: [-3, -1, 1, 2], target: 1, want: 0 },
    { name: "Example 3", arr: [1, 0, 1, 1], target: 100, want: 3 },
    { name: "Example 4", arr: [0, 0, 1, 1, 2, 6], target: 5, want: 4 },
  ])("$name", ({ arr, target, want }) => {
    expect(searchTriplet(arr, target)).toBe(want);
  });
});
