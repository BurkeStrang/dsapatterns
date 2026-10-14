use super::shared::tree;
use super::zigzagtraversal::traverse_zig_zag;

#[test]
fn test_traverse_zig_zag() {
    let tests = [
        (
            "Example 1",
            "[1, 2, 3, 4, 5, null, 6]",
            vec![vec![1], vec![3, 2], vec![4, 5, 6]],
        ),
        (
            "Example 2",
            "[7, 4, 8, 2, 5, null, 9, null, 3]",
            vec![vec![7], vec![8, 4], vec![2, 5, 9], vec![3]],
        ),
        ("Single node", "[42]", vec![vec![42]]),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let got = traverse_zig_zag(&tree(root));
        assert_eq!(got, want, "{name}: traverse_zig_zag()");
    }
}
