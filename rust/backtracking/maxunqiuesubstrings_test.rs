use super::maxunqiuesubstrings::max_unique_split;

#[test]
fn test_max_unique_split() {
    let tests = [
        ("Example 1", "ababccc", 5),
        ("Example 2", "aba", 2),
        ("Example 3", "aa", 1),
    ];
    for (name, s, want) in tests {
        let got = max_unique_split(s);
        assert_eq!(got, want, "{name}: max_unique_split()");
    }
}
