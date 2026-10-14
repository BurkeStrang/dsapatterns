use super::rearrangedist::reorganize_string;

#[test]
fn test_reorganize_string() {
    let tests = [
        ("Example 1", "mmpp", 2, "mpmp"),
        ("Example 2", "Programming", 3, "gmrPagimnor"),
        ("Example 3", "aab", 2, "aba"),
        ("Example 4: not possible", "aappa", 3, ""),
        ("k of 1 changes nothing", "aab", 1, "aab"),
    ];
    for (name, s, k, want) in tests {
        let got = reorganize_string(s, k);
        assert_eq!(got, want, "{name}: reorganize_string()");
    }
}
