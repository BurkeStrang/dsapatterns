import { describe, expect, test } from "vitest";

import { countPrimes, getPrimes, isPrime } from "./isprime.ts";

describe("isPrime", () => {
  test.each([
    { n: 1, want: false },
    { n: 2, want: true },
    { n: 3, want: true },
    { n: 4, want: false },
    { n: 5, want: true },
    { n: 167, want: true },
  ])("isPrime($n)", ({ n, want }) => {
    expect(isPrime(n)).toBe(want);
  });
});

describe("countPrimes", () => {
  test.each([
    { n: 1, want: 0 },
    { n: 10, want: 4 },
    { n: 100, want: 25 },
    { n: 1000, want: 168 },
    { n: 10000, want: 1229 },
  ])("countPrimes($n)", ({ n, want }) => {
    expect(countPrimes(n)).toBe(want);
  });
});

describe("getPrimes", () => {
  test.each([
    { n: 1, want: [] },
    { n: 10, want: [2, 3, 5, 7] },
    { n: 20, want: [2, 3, 5, 7, 11, 13, 17, 19] },
    { n: 30, want: [2, 3, 5, 7, 11, 13, 17, 19, 23, 29] },
    {
      n: 100,
      // prettier-ignore
      want: [
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61,
        67, 71, 73, 79, 83, 89, 97,
      ],
    },
  ])("getPrimes($n)", ({ n, want }) => {
    expect(getPrimes(n)).toEqual(want);
  });
});
