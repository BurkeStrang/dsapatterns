use super::distinctislands::find_distinct_islands_dfs;

#[test]
fn test_find_distinct_islands_dfs() {
    let tests = [
        (
            "two distinct islands",
            vec![
                vec![1, 1, 0, 0, 0],
                vec![1, 0, 0, 1, 1],
                vec![0, 0, 0, 1, 1],
            ],
            2,
        ),
        (
            "all islands same shape",
            vec![vec![1, 0, 1, 0], vec![1, 0, 1, 0]],
            1,
        ),
        ("no islands", vec![vec![0, 0], vec![0, 0]], 0),
        ("single island", vec![vec![1, 1], vec![1, 1]], 1),
    ];
    for (name, matrix, want) in tests {
        let got = find_distinct_islands_dfs(&matrix);
        assert_eq!(got, want, "{name}: find_distinct_islands_dfs()");
    }
}
