use super::infinitearray::{ArrayReader, search_infinite_sorted_array};

#[test]
fn test_search_infinite_sorted_array() {
    let tests = [
        ("Example 1", (4..=30).step_by(2).collect(), 16, 6),
        ("Example 2", (4..=30).step_by(2).collect(), 11, -1),
        ("Example 3", vec![1, 3, 8, 10, 15], 15, 4),
    ];
    for (name, arr, key, want) in tests {
        let reader = ArrayReader { arr };
        let got = search_infinite_sorted_array(&reader, key);
        assert_eq!(got, want, "{name}: search_infinite_sorted_array()");
    }
}
