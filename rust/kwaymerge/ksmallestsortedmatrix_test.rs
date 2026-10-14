use super::ksmallestsortedmatrix::find_kth_smallest_point;

#[test]
fn test_find_kth_smallest_point() {
    let tests = [
        (
            "Example 1",
            vec![vec![2, 6, 8], vec![3, 7, 10], vec![5, 7, 8]],
            5,
            7,
        ),
        (
            "Smaller numbers further down",
            vec![vec![1, 20, 30], vec![2, 21, 31], vec![3, 22, 32]],
            3,
            3,
        ),
    ];
    for (name, matrix, k, want) in tests {
        let got = find_kth_smallest_point(&matrix, k);
        assert_eq!(got, want, "{name}: find_kth_smallest_point()");
    }
}
