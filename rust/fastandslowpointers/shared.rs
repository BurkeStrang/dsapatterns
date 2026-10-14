use std::cell::RefCell;
use std::rc::Rc;

/// A link to a node, or None at the end of the list.
///
/// The lists in this pattern can loop back on themselves, so more than one
/// link may point at the same node. `Box` allows only one owner, so the nodes
/// are shared with `Rc` and changed through `RefCell`.
pub type Link = Option<Rc<RefCell<ListNode>>>;

#[derive(Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Link,
}

/// Returns the link after the given one; None stays None.
pub fn next(link: &Link) -> Link {
    link.as_ref().and_then(|node| node.borrow().next.clone())
}

/// Reports whether two links point at the very same node (or are both None).
pub fn same_node(a: &Link, b: &Link) -> bool {
    match (a, b) {
        (Some(a), Some(b)) => Rc::ptr_eq(a, b),
        (None, None) => true,
        _ => false,
    }
}

/// Builds one node per value, each linked to the next, and returns them all so
/// a test can point the last node back at an earlier one to make a cycle.
/// A list with a cycle is never freed, which is fine for a test.
pub fn build_nodes(vals: &[i32]) -> Vec<Rc<RefCell<ListNode>>> {
    let nodes: Vec<_> = vals
        .iter()
        .map(|&val| Rc::new(RefCell::new(ListNode { val, next: None })))
        .collect();
    for i in 1..nodes.len() {
        nodes[i - 1].borrow_mut().next = Some(nodes[i].clone());
    }
    nodes
}

/// Builds a linked list holding the given values, in order.
pub fn build_list(vals: &[i32]) -> Link {
    build_nodes(vals).first().cloned()
}

/// Collects the values of a linked list, so two lists are easy to compare.
pub fn list_to_vec(head: &Link) -> Vec<i32> {
    let mut vals = Vec::new();
    let mut current = head.clone();
    while let Some(node) = current {
        vals.push(node.borrow().val);
        current = node.borrow().next.clone();
    }
    vals
}
