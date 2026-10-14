use super::reconstructsequence::can_construct;

#[test]
fn test_can_construct() {
    let tests = [
        (
            "Example 1",
            vec![1, 2, 3, 4],
            vec![vec![1, 2], vec![2, 3], vec![3, 4]],
            true,
        ),
        (
            "Example 2",
            vec![1, 2, 3, 4],
            vec![vec![1, 2], vec![2, 3], vec![2, 4]],
            false,
        ),
        (
            "Example 3",
            vec![3, 1, 4, 2, 5],
            vec![vec![3, 1, 5], vec![1, 4, 2, 5]],
            true,
        ),
        (
            "Different order",
            vec![1, 2, 3],
            vec![vec![3, 2], vec![2, 1]],
            false,
        ),
        ("Missing number", vec![1, 2, 3], vec![vec![1, 2]], false),
        (
            "Cyclic sequences",
            vec![1, 2, 3],
            vec![vec![1, 2], vec![2, 3], vec![3, 1]],
            false,
        ),
    ];
    for (name, original_seq, sequences, want) in tests {
        let got = can_construct(&original_seq, &sequences);
        assert_eq!(got, want, "{name}: can_construct()");
    }
}
