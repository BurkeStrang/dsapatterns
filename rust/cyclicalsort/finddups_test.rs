use super::finddups::find_dups;

#[test]
fn test_find_dups() {
    let tests = [
        ("Example 1", vec![3, 4, 4, 5, 5], vec![5, 4]),
        ("Example 2", vec![5, 4, 7, 2, 3, 5, 3], vec![3, 5]),
    ];
    for (name, mut nums, want) in tests {
        let got = find_dups(&mut nums);
        assert_eq!(got, want, "{name}: find_dups()");
    }
}
