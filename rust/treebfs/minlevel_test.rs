use super::minlevel::find_depth;
use super::shared::tree;

#[test]
fn test_find_depth() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, 5]", 2),
        ("Example 2", "[1, 2]", 2),
        ("Example 3", "[1, 2, 3, 4, 5, 6]", 3),
        ("Example 4", "[1]", 1),
        ("Empty tree", "[]", 0),
    ];
    for (name, root, want) in tests {
        let got = find_depth(&tree(root));
        assert_eq!(got, want, "{name}: find_depth()");
    }
}
