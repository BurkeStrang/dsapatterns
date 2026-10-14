use super::balancedparentheses::valid_parentheses;

#[test]
fn test_valid_parentheses() {
    let tests = [
        ("Example 1 - balanced", "{[()]}", true),
        ("Example 2 - not balanced", "{[}]", false),
        ("Example 3 - not balanced", "(]", false),
        ("Empty string - balanced", "", true),
        ("Single type - balanced", "()[]{}", true),
        ("Single type - not balanced", "(((", false),
    ];
    for (name, s1, want) in tests {
        let got = valid_parentheses(s1);
        assert_eq!(got, want, "{name}: valid_parentheses()");
    }
}
