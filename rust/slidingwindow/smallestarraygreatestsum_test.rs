use super::smallestarraygreatestsum::find_min_sub_array;

#[test]
fn test_find_min_sub_array() {
    let tests = [
        ("Example 1", 7, vec![2, 1, 5, 2, 3, 2], 2),
        ("Example 2", 7, vec![2, 1, 5, 2, 8], 1),
        ("Example 3", 8, vec![3, 4, 1, 1, 6], 3),
        ("No subarray meets S", 20, vec![1, 2, 3, 4], 0),
    ];
    for (name, s, arr, want) in tests {
        let got = find_min_sub_array(s, &arr);
        assert_eq!(got, want, "{name}: find_min_sub_array()");
    }
}
