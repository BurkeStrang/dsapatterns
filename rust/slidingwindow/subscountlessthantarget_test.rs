use super::subscountlessthantarget::find_subarray_count;

#[test]
fn test_find_subarray_count() {
    let tests = [
        ("Example 1", vec![2, 5, 3, 10], 30, 6),
        ("Example 2", vec![8, 2, 6, 5], 50, 7),
        ("Example 3 (target 0)", vec![10, 5, 2, 6], 0, 0),
        ("Single element < target", vec![1], 2, 1),
        ("Single element >= target", vec![5], 5, 0),
    ];
    for (name, nums, target, want) in tests {
        let got = find_subarray_count(&nums, target);
        assert_eq!(got, want, "{name}: find_subarray_count()");
    }
}
