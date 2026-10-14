use super::allpathsforsum::find_paths;
use super::shared::tree;

#[test]
fn test_find_paths() {
    let tests = [
        (
            "Example 1",
            "[1, 2, 3, 4, 5, 6, 7]",
            10,
            vec![vec![1, 3, 6]],
        ),
        (
            "Example 2",
            "[12, 7, 1, 9, null, 10, 5]",
            23,
            vec![vec![12, 1, 10]],
        ),
        (
            "No path",
            "[5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]",
            100,
            vec![],
        ),
        (
            "Two paths",
            "[5, 4, 8, 11, null, 13, 4, 7, 2, null, null, 5, 1]",
            22,
            vec![vec![5, 4, 11, 2], vec![5, 8, 4, 5]],
        ),
        ("Empty tree", "[]", 0, vec![]),
    ];
    for (name, root, sum, want) in tests {
        let got = find_paths(&tree(root), sum);
        assert_eq!(got, want, "{name}: find_paths()");
    }
}
