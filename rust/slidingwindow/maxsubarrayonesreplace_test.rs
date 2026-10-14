use super::maxsubarrayonesreplace::max_ones_length;

#[test]
fn test_max_ones_length() {
    let tests = [
        ("Example 1", vec![0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1], 2, 6),
        (
            "Example 2",
            vec![0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1],
            3,
            9,
        ),
        ("Example 3", vec![1, 0, 0, 1, 1, 0, 1, 1], 2, 6),
    ];
    for (name, arr, k, want) in tests {
        let got = max_ones_length(&arr, k);
        assert_eq!(got, want, "{name}: max_ones_length()");
    }
}
