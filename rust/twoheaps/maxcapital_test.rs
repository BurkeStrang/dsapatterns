use super::maxcapital::find_maximum_capital;

#[test]
fn test_find_maximum_capital() {
    // (name, capital, profits, number of projects, initial capital, want)
    let tests = [
        ("basic example", vec![0, 1, 2], vec![1, 2, 3], 2, 1, 6),
        (
            "not enough capital for any project",
            vec![5, 10, 15],
            vec![1, 2, 3],
            3,
            0,
            0,
        ),
        (
            "all projects affordable from start",
            vec![0, 0, 0],
            vec![1, 2, 3],
            2,
            0,
            5,
        ),
        ("single project", vec![0], vec![5], 1, 0, 5),
        (
            "chain of unlocking projects",
            vec![0, 1, 2, 3],
            vec![1, 1, 1, 1],
            4,
            0,
            4,
        ),
    ];
    for (name, capital, profits, number_of_projects, initial, want) in tests {
        let got = find_maximum_capital(
            &capital,
            &profits,
            number_of_projects,
            initial,
        );
        assert_eq!(got, want, "{name}: find_maximum_capital()");
    }
}
