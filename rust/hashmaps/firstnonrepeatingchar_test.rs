use super::firstnonrepeatingchar::first_uniq_char;

#[test]
fn test_first_uniq_char() {
    let tests = [
        ("Example 1: apple", "apple", 0),
        ("Example 2: abcab", "abcab", 2),
        ("Example 3: abab", "abab", -1),
        ("Single character", "z", 0),
        ("All unique", "abcdef", 0),
        ("Last unique", "aabbc", 4),
    ];
    for (name, s, want) in tests {
        let got = first_uniq_char(s);
        assert_eq!(got, want, "{name}: first_uniq_char()");
    }
}
