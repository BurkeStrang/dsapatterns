use super::smallestrange::find_smallest_range;

#[test]
fn test_find_smallest_range() {
    let tests = [
        (
            "Example 1",
            vec![vec![1, 5, 8], vec![4, 12], vec![7, 8, 10]],
            [4, 7],
        ),
        (
            "Example 2",
            vec![vec![1, 9], vec![4, 12], vec![7, 10, 16]],
            [9, 12],
        ),
    ];
    for (name, lists, want) in tests {
        let got = find_smallest_range(&lists);
        assert_eq!(got, want, "{name}: find_smallest_range()");
    }
}
