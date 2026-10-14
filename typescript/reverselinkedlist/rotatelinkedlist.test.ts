import { describe, expect, test } from "vitest";

import { buildList, listValues } from "../common/list.ts";
import { rotate } from "./rotatelinkedlist.ts";

describe("rotate", () => {
  test.each([
    {
      name: "rotate by 2",
      head: [1, 2, 3, 4, 5],
      rotations: 2,
      want: [4, 5, 1, 2, 3],
    },
    {
      name: "rotate by 0 (no change)",
      head: [1, 2, 3],
      rotations: 0,
      want: [1, 2, 3],
    },
    {
      name: "rotate by length (no change)",
      head: [1, 2, 3],
      rotations: 3,
      want: [1, 2, 3],
    },
    {
      name: "rotate by more than length",
      head: [1, 2, 3],
      rotations: 5,
      want: [2, 3, 1],
    },
    { name: "single node", head: [1], rotations: 1, want: [1] },
    { name: "empty list", head: [], rotations: 3, want: [] },
  ])("$name", ({ head, rotations, want }) => {
    expect(listValues(rotate(buildList(head), rotations))).toEqual(want);
  });
});
