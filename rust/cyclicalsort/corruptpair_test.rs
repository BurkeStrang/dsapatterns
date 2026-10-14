use super::corruptpair::find_corrupt;

#[test]
fn test_find_corrupt() {
    let tests = [
        ("Example 1", vec![3, 1, 2, 5, 2], Some((2, 4))),
        ("Example 2", vec![3, 1, 2, 3, 6, 4], Some((3, 5))),
    ];
    for (name, mut nums, want) in tests {
        let got = find_corrupt(&mut nums);
        assert_eq!(got, want, "{name}: find_corrupt()");
    }
}
