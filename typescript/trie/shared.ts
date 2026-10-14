// Helpers shared by the trie problems.

// TrieNode is one node of a trie of words. Each problem of this pattern
// builds the trie it needs out of these nodes.
export class TrieNode {
  // The node for each letter that can come next.
  readonly children = new Map<string, TrieNode>();
  // Flag to represent if the node is the end of a word.
  isEnd = false;
}

// insert adds a word to the trie under root.
export function insert(root: TrieNode, word: string): void {
  let node = root;
  for (const c of word) {
    // If the child node doesn't exist, create it, then move to it.
    let child = node.children.get(c);
    if (child === undefined) {
      child = new TrieNode();
      node.children.set(c, child);
    }
    node = child;
  }
  node.isEnd = true; // Mark the end of the word.
}
