import { describe, expect, test } from "vitest";

import { sortCharacterByFrequency } from "./frequencysort.ts";
import { countLetters } from "./shared.ts";

// Characters with the same frequency may come out in any order, so check the
// shape of the output instead of comparing it with one fixed answer: each
// character sits in a single run as long as its frequency, and the runs never
// get longer.
function validFrequencySort(input: string, output: string): boolean {
  if (input.length !== output.length) {
    return false;
  }
  const freq = countLetters(input);
  let prevFreq = Infinity;
  let i = 0;
  while (i < output.length) {
    const c = output[i];
    let count = 0;
    while (i < output.length && output[i] === c) {
      count++;
      i++;
    }
    if (freq.get(c) !== count || count > prevFreq) {
      return false;
    }
    prevFreq = count;
  }
  return true;
}

describe("sortCharacterByFrequency", () => {
  test.each([
    { name: "Example 1", s: "Programming" },
    { name: "Example 2", s: "abcbab" },
  ])("$name", ({ s }) => {
    const got = sortCharacterByFrequency(s);
    expect(validFrequencySort(s, got), `got "${got}"`).toBe(true);
  });
});
