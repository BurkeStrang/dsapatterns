use super::longestpalindromicstring::find_lp_string_length;

#[test]
fn test_find_lp_string_length() {
    let tests = [
        ("Example 1", "abdbca", 3),
        ("Example 2", "cddpd", 3),
        ("Example 3", "pqr", 1),
    ];
    for (name, st, want) in tests {
        let got = find_lp_string_length(st);
        assert_eq!(got, want, "{name}: find_lp_string_length()");
    }
}
