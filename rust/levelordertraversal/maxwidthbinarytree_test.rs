use super::maxwidthbinarytree::width_of_binary_tree;
use super::shared::tree;

#[test]
fn test_width_of_binary_tree() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, null, null, 5]", 4),
        ("Example 2", "[1, 2, 3, 4, null, 5, 6, null, 7]", 4),
        ("Example 3", "[1, 2, null, 3, 4, 5]", 2),
        ("Single node", "[42]", 1),
        ("Empty tree", "[]", 0),
    ];
    for (name, root, want) in tests {
        let got = width_of_binary_tree(&tree(root));
        assert_eq!(got, want, "{name}: width_of_binary_tree()");
    }
}
