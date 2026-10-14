use super::factorcombinations::get_factors;

#[test]
fn test_get_factors() {
    let tests = [
        ("Example 1", 8, vec![vec![2, 2, 2], vec![2, 4]]),
        (
            "Example 2",
            20,
            vec![vec![2, 2, 5], vec![2, 10], vec![4, 5]],
        ),
        ("A prime has none", 7, vec![]),
    ];
    for (name, n, want) in tests {
        let mut got = get_factors(n);
        // the combinations may come back in any order
        got.sort();
        assert_eq!(got, want, "{name}: get_factors()");
    }
}
