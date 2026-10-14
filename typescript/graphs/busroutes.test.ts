import { describe, expect, test } from "vitest";

import { numBusesToDestination } from "./busroutes.ts";

describe("numBusesToDestination", () => {
  test.each([
    {
      name: "example 1",
      routes: [
        [1, 2, 7],
        [3, 6, 7],
      ],
      source: 1,
      target: 6,
      want: 2,
    },
    {
      name: "example 2",
      routes: [[7, 12], [4, 5, 15], [6], [15, 19], [9, 12, 13]],
      source: 15,
      target: 12,
      want: -1,
    },
  ])("$name", ({ routes, source, target, want }) => {
    expect(numBusesToDestination(routes, source, target)).toBe(want);
  });
});
