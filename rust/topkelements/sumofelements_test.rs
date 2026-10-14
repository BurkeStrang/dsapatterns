use super::sumofelements::find_sum_of_elements;

#[test]
fn test_find_sum_of_elements() {
    let tests = [
        ("basic test", vec![1, 3, 12, 5, 15, 11], 3, 6, 23),
        ("second test", vec![3, 5, 8, 7], 1, 4, 12),
    ];
    for (name, nums, k1, k2, want) in tests {
        let got = find_sum_of_elements(&nums, k1, k2);
        assert_eq!(got, want, "{name}: find_sum_of_elements()");
    }
}
