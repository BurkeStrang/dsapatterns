use super::findpath::valid_path;

#[test]
fn test_valid_path() {
    let tests = [
        (
            "path exists simple",
            4,
            vec![[0, 1], [1, 2], [2, 3]],
            0,
            3,
            true,
        ),
        (
            "no path between disconnected components",
            4,
            vec![[0, 1], [2, 3]],
            0,
            3,
            false,
        ),
        (
            "no path with isolated nodes",
            5,
            vec![[0, 1], [3, 4]],
            0,
            4,
            false,
        ),
        ("single node graph", 1, vec![], 0, 0, true),
    ];
    for (name, n, edges, start, end, want) in tests {
        let got = valid_path(n, &edges, start, end);
        assert_eq!(got, want, "{name}: valid_path()");
    }
}
