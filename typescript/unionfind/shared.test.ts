import { expect, test } from "vitest";

import { UnionFind } from "./shared.ts";

test("union find", () => {
  const uf = new UnionFind(5);
  expect(uf.connected(0, 1), "connected before any union").toBe(false);

  uf.unite(0, 1);
  uf.unite(3, 4);
  uf.unite(1, 1);
  expect(uf.connected(0, 1)).toBe(true);
  expect(uf.connected(1, 3)).toBe(false);

  uf.unite(1, 4);
  expect(uf.connected(0, 3), "connected after joining both sets").toBe(true);
  expect(uf.connected(2, 0)).toBe(false);
});
