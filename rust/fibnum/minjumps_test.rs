use super::minjumps::count_min_jumps;

#[test]
fn test_count_min_jumps() {
    let tests = [
        ("Example 1", vec![2, 1, 1, 1, 4], Some(3)),
        ("Example 2", vec![1, 1, 3, 6, 9, 3, 0, 1, 3], Some(4)),
        ("Blocked by a zero", vec![1, 0, 2], None),
        ("Single element", vec![0], Some(0)),
    ];
    for (name, jumps, want) in tests {
        let got = count_min_jumps(&jumps);
        assert_eq!(got, want, "{name}: count_min_jumps()");
    }
}
