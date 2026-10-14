use super::orderagnosticbs::desc_or_asc_search;

#[test]
fn test_desc_or_asc_search() {
    let tests = [
        ("ascending - key found in middle", vec![1, 3, 5, 7, 9], 5, 2),
        ("ascending - key found at start", vec![1, 3, 5, 7, 9], 1, 0),
        ("ascending - key found at end", vec![1, 3, 5, 7, 9], 9, 4),
        ("ascending - key not found", vec![1, 3, 5, 7, 9], 4, -1),
        (
            "descending - key found in middle",
            vec![9, 7, 5, 3, 1],
            5,
            2,
        ),
        ("descending - key found at start", vec![9, 7, 5, 3, 1], 9, 0),
        ("descending - key found at end", vec![9, 7, 5, 3, 1], 1, 4),
        ("descending - key not found", vec![9, 7, 5, 3, 1], 4, -1),
        ("single element - found", vec![42], 42, 0),
        ("single element - not found", vec![42], 7, -1),
    ];
    for (name, arr, key, want) in tests {
        let got = desc_or_asc_search(&arr, key);
        assert_eq!(got, want, "{name}: desc_or_asc_search()");
    }
}
