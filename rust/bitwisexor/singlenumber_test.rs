use super::singlenumber::find_single_number;

#[test]
fn test_find_single_number() {
    let tests = [
        ("Example 1", vec![1, 4, 2, 1, 3, 2, 3], 4),
        ("Example 2", vec![7, 9, 7], 9),
        ("Example 3", vec![5, 6, 7, 5, 6], 7),
    ];
    for (name, arr, want) in tests {
        let got = find_single_number(&arr);
        assert_eq!(got, want, "{name}: find_single_number()");
    }
}
