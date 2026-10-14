import { describe, expect, test } from "vitest";

import { Median } from "./mediannumberstream.ts";

describe("Median", () => {
  // each number to insert, and the median after inserting it
  test.each<{ name: string; steps: [number, number][] }>([
    {
      name: "in order",
      steps: [
        [1, 1.0],
        [2, 1.5],
        [3, 2.0],
        [4, 2.5],
        [5, 3.0],
      ],
    },
    {
      name: "unordered",
      steps: [
        [5, 5.0],
        [3, 4.0],
        [8, 5.0],
        [1, 4.0],
        [2, 3.0],
      ],
    },
  ])("$name", ({ steps }) => {
    const m = new Median();
    for (const [num, want] of steps) {
      m.insertNum(num);
      expect(m.findMedian(), `after inserting ${String(num)}`).toBeCloseTo(
        want,
        9,
      );
    }
  });
});
