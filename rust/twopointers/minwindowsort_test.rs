use super::minwindowsort::min_sort;

#[test]
fn test_min_sort() {
    let tests = [
        ("Example 1", vec![1, 2, 5, 3, 7, 10, 9, 12], 5),
        ("Example 2", vec![1, 3, 2, 0, -1, 7, 10], 5),
        ("Example 3", vec![1, 2, 3], 0),
        ("Example 4", vec![3, 2, 1], 3),
    ];
    for (name, arr, want) in tests {
        let got = min_sort(&arr);
        assert_eq!(got, want, "{name}: min_sort()");
    }
}
