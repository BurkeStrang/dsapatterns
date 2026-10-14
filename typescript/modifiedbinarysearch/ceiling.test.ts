import { describe, expect, test } from "vitest";

import { searchCeilingOfANumber } from "./ceiling.ts";

describe("searchCeilingOfANumber", () => {
  test.each([
    { name: "Example 1", arr: [4, 6, 10], key: 5, want: 1 },
    { name: "key exists in array", arr: [1, 3, 8, 10, 15], key: 8, want: 2 },
    {
      name: "key between two elements",
      arr: [1, 3, 8, 10, 15],
      key: 12,
      want: 4,
    },
    {
      name: "key smaller than all elements",
      arr: [1, 3, 8, 10, 15],
      key: 0,
      want: 0,
    },
    {
      name: "key larger than all elements",
      arr: [1, 3, 8, 10, 15],
      key: 20,
      want: -1,
    },
    {
      name: "key is smallest element",
      arr: [1, 3, 8, 10, 15],
      key: 1,
      want: 0,
    },
    {
      name: "key is largest element",
      arr: [1, 3, 8, 10, 15],
      key: 15,
      want: 4,
    },
    {
      name: "key just below a middle element",
      arr: [2, 4, 6, 8, 10],
      key: 5,
      want: 2,
    },
    { name: "single element - key matches", arr: [5], key: 5, want: 0 },
    { name: "single element - key is smaller", arr: [5], key: 3, want: 0 },
    { name: "single element - key is larger", arr: [5], key: 7, want: -1 },
  ])("$name", ({ arr, key, want }) => {
    expect(searchCeilingOfANumber(arr, key)).toBe(want);
  });
});
