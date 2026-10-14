use super::longestsubstringwithkchars::find_length;

#[test]
fn test_find_length() {
    let tests = [
        ("Example 1", "araaci", 2, 4),
        ("Example 2", "araaci", 1, 2),
        ("Example 3", "cbbebi", 3, 5),
    ];
    for (name, s, k, want) in tests {
        let got = find_length(s, k);
        assert_eq!(got, want, "{name}: find_length()");
    }
}
