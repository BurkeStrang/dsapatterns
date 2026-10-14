use super::lts::traverse_basic;
use super::shared::tree;

#[test]
fn test_traverse_basic() {
    let tests = [
        (
            "Example 1",
            "[1, 2, 3, 4, 5, null, 6]",
            vec![vec![1], vec![2, 3], vec![4, 5, 6]],
        ),
        ("Single node", "[42]", vec![vec![42]]),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let got = traverse_basic(&tree(root));
        assert_eq!(got, want, "{name}: traverse_basic()");
    }
}
