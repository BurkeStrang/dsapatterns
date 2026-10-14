use super::removeminmax::min_moves;

#[test]
fn test_min_moves() {
    let tests = [
        ("Example 1", vec![3, 2, 5, 1, 4], 3),
        ("Example 2", vec![7, 5, 6, 8, 1], 2),
        ("Single element", vec![9], 1),
    ];
    for (name, nums, want) in tests {
        let got = min_moves(&nums);
        assert_eq!(got, want, "{name}: min_moves()");
    }
}
