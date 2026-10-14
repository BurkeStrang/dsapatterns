// Example 1:
// input: 2
// output: 2

export function countTrees(n: number): number {
  if (n <= 1) {
    return 1;
  }
  let count = 0;
  for (let i = 1; i <= n; i++) {
    // making 'i' root of the tree
    const countOfLeftSubtrees = countTrees(i - 1);
    const countOfRightSubtrees = countTrees(n - i);
    count += countOfLeftSubtrees * countOfRightSubtrees;
  }
  return count;
}
