use super::scheduelingtask::schedule_tasks;

#[test]
fn test_schedule_tasks() {
    let tests = [
        ("Example 1", vec!["a", "a", "a", "b", "c", "c"], 2, 7),
        ("Example 2", vec!["a", "b", "a"], 3, 5),
    ];
    for (name, tasks, k, want) in tests {
        let got = schedule_tasks(&tasks, k);
        assert_eq!(got, want, "{name}: schedule_tasks()");
    }
}
