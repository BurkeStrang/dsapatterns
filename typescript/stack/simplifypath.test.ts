import { describe, expect, test } from "vitest";

import { simplifyPath } from "./simplifypath.ts";

describe("simplifyPath", () => {
  test.each([
    { name: "Example 1", path: "/a//b////c/d//././/..", want: "/a/b/c" },
    { name: "Example 2", path: "/../", want: "/" },
    { name: "Example 3", path: "/home//foo/", want: "/home/foo" },
    { name: "Root only", path: "/", want: "/" },
    { name: "Multiple .. at root", path: "/../../..", want: "/" },
    { name: "Dot only", path: "/./././.", want: "/" },
    { name: "Trailing slash", path: "/a/b/c/", want: "/a/b/c" },
    { name: "Complex", path: "/a/./b/../../c/", want: "/c" },
  ])("$name", ({ path, want }) => {
    expect(simplifyPath(path)).toBe(want);
  });
});
