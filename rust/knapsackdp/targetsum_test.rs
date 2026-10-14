use super::targetsum::find_target_subsets;

#[test]
fn test_find_target_subsets() {
    let tests = [
        ("Example 1", vec![1, 1, 2, 3], 1, 3),
        ("Example 2", vec![1, 2, 7, 1], 9, 2),
    ];
    for (name, num, s, want) in tests {
        let got = find_target_subsets(&num, s);
        assert_eq!(got, want, "{name}: find_target_subsets()");
    }
}
