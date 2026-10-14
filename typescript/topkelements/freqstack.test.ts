import { describe, expect, test } from "vitest";

import { FrequencyStack } from "./freqstack.ts";

describe("FrequencyStack", () => {
  test("push then pop until empty", () => {
    const stack = new FrequencyStack();
    for (const num of [1, 2, 3, 2, 1, 2, 5]) {
      stack.push(num);
    }
    // 2 is the most frequent; then 1 and 2 are tied and 1 was pushed last;
    // then 2; after that every push left is a first push of its number, and
    // the latest of those comes out first
    const want = [2, 1, 2, 5, 3, 2, 1, null];
    const got = want.map(() => stack.pop());
    expect(got).toEqual(want);
  });
});
