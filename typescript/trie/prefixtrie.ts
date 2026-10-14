// Design and implement a Trie (also known as a Prefix Tree).
// A trie is a tree-like data structure that stores a dynamic set of strings,
// and is particularly useful for searching for words with a given prefix.
// Implement the Solution class:
// Solution() Initializes the object.
// void insert(word) Inserts word into the trie, making it available for future
// searches.
// bool search(word) Checks if the word exists in the trie.
// bool startsWith(word) Checks if any word in the trie starts with the given
// prefix.
//
// Example 1:
// Input:
// Trie operations: ["Trie", "insert", "search", "startsWith"]
// Arguments: [[], ["apple"], ["apple"], ["app"]]
// Expected Output: [-1, -1, 1, 1]
// Justification: After inserting "apple",
// "apple" exists in the Trie.
// There is also a word that starts with "app", which is "apple".
//
// Example 2:
// Input:
// Trie operations: ["Trie", "insert", "search", "startsWith", "search"]
// Arguments: [[], ["banana"], ["apple"], ["ban"], ["banana"]]
// Expected Output: [-1, -1, 0, 1, 1]
// Justification: After inserting "banana",
// "apple" does not exist in the Trie but a word that starts with "ban",
// which is "banana", does exist.
//
// Example 3:
// Input:
// Trie operations: ["Trie", "insert", "search", "startsWith", "startsWith"]
// Arguments: [[], ["grape"], ["grape"], ["grap"], ["gr"]]
// Expected Output: [-1, -1, 1, 1, 1]
// Justification: After inserting "grape",
// "grape" exists in the Trie.
// There are words that start with "grap" and "gr", which is "grape".
// Constraints:
// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and
// startsWith.

import { insert, TrieNode } from "./shared.ts";

export class Trie {
  private readonly root = new TrieNode();

  // insert inserts a word into the trie.
  insert(word: string): void {
    insert(this.root, word);
  }

  // search returns if the word is in the trie.
  search(word: string): boolean {
    let node: TrieNode | undefined = this.root;
    for (const c of word) {
      node = node.children.get(c);
      if (node === undefined) {
        return false;
      }
    }
    return node.isEnd;
  }

  // startsWith returns if there is any word in the trie that starts with
  // the given prefix.
  startsWith(prefix: string): boolean {
    let node: TrieNode | undefined = this.root;
    for (const c of prefix) {
      node = node.children.get(c);
      if (node === undefined) {
        return false;
      }
    }
    return true;
  }
}
