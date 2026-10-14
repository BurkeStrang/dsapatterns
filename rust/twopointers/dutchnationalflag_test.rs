use super::dutchnationalflag::dutch;

#[test]
fn test_dutch() {
    let tests = [
        ("example1", vec![1, 0, 2, 1, 0], vec![0, 0, 1, 1, 2]),
        ("example2", vec![2, 2, 0, 1, 2, 0], vec![0, 0, 1, 2, 2, 2]),
        ("all zeros", vec![0, 0, 0], vec![0, 0, 0]),
        ("all twos", vec![2, 2, 2], vec![2, 2, 2]),
        (
            "already sorted",
            vec![0, 0, 1, 1, 2, 2],
            vec![0, 0, 1, 1, 2, 2],
        ),
        ("single element", vec![1], vec![1]),
    ];
    for (name, input, want) in tests {
        let mut got = input.clone();
        dutch(&mut got);
        assert_eq!(got, want, "{name}: dutch({input:?})");
    }
}
