use super::shared::Trie;

#[test]
fn test_search_node() {
    let tests = [
        ("SearchNode 'c.t'", vec!["cat", "dog"], "c.t", true),
        ("SearchNode 'd..g'", vec!["cat", "dog"], "d..g", false),
        ("SearchNode 'h.llo'", vec!["hello"], "h.llo", true),
        ("SearchNode '...'", vec!["cat", "dog"], "...", true),
        ("SearchNode 'do'", vec!["cat", "dog"], "do", false),
    ];
    for (name, add, word, want) in tests {
        let mut trie = Trie::new();
        for w in add {
            trie.add_word(w);
        }
        let got = trie.search_node(word);
        assert_eq!(got, want, "{name}: search_node()");
    }
}
