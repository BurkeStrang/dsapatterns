import { describe, expect, test } from "vitest";

import { Trie } from "./searchadd.ts";

describe("Trie.searchNode", () => {
  test.each([
    { name: "SearchNode 'c.t'", add: ["cat", "dog"], word: "c.t", want: true },
    {
      name: "SearchNode 'd..g'",
      add: ["cat", "dog"],
      word: "d..g",
      want: false,
    },
    { name: "SearchNode 'h.llo'", add: ["hello"], word: "h.llo", want: true },
    { name: "SearchNode '...'", add: ["cat", "dog"], word: "...", want: true },
    { name: "SearchNode 'do'", add: ["cat", "dog"], word: "do", want: false },
  ])("$name", ({ add, word, want }) => {
    const trie = new Trie();
    for (const w of add) {
      trie.addWord(w);
    }
    expect(trie.searchNode(word)).toBe(want);
  });
});
