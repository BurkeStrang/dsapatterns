import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { reverseSub } from "./reversesublist.ts";

describe("reverseSub", () => {
  test.each([
    {
      name: "reverse middle sublist",
      head: [1, 2, 3, 4, 5],
      p: 2,
      q: 4,
      want: [1, 4, 3, 2, 5],
    },
    {
      name: "reverse entire list",
      head: [1, 2, 3],
      p: 1,
      q: 3,
      want: [3, 2, 1],
    },
    {
      name: "reverse single node (no change)",
      head: [1, 2],
      p: 2,
      q: 2,
      want: [1, 2],
    },
    { name: "reverse head only", head: [1, 2], p: 1, q: 1, want: [1, 2] },
    { name: "reverse first two", head: [1, 2, 3], p: 1, q: 2, want: [2, 1, 3] },
    { name: "reverse last two", head: [1, 2, 3], p: 2, q: 3, want: [1, 3, 2] },
    { name: "empty list", head: [], p: 1, q: 1, want: [] },
  ])("$name", ({ head, p, q, want }) => {
    expect(listValues(reverseSub(buildList(head), p, q))).toEqual(want);
  });
});
