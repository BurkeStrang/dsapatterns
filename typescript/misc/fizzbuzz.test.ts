import { describe, expect, test } from "vitest";

import { fizzBuzz } from "./fizzbuzz.ts";

describe("fizzBuzz", () => {
  test.each([
    { name: "5", n: 5, want: ["1", "2", "Fizz", "4", "Buzz"] },
    {
      name: "15",
      n: 15,
      // prettier-ignore
      want: [
        "1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz",
        "11", "Fizz", "13", "14", "FizzBuzz",
      ],
    },
  ])("$name", ({ n, want }) => {
    expect(fizzBuzz(n)).toEqual(want);
  });
});
