use super::redundantconnection::find_redundant_connection;

#[test]
fn test_find_redundant_connection() {
    let tests = [
        (
            "Example 1",
            vec![[1, 2], [1, 3], [3, 4], [1, 4], [1, 5]],
            Some([1, 4]),
        ),
        (
            "Example 2",
            vec![[1, 2], [2, 3], [3, 1], [3, 4]],
            Some([3, 1]),
        ),
        (
            "Example 3",
            vec![[1, 2], [2, 3], [3, 4], [4, 2], [5, 6]],
            Some([4, 2]),
        ),
    ];
    for (name, edges, want) in tests {
        let got = find_redundant_connection(&edges);
        assert_eq!(got, want, "{name}: find_redundant_connection()");
    }
}
