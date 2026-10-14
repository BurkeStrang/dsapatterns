use super::numberofprovinces::find_provinces;

#[test]
fn test_find_provinces() {
    let tests = [
        (
            "Example 1",
            vec![vec![1, 1, 0], vec![1, 1, 0], vec![0, 0, 1]],
            2,
        ),
        (
            "Example 2",
            vec![vec![1, 0, 0], vec![0, 1, 0], vec![0, 0, 1]],
            3,
        ),
        (
            "Example 3",
            vec![
                vec![1, 0, 0, 1],
                vec![0, 1, 1, 0],
                vec![0, 1, 1, 0],
                vec![1, 0, 0, 1],
            ],
            2,
        ),
    ];
    for (name, is_connected, want) in tests {
        let got = find_provinces(&is_connected);
        assert_eq!(got, want, "{name}: find_provinces()");
    }
}
