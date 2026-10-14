use super::avg::find_averages;
use super::shared::equal_float_slices;

#[test]
fn test_find_averages() {
    let tests = [
        (
            "basic case",
            5,
            vec![1, 3, 2, 6, -1, 4, 1, 8, 2],
            vec![2.2, 2.8, 2.4, 3.6, 2.8],
        ),
        ("window size 1", 1, vec![5, 10, 15], vec![5.0, 10.0, 15.0]),
        (
            "window size equals array length",
            4,
            vec![2, 4, 6, 8],
            vec![5.0],
        ),
    ];
    for (name, k, arr, want) in tests {
        let got = find_averages(k, &arr);
        assert!(
            equal_float_slices(&got, &want),
            "{name}: find_averages() = {got:?}, want {want:?}"
        );
    }
}
