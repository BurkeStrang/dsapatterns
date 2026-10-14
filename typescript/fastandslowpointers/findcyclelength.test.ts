import { describe, expect, test } from "vitest";

import { buildNodes } from "../common/list.ts";
import { findCycleLength } from "./findcyclelength.ts";

describe("findCycleLength", () => {
  // cycleStart is the index the last node points back to, or null
  test.each([
    // cycle starts at the second node, length 3
    { name: "cycle of length 3", values: [1, 2, 3, 4], cycleStart: 1, want: 3 },
    { name: "no cycle", values: [1, 2, 3], cycleStart: null, want: 0 },
    {
      name: "cycle of length 1 (self loop)",
      values: [1],
      cycleStart: 0,
      want: 1,
    },
  ])("$name", ({ values, cycleStart, want }) => {
    const nodes = buildNodes(values);
    if (cycleStart !== null) {
      nodes[nodes.length - 1].next = nodes[cycleStart];
    }
    expect(findCycleLength(nodes[0])).toBe(want);
  });
});
