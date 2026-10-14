use super::countofsubsetsum::count_subsets;

#[test]
fn test_count_subsets() {
    let tests = [
        ("Example 1", vec![1, 1, 2, 3], 4, 3),
        ("Example 2", vec![1, 2, 7, 1, 5], 9, 3),
    ];
    for (name, num, sum, want) in tests {
        let got = count_subsets(&num, sum);
        assert_eq!(got, want, "{name}: count_subsets()");
    }
}
