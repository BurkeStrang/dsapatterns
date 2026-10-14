"""
Given a list of distinct strings products and a string searchWord.
Determine a set of product suggestions after each character of the search
word is typed.
Every time a character is typed,
return a list containing up to three product names from the products list
that have the same prefix as the typed string.
If there are more than 3 matching products,
return 3 lexicographically smallest products.
These product names should be returned in lexicographical (alphabetical)
order.

Example 1:
Input: Products: ["apple", "apricot", "application"], searchWord: "app"
Expected Output: [["apple", "apricot", "application"], ["apple", "apricot",
"application"], ["apple", "application"]]
Justification: For the perfix 'a', "apple", "apricot", and "application"
match.
For the prefix 'ap', "apple", "apricot", and "application" match. For the
prefix 'app', "apple", and "application" match

Example 2:
Input: Products: ["king", "kingdom", "kit"], searchWord: "ki"
Expected Output: [["king", "kingdom", "kit"], ["king", "kingdom", "kit"]]
Justification: All products starting with "k" are "king", "kingdom", and
"kit". The list remains the same for the 'ki' prefix.

Example 3:
Input: Products: ["fantasy", "fast", "festival"], searchWord: "farm"
Expected Output: [["fantasy", "fast", "festival"], ["fantasy", "fast"], [],
[]]
Justification: Initially, "fantasy", "fast", and "festival" match 'f'. Moving
to 'fa', only "fantasy" and "fast" match. No product matches with "far", and
"farm".

Constraints:
1 <= products.length <= 1000
1 <= products[i].length <= 3000
1 <= sum(products[i].length) <= 2 * 104
All the strings of products are unique.
products[i] consists of lowercase English letters.
1 <= searchWord.length <= 1000
searchWord consists of lowercase English letters.
"""

import string

from trie.shared import TrieNode


def dfs(node: TrieNode, word: str, found: list[str]) -> None:
    """Collects the words under a node in alphabetical order, stopping at
    3."""
    if len(found) == 3:
        return
    if node.is_end:
        found.append(word)
    for ch in string.ascii_lowercase:
        child = node.children.get(ch)
        if child is not None:
            dfs(child, word + ch, found)


class Trie:
    def __init__(self) -> None:
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root
        for c in word:
            # If the child node doesn't exist, create it, then move to it.
            node = node.children.setdefault(c, TrieNode())
        node.is_end = True

    def search_prefix(self, prefix: str) -> list[str]:
        """Search for words starting with prefix."""
        node = self.root
        found: list[str] = []
        for ch in prefix:
            child = node.children.get(ch)
            if child is None:
                return found
            node = child
        dfs(node, prefix, found)
        return found


def suggested_products(
    products: list[str], search_word: str
) -> list[list[str]]:
    trie = Trie()
    for product in products:
        trie.insert(product)

    # search with one more letter of the search word each time
    return [
        trie.search_prefix(search_word[:end])
        for end in range(1, len(search_word) + 1)
    ]
