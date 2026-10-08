package trie

// Design a data structure that supports the addition of new words and the ability to check if a string matches any previously added word.
// Implement the Solution class:
//
// Solution() Initializes the object.
// void addWord(word) Inserts word into the data structure, making it available for future searches.
// bool search(word) Checks if there is any word in the data structure that matches word. The method returns true if such a match exists, otherwise returns false.
// Note: In the search query word, the character '.' can represent any single letter, effectively serving as a wildcard character.
//
// Examples
// Example 1:
//
// Input:
// ["Solution", "addWord", "addWord", "search", "search"]
// [[], ["apple"], ["banana"], ["apple"], ["......"]]
// Expected Output:
// [-1, -1, -1, 1, 1]
// Justification: After adding the words "apple" and "banana", searching for "apple" will return true since "apple" is in the data structure. Searching for "......" will also return true as "banana" match the pattern.
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

// AddWord adds a word into the trie structure.
func (s *Solution) AddWord(word string) {
	node := s.root
	for _, c := range word {
		index := c - 'a'
		if node.Children[index] == nil { // If the child node doesn't exist, create it.
			node.Children[index] = &TrieNode{}
		}
		node = node.Children[index] // Move to the child node.
	}
	node.IsEnd = true // Mark the end of the word.
}

// Search searches a word, considering '.' as a wildcard.
func (s *Solution) SearchNode(word string) bool {
	return searchInNode(word, s.root)
}

// searchInNode is a helper method to search a word in the trie node.
func searchInNode(word string, node *TrieNode) bool {
	for i, ch := range word {
		if ch == '.' {
			// If it's a wildcard, recursively search for all possible characters.
			for _, child := range node.Children {
				if child != nil && searchInNode(word[i+1:], child) {
					return true
				}
			}
			return false
		} else {
			index := ch - 'a'
			if node.Children[index] == nil {
				return false
			}
			node = node.Children[index] // Move to the next node.
		}
	}
	return node.IsEnd // Return if we're at the end of a valid word.
}
