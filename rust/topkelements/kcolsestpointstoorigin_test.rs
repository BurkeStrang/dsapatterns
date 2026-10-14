use super::kcolsestpointstoorigin::{Point, find_closest_points};

fn points(pairs: &[(i32, i32)]) -> Vec<Point> {
    pairs.iter().map(|&(x, y)| Point { x, y }).collect()
}

#[test]
fn test_find_closest_points() {
    let tests = [
        ("Example 1", points(&[(1, 2), (1, 3)]), 1, points(&[(1, 2)])),
        (
            "Example 2",
            points(&[(1, 3), (3, 4), (2, -1)]),
            2,
            points(&[(1, 3), (2, -1)]),
        ),
        (
            "Example 3",
            points(&[(1, 2), (3, 4), (1, -1)]),
            2,
            points(&[(1, -1), (1, 2)]),
        ),
        (
            "Example 4",
            points(&[(3, 3), (5, -1), (-2, 4)]),
            2,
            points(&[(-2, 4), (3, 3)]),
        ),
        (
            "All points are the same",
            points(&[(1, 1), (1, 1), (1, 1)]),
            2,
            points(&[(1, 1), (1, 1)]),
        ),
    ];
    for (name, points, k, want) in tests {
        let mut got = find_closest_points(&points, k);
        // the points may come back in any order
        got.sort();
        assert_eq!(got, want, "{name}: find_closest_points()");
    }
}
