use super::minheighttrees::find_trees;

#[test]
fn test_find_trees() {
    let tests = [
        (
            "Example 1",
            5,
            vec![[0, 1], [1, 2], [1, 3], [2, 4]],
            vec![1, 2],
        ),
        ("Example 2", 4, vec![[0, 1], [0, 2], [2, 3]], vec![0, 2]),
        ("Example 3", 4, vec![[0, 1], [1, 2], [1, 3]], vec![1]),
        ("Star", 4, vec![[1, 0], [1, 2], [1, 3]], vec![1]),
        (
            "Two centres",
            6,
            vec![[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]],
            vec![3, 4],
        ),
        ("One node", 1, vec![], vec![0]),
        ("No nodes", 0, vec![], vec![]),
    ];
    for (name, nodes, edges, want) in tests {
        let mut got = find_trees(nodes, &edges);
        // the roots can come back in any order
        got.sort_unstable();
        assert_eq!(got, want, "{name}: find_trees()");
    }
}
