use super::reversestring::reverse_string;

#[test]
fn test_reverse_string() {
    let tests = [
        ("Example 1", "Hello, World!", "!dlroW ,olleH"),
        ("Example 2", "OpenAI", "IAnepO"),
        ("Example 3", "Stacks are fun!", "!nuf era skcatS"),
    ];
    for (name, input, want) in tests {
        let got = reverse_string(input);
        assert_eq!(got, want, "{name}: reverse_string()");
    }
}
