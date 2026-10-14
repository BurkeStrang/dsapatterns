import { describe, expect, test } from "vitest";

import { minimumCostToConnectRopes } from "./connectropes.ts";

describe("minimumCostToConnectRopes", () => {
  test.each([
    { name: "Example 1", ropeLengths: [1, 2, 3, 4, 5], want: 33 },
    { name: "Example 2", ropeLengths: [3, 4, 5, 6], want: 36 },
    { name: "Example 3", ropeLengths: [1, 3, 11, 5, 2], want: 42 },
  ])("$name", ({ ropeLengths, want }) => {
    expect(minimumCostToConnectRopes(ropeLengths)).toBe(want);
  });
});
