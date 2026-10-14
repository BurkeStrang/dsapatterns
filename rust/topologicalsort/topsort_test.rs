use super::shared::is_topological_order;
use super::topsort::sort;

#[test]
fn test_sort() {
    let tests = [
        (
            "Test Case 1",
            6,
            vec![[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]],
        ),
        ("Test Case 2", 4, vec![[0, 1], [1, 2], [2, 3]]),
    ];
    for (name, vertices, edges) in tests {
        let got = sort(vertices, &edges);
        assert!(
            is_topological_order(&got, vertices, &edges),
            "{name}: sort() = {got:?} is not a topological order"
        );
    }
}

#[test]
fn test_sort_cycle() {
    let got = sort(3, &[[0, 1], [1, 2], [2, 0]]);
    assert_eq!(got, vec![], "a graph with a cycle has no order");
}
