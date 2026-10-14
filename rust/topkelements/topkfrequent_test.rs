use super::topkfrequent::find_top_k_frequent_numbers;

#[test]
fn test_find_top_k_frequent_numbers() {
    // numbers with the same frequency may be picked in any order, so each
    // case lists every number that is allowed in the result
    let tests = [
        ("Example 1", vec![1, 3, 5, 12, 11, 12, 11], 2, vec![11, 12]),
        ("Example 2", vec![5, 12, 11, 3, 11], 2, vec![11, 5, 12, 3]),
        (
            "Example 3",
            vec![1, 1, 1, 3, 3, 3, 5, 5, 5, 12],
            2,
            vec![1, 3, 5],
        ),
    ];
    for (name, nums, k, valid) in tests {
        let got = find_top_k_frequent_numbers(&nums, k);
        assert_eq!(got.len(), k, "{name}: got {got:?}");
        for v in &got {
            assert!(valid.contains(v), "{name}: unexpected {v} in {got:?}");
        }
    }
}
