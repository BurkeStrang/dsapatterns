import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { reverseKSub } from "./reverseksublist.ts";

describe("reverseKSub", () => {
  test.each([
    {
      name: "reverse every 2 nodes",
      head: [1, 2, 3, 4, 5],
      k: 2,
      want: [2, 1, 4, 3, 5],
    },
    {
      name: "reverse every 3 nodes",
      head: [1, 2, 3, 4, 5],
      k: 3,
      want: [3, 2, 1, 5, 4],
    },
    { name: "k greater than length", head: [1, 2], k: 5, want: [2, 1] },
    { name: "single node", head: [1], k: 2, want: [1] },
    { name: "empty list", head: [], k: 2, want: [] },
  ])("$name", ({ head, k, want }) => {
    expect(listValues(reverseKSub(buildList(head), k))).toEqual(want);
  });
});
