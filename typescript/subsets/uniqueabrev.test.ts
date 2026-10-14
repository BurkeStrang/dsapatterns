import { describe, expect, test } from "vitest";

import { generateGeneralizedAbbreviation } from "./uniqueabrev.ts";

describe("generateGeneralizedAbbreviation", () => {
  test.each([
    {
      name: "word",
      word: "word",
      // prettier-ignore
      want: [
        "word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d",
        "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4",
      ],
    },
  ])("$name", ({ word, want }) => {
    // the abbreviations may come back in any order
    expect(generateGeneralizedAbbreviation(word).sort()).toEqual(want.sort());
  });
});
