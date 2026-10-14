import { describe, expect, test } from "vitest";

import { buildNodes, type ListNode } from "../common/list.ts";
import { findCycleStart } from "./startofcycle.ts";

describe("findCycleStart", () => {
  // cycleStart is the index the last node points back to, or null
  test.each([
    { name: "cycle at node 2", values: [1, 2, 3, 4], cycleStart: 1 },
    { name: "cycle at the head", values: [1, 2, 3], cycleStart: 0 },
    { name: "no cycle", values: [1, 2, 3], cycleStart: null },
  ])("$name", ({ values, cycleStart }) => {
    const nodes = buildNodes(values);
    let want: ListNode | null = null;
    if (cycleStart !== null) {
      want = nodes[cycleStart];
      nodes[nodes.length - 1].next = want;
    }
    // the same node, not just a node with the same value
    expect(findCycleStart(nodes[0])).toBe(want);
  });
});
