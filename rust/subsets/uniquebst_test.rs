use super::uniquebst::{TreeNode, find_unique_trees};

type Tree = Option<Box<TreeNode>>;

fn node(val: i32, left: Tree, right: Tree) -> Tree {
    Some(Box::new(TreeNode { val, left, right }))
}

fn leaf(val: i32) -> Tree {
    node(val, None, None)
}

#[test]
fn test_find_unique_trees() {
    let tests = [
        (
            "Example 1",
            2,
            vec![node(1, None, leaf(2)), node(2, leaf(1), None)],
        ),
        (
            "Example 2",
            3,
            vec![
                node(1, None, node(2, None, leaf(3))),
                node(1, None, node(3, leaf(2), None)),
                node(2, leaf(1), leaf(3)),
                node(3, node(1, None, leaf(2)), None),
                node(3, node(2, leaf(1), None), None),
            ],
        ),
        ("Nothing to build", 0, vec![]),
    ];
    for (name, n, want) in tests {
        let got = find_unique_trees(n);
        assert_eq!(got, want, "{name}: find_unique_trees()");
    }
}
