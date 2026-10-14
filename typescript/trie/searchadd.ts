// Design a data structure that supports the addition of new words and the
// ability to check if a string matches any previously added word.
// Implement the Solution class:
//
// Solution() Initializes the object.
// void addWord(word) Inserts word into the data structure, making it available
// for future searches.
// bool search(word) Checks if there is any word in the data structure that
// matches word. The method returns true if such a match exists, otherwise
// returns false.
// Note: In the search query word, the character '.' can represent any single
// letter, effectively serving as a wildcard character.
//
// Examples
// Example 1:
//
// Input:
// ["Solution", "addWord", "addWord", "search", "search"]
// [[], ["apple"], ["banana"], ["apple"], ["......"]]
// Expected Output:
// [-1, -1, -1, 1, 1]
// Justification: After adding the words "apple" and "banana", searching for
// "apple" will return true since "apple" is in the data structure. Searching
// for "......" will also return true as "banana" match the pattern.
// Example 2:
//
// Input:
// ["Solution", "addWord", "addWord", "search", "search"]
// [[], ["cat"], ["dog"], ["c.t"], ["d..g"]]
// Expected Output:
// [-1, -1, -1, 1, 0]
// Justification: "c.t" matches "cat" and "d..g" doesn't matches "dog".
// Example 3:
//
// Input:
// ["Solution", "addWord", "search", "search"]
// [[], ["hello"], ["h.llo"], ["h...o"]]
// Expected Output:
// [-1, -1, 1, 1]
// Justification: "h.llo" and "h...o" both match "hello".
// Constraints:
//
// 1 <= word.length <= 25
// word in addWord consists of lowercase English letters.
// word in search consist of '.' or lowercase English letters.
// There will be at most 2 dots in word for search queries.
// At most 104 calls will be made to addWord and search.

import { insert, TrieNode } from "./shared.ts";

// searchInNode is a helper method to search a word in the trie node.
export function searchInNode(word: string, node: TrieNode): boolean {
  for (let i = 0; i < word.length; i++) {
    const ch = word[i];
    if (ch === ".") {
      // If it's a wildcard, recursively search for all possible characters.
      for (const child of node.children.values()) {
        if (searchInNode(word.slice(i + 1), child)) {
          return true;
        }
      }
      return false;
    }
    const child = node.children.get(ch);
    if (child === undefined) {
      return false;
    }
    node = child;
  }
  return node.isEnd; // Return if we're at the end of a valid word.
}

export class Trie {
  private readonly root = new TrieNode();

  // addWord adds a word into the trie structure.
  addWord(word: string): void {
    insert(this.root, word);
  }

  // searchNode searches a word, considering '.' as a wildcard.
  searchNode(word: string): boolean {
    return searchInNode(word, this.root);
  }
}
