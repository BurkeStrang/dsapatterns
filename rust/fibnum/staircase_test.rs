use super::staircase::count_ways;

#[test]
fn test_count_ways() {
    let tests = [("Example 1", 3, 4), ("Example 2", 4, 7)];
    for (name, n, want) in tests {
        let got = count_ways(n);
        assert_eq!(got, want, "{name}: count_ways()");
    }
}
