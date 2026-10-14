use super::equalsumpartition::can_partition;

#[test]
fn test_can_partition() {
    let tests = [
        ("Example 1", vec![1, 2, 3, 4], true),
        ("Example 2", vec![1, 1, 3, 4, 7], true),
        ("Example 3", vec![2, 3, 4, 6], false),
    ];
    for (name, nums, want) in tests {
        let got = can_partition(&nums);
        assert_eq!(got, want, "{name}: can_partition()");
    }
}
