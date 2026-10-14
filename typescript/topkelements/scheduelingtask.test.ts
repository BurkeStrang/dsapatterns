import { describe, expect, test } from "vitest";

import { scheduleTasks } from "./scheduelingtask.ts";

describe("scheduleTasks", () => {
  test.each([
    { name: "Example 1", tasks: ["a", "a", "a", "b", "c", "c"], k: 2, want: 7 },
    { name: "Example 2", tasks: ["a", "b", "a"], k: 3, want: 5 },
  ])("$name", ({ tasks, k, want }) => {
    expect(scheduleTasks(tasks, k)).toBe(want);
  });
});
