use super::smallestwindowsubstring::find_substring;

#[test]
fn test_find_substring() {
    let tests = [
        ("Example 1", "aabdec", "abc", "abdec"),
        ("Example 2", "aabdec", "abac", "aabdec"),
        ("Example 3", "abdbca", "abc", "bca"),
        ("Example 4", "adcad", "abc", ""),
    ];
    for (name, s, pattern, want) in tests {
        let got = find_substring(s, pattern);
        assert_eq!(got, want, "{name}: find_substring()");
    }
}
