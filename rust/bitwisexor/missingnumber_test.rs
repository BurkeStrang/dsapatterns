use super::missingnumber::find_missing_number;

#[test]
fn test_find_missing_number() {
    let tests = [
        ("Example 1", vec![1, 2, 3, 5], 4),
        ("Example 2", vec![1, 2, 4, 5], 3),
        ("Example 3", (1..=20).collect(), 21),
    ];
    for (name, arr, want) in tests {
        let got = find_missing_number(&arr);
        assert_eq!(got, want, "{name}: find_missing_number()");
    }
}
