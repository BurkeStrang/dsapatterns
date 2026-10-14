use super::longestpalindrome::longest_palindrome;

#[test]
fn test_longest_palindrome() {
    let tests = [
        ("applepie", "applepie", 5),
        ("aabbcc", "aabbcc", 6),
        ("bananas", "bananas", 5),
        ("single character", "a", 1),
        ("all unique", "abcdef", 1),
        ("all pairs", "aabb", 4),
    ];
    for (name, s, want) in tests {
        let got = longest_palindrome(s);
        assert_eq!(got, want, "{name}: longest_palindrome()");
    }
}
