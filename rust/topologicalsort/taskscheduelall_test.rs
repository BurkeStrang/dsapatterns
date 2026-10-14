use super::taskscheduelall::print_orders;

#[test]
fn test_print_orders() {
    // want lists every valid ordering; they can come back in any order
    let tests = [
        (
            "Example 1: two orderings",
            4,
            vec![[3, 2], [3, 0], [2, 0], [2, 1]],
            vec![vec![3, 2, 0, 1], vec![3, 2, 1, 0]],
        ),
        (
            "Example 2: one ordering",
            3,
            vec![[0, 1], [1, 2]],
            vec![vec![0, 1, 2]],
        ),
        (
            "Example 3: thirteen orderings",
            6,
            vec![[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]],
            vec![
                vec![0, 1, 4, 3, 2, 5],
                vec![0, 1, 3, 4, 2, 5],
                vec![0, 1, 3, 2, 4, 5],
                vec![0, 1, 3, 2, 5, 4],
                vec![1, 0, 3, 4, 2, 5],
                vec![1, 0, 3, 2, 4, 5],
                vec![1, 0, 3, 2, 5, 4],
                vec![1, 0, 4, 3, 2, 5],
                vec![1, 3, 0, 2, 4, 5],
                vec![1, 3, 0, 2, 5, 4],
                vec![1, 3, 0, 4, 2, 5],
                vec![1, 3, 2, 0, 5, 4],
                vec![1, 3, 2, 0, 4, 5],
            ],
        ),
        (
            "No prerequisites: every arrangement",
            3,
            vec![],
            vec![
                vec![0, 1, 2],
                vec![0, 2, 1],
                vec![1, 0, 2],
                vec![1, 2, 0],
                vec![2, 0, 1],
                vec![2, 1, 0],
            ],
        ),
        (
            "Cyclic prerequisites: no ordering",
            3,
            vec![[0, 1], [1, 2], [2, 0]],
            vec![],
        ),
        ("No tasks", 0, vec![], vec![]),
    ];
    for (name, tasks, prerequisites, mut want) in tests {
        let mut got = print_orders(tasks, &prerequisites);
        got.sort();
        want.sort();
        assert_eq!(got, want, "{name}: print_orders()");
    }
}
