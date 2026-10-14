import { describe, expect, test } from "vitest";

import { dutch } from "./dutchnationalflag.ts";

describe("dutch", () => {
  test.each([
    { name: "example1", arr: [1, 0, 2, 1, 0], want: [0, 0, 1, 1, 2] },
    { name: "example2", arr: [2, 2, 0, 1, 2, 0], want: [0, 0, 1, 2, 2, 2] },
    { name: "all zeros", arr: [0, 0, 0], want: [0, 0, 0] },
    { name: "all twos", arr: [2, 2, 2], want: [2, 2, 2] },
    {
      name: "already sorted",
      arr: [0, 0, 1, 1, 2, 2],
      want: [0, 0, 1, 1, 2, 2],
    },
    { name: "single element", arr: [1], want: [1] },
  ])("$name", ({ arr, want }) => {
    dutch(arr);
    expect(arr).toEqual(want);
  });
});
