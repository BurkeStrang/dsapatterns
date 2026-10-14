use super::subsetsum::can_partition_sum;

#[test]
fn test_can_partition_sum() {
    let tests = [
        ("Example 1", vec![1, 2, 3, 7], 6, true),
        ("Example 2", vec![1, 2, 7, 1, 5], 10, true),
        ("Example 3", vec![1, 3, 4, 8], 6, false),
    ];
    for (name, nums, sum, want) in tests {
        let got = can_partition_sum(&nums, sum);
        assert_eq!(got, want, "{name}: can_partition_sum()");
    }
}
