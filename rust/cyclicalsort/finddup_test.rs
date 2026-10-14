use super::finddup::find_dup;

#[test]
fn test_find_dup() {
    let tests = [
        ("Example 1", vec![1, 4, 4, 3, 2], 4),
        ("Example 2", vec![2, 1, 3, 3, 5, 4], 3),
        ("Example 3", vec![2, 4, 1, 4, 4], 4),
    ];
    for (name, nums, want) in tests {
        let got = find_dup(&nums);
        assert_eq!(got, want, "{name}: find_dup()");
    }
}
