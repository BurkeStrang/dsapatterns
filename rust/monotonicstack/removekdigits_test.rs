use super::removekdigits::remove_kdigits;

#[test]
fn test_remove_kdigits() {
    let tests = [
        ("Example 1", "1432219", 3, "1219"),
        ("Example 2", "10200", 1, "200"),
        ("Example 3", "1901042", 4, "2"),
        ("Remove all digits", "10", 2, "0"),
        ("Leading zeros after removal", "100200", 1, "200"),
        ("No removal needed", "12345", 0, "12345"),
    ];
    for (name, num, k, want) in tests {
        let got = remove_kdigits(num, k);
        assert_eq!(got, want, "{name}: remove_kdigits()");
    }
}
