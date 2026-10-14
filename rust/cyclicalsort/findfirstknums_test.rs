use super::findfirstknums::find_first_k;

#[test]
fn test_find_first_k() {
    let tests = [
        ("Example 1", vec![3, -1, 4, 5, 5], 3, vec![1, 2, 6]),
        ("Example 2", vec![2, 3, 4], 3, vec![1, 5, 6]),
        ("Example 3", vec![-2, -3, 4], 2, vec![1, 2]),
    ];
    for (name, mut nums, k, want) in tests {
        let got = find_first_k(&mut nums, k);
        assert_eq!(got, want, "{name}: find_first_k()");
    }
}
