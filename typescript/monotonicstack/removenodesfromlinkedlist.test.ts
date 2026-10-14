import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { removeNodes } from "./removenodesfromlinkedlist.ts";

describe("removeNodes", () => {
  test.each([
    { name: "Example 1", head: [5, 3, 7, 4, 2, 1], want: [7, 4, 2, 1] },
    { name: "Example 2", head: [1, 2, 3, 4, 5], want: [5] },
    { name: "Example 3", head: [5, 4, 3, 2, 1], want: [5, 4, 3, 2, 1] },
    { name: "Empty list", head: [], want: [] },
  ])("$name", ({ head, want }) => {
    expect(listValues(removeNodes(buildList(head)))).toEqual(want);
  });
});
