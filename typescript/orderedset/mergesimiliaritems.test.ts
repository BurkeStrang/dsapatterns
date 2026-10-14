import { describe, expect, test } from "vitest";

import { mergeSimilarItems } from "./mergesimiliaritems.ts";

describe("mergeSimilarItems", () => {
  test.each<{
    name: string;
    items1: [number, number][];
    items2: [number, number][];
    want: number[][];
  }>([
    {
      name: "Example 1",
      items1: [
        [1, 2],
        [4, 3],
      ],
      items2: [
        [2, 1],
        [4, 3],
        [3, 4],
      ],
      want: [
        [1, 2],
        [2, 1],
        [3, 4],
        [4, 6],
      ],
    },
    { name: "Example 2", items1: [[5, 5]], items2: [[5, 10]], want: [[5, 15]] },
    {
      name: "Example 3",
      items1: [
        [1, 1],
        [2, 2],
      ],
      items2: [[3, 3]],
      want: [
        [1, 1],
        [2, 2],
        [3, 3],
      ],
    },
    {
      name: "Unsorted input",
      items1: [
        [9, 1],
        [2, 2],
      ],
      items2: [
        [5, 3],
        [2, 4],
      ],
      want: [
        [2, 6],
        [5, 3],
        [9, 1],
      ],
    },
  ])("$name", ({ items1, items2, want }) => {
    expect(mergeSimilarItems(items1, items2)).toEqual(want);
  });
});
