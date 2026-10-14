import { describe, expect, test } from "vitest";

import { buildList } from "../common/list.ts";
import { findMiddle } from "./findmiddle.ts";

describe("findMiddle", () => {
  // want is the value of the middle node
  test.each([
    { name: "odd length list", head: [1, 2, 3, 4, 5], want: 3 },
    { name: "even length list", head: [1, 2, 3, 4], want: 3 },
    { name: "single node", head: [1], want: 1 },
    { name: "two nodes", head: [1, 2], want: 2 },
    { name: "empty list", head: [], want: null },
  ])("$name", ({ head, want }) => {
    expect(findMiddle(buildList(head))?.value ?? null).toBe(want);
  });
});
