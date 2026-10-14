use super::permutationsinstring::find_permutation;

#[test]
fn test_find_permutation() {
    let tests = [
        ("Example 1", "oidbcaf", "abc", true),
        ("Example 2", "odicf", "dc", false),
        ("Example 3", "bcdxabcdy", "bcdyabcdx", true),
        ("Example 4", "aaacb", "abc", true),
    ];
    for (name, s, pattern, want) in tests {
        let got = find_permutation(s, pattern);
        assert_eq!(got, want, "{name}: find_permutation()");
    }
}
