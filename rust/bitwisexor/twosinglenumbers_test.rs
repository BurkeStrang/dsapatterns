use super::twosinglenumbers::find_single_numbers;

#[test]
fn test_find_single_numbers() {
    let tests = [
        ("Example 1", vec![1, 4, 2, 1, 3, 5, 6, 2, 3, 5], [4, 6]),
        ("Example 2", vec![2, 1, 3, 2], [1, 3]),
    ];
    for (name, nums, want) in tests {
        let mut got = find_single_numbers(&nums);
        // the two numbers may come back in either order
        got.sort();
        assert_eq!(got, want, "{name}: find_single_numbers()");
    }
}
