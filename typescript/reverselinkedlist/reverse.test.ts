import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { reverse } from "./reverse.ts";

describe("reverse", () => {
  test.each([
    { name: "multiple nodes", head: [1, 2, 3], want: [3, 2, 1] },
    { name: "single node", head: [1], want: [1] },
    { name: "empty list", head: [], want: [] },
  ])("$name", ({ head, want }) => {
    expect(listValues(reverse(buildList(head)))).toEqual(want);
  });
});
