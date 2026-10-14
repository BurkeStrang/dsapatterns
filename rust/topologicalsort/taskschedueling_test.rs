use super::taskschedueling::is_scheduling_possible;

#[test]
fn test_is_scheduling_possible() {
    let tests = [
        ("Test Case 1", 3, vec![[0, 1], [1, 2]], true),
        ("Test Case 2", 3, vec![[0, 1], [1, 2], [2, 0]], false),
        ("Test Case 3", 4, vec![[0, 1], [1, 2], [2, 3]], true),
    ];
    for (name, tasks, prerequisites, want) in tests {
        let got = is_scheduling_possible(tasks, &prerequisites);
        assert_eq!(got, want, "{name}: is_scheduling_possible()");
    }
}
