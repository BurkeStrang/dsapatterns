use super::shared::Trie;

#[test]
fn test_search() {
    // (name, inserted word, searched word, want)
    let tests = [
        ("Search 'grape'", "grape", "grape", true),
        ("Search 'grapefruit'", "grapefruit", "grapefruit", true),
        ("Search a prefix of a word", "grape", "grap", false),
        ("Search a longer word", "grape", "grapes", false),
    ];
    for (name, inserted, word, want) in tests {
        let mut trie = Trie::new();
        trie.insert(inserted);
        let got = trie.search(word);
        assert_eq!(got, want, "{name}: search()");
    }
}

#[test]
fn test_starts_with() {
    // (name, inserted word, prefix, want)
    let tests = [
        ("StartsWith 'grap'", "grape", "grap", true),
        ("StartsWith 'gr'", "grape", "gr", true),
        ("StartsWith 'gra'", "grape", "gra", true),
        ("StartsWith 'gro'", "grape", "gro", false),
    ];
    for (name, inserted, prefix, want) in tests {
        let mut trie = Trie::new();
        trie.insert(inserted);
        let got = trie.starts_with(prefix);
        assert_eq!(got, want, "{name}: starts_with()");
    }
}
