use super::connectalllevelordersibs::connect_all;
use super::shared::{Tree, tree};

// flatten_next walks the tree using next pointers and returns the values in
// order.
fn flatten_next(root: &Tree) -> Vec<i32> {
    let mut result = Vec::new();
    let mut curr = root.clone();
    while let Some(node) = curr {
        result.push(node.borrow().val);
        curr = node.borrow().next.clone();
    }
    result
}

#[test]
fn test_connect_all() {
    let tests = [
        (
            "Example 1",
            "[1, 2, 3, 4, 5, 6, 7]",
            vec![1, 2, 3, 4, 5, 6, 7],
        ),
        (
            "Example 2",
            "[12, 7, 1, 9, null, 10, 5]",
            vec![12, 7, 1, 9, 10, 5],
        ),
        ("Empty tree", "[]", vec![]),
    ];
    for (name, root, want) in tests {
        let root = tree(root);
        connect_all(&root);
        assert_eq!(flatten_next(&root), want, "{name}: connect_all()");
    }
}
