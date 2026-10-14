use super::ksmallest::find_kth_smallest;

#[test]
fn test_find_kth_smallest() {
    let tests = [
        (
            "Example 1",
            vec![vec![2, 6, 8], vec![3, 6, 7], vec![1, 3, 4]],
            5,
            4,
        ),
        ("Example 2", vec![vec![5, 8, 9], vec![1, 7]], 3, 7),
    ];
    for (name, lists, k, want) in tests {
        let got = find_kth_smallest(&lists, k);
        assert_eq!(got, want, "{name}: find_kth_smallest()");
    }
}
