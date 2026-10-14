use super::nextinterval::{Interval, find_next_interval};

fn intervals(pairs: &[(i32, i32)]) -> Vec<Interval> {
    pairs
        .iter()
        .map(|&(start, end)| Interval { start, end })
        .collect()
}

#[test]
fn test_find_next_interval() {
    let tests = [
        (
            "basic non-overlapping",
            intervals(&[(2, 3), (3, 4), (5, 6)]),
            vec![1, 2, -1],
        ),
        (
            "overlapping intervals",
            intervals(&[(3, 4), (1, 5), (4, 6)]),
            vec![2, -1, -1],
        ),
        ("single interval", intervals(&[(1, 2)]), vec![-1]),
        (
            "self as next interval",
            intervals(&[(1, 1), (3, 4)]),
            vec![0, -1],
        ),
        (
            "no next interval for identical",
            intervals(&[(1, 2), (1, 2), (1, 2)]),
            vec![-1, -1, -1],
        ),
        (
            "start equals end",
            intervals(&[(1, 2), (2, 3), (3, 4)]),
            vec![1, 2, -1],
        ),
    ];
    for (name, intervals, want) in tests {
        let got = find_next_interval(&intervals);
        assert_eq!(got, want, "{name}: find_next_interval()");
    }
}
