import { describe, expect, test } from "vitest";

import { isTopologicalOrder } from "./shared.ts";
import { findOrder } from "./taskscheduelorder.ts";

describe("findOrder", () => {
  test.each<{ name: string; tasks: number; prerequisites: [number, number][] }>(
    [
      {
        name: "Test Case 1",
        tasks: 6,
        prerequisites: [
          [2, 5],
          [0, 5],
          [0, 4],
          [1, 4],
          [3, 2],
          [1, 3],
        ],
      },
      {
        name: "Test Case 2",
        tasks: 3,
        prerequisites: [
          [0, 1],
          [1, 2],
        ],
      },
    ],
  )("$name", ({ tasks, prerequisites }) => {
    const got = findOrder(tasks, prerequisites);
    expect(
      isTopologicalOrder(got, tasks, prerequisites),
      `${JSON.stringify(got)} is not a valid order`,
    ).toBe(true);
  });

  test("Cyclic prerequisites have no order", () => {
    expect(
      findOrder(3, [
        [0, 1],
        [1, 2],
        [2, 0],
      ]),
    ).toEqual([]);
  });
});
