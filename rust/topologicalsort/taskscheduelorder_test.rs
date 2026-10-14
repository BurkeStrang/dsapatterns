use super::shared::is_topological_order;
use super::taskscheduelorder::find_order;

#[test]
fn test_find_order() {
    let tests = [
        (
            "Test Case 1",
            6,
            vec![[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]],
        ),
        ("Test Case 2", 3, vec![[0, 1], [1, 2]]),
    ];
    for (name, tasks, prerequisites) in tests {
        let got = find_order(tasks, &prerequisites);
        assert!(
            is_topological_order(&got, tasks, &prerequisites),
            "{name}: find_order() = {got:?} is not a valid order"
        );
    }
}

#[test]
fn test_find_order_cycle() {
    let got = find_order(3, &[[0, 1], [1, 2], [2, 0]]);
    assert_eq!(got, vec![], "cyclic prerequisites have no order");
}
