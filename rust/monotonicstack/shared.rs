#[derive(Debug, PartialEq, Eq)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

/// Builds a linked list holding the given values, in order.
pub fn build_list(vals: &[i32]) -> Option<Box<ListNode>> {
    let mut head = None;
    for &val in vals.iter().rev() {
        head = Some(Box::new(ListNode { val, next: head }));
    }
    head
}

/// Collects the values of a linked list, so two lists are easy to compare.
pub fn list_to_vec(head: &Option<Box<ListNode>>) -> Vec<i32> {
    let mut vals = Vec::new();
    let mut current = head;
    while let Some(node) = current {
        vals.push(node.val);
        current = &node.next;
    }
    vals
}
