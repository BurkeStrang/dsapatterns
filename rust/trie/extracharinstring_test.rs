use super::extracharinstring::min_extra_char;

#[test]
fn test_min_extra_char() {
    let tests = [
        ("Test Case 1", "amazingracecar", vec!["race"], 10),
        ("Test Case 2", "amazingracecar", vec!["race", "car"], 7),
        ("Test Case 3", "bookkeeperreading", vec!["keep", "read"], 9),
    ];
    for (name, s, dictionary, want) in tests {
        let got = min_extra_char(s, &dictionary);
        assert_eq!(got, want, "{name}: min_extra_char()");
    }
}
