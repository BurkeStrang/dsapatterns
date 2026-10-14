use super::islandperimeter::find_island_perimeter;

#[test]
fn test_find_island_perimeter() {
    let tests = [
        (
            // shape is a plus sign → perimeter = 12
            "plus sign island",
            vec![vec![0, 1, 0], vec![1, 1, 1], vec![0, 1, 0]],
            12,
        ),
        ("single land cell", vec![vec![1]], 4),
        // ends (3 sides + 3 sides) + middle (2 + 2)
        ("single row island", vec![vec![1, 1, 1, 1]], 10),
        // 2x2 block perimeter = 8
        ("one big solid block", vec![vec![1, 1], vec![1, 1]], 8),
        // Shape:
        // 1 .
        // 1 1
        ("L-shaped island", vec![vec![1, 0], vec![1, 1]], 8),
        (
            "island touching border",
            vec![vec![1, 1, 0], vec![1, 0, 0], vec![1, 1, 1]],
            14,
        ),
        (
            // A hollow square → perimeter counts both outer and inner edges
            // outer = 12, inner hole = 4 → total = 16
            "island with a hole inside",
            vec![vec![1, 1, 1], vec![1, 0, 1], vec![1, 1, 1]],
            16,
        ),
    ];
    for (name, matrix, want) in tests {
        let got = find_island_perimeter(&matrix);
        assert_eq!(got, want, "{name}: find_island_perimeter()");
    }
}
