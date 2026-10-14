use super::kclosestnumbers::find_closest_elements;

#[test]
fn test_find_closest_elements() {
    let tests = [
        ("Example 1", vec![5, 6, 7, 8, 9], 3, 7, vec![6, 7, 8]),
        ("Example 2", vec![2, 4, 5, 6, 9], 3, 6, vec![4, 5, 6]),
        ("Example 3", vec![2, 4, 5, 6, 9], 3, 10, vec![5, 6, 9]),
    ];
    for (name, arr, k, x, want) in tests {
        let got = find_closest_elements(&arr, k, x);
        assert_eq!(got, want, "{name}: find_closest_elements()");
    }
}
