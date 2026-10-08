package trie

// Given a list of distinct strings products and a string searchWord.
// Determine a set of product suggestions after each character of the search word is typed.
// Every time a character is typed,
// return a list containing up to three product names from the products list that have the same prefix as the typed string.
// If there are more than 3 matching products,
// return 3 lexicographically smallest products.
// These product names should be returned in lexicographical (alphabetical) order.
//
// Example 1:
// Input: Products: ["apple", "apricot", "application"], searchWord: "app"
// Expected Output: [["apple", "apricot", "application"], ["apple", "apricot", "application"], ["apple", "application"]]
// Justification: For the perfix 'a', "apple", "apricot", and "application" match.
// For the prefix 'ap', "apple", "apricot", and "application" match. For the prefix 'app', "apple", and "application" match
//
// Example 2:
// Input: Products: ["king", "kingdom", "kit"], searchWord: "ki"
// Expected Output: [["king", "kingdom", "kit"], ["king", "kingdom", "kit"]]
// Justification: All products starting with "k" are "king", "kingdom", and "kit". The list remains the same for the 'ki' prefix.
//
// Example 3:
// Input: Products: ["fantasy", "fast", "festival"], searchWord: "farm"
// Expected Output: [["fantasy", "fast", "festival"], ["fantasy", "fast"], [], []]
// Justification: Initially, "fantasy", "fast", and "festival" match 'f'. Moving to 'fa', only "fantasy" and "fast" match. No product matches with "far", and "farm".
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
func dfs(node *TrieNode, word string, list *[]string) {
	if len(*list) == 3 {
		return
	}
	if node.IsEnd {
		*list = append(*list, word)
	}

	for ch := 'a'; ch <= 'z'; ch++ {
		if node.Children[ch-'a'] != nil {
			dfs(node.Children[ch-'a'], word+string(ch), list)
		}
	}
}

// Search for words starting with prefix
func (t *Trie) Search(prefix string) []string {
	node := t.root
	list := []string{}

	for _, ch := range prefix {
		if node.Children[ch-'a'] == nil {
			return list
		}
		node = node.Children[ch-'a']
	}

	dfs(node, prefix, &list)
	return list
}

// Solution structure with a method to get suggested products
type Suggestion struct{}

func (s *Suggestion) suggestedProducts(products []string, searchWord string) [][]string {
	trie := NewTrie()
	for _, product := range products {
		trie.Insert(product)
	}

	result := [][]string{}
	prefix := ""
	for _, ch := range searchWord {
		prefix += string(ch)
		result = append(result, trie.Search(prefix))
	}

	return result
}
