use super::hascycle::has_cycle;

#[test]
fn test_has_cycle() {
    let tests = [
        (
            "no cycle",
            vec![
                vec!['A', 'B', 'C'],
                vec!['D', 'E', 'F'],
                vec!['G', 'H', 'I'],
            ],
            false,
        ),
        (
            "simple cycle",
            vec![
                vec!['A', 'A', 'A'],
                vec!['A', 'B', 'A'],
                vec!['A', 'A', 'A'],
            ],
            true,
        ),
    ];
    for (name, matrix, want) in tests {
        let got = has_cycle(&matrix);
        assert_eq!(got, want, "{name}: has_cycle()");
    }
}
