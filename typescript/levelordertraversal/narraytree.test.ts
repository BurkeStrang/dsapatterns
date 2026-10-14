import { describe, expect, test } from "vitest";

import { levelOrder, type NAryNode } from "./narraytree.ts";

// node makes an N-ary tree node, to keep the test table short.
function node(value: number, children: NAryNode[] = []): NAryNode {
  return { value, children };
}

describe("levelOrder", () => {
  test.each([
    {
      name: "Example 1: [1,null,2,3,4,null,5,6]",
      root: node(1, [node(2, [node(5), node(6)]), node(3), node(4)]),
      want: [[1], [2, 3, 4], [5, 6]],
    },
    { name: "Single node", root: node(42), want: [[42]] },
    { name: "Empty tree", root: null, want: [] },
  ])("$name", ({ root, want }) => {
    expect(levelOrder(root)).toEqual(want);
  });
});
