use super::numislands::count_islands;

#[test]
fn test_count_islands() {
    let tests = [
        (
            "three islands",
            vec![
                vec![1, 1, 0, 0],
                vec![1, 1, 0, 0],
                vec![0, 0, 1, 0],
                vec![0, 0, 0, 1],
            ],
            3,
        ),
        ("no islands", vec![vec![0, 0, 0], vec![0, 0, 0]], 0),
        ("all land", vec![vec![1, 1], vec![1, 1]], 1),
    ];
    for (name, mut matrix, want) in tests {
        let got = count_islands(&mut matrix);
        assert_eq!(got, want, "{name}: count_islands()");
    }
}
