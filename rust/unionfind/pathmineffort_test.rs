use super::pathmineffort::minimum_effort_path;

#[test]
fn test_minimum_effort_path() {
    let tests = [
        (
            "Example 1",
            vec![vec![1, 2, 3], vec![3, 8, 4], vec![5, 3, 5]],
            1,
        ),
        (
            "Example 2",
            vec![vec![1, 2, 2], vec![3, 3, 3], vec![5, 3, 1]],
            2,
        ),
        (
            "Example 3",
            vec![vec![1, 1, 1], vec![1, 1, 1], vec![1, 1, 1]],
            0,
        ),
        ("One cell", vec![vec![7]], 0),
    ];
    for (name, heights, want) in tests {
        let got = minimum_effort_path(&heights);
        assert_eq!(got, want, "{name}: minimum_effort_path()");
    }
}
