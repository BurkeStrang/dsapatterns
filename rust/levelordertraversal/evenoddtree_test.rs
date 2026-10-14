use super::evenoddtree::is_even_odd_tree;
use super::shared::tree;

#[test]
fn test_is_even_odd_tree() {
    let tests = [
        ("Example 1: Valid Even-Odd Tree", "[1, 10, 4, 3, 7]", true),
        (
            "Example 2: Invalid Even-Odd Tree (odd values at level 1)",
            "[5, 9, 3, 12, null, null, 8]",
            false,
        ),
        (
            "Example 3: Invalid Even-Odd Tree (even values at even level)",
            "[7, 10, 2, 12, 8]",
            false,
        ),
        ("Single node (odd value at level 0)", "[1]", true),
        ("Single node (even value at level 0)", "[2]", false),
        ("Empty tree", "[]", true),
    ];
    for (name, root, want) in tests {
        let got = is_even_odd_tree(&tree(root));
        assert_eq!(got, want, "{name}: is_even_odd_tree()");
    }
}
