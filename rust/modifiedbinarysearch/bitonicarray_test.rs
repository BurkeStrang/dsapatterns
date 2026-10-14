use super::bitonicarray::search_bitonic;

#[test]
fn test_search_bitonic() {
    let tests = [
        ("Example 1", vec![1, 3, 8, 4, 3], 4, 3),
        ("Example 2", vec![3, 8, 3, 1], 8, 1),
        ("Example 3", vec![1, 3, 8, 12], 12, 3),
        ("Example 4", vec![10, 9, 8], 10, 0),
    ];
    for (name, arr, key, want) in tests {
        let got = search_bitonic(&arr, key);
        assert_eq!(got, want, "{name}: search_bitonic()");
    }
}
