use super::numofclosed::count_closed_islands;

#[test]
fn test_count_closed_islands() {
    let tests = [
        (
            "one simple closed island",
            vec![
                vec![1, 1, 1, 1, 1],
                vec![1, 0, 0, 0, 1],
                vec![1, 0, 1, 0, 1],
                vec![1, 0, 0, 0, 1],
                vec![1, 1, 1, 1, 1],
            ],
            1,
        ),
        (
            "two closed islands",
            vec![
                vec![1, 1, 0, 1, 0, 0],
                vec![1, 0, 1, 0, 0, 0],
                vec![1, 0, 1, 0, 1, 0],
                vec![1, 1, 0, 1, 0, 0],
            ],
            2,
        ),
        (
            "islands touching border are NOT closed",
            vec![
                vec![0, 1, 1, 1],
                vec![1, 0, 0, 1],
                vec![1, 1, 0, 1],
                vec![1, 1, 1, 1],
            ],
            0,
        ),
        (
            "all land, touching every border",
            vec![vec![1, 1, 1], vec![1, 1, 1], vec![1, 1, 1]],
            0,
        ),
        (
            "no land at all",
            vec![vec![0, 0, 0], vec![0, 0, 0], vec![0, 0, 0]],
            0,
        ),
        (
            "inner island next to one that reaches the border",
            vec![
                vec![1, 1, 1, 1, 1, 1],
                vec![1, 0, 0, 0, 0, 1],
                vec![1, 0, 1, 0, 0, 1],
                vec![0, 0, 0, 0, 1, 1],
                vec![1, 1, 1, 1, 1, 1],
            ],
            1,
        ),
    ];
    for (name, matrix, want) in tests {
        let got = count_closed_islands(&matrix);
        assert_eq!(got, want, "{name}: count_closed_islands()");
    }
}
