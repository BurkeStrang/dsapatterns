use super::maxsubstringkreplace::max_length_replace;

#[test]
fn test_max_length_replace() {
    let tests = [
        ("Example 1", "aabccbb", 2, 5),
        ("Example 2", "abbcb", 1, 4),
        ("Example 3", "abccde", 1, 3),
    ];
    for (name, s, k, want) in tests {
        let got = max_length_replace(s, k);
        assert_eq!(got, want, "{name}: max_length_replace()");
    }
}
