import { describe, expect, test } from "vitest";

import { buildNodes } from "../common/list.ts";
import { hasCycle } from "./linkedlistcycle.ts";

describe("hasCycle", () => {
  // cycleStart is the index the last node points back to, or null
  test.each([
    { name: "no cycle", values: [1, 2, 3], cycleStart: null, want: false },
    { name: "cycle exists", values: [1, 2, 3], cycleStart: 0, want: true },
  ])("$name", ({ values, cycleStart, want }) => {
    const nodes = buildNodes(values);
    if (cycleStart !== null) {
      nodes[nodes.length - 1].next = nodes[cycleStart];
    }
    expect(hasCycle(nodes[0])).toBe(want);
  });
});
