import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { rearangeList } from "./rearangelist.ts";

describe("rearangeList", () => {
  test.each([
    { name: "even length list", head: [1, 2, 3, 4], want: [1, 4, 2, 3] },
    { name: "odd length list", head: [1, 2, 3], want: [1, 3, 2] },
    { name: "single node", head: [1], want: [1] },
    { name: "empty list", head: [], want: [] },
  ])("$name", ({ head, want }) => {
    expect(listValues(rearangeList(buildList(head)))).toEqual(want);
  });
});
