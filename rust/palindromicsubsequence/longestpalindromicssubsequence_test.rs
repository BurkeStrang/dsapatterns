use super::longestpalindromicssubsequence::find_lps_length;

#[test]
fn test_find_lps_length() {
    let tests = [
        ("Example 1", "abdbca", 5),
        ("Example 2", "cddpd", 3),
        ("Example 3", "pqr", 1),
        ("Empty string", "", 0),
    ];
    for (name, st, want) in tests {
        let got = find_lps_length(st);
        assert_eq!(got, want, "{name}: find_lps_length()");
    }
}
