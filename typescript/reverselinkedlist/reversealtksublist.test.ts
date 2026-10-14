import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { reverseAlt } from "./reversealtksublist.ts";

describe("reverseAlt", () => {
  test.each([
    {
      name: "reverse every alternate 2 nodes",
      head: [1, 2, 3, 4, 5, 6],
      k: 2,
      want: [2, 1, 3, 4, 6, 5],
    },
    {
      name: "reverse every alternate 3 nodes",
      head: [1, 2, 3, 4, 5, 6, 7],
      k: 3,
      want: [3, 2, 1, 4, 5, 6, 7],
    },
    { name: "k greater than length", head: [1, 2], k: 5, want: [2, 1] },
    { name: "single node", head: [1], k: 2, want: [1] },
    { name: "empty list", head: [], k: 2, want: [] },
  ])("$name", ({ head, k, want }) => {
    expect(listValues(reverseAlt(buildList(head), k))).toEqual(want);
  });
});
