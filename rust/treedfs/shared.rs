use std::collections::VecDeque;

#[derive(Debug)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Box<TreeNode>>,
    pub right: Option<Box<TreeNode>>,
}

/// Builds a binary tree from its values in level order, with `null` for a
/// missing child, for example `"[1, 2, 3, null, 4]"`. Keeps the test tables
/// short.
pub fn tree(s: &str) -> Option<Box<TreeNode>> {
    // "null" doesn't parse as a number, so it becomes None
    let vals: Vec<Option<i32>> = s
        .trim_matches(['[', ']'])
        .split(',')
        .map(|token| token.trim().parse().ok())
        .collect();

    // first work out which positions hold the children of each node
    let mut children = vec![(None, None); vals.len()];
    let mut queue = VecDeque::new();
    if vals[0].is_some() {
        queue.push_back(0);
    }
    let mut i = 1;
    while let Some(parent) = queue.pop_front() {
        if i < vals.len() {
            if vals[i].is_some() {
                children[parent].0 = Some(i);
                queue.push_back(i);
            }
            i += 1;
        }
        if i < vals.len() {
            if vals[i].is_some() {
                children[parent].1 = Some(i);
                queue.push_back(i);
            }
            i += 1;
        }
    }

    build(&vals, &children, Some(0))
}

type Children = (Option<usize>, Option<usize>);

fn build(
    vals: &[Option<i32>],
    children: &[Children],
    i: Option<usize>,
) -> Option<Box<TreeNode>> {
    let i = i?;
    Some(Box::new(TreeNode {
        val: vals[i]?,
        left: build(vals, children, children[i].0),
        right: build(vals, children, children[i].1),
    }))
}
