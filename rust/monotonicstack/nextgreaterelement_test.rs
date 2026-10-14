use super::nextgreaterelement::next_greater_element;

#[test]
fn test_next_greater_element() {
    let tests = [
        (
            "Example 1",
            vec![4, 2, 6],
            vec![6, 2, 4, 5, 3, 7],
            vec![5, 4, 7],
        ),
        (
            "Example 2",
            vec![9, 7, 1],
            vec![1, 7, 9, 5, 4, 3],
            vec![-1, 9, 7],
        ),
        (
            "Example 3",
            vec![5, 12, 3],
            vec![12, 3, 5, 4, 10, 15],
            vec![10, 15, 5],
        ),
        ("No greater element", vec![8], vec![8, 7, 6], vec![-1]),
        (
            "All increasing",
            vec![1, 2, 3],
            vec![1, 2, 3, 4],
            vec![2, 3, 4],
        ),
    ];
    for (name, nums1, nums2, want) in tests {
        let got = next_greater_element(&nums1, &nums2);
        assert_eq!(got, want, "{name}: next_greater_element()");
    }
}
