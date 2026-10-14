use super::removeadjacentdups::remove_duplicates;

#[test]
fn test_remove_duplicates() {
    let tests = [
        ("empty string", "", ""),
        ("no duplicates", "abcd", "abcd"),
        ("all removed", "abccba", ""),
        ("simple pair", "aabb", ""),
        ("single removal", "foobar", "fbar"),
        ("triple duplicate", "fooobar", "fobar"),
        ("nested removals", "azxxzy", "ay"),
        ("single char", "a", "a"),
        ("all same", "aaaa", ""),
    ];
    for (name, s, want) in tests {
        let got = remove_duplicates(s);
        assert_eq!(got, want, "{name}: remove_duplicates({s:?})");
    }
}
