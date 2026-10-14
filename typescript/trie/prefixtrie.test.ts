import { describe, expect, test } from "vitest";

import { Trie } from "./prefixtrie.ts";

describe("Trie", () => {
  test.each([
    {
      name: "grape",
      inserted: "grape",
      word: "grape",
      wantSearch: true,
      wantStartsWith: true,
    },
    {
      name: "grapefruit",
      inserted: "grapefruit",
      word: "grapefruit",
      wantSearch: true,
      wantStartsWith: true,
    },
    {
      name: "a prefix of a word",
      inserted: "grape",
      word: "grap",
      wantSearch: false,
      wantStartsWith: true,
    },
    {
      name: "a shorter prefix",
      inserted: "grape",
      word: "gr",
      wantSearch: false,
      wantStartsWith: true,
    },
    {
      name: "a longer word",
      inserted: "grape",
      word: "grapes",
      wantSearch: false,
      wantStartsWith: false,
    },
    {
      name: "a different word",
      inserted: "grape",
      word: "gro",
      wantSearch: false,
      wantStartsWith: false,
    },
  ])("$name", ({ inserted, word, wantSearch, wantStartsWith }) => {
    const trie = new Trie();
    trie.insert(inserted);
    expect(trie.search(word)).toBe(wantSearch);
    expect(trie.startsWith(word)).toBe(wantStartsWith);
  });
});
