import { describe, expect, test } from "vitest";

import { findProvinces } from "./numberofprovinces.ts";

describe("findProvinces", () => {
  test.each([
    {
      name: "Example 1",
      isConnected: [
        [1, 1, 0],
        [1, 1, 0],
        [0, 0, 1],
      ],
      want: 2,
    },
    {
      name: "Example 2",
      isConnected: [
        [1, 0, 0],
        [0, 1, 0],
        [0, 0, 1],
      ],
      want: 3,
    },
    {
      name: "Example 3",
      isConnected: [
        [1, 0, 0, 1],
        [0, 1, 1, 0],
        [0, 1, 1, 0],
        [1, 0, 0, 1],
      ],
      want: 2,
    },
  ])("$name", ({ isConnected, want }) => {
    expect(findProvinces(isConnected)).toBe(want);
  });
});
