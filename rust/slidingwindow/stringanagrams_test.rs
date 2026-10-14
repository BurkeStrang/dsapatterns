use super::stringanagrams::find_string_anagrams;

#[test]
fn test_find_string_anagrams() {
    let tests = [
        ("Example 1", "ppqp", "pq", vec![1, 2]),
        ("Example 2", "abbcabc", "abc", vec![2, 3, 4]),
    ];
    for (name, s, pattern, want) in tests {
        let got = find_string_anagrams(s, pattern);
        assert_eq!(got, want, "{name}: find_string_anagrams()");
    }
}
