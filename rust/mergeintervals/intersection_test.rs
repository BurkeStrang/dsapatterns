use super::intersection::intersecting_intervals;
use super::shared::intervals;

#[test]
fn test_intersecting_intervals() {
    let tests = [
        (
            "Example 1",
            intervals(&[(1, 3), (5, 6), (7, 9)]),
            intervals(&[(2, 3), (5, 7)]),
            intervals(&[(2, 3), (5, 6), (7, 7)]),
        ),
        (
            "Example 2",
            intervals(&[(1, 3), (5, 7), (9, 12)]),
            intervals(&[(5, 10)]),
            intervals(&[(5, 7), (9, 10)]),
        ),
    ];
    for (name, arr1, arr2, want) in tests {
        let got = intersecting_intervals(&arr1, &arr2);
        assert_eq!(got, want, "{name}: intersecting_intervals()");
    }
}
