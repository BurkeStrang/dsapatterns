use super::conflictingappointments::can_attend_all_appointments;
use super::shared::intervals;

#[test]
fn test_can_attend_all_appointments() {
    let tests = [
        (
            "Example 1: overlapping intervals",
            intervals(&[(1, 4), (2, 5), (7, 9)]),
            false,
        ),
        (
            "Example 2: non-overlapping intervals",
            intervals(&[(6, 7), (2, 4), (13, 14), (8, 12), (45, 47)]),
            true,
        ),
        (
            "Example 3: overlapping intervals",
            intervals(&[(4, 5), (2, 3), (3, 6)]),
            false,
        ),
    ];
    for (name, mut intervals, want) in tests {
        let got = can_attend_all_appointments(&mut intervals);
        assert_eq!(got, want, "{name}: can_attend_all_appointments()");
    }
}
