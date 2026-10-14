import { describe, expect, test } from "vitest";

import { ArrayReader, searchInfiniteSortedArray } from "./infinitearray.ts";

const EVENS = Array.from({ length: 14 }, (_, i) => 4 + 2 * i); // 4, 6, ..., 30

describe("searchInfiniteSortedArray", () => {
  test.each([
    { name: "Example 1", arr: EVENS, key: 16, want: 6 },
    { name: "Example 2", arr: EVENS, key: 11, want: -1 },
    { name: "Example 3", arr: [1, 3, 8, 10, 15], key: 15, want: 4 },
  ])("$name", ({ arr, key, want }) => {
    expect(searchInfiniteSortedArray(new ArrayReader(arr), key)).toBe(want);
  });
});
