use super::mergeintervals::merge;
use super::shared::intervals;

#[test]
fn test_merge() {
    let tests = [
        (
            "Example 1",
            intervals(&[(1, 4), (2, 5), (7, 9)]),
            intervals(&[(1, 5), (7, 9)]),
        ),
        (
            "Example 2",
            intervals(&[(6, 7), (2, 4), (5, 9)]),
            intervals(&[(2, 4), (5, 9)]),
        ),
        (
            "Example 3",
            intervals(&[(1, 4), (2, 6), (3, 5)]),
            intervals(&[(1, 6)]),
        ),
        (
            "No overlap",
            intervals(&[(1, 2), (3, 4), (5, 6)]),
            intervals(&[(1, 2), (3, 4), (5, 6)]),
        ),
        (
            "Single interval",
            intervals(&[(1, 10)]),
            intervals(&[(1, 10)]),
        ),
    ];
    for (name, mut intervals, want) in tests {
        let got = merge(&mut intervals);
        assert_eq!(got, want, "{name}: merge()");
    }
}
