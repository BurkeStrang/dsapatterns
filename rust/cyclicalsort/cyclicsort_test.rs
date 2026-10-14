use super::cyclicsort::sort;

#[test]
fn test_sort() {
    let tests = [
        ("Example 1", vec![3, 1, 5, 4, 2], vec![1, 2, 3, 4, 5]),
        ("Example 2", vec![2, 6, 4, 3, 1, 5], vec![1, 2, 3, 4, 5, 6]),
        ("Example 3", vec![1, 5, 6, 4, 3, 2], vec![1, 2, 3, 4, 5, 6]),
    ];
    for (name, mut nums, want) in tests {
        sort(&mut nums);
        assert_eq!(nums, want, "{name}: sort()");
    }
}
