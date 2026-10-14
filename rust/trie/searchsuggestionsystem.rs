use super::shared::{Trie, TrieNode, index};

// Given a list of distinct strings products and a string searchWord.
// Determine a set of product suggestions after each character of the search
// word is typed.
// Every time a character is typed,
// return a list containing up to three product names from the products list
// that have the same prefix as the typed string.
// If there are more than 3 matching products,
// return 3 lexicographically smallest products.
// These product names should be returned in lexicographical (alphabetical)
// order.
//
// Example 1:
// Input: Products: ["apple", "apricot", "application"], searchWord: "app"
// Expected Output: [["apple", "apricot", "application"], ["apple", "apricot",
// "application"], ["apple", "application"]]
// Justification: For the perfix 'a', "apple", "apricot", and "application"
// match.
// For the prefix 'ap', "apple", "apricot", and "application" match. For the
// prefix 'app', "apple", and "application" match
//
// Example 2:
// Input: Products: ["king", "kingdom", "kit"], searchWord: "ki"
// Expected Output: [["king", "kingdom", "kit"], ["king", "kingdom", "kit"]]
// Justification: All products starting with "k" are "king", "kingdom", and
// "kit". The list remains the same for the 'ki' prefix.
//
// Example 3:
// Input: Products: ["fantasy", "fast", "festival"], searchWord: "farm"
// Expected Output: [["fantasy", "fast", "festival"], ["fantasy", "fast"], [],
// []]
// Justification: Initially, "fantasy", "fast", and "festival" match 'f'. Moving
// to 'fa', only "fantasy" and "fast" match. No product matches with "far", and
// "farm".
//
// Constraints:
// 1 <= products.length <= 1000
// 1 <= products[i].length <= 3000
// 1 <= sum(products[i].length) <= 2 * 104
// All the strings of products are unique.
// products[i] consists of lowercase English letters.
// 1 <= searchWord.length <= 1000
// searchWord consists of lowercase English letters.

// DFS to find words starting with the given prefix

// dfs collects the words under a node in alphabetical order, stopping at 3
fn dfs(node: &TrieNode, word: &mut String, list: &mut Vec<String>) {
    if list.len() == 3 {
        return;
    }
    if node.is_end {
        list.push(word.clone());
    }

    for ch in 'a'..='z' {
        if let Some(child) = &node.children[index(ch as u8)] {
            word.push(ch);
            dfs(child, word, list);
            word.pop();
        }
    }
}

impl Trie {
    // Search for words starting with prefix
    pub fn search_prefix(&self, prefix: &str) -> Vec<String> {
        let mut node = &self.root;
        let mut list = Vec::new();
        for ch in prefix.bytes() {
            let Some(child) = &node.children[index(ch)] else {
                return list;
            };
            node = child;
        }
        dfs(node, &mut prefix.to_string(), &mut list);
        list
    }
}

pub fn suggested_products(
    products: &[&str],
    search_word: &str,
) -> Vec<Vec<String>> {
    let mut trie = Trie::new();
    for product in products {
        trie.insert(product);
    }

    let mut result = Vec::new();
    // search with one more letter of the search word each time
    for end in 1..=search_word.len() {
        result.push(trie.search_prefix(&search_word[..end]));
    }
    result
}
