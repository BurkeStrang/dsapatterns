use super::ceiling::search_ceiling_of_a_number;

#[test]
fn test_search_ceiling_of_a_number() {
    let tests = [
        ("Example 1", vec![4, 6, 10], 5, 1),
        ("key exists in array", vec![1, 3, 8, 10, 15], 8, 2),
        ("key between two elements", vec![1, 3, 8, 10, 15], 12, 4),
        ("key smaller than all elements", vec![1, 3, 8, 10, 15], 0, 0),
        (
            "key larger than all elements",
            vec![1, 3, 8, 10, 15],
            20,
            -1,
        ),
        ("key is smallest element", vec![1, 3, 8, 10, 15], 1, 0),
        ("key is largest element", vec![1, 3, 8, 10, 15], 15, 4),
        (
            "key just below a middle element",
            vec![2, 4, 6, 8, 10],
            5,
            2,
        ),
        ("single element - key matches", vec![5], 5, 0),
        ("single element - key is smaller", vec![5], 3, 0),
        ("single element - key is larger", vec![5], 7, -1),
    ];
    for (name, arr, key, want) in tests {
        let got = search_ceiling_of_a_number(&arr, key);
        assert_eq!(got, want, "{name}: search_ceiling_of_a_number()");
    }
}
