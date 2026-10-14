r"""
Given a binary tree, return true if it is an Even-Odd tree. Otherwise, return
false.
The Even-odd tree must follow below two rules:

At every even-indexed level (starting from 0),
all node values must be odd and arranged in strictly increasing order from
left to right.
At every odd-indexed level,
all node values must be even and arranged in strictly decreasing order from
left to right.

Example 1
Input:
    1
   / \
  10  4
 / \
3   7
Expected Output: true
Justification: The tree follows both conditions for each odd and even level.
So, it is an odd-even tree.

Example 2
Input:

    5
   / \
  9   3
 /     \
12      8
Expected Output: false
Justification: Level 1 has Odd values 9 and 3 in decreasing order, but it
should have even values. So, the tree is not an odd-even tree.

Example 3
Input:
    7
   / \
  10  2
 / \
12  8
Expected Output: false
Justification: At level 2 (even-indexed), the values are 12 and 8, which are
even, but they should have odd values. So, the tree is not an odd-even tree.

Constraints:
The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 10^6
"""

from collections import deque

from common.tree import TreeNode


def is_even_odd_tree(root: TreeNode | None) -> bool:
    if root is None:
        return True  # Check if the tree is empty

    queue = deque([root])
    level = 0  # Start with level 0

    while queue:
        values: list[int] = []  # Node values at the current level
        for _ in range(len(queue)):
            node = queue.popleft()  # Take the next node
            values.append(node.value)

            # Add the children to the queue if they exist
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)

        # Check values for the current level
        for i, value in enumerate(values):
            if level % 2 == 0:
                # Even level: values must be odd and strictly increasing
                if value % 2 == 0 or (i > 0 and value <= values[i - 1]):
                    return False
            # Odd level: values must be even and strictly decreasing
            elif value % 2 != 0 or (i > 0 and value >= values[i - 1]):
                return False

        level += 1  # Move to the next level

    return True  # If all levels satisfy the conditions, return true
