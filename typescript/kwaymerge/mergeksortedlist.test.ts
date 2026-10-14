import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { merge } from "./mergeksortedlist.ts";

describe("merge", () => {
  test.each([
    {
      name: "Example 1",
      lists: [
        [2, 6, 8],
        [3, 6, 7],
        [1, 3, 4],
      ],
      want: [1, 2, 3, 3, 4, 6, 6, 7, 8],
    },
    {
      name: "Example 2",
      lists: [
        [5, 8, 9],
        [1, 7],
      ],
      want: [1, 5, 7, 8, 9],
    },
    { name: "An empty list among them", lists: [[], [1]], want: [1] },
  ])("$name", ({ lists, want }) => {
    expect(listValues(merge(lists.map(buildList)))).toEqual(want);
  });
});
