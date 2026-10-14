use super::rotatedarray::search_rotated;

#[test]
fn test_search_rotated() {
    let tests = [
        ("Example 1", vec![10, 15, 1, 3, 8], 15, 1),
        ("Example 2", vec![4, 5, 7, 9, 10, -1, 2], 10, 4),
        ("Example 3", vec![10, 15, 1, 3, 8], 100, -1),
        ("Example 4", vec![10, 15, 1, 3, 8], 1, 2),
    ];
    for (name, arr, key, want) in tests {
        let got = search_rotated(&arr, key);
        assert_eq!(got, want, "{name}: search_rotated()");
    }
}
