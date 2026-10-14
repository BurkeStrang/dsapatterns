use super::combinationsum::combination_sum;

#[test]
fn test_combination_sum() {
    let tests = [
        ("test1", vec![2, 3, 6, 7], 7, vec![vec![2, 2, 3], vec![7]]),
        (
            "test2",
            vec![2, 4, 6, 8],
            10,
            vec![
                vec![2, 2, 2, 2, 2],
                vec![2, 2, 2, 4],
                vec![2, 2, 6],
                vec![2, 4, 4],
                vec![2, 8],
                vec![4, 6],
            ],
        ),
        ("test3", vec![2], 1, vec![]),
    ];
    for (name, candidates, target, want) in tests {
        let got = combination_sum(&candidates, target);
        assert_eq!(got, want, "{name}: combination_sum()");
    }
}
