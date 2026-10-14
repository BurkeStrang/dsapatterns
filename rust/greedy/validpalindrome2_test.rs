use super::validpalindrome2::is_palindrome_possible;

#[test]
fn test_is_palindrome_possible() {
    let tests = [
        ("Example 1", "racecar", true),
        ("Example 2", "abeccdeba", true),
        ("Example 3", "abcdef", false),
        ("Empty string", "", true),
    ];
    for (name, input, want) in tests {
        let got = is_palindrome_possible(input);
        assert_eq!(got, want, "{name}: is_palindrome_possible()");
    }
}
