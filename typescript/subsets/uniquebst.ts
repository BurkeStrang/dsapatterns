// Given a number n,
// write a function to return all structurally unique Binary Search Trees (BST),
// that can store values 1 to n?

import { TreeNode } from "../common/tree.ts";

// findUniqueTreesRecursive is the recursive method to find unique trees
export function findUniqueTreesRecursive(
  start: number,
  end: number,
): (TreeNode | null)[] {
  const result: (TreeNode | null)[] = [];
  // base condition, return null for an empty sub-tree
  // consider n=1, in this case we will have start=end=1, this means we
  // should have only one tree we will have two recursive calls,
  // findUniqueTreesRecursive(1, 0) & (2, 1) both of these should return null
  // for the left and the right child
  if (start > end) {
    result.push(null);
    return result;
  }

  for (let i = start; i <= end; i++) {
    // making 'i' root of the tree
    const leftSubtrees = findUniqueTreesRecursive(start, i - 1);
    const rightSubtrees = findUniqueTreesRecursive(i + 1, end);
    for (const leftTree of leftSubtrees) {
      for (const rightTree of rightSubtrees) {
        // the trees share their sub-trees, like the Go version
        result.push(new TreeNode(i, leftTree, rightTree));
      }
    }
  }
  return result;
}

export function findUniqueTrees(n: number): (TreeNode | null)[] {
  if (n <= 0) {
    return [];
  }
  return findUniqueTreesRecursive(1, n);
}
