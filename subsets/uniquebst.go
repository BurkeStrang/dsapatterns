package subsets

// Given a number n,
// write a function to return all structurally unique Binary Search Trees (BST),
// that can store values 1 to n?

// Example 1:
// input: 2
// output: [[1,null,2],[2,1]]

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findUniqueTrees(n int) []*TreeNode {
	if n <= 0 {
		return []*TreeNode{}
	}
	return findUniqueTreesRecursive(1, n)
}

// findUniqueTreesRecursive is the recursive method to find unique trees
func findUniqueTreesRecursive(start, end int) []*TreeNode {
	var result []*TreeNode
	// base condition, return 'null' for an empty sub-tree
	// consider n=1, in this case we will have start=end=1, this means we should have
	// only one tree we will have two recursive calls, findUniqueTreesRecursive(1, 0) &
	// (2, 1) both of these should return 'null' for the left and the right child
	if start > end {
		result = append(result, nil)
		return result
	}

	for i := start; i <= end; i++ {
		// making 'i' root of the tree
		leftSubtrees := findUniqueTreesRecursive(start, i-1)
		rightSubtrees := findUniqueTreesRecursive(i+1, end)
		for _, leftTree := range leftSubtrees {
			for _, rightTree := range rightSubtrees {
				root := &TreeNode{Val: i}
				root.Left = leftTree
				root.Right = rightTree
				result = append(result, root)
			}
		}
	}
	return result
}
