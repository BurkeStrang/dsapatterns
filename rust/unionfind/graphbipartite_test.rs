use super::graphbipartite::is_bipartite;

#[test]
fn test_is_bipartite() {
    let tests = [
        (
            "Example 1",
            vec![vec![1, 3], vec![0, 2], vec![1, 3], vec![0, 2]],
            true,
        ),
        ("Example 2", vec![vec![1], vec![0], vec![3], vec![2]], true),
        (
            "Example 3",
            vec![vec![1, 2, 3], vec![0, 2], vec![0, 1, 3], vec![0, 2]],
            false,
        ),
        ("No edges", vec![vec![], vec![], vec![]], true),
    ];
    for (name, graph, want) in tests {
        let got = is_bipartite(&graph);
        assert_eq!(got, want, "{name}: is_bipartite()");
    }
}
