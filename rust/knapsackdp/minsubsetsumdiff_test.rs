use super::minsubsetsumdiff::can_partition_min;

#[test]
fn test_can_partition_min() {
    let tests = [
        ("Example 1", vec![1, 2, 3, 9], 3),
        ("Example 2", vec![1, 2, 7, 1, 5], 0),
        ("Example 3", vec![1, 3, 100, 4], 92),
    ];
    for (name, num, want) in tests {
        let got = can_partition_min(&num);
        assert_eq!(got, want, "{name}: can_partition_min()");
    }
}
