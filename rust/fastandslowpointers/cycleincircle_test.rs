use super::cycleincircle::loop_exists;

#[test]
fn test_loop_exists() {
    let tests = [
        (vec![1, 2, -1, 2, 2], true), // Example 1
        (vec![2, 2, -1, 2], true),    // Example 2
        (vec![2, 1, -1, -2], false),  // Example 3
        (vec![1, -1, 1, -1], false),  // No cycle, alternating directions
        (vec![3, 1, 2], true),        // Simple cycle
    ];
    for (arr, want) in tests {
        let got = loop_exists(&arr);
        assert_eq!(got, want, "loop_exists({arr:?})");
    }
}
