use super::maxareaisland::max_area_of_island;

#[test]
fn test_max_area_of_island() {
    let tests = [
        (
            "two islands",
            vec![
                vec![0, 1, 0, 0],
                vec![1, 1, 0, 0],
                vec![0, 0, 1, 1],
                vec![0, 0, 1, 1],
            ],
            4,
        ),
        ("no island", vec![vec![0, 0, 0], vec![0, 0, 0]], 0),
        (
            "multiple islands",
            vec![vec![1, 0, 0, 1], vec![0, 1, 1, 0], vec![0, 0, 0, 1]],
            2,
        ),
    ];
    for (name, mut matrix, want) in tests {
        let got = max_area_of_island(&mut matrix);
        assert_eq!(got, want, "{name}: max_area_of_island()");
    }
}
