use super::shared::{Link, next};

// Given the head of a singly LinkedList, change the list in place so that
// the nodes from the second half are put, in reverse order, between the nodes
// of the first half. So 1 -> 2 -> 3 -> 4 becomes 1 -> 4 -> 2 -> 3.

pub fn rearange_list(head: Link) -> Link {
    head.as_ref()?;

    // find middle
    let mut slow = head.clone();
    let mut fast = head.clone();
    while fast.is_some() && next(&fast).is_some() {
        slow = next(&slow);
        fast = next(&next(&fast));
    }

    // reverse second half
    let mut curr = slow;
    let mut prev = None;
    while let Some(node) = curr {
        curr = node.borrow_mut().next.take();
        node.borrow_mut().next = prev;
        prev = Some(node);
    }

    // set every other one as the reverse second half
    let mut first = head.clone();
    let mut second = prev;
    while let (Some(f), Some(s)) = (first, second) {
        let tmp2 = s.borrow().next.clone();
        if tmp2.is_none() {
            break;
        }
        let tmp1 = f.borrow().next.clone();
        f.borrow_mut().next = Some(s.clone());
        s.borrow_mut().next = tmp1.clone();
        first = tmp1;
        second = tmp2;
    }

    head
}
