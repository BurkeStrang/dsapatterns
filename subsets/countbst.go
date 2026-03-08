package subsets

// Example 1:
// input: 2
// output: 2

// Example 2:
// input: 3
// output: 5

func countTrees(n int) int {
	if n <= 1 {
		return 1
	}
	count := 0
	for i := 1; i <= n; i++ {
		// making 'i' root of the tree
		countOfLeftSubtrees := countTrees(i - 1)
		countOfRightSubtrees := countTrees(n - i)
		count += (countOfLeftSubtrees * countOfRightSubtrees)
	}
	return count
}

