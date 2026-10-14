use super::rotatedarraydups::search_rotated_dups;

#[test]
fn test_search_rotated_dups() {
    let tests = [
        ("Example 1", vec![3, 7, 3, 3, 3], 7, 1),
        ("Example 2", vec![3, 3, 3, 7, 3], 7, 3),
        ("Example 3", vec![3, 3, 7, 3, 3], 7, 2),
    ];
    for (name, arr, key, want) in tests {
        let got = search_rotated_dups(&arr, key);
        assert_eq!(got, want, "{name}: search_rotated_dups()");
    }
}
