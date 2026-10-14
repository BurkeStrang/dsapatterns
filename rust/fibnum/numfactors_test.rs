use super::numfactors::factors;

#[test]
fn test_factors() {
    let tests = [("Example 1", 4, 4), ("Example 2", 5, 6)];
    for (name, n, want) in tests {
        let got = factors(n);
        assert_eq!(got, want, "{name}: factors()");
    }
}
