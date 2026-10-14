use super::findminmissingposnum::find_mis;

#[test]
fn test_find_mis() {
    let tests = [
        ("Example 1", vec![-3, 1, 5, 4, 2], 3),
        ("Example 2", vec![3, -2, 0, 1, 2], 4),
        ("Example 3", vec![3, 2, 5, 1], 4),
        ("Example 4", vec![33, 37, 5], 1),
    ];
    for (name, mut nums, want) in tests {
        let got = find_mis(&mut nums);
        assert_eq!(got, want, "{name}: find_mis()");
    }
}
