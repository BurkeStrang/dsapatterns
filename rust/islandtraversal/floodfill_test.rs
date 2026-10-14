use super::floodfill::flood_fill;

#[test]
fn test_flood_fill() {
    let tests = [
        (
            "basic flood fill",
            vec![vec![1, 1, 1], vec![1, 1, 0], vec![1, 0, 1]],
            1,
            1,
            2,
            vec![vec![2, 2, 2], vec![2, 2, 0], vec![2, 0, 1]],
        ),
        (
            "starting point already new color",
            vec![vec![0, 0], vec![0, 1]],
            1,
            1,
            1,
            vec![vec![0, 0], vec![0, 1]],
        ),
        (
            "no fill when starting outside bounds",
            vec![vec![1, 1], vec![1, 1]],
            3, // outside grid
            0,
            5,
            vec![vec![1, 1], vec![1, 1]],
        ),
        ("single cell matrix", vec![vec![1]], 0, 0, 9, vec![vec![9]]),
    ];
    for (name, mut matrix, x, y, new_color, want) in tests {
        flood_fill(&mut matrix, x, y, new_color);
        assert_eq!(matrix, want, "{name}: flood_fill()");
    }
}
