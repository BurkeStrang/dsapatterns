use super::balanceparentheses::generate_valid_parentheses;

#[test]
fn test_generate_valid_parentheses() {
    let tests = [
        ("example 1", 2, vec!["(())", "()()"]),
        (
            "example 2",
            3,
            vec!["((()))", "(()())", "(())()", "()(())", "()()()"],
        ),
    ];
    for (name, num, want) in tests {
        let got = generate_valid_parentheses(num);
        assert_eq!(got, want, "{name}: generate_valid_parentheses()");
    }
}
