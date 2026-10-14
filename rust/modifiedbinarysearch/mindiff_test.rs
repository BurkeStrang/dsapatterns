use super::mindiff::search_min_diff;

#[test]
fn test_search_min_diff() {
    let tests = [
        ("Example 1", vec![4, 6, 10], 7, 6),
        ("Example 2", vec![4, 6, 10], 4, 4),
        ("Example 3", vec![1, 3, 8, 10, 15], 12, 10),
        ("Example 4", vec![4, 6, 10], 17, 10),
    ];
    for (name, arr, key, want) in tests {
        let got = search_min_diff(&arr, key);
        assert_eq!(got, want, "{name}: search_min_diff()");
    }
}
