use super::largestuniquenum::largest_unique_number;

#[test]
fn test_largest_unique_number() {
    let tests = [
        ("Example 1", vec![5, 7, 3, 7, 5, 8], 8),
        ("Example 2", vec![1, 2, 3, 2, 1, 4, 4], 3),
        ("Example 3", vec![9, 9, 8, 8, 7, 7], -1),
    ];
    for (name, a, want) in tests {
        let got = largest_unique_number(&a);
        assert_eq!(got, want, "{name}: largest_unique_number()");
    }
}
