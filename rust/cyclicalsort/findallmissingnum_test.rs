use super::findallmissingnum::find_numbers;

#[test]
fn test_find_numbers() {
    let tests = [
        ("Example 1", vec![2, 3, 1, 8, 2, 3, 5, 1], vec![4, 6, 7]),
        ("Example 2", vec![2, 4, 1, 2], vec![3]),
        ("Example 3", vec![2, 3, 2, 1], vec![4]),
    ];
    for (name, mut nums, want) in tests {
        let got = find_numbers(&mut nums);
        assert_eq!(got, want, "{name}: find_numbers()");
    }
}
