use super::flipandinvert::flip_and_invert_image;

#[test]
fn test_flip_and_invert_image() {
    let tests = [
        (
            "Example 1",
            vec![vec![1, 0, 1], vec![1, 1, 1], vec![0, 1, 1]],
            vec![vec![0, 1, 0], vec![0, 0, 0], vec![0, 0, 1]],
        ),
        (
            "Example 2",
            vec![
                vec![1, 1, 0, 0],
                vec![1, 0, 0, 1],
                vec![0, 1, 1, 1],
                vec![1, 0, 1, 0],
            ],
            vec![
                vec![1, 1, 0, 0],
                vec![0, 1, 1, 0],
                vec![0, 0, 0, 1],
                vec![1, 0, 1, 0],
            ],
        ),
        ("Single row", vec![vec![1, 0, 0, 1]], vec![vec![0, 1, 1, 0]]),
    ];
    for (name, mut arr, want) in tests {
        flip_and_invert_image(&mut arr);
        assert_eq!(arr, want, "{name}: flip_and_invert_image()");
    }
}
