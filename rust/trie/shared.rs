#[derive(Default)]
pub struct TrieNode {
    // One slot for each letter of the alphabet.
    pub children: [Option<Box<TrieNode>>; 26],
    // Flag to represent if the node is the end of a word.
    pub is_end: bool,
}

/// A trie of lowercase words. The methods are spread over the files of this
/// pattern, each problem adding the ones it is about: `insert`, `search` and
/// `starts_with` are in prefixtrie.rs.
#[derive(Default)]
pub struct Trie {
    pub root: TrieNode,
}

impl Trie {
    pub fn new() -> Self {
        Self::default()
    }
}

/// Returns the slot of a lowercase letter in `TrieNode::children`.
pub fn index(letter: u8) -> usize {
    usize::from(letter - b'a')
}
