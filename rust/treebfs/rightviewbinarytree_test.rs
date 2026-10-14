use super::rightviewbinarytree::right_view;
use super::shared::tree;

#[test]
fn test_right_view() {
    let tests = [
        ("Example 1", "[1, 2, 3, 4, 5, 6, 7]", vec![1, 3, 7]),
        (
            "Example 2",
            "[12, 7, 1, null, 9, 10, 5, null, 3]",
            vec![12, 1, 5, 3],
        ),
        (
            "Example 3",
            "[8, 4, 9, 3, null, null, 10, 2]",
            vec![8, 9, 10, 2],
        ),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let got = right_view(&tree(root));
        assert_eq!(got, want, "{name}: right_view()");
    }
}
