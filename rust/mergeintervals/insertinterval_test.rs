use super::insertinterval::insert;
use super::shared::{Interval, intervals};

#[test]
fn test_insert() {
    let tests = [
        (
            "Example 1",
            intervals(&[(1, 3), (5, 7), (8, 12)]),
            Interval { start: 4, end: 6 },
            intervals(&[(1, 3), (4, 7), (8, 12)]),
        ),
        (
            "Example 2",
            intervals(&[(1, 3), (5, 7), (8, 12)]),
            Interval { start: 4, end: 10 },
            intervals(&[(1, 3), (4, 12)]),
        ),
        (
            "Example 3",
            intervals(&[(2, 3), (5, 7)]),
            Interval { start: 1, end: 4 },
            intervals(&[(1, 4), (5, 7)]),
        ),
    ];
    for (name, intervals, new_interval, want) in tests {
        let got = insert(&intervals, new_interval);
        assert_eq!(got, want, "{name}: insert()");
    }
}
