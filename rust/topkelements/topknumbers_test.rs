use super::topknumbers::find_k_largest_numbers;

#[test]
fn test_find_k_largest_numbers() {
    let tests = [
        ("Example 1", vec![3, 1, 5, 12, 2, 11], 3, vec![5, 11, 12]),
        ("Example 2", vec![5, 12, 11, -1, 12], 3, vec![11, 12, 12]),
        (
            "All negative",
            vec![-3, -1, -5, -12, -2, -11],
            3,
            vec![-3, -2, -1],
        ),
    ];
    for (name, nums, k, want) in tests {
        let mut got = find_k_largest_numbers(&nums, k);
        // the numbers may come back in any order
        got.sort_unstable();
        assert_eq!(got, want, "{name}: find_k_largest_numbers()");
    }
}
