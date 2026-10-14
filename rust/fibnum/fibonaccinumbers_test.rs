use super::fibonaccinumbers::calculate_fibonacci;

#[test]
fn test_calculate_fibonacci() {
    let tests = [
        ("Example 1", 0, 0),
        ("Example 2", 1, 1),
        ("Example 3", 2, 1),
        ("Example 4", 3, 2),
        ("Example 5", 4, 3),
        ("Example 6", 55, 139583862445),
    ];
    for (name, n, want) in tests {
        let got = calculate_fibonacci(n);
        assert_eq!(got, want, "{name}: calculate_fibonacci()");
    }
}
