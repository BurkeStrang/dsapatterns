import { describe, expect, test } from "vitest";

import { suggestedProducts } from "./searchsuggestionsystem.ts";

describe("suggestedProducts", () => {
  test.each([
    {
      name: "Test Case 1",
      products: ["mobile", "mouse", "moneypot", "monitor", "mousepad"],
      searchWord: "mouse",
      want: [
        ["mobile", "moneypot", "monitor"],
        ["mobile", "moneypot", "monitor"],
        ["mouse", "mousepad"],
        ["mouse", "mousepad"],
        ["mouse", "mousepad"],
      ],
    },
    {
      name: "Test Case 2",
      products: ["havana"],
      searchWord: "havana",
      want: Array.from({ length: 6 }, () => ["havana"]),
    },
  ])("$name", ({ products, searchWord, want }) => {
    expect(suggestedProducts(products, searchWord)).toEqual(want);
  });
});
