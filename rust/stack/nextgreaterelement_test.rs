use super::nextgreaterelement::next_larger_element;

#[test]
fn test_next_larger_element() {
    let tests = [
        ("Example 1", vec![4, 5, 2, 25], vec![5, 25, 25, -1]),
        ("Example 2", vec![13, 7, 6, 12], vec![-1, 12, 12, -1]),
        ("Example 3", vec![1, 2, 3, 4, 5], vec![2, 3, 4, 5, -1]),
    ];
    for (name, arr, want) in tests {
        let got = next_larger_element(&arr);
        assert_eq!(got, want, "{name}: next_larger_element()");
    }
}
