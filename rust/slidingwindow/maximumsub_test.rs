use super::maximumsub::find_max_sum_sub_array;

#[test]
fn test_find_max_sum_sub_array() {
    let tests = [
        ("basic case", 3, vec![2, 1, 5, 1, 3, 2], 9),
        ("single element window", 1, vec![4, 2, 7, 1], 7),
        ("window equals array length", 4, vec![1, 2, 3, 4], 10),
        ("empty array", 3, vec![], 0),
    ];
    for (name, k, arr, want) in tests {
        let got = find_max_sum_sub_array(k, &arr);
        assert_eq!(got, want, "{name}: find_max_sum_sub_array()");
    }
}
