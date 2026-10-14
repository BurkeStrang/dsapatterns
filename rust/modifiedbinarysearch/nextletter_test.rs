use super::nextletter::search_next_letter;

#[test]
fn test_search_next_letter() {
    let tests = [
        ("key in middle of array", vec!['a', 'c', 'f', 'h'], 'f', 'h'),
        (
            "key before first element",
            vec!['a', 'c', 'f', 'h'],
            'b',
            'c',
        ),
        (
            "key is smallest element",
            vec!['a', 'c', 'f', 'h'],
            'a',
            'c',
        ),
        (
            "key is largest element - wraps around",
            vec!['a', 'c', 'f', 'h'],
            'h',
            'a',
        ),
        (
            "key larger than all - wraps around",
            vec!['a', 'c', 'f', 'h'],
            'z',
            'a',
        ),
        (
            "key smaller than all elements",
            vec!['c', 'f', 'j'],
            'a',
            'c',
        ),
        (
            "key between two adjacent elements",
            vec!['a', 'c', 'f', 'h'],
            'g',
            'h',
        ),
        ("single element - wraps around", vec!['m'], 'm', 'm'),
    ];
    for (name, letters, key, want) in tests {
        let got = search_next_letter(&letters, key);
        assert_eq!(got, want, "{name}: search_next_letter()");
    }
}
