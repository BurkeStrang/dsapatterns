use super::slidingwindowmedian::find_sliding_window_median;

#[test]
fn test_find_sliding_window_median() {
    let tests = [
        ("k=2", vec![1, 2, -1, 3, 5], 2, vec![1.5, 0.5, 1.0, 4.0]),
        ("k=3", vec![1, 2, -1, 3, 5], 3, vec![1.0, 2.0, 3.0]),
        (
            "single element window",
            vec![4, 1, 3],
            1,
            vec![4.0, 1.0, 3.0],
        ),
    ];
    for (name, nums, k, want) in tests {
        let got = find_sliding_window_median(&nums, k);
        assert_eq!(got, want, "{name}: find_sliding_window_median()");
    }
}
