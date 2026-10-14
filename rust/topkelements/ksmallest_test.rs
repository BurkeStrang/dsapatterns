use super::ksmallest::find_kth_smallest_number;

#[test]
fn test_find_kth_smallest_number() {
    let tests = [
        ("Example 1", vec![1, 5, 12, 2, 11, 5], 3, 5),
        ("Example 2", vec![1, 5, 12, 2, 11, 5], 4, 5),
        ("Example 3", vec![5, 12, 11, -1, 12], 3, 11),
        ("Example 4", vec![1, 5, 12, 2, 11, 5], 1, 1),
    ];
    for (name, nums, k, want) in tests {
        let got = find_kth_smallest_number(&nums, k);
        assert_eq!(got, want, "{name}: find_kth_smallest_number()");
    }
}
