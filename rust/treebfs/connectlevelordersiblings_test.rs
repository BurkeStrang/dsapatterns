use super::connectlevelordersiblings::connect;
use super::shared::{Tree, tree};

// level_order_next walks the tree using next pointers and returns the values
// level by level.
fn level_order_next(root: &Tree) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    let mut level_start = root.clone();
    while level_start.is_some() {
        let mut level = Vec::new();
        let mut curr = level_start;
        let mut next_level: Tree = None;
        while let Some(node) = curr {
            let node = node.borrow();
            level.push(node.val);
            if next_level.is_none() {
                next_level = node.left.clone().or(node.right.clone());
            }
            curr = node.next.clone();
        }
        result.push(level);
        level_start = next_level;
    }
    result
}

#[test]
fn test_connect() {
    let tests = [
        (
            "Example 1",
            "[1, 2, 3, 4, 5, 6, 7]",
            vec![vec![1], vec![2, 3], vec![4, 5, 6, 7]],
        ),
        (
            "Example 2",
            "[12, 7, 1, 9, null, 10, 5]",
            vec![vec![12], vec![7, 1], vec![9, 10, 5]],
        ),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let root = tree(root);
        connect(&root);
        assert_eq!(level_order_next(&root), want, "{name}: connect()");
    }
}
