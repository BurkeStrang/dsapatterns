import { describe, expect, test } from "vitest";

import { findSubarrays } from "./subslessthantarget.ts";

// sortLists puts a list of number lists in a fixed order, so that two lists
// holding the same lists in a different order compare equal.
function sortLists(lists: number[][]): number[][] {
  return [...lists].sort((a, b) => a.join(",").localeCompare(b.join(",")));
}

describe("findSubarrays", () => {
  test.each([
    {
      name: "Example 1",
      arr: [2, 5, 3, 10],
      target: 30,
      want: [[2], [2, 5], [5], [5, 3], [3], [10]],
    },
    {
      name: "Example 2",
      arr: [8, 2, 6, 5],
      target: 50,
      want: [[8], [8, 2], [2], [2, 6], [6], [6, 5], [5]],
    },
    { name: "Target 0", arr: [10, 5, 2, 6], target: 0, want: [] },
    { name: "Single element < target", arr: [1], target: 2, want: [[1]] },
    { name: "Single element >= target", arr: [5], target: 5, want: [] },
  ])("$name", ({ arr, target, want }) => {
    // the subarrays may come back in any order
    expect(sortLists(findSubarrays(arr, target))).toEqual(sortLists(want));
  });
});
