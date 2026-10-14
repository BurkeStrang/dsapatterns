use super::numberrange::find_range;

#[test]
fn test_find_range() {
    let tests = [
        ("example1", vec![4, 6, 6, 6, 9], 6, [1, 3]),
        ("example2", vec![1, 3, 8, 10, 15], 10, [3, 3]),
        ("example3", vec![1, 3, 8, 10, 15], 12, [-1, -1]),
    ];
    for (name, arr, key, want) in tests {
        let got = find_range(&arr, key);
        assert_eq!(got, want, "{name}: find_range()");
    }
}
