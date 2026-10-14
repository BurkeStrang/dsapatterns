use super::issubarray::is_subarray;

#[test]
fn test_is_subarray() {
    let tests = [
        ("Example 1", vec![1, 2, 3], vec![2, 3], true),
        (
            "Same numbers, not next to each other",
            vec![1, 2, 3],
            vec![1, 3],
            false,
        ),
        ("Longer than the array", vec![1, 2], vec![1, 2, 3], false),
        ("Empty subarray", vec![1, 2], vec![], true),
    ];
    for (name, nums, sub, want) in tests {
        let got = is_subarray(&nums, &sub);
        assert_eq!(got, want, "{name}: is_subarray()");
    }
}
