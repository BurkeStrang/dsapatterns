use super::minnumreachallnodes::find_smallest_set_of_vertices;

#[test]
fn test_find_smallest_set_of_vertices() {
    let tests = [
        (
            "Example 1",
            6,
            vec![[0, 1], [0, 2], [2, 5], [3, 4], [4, 2]],
            vec![0, 3],
        ),
        ("Single node", 1, vec![], vec![0]),
        ("Disconnected nodes", 3, vec![], vec![0, 1, 2]),
        (
            "All nodes connected in a chain",
            4,
            vec![[0, 1], [1, 2], [2, 3]],
            vec![0],
        ),
    ];
    for (name, n, edges, want) in tests {
        let got = find_smallest_set_of_vertices(n, &edges);
        assert_eq!(got, want, "{name}: find_smallest_set_of_vertices()");
    }
}
