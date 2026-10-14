use super::removeadjactentdupsii::remove_duplicates_ii;

#[test]
fn test_remove_duplicates_ii() {
    let tests = [
        ("remove bbb then aaa", "abbbaaca", 3, "ca"),
        ("no removal possible", "abbaccaa", 3, "abbaccaa"),
        ("remove ccc then aaa", "abbacccaa", 3, "abb"),
        ("all removed", "aaa", 3, ""),
        ("single char, k=2", "a", 2, "a"),
        ("multiple removals", "deeedbbcccbdaa", 3, "aa"),
    ];
    for (name, s, k, want) in tests {
        let got = remove_duplicates_ii(s, k);
        assert_eq!(got, want, "{name}: remove_duplicates_ii()");
    }
}
