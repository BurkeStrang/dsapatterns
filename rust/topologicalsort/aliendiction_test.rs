use super::aliendiction::find_alien_order;

#[test]
fn test_find_alien_order() {
    let tests = [
        ("Example 1", vec!["ba", "bc", "ac", "cab"], "bac"),
        ("Example 2", vec!["cab", "aaa", "aab"], "cab"),
        (
            "Example 3",
            vec!["ywx", "wz", "xww", "xz", "zyy", "zwz"],
            "ywxz",
        ),
        ("Word before its own prefix", vec!["abc", "ab"], ""),
        ("Cyclic ordering", vec!["a", "b", "a"], ""),
        ("No words", vec![], ""),
    ];
    for (name, words, want) in tests {
        let got = find_alien_order(&words);
        assert_eq!(got, want, "{name}: find_alien_order()");
    }
}
