import { describe, expect, test } from "vitest";

import { canConstruct } from "./reconstructsequence.ts";

describe("canConstruct", () => {
  test.each([
    {
      name: "Example 1",
      originalSeq: [1, 2, 3, 4],
      sequences: [
        [1, 2],
        [2, 3],
        [3, 4],
      ],
      want: true,
    },
    {
      name: "Example 2",
      originalSeq: [1, 2, 3, 4],
      sequences: [
        [1, 2],
        [2, 3],
        [2, 4],
      ],
      want: false,
    },
    {
      name: "Example 3",
      originalSeq: [3, 1, 4, 2, 5],
      sequences: [
        [3, 1, 5],
        [1, 4, 2, 5],
      ],
      want: true,
    },
    {
      name: "Different order",
      originalSeq: [1, 2, 3],
      sequences: [
        [3, 2],
        [2, 1],
      ],
      want: false,
    },
    {
      name: "Missing number",
      originalSeq: [1, 2, 3],
      sequences: [[1, 2]],
      want: false,
    },
    {
      name: "Cyclic sequences",
      originalSeq: [1, 2, 3],
      sequences: [
        [1, 2],
        [2, 3],
        [3, 1],
      ],
      want: false,
    },
  ])("$name", ({ originalSeq, sequences, want }) => {
    expect(canConstruct(originalSeq, sequences)).toBe(want);
  });
});
