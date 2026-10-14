use super::decimaltobinary::decimal_to_binary;

#[test]
fn test_decimal_to_binary() {
    let tests = [
        ("Example 1", 2, "10"),
        ("Example 2", 7, "111"),
        ("Example 3", 18, "10010"),
    ];
    for (name, num, want) in tests {
        let got = decimal_to_binary(num);
        assert_eq!(got, want, "{name}: decimal_to_binary()");
    }
}
