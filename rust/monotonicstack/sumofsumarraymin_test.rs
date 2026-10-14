use super::sumofsumarraymin::sum_subarray_mins;

#[test]
fn test_sum_subarray_mins() {
    let tests = [
        ("Example 1", vec![3, 1, 2, 4, 5], 30),
        ("Example 2", vec![2, 6, 5, 4], 36),
        ("Example 3", vec![7, 3, 8], 27),
        ("Single element", vec![5], 5),
        ("All same elements", vec![2, 2, 2], 12),
    ];
    for (name, arr, want) in tests {
        let got = sum_subarray_mins(&arr);
        assert_eq!(got, want, "{name}: sum_subarray_mins()");
    }
}
