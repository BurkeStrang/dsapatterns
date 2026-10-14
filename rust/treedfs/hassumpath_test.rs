use super::hassumpath::has_path;
use super::shared::tree;

#[test]
fn test_has_path() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, 5, 6, 7]", 10, true),
        ("Example 2", "[12, 7, 1, 9, null, 10, 5]", 23, true),
        ("Example 3", "[12, 7, 1, 9, null, 10, 5]", 16, false),
        ("Empty tree", "[]", 0, false),
    ];
    for (name, root, sum, want) in tests {
        let got = has_path(&tree(root), sum);
        assert_eq!(got, want, "{name}: has_path()");
    }
}
