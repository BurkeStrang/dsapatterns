// Binary trees, as used by the tree patterns.

export class TreeNode {
  value: number;
  left: TreeNode | null;
  right: TreeNode | null;
  // the node to the right on the same level; only the problems that connect
  // siblings set it
  next: TreeNode | null = null;

  constructor(
    value: number,
    left: TreeNode | null = null,
    right: TreeNode | null = null,
  ) {
    this.value = value;
    this.left = left;
    this.right = right;
  }
}

// tree builds a binary tree from its values in level order, with null for a
// missing child, for example tree([1, 2, 3, null, 4]). It keeps the test
// tables short.
export function tree(values: (number | null)[]): TreeNode | null {
  if (values.length === 0 || values[0] === null) {
    return null;
  }

  const root = new TreeNode(values[0]);
  // a for-of loop over an array also visits the items pushed onto it while
  // the loop runs, so the array works as the queue
  const queue = [root];
  let i = 1;
  for (const parent of queue) {
    if (i >= values.length) {
      break;
    }
    const left = values[i];
    if (left !== null) {
      parent.left = new TreeNode(left);
      queue.push(parent.left);
    }
    i++;
    const right = i < values.length ? values[i] : null;
    if (right !== null) {
      parent.right = new TreeNode(right);
      queue.push(parent.right);
    }
    i++;
  }
  return root;
}
