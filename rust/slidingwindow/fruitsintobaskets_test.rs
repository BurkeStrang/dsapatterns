use super::fruitsintobaskets::max_fruit;

#[test]
fn test_max_fruit() {
    let tests = [
        ("basic example", vec!['A', 'B', 'C', 'A', 'C'], 3),
        ("all same fruit", vec!['A', 'A', 'A', 'A'], 4),
        (
            "two types alternating",
            vec!['A', 'B', 'A', 'B', 'A', 'B'],
            6,
        ),
        ("three types", vec!['A', 'B', 'C', 'B', 'B', 'C', 'A'], 5),
    ];
    for (name, arr, want) in tests {
        let got = max_fruit(&arr);
        assert_eq!(got, want, "{name}: max_fruit()");
    }
}
