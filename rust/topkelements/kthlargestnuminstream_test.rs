use super::kthlargestnuminstream::KthLargest;

#[test]
fn test_kth_largest_add() {
    let tests = [
        ("Example 1", vec![3, 1, 5, 12, 2, 11], 4, 6, 5),
        ("Example 2", vec![3, 1, 5, 12, 2, 11], 4, 13, 5),
        ("Example 3", vec![3, 1, 5, 12, 2, 11], 4, 4, 4),
    ];
    for (name, nums, k, num, want) in tests {
        let mut s = KthLargest::new(&nums, k);
        let got = s.add(num);
        assert_eq!(got, want, "{name}: add()");
    }
}
