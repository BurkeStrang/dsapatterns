use super::findmissingnum::find_missing_number;

#[test]
fn test_find_missing_number() {
    let tests = [
        ("Example 1", vec![4, 0, 3, 1], 2),
        ("Example 2", vec![8, 3, 5, 2, 4, 6, 0, 1], 7),
    ];
    for (name, mut nums, want) in tests {
        let got = find_missing_number(&mut nums);
        assert_eq!(got, want, "{name}: find_missing_number()");
    }
}
