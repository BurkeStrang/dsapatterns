use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;

/// A link to a node, or None where there is no node.
///
/// Two of the problems in this pattern point every node at its neighbour with
/// `next`, so a node can be reached from both its parent and its neighbour.
/// `Box` allows only one owner, so the nodes are shared with `Rc` and changed
/// through `RefCell`.
pub type Tree = Option<Rc<RefCell<TreeNode>>>;

#[derive(Debug)]
pub struct TreeNode {
    pub val: i32,
    pub left: Tree,
    pub right: Tree,
    pub next: Tree,
}

/// Builds a binary tree from its values in level order, with `null` for a
/// missing child, for example `"[1, 2, 3, null, 4]"`. Keeps the test tables
/// short.
pub fn tree(s: &str) -> Tree {
    // "null" doesn't parse as a number, so it becomes None
    let mut vals = s
        .trim_matches(['[', ']'])
        .split(',')
        .map(|token| token.trim().parse().ok())
        .map(|val: Option<i32>| {
            let node = TreeNode {
                val: val?,
                left: None,
                right: None,
                next: None,
            };
            Some(Rc::new(RefCell::new(node)))
        });

    let root = vals.next()??;
    let mut queue = VecDeque::new();
    queue.push_back(root.clone());
    while let Some(node) = queue.pop_front() {
        // the next two values are this node's children; stop when they run out
        let Some(left) = vals.next() else { break };
        queue.extend(left.clone());
        node.borrow_mut().left = left;

        let Some(right) = vals.next() else { break };
        queue.extend(right.clone());
        node.borrow_mut().right = right;
    }

    Some(root)
}

/// Reports whether two float slices hold the same values, allowing for
/// rounding error.
pub fn equal_float_slices(a: &[f64], b: &[f64]) -> bool {
    a.len() == b.len() && a.iter().zip(b).all(|(x, y)| (x - y).abs() <= 1e-9)
}
