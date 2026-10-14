import { describe, expect, test } from "vitest";

import { findRange } from "./numberrange.ts";

describe("findRange", () => {
  test.each([
    { name: "example1", arr: [4, 6, 6, 6, 9], key: 6, want: [1, 3] },
    { name: "example2", arr: [1, 3, 8, 10, 15], key: 10, want: [3, 3] },
    { name: "example3", arr: [1, 3, 8, 10, 15], key: 12, want: [-1, -1] },
  ])("$name", ({ arr, key, want }) => {
    expect(findRange(arr, key)).toEqual(want);
  });
});
