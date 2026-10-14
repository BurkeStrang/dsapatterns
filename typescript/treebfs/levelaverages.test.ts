import { describe, expect, test } from "vitest";

import { tree } from "../common/tree.ts";
import { levelAverage } from "./levelaverages.ts";

describe("levelAverage", () => {
  test.each([
    { name: "Example 1", root: [1, 2, 3, 4, 5, 6, 7], want: [1.0, 2.5, 5.5] },
    {
      name: "Example 2",
      root: [12, 7, 1, null, 9, 10, 5],
      want: [12.0, 4.0, 8.0],
    },
    { name: "Empty tree", root: [], want: [] },
  ])("$name", ({ root, want }) => {
    const got = levelAverage(tree(root));
    expect(got).toHaveLength(want.length);
    got.forEach((value, i) => {
      expect(value).toBeCloseTo(want[i], 9);
    });
  });
});
