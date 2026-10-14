use super::maxdistinctelements::find_maximum_distinct_elements;

#[test]
fn test_find_maximum_distinct_elements() {
    let tests = [
        ("Example 1", vec![7, 3, 5, 8, 5, 3, 3], 2, 3),
        ("Example 2", vec![3, 5, 12, 11, 12], 3, 2),
        ("Example 3", vec![1, 2, 3, 3, 3, 3, 4, 4, 5, 5, 5], 2, 3),
    ];
    for (name, nums, k, want) in tests {
        let got = find_maximum_distinct_elements(&nums, k);
        assert_eq!(got, want, "{name}: find_maximum_distinct_elements()");
    }
}
