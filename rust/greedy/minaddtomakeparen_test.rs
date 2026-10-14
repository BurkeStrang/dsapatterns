use super::minaddtomakeparen::min_add_to_make_valid;

#[test]
fn test_min_add_to_make_valid() {
    let tests = [
        ("Example 1", "(()", 1),
        ("Example 2", "))((", 4),
        ("Example 3", "(()())(", 1),
        ("Already valid", "()()", 0),
    ];
    for (name, s, want) in tests {
        let got = min_add_to_make_valid(s);
        assert_eq!(got, want, "{name}: min_add_to_make_valid()");
    }
}
