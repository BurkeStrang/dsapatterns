use super::kpairslargestsum::find_k_largest_pairs;

#[test]
fn test_find_k_largest_pairs() {
    // the pairs come back with the smallest sum first; pairs with the same
    // sum come back in the order of their numbers
    let tests = [
        (
            "Example 1",
            vec![9, 8, 2],
            vec![6, 3, 1],
            3,
            vec![[9, 3], [8, 6], [9, 6]],
        ),
        (
            "Example 2",
            vec![5, 2, 1],
            vec![2, -1],
            3,
            vec![[2, 2], [5, -1], [5, 2]],
        ),
    ];
    for (name, nums1, nums2, k, want) in tests {
        let got = find_k_largest_pairs(&nums1, &nums2, k);
        assert_eq!(got, want, "{name}: find_k_largest_pairs()");
    }
}
