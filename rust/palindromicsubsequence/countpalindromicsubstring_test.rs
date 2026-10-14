use super::countpalindromicsubstring::find_cps;

#[test]
fn test_find_cps() {
    let tests = [
        ("Example 1", "abdbca", 7),
        ("Example 2", "cddpd", 7),
        ("Example 3", "pqr", 3),
        ("Empty string", "", 0),
    ];
    for (name, st, want) in tests {
        let got = find_cps(st);
        assert_eq!(got, want, "{name}: find_cps()");
    }
}
