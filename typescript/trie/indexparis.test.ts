import { describe, expect, test } from "vitest";

import { indexPairs } from "./indexparis.ts";

describe("indexPairs", () => {
  test.each([
    {
      name: "Test Case 1",
      text: "thestarsareout",
      words: ["star", "stars", "are"],
      want: [
        [3, 6],
        [3, 7],
        [8, 10],
      ],
    },
    {
      name: "Test Case 2",
      text: "bluebirdskyscraper",
      words: ["blue", "bird", "sky"],
      want: [
        [0, 3],
        [4, 7],
        [8, 10],
      ],
    },
  ])("$name", ({ text, words, want }) => {
    expect(indexPairs(text, words)).toEqual(want);
  });
});
