use super::reverselevelorder::traverse;
use super::shared::tree;

#[test]
fn test_traverse() {
    let tests = [
        (
            "Example 1",
            "[1, 2, 3, 4, 5, 6, 7]",
            vec![vec![4, 5, 6, 7], vec![2, 3], vec![1]],
        ),
        (
            "Example 2",
            "[12, 7, 1, null, 9, 10, 5]",
            vec![vec![9, 10, 5], vec![7, 1], vec![12]],
        ),
        (
            "Example 3",
            "[6, 5, 2, null, null, 1, 6, 3, 56, null, 3]",
            vec![vec![3, 56, 3], vec![1, 6], vec![5, 2], vec![6]],
        ),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let got = traverse(&tree(root));
        assert_eq!(got, want, "{name}: traverse()");
    }
}
