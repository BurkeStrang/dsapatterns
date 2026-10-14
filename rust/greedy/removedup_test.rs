use super::removedup::remove_duplicate_letters;

#[test]
fn test_remove_duplicate_letters() {
    let tests = [
        ("Example 1", "babac", "abc"),
        ("Example 2", "zabccde", "zabcde"),
        ("Example 3", "mnopmn", "mnop"),
    ];
    for (name, s, want) in tests {
        let got = remove_duplicate_letters(s);
        assert_eq!(got, want, "{name}: remove_duplicate_letters()");
    }
}
