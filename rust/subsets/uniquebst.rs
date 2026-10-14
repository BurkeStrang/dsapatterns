// Given a number n,
// write a function to return all structurally unique Binary Search Trees (BST),
// that can store values 1 to n?

// Example 1:
// input: 2
// output: [[1,null,2],[2,1]]

#[derive(Debug, Clone, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Box<TreeNode>>,
    pub right: Option<Box<TreeNode>>,
}

pub fn find_unique_trees(n: i32) -> Vec<Option<Box<TreeNode>>> {
    if n <= 0 {
        return Vec::new();
    }
    find_unique_trees_recursive(1, n)
}

// find_unique_trees_recursive is the recursive method to find unique trees
fn find_unique_trees_recursive(
    start: i32,
    end: i32,
) -> Vec<Option<Box<TreeNode>>> {
    let mut result = Vec::new();
    // base condition, return None for an empty sub-tree
    // consider n=1, in this case we will have start=end=1, this means we
    // should have only one tree we will have two recursive calls,
    // find_unique_trees_recursive(1, 0) & (2, 1) both of these should return
    // None for the left and the right child
    if start > end {
        result.push(None);
        return result;
    }

    for i in start..=end {
        // making 'i' root of the tree
        let left_subtrees = find_unique_trees_recursive(start, i - 1);
        let right_subtrees = find_unique_trees_recursive(i + 1, end);
        for left_tree in &left_subtrees {
            for right_tree in &right_subtrees {
                // each tree owns its nodes, so the sub-trees are copied
                result.push(Some(Box::new(TreeNode {
                    val: i,
                    left: left_tree.clone(),
                    right: right_tree.clone(),
                })));
            }
        }
    }
    result
}
