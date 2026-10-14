use super::minmeetingrooms::{Meeting, find_minimum_meeting_rooms};

fn meetings(pairs: &[(i32, i32)]) -> Vec<Meeting> {
    pairs
        .iter()
        .map(|&(start, end)| Meeting { start, end })
        .collect()
}

#[test]
fn test_find_minimum_meeting_rooms() {
    let tests = [
        (
            "Example 1: overlapping meetings",
            meetings(&[(1, 4), (2, 5), (7, 9)]),
            2,
        ),
        (
            "Example 2: non-overlapping meetings",
            meetings(&[(6, 7), (2, 4), (8, 12)]),
            1,
        ),
        (
            "Example 3: overlapping meetings",
            meetings(&[(1, 4), (2, 3), (3, 6)]),
            2,
        ),
        (
            "Example 4: complex overlaps",
            meetings(&[(4, 5), (2, 3), (2, 4), (3, 5)]),
            2,
        ),
    ];
    for (name, mut meetings, want) in tests {
        let got = find_minimum_meeting_rooms(&mut meetings);
        assert_eq!(got, want, "{name}: find_minimum_meeting_rooms()");
    }
}
