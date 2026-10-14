use super::countbst::count_trees;

#[test]
fn test_count_trees() {
    let tests = [("Example 1", 2, 2), ("Example 2", 3, 5)];
    for (name, n, want) in tests {
        let got = count_trees(n);
        assert_eq!(got, want, "{name}: count_trees()");
    }
}
