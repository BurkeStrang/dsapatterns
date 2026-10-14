use super::mindeletiontomakepal::find_minimum_deletions;

#[test]
fn test_find_minimum_deletions() {
    let tests = [
        ("Example 1", "abdbca", 1),
        ("Example 2", "cddpd", 2),
        ("Example 3", "pqr", 2),
        ("Empty string", "", 0),
    ];
    for (name, st, want) in tests {
        let got = find_minimum_deletions(st);
        assert_eq!(got, want, "{name}: find_minimum_deletions()");
    }
}
