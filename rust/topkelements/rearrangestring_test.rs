use super::rearrangestring::rearrange_string;

#[test]
fn test_rearrange_string() {
    let tests = [
        ("Example 1", "aappp", "papap"),
        ("Example 2", "Programming", "gmrPagimnor"),
        ("Example 3", "aapa", ""),
        ("Single character", "a", "a"),
    ];
    for (name, s, want) in tests {
        let got = rearrange_string(s);
        assert_eq!(got, want, "{name}: rearrange_string()");
    }
}
