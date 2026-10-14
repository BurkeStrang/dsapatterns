use super::rotationcount::count_rotations;

#[test]
fn test_count_rotations() {
    let tests = [
        ("Example 1", vec![10, 15, 1, 3, 8], 2),
        ("Example 2", vec![4, 5, 7, 9, 10, -1, 2], 5),
        ("Example 3", vec![1, 3, 8, 10], 0),
    ];
    for (name, arr, want) in tests {
        let got = count_rotations(&arr);
        assert_eq!(got, want, "{name}: count_rotations()");
    }
}
