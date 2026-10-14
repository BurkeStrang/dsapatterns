use super::bitonicarraymax::find_max_in_bitonic_array;

#[test]
fn test_find_max_in_bitonic_array() {
    let tests = [
        ("Example 1", vec![1, 3, 8, 12, 4, 2], 12),
        ("Example 2", vec![3, 8, 3, 1], 8),
        ("Example 3", vec![1, 3, 8, 12], 12),
        ("Example 4", vec![10, 9, 8], 10),
    ];
    for (name, arr, want) in tests {
        let got = find_max_in_bitonic_array(&arr);
        assert_eq!(got, want, "{name}: find_max_in_bitonic_array()");
    }
}
