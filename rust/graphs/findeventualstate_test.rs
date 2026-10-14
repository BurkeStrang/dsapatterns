use super::findeventualstate::eventual_safe_nodes;

#[test]
fn test_eventual_safe_nodes() {
    let tests = [
        (
            "Example 1: [3,4,5,6]",
            vec![
                vec![1, 2],
                vec![2, 3],
                vec![2],
                vec![],
                vec![5],
                vec![6],
                vec![],
            ],
            vec![3, 4, 5, 6],
        ),
        (
            "Example 2: [2,4,5,6]",
            vec![
                vec![1, 2],
                vec![2, 3],
                vec![5],
                vec![0],
                vec![],
                vec![],
                vec![4],
            ],
            vec![2, 4, 5, 6],
        ),
        (
            "Example 3: [0,1,2,3,4]",
            vec![vec![1, 2, 3], vec![2, 3], vec![3], vec![], vec![0, 1, 2]],
            vec![0, 1, 2, 3, 4],
        ),
    ];
    for (name, graph, want) in tests {
        let got = eventual_safe_nodes(&graph);
        assert_eq!(got, want, "{name}: eventual_safe_nodes()");
    }
}
