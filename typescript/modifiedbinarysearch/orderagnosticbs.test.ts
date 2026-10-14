import { describe, expect, test } from "vitest";

import { descOrAscSearch } from "./orderagnosticbs.ts";

const ASC = [1, 3, 5, 7, 9];
const DESC = [9, 7, 5, 3, 1];

describe("descOrAscSearch", () => {
  test.each([
    { name: "ascending - key found in middle", arr: ASC, key: 5, want: 2 },
    { name: "ascending - key found at start", arr: ASC, key: 1, want: 0 },
    { name: "ascending - key found at end", arr: ASC, key: 9, want: 4 },
    { name: "ascending - key not found", arr: ASC, key: 4, want: -1 },
    { name: "descending - key found in middle", arr: DESC, key: 5, want: 2 },
    { name: "descending - key found at start", arr: DESC, key: 9, want: 0 },
    { name: "descending - key found at end", arr: DESC, key: 1, want: 4 },
    { name: "descending - key not found", arr: DESC, key: 4, want: -1 },
    { name: "single element - found", arr: [42], key: 42, want: 0 },
    { name: "single element - not found", arr: [42], key: 7, want: -1 },
  ])("$name", ({ arr, key, want }) => {
    expect(descOrAscSearch(arr, key)).toBe(want);
  });
});
