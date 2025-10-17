package levelordertraversal

type NAryNode struct {
	Val      int
	Children []*NAryNode
}

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

type Pair struct {
	node  *TreeNode
	index int
}

func equal(a, b any) bool {
	switch aTyped := a.(type) {
	case []int:
		bTyped, ok := b.([]int)
		if !ok || len(aTyped) != len(bTyped) {
			return false
		}
		for i := range aTyped {
			if aTyped[i] != bTyped[i] {
				return false
			}
		}
		return true
	case [][]int:
		bTyped, ok := b.([][]int)
		if !ok || len(aTyped) != len(bTyped) {
			return false
		}
		for i := range aTyped {
			if len(aTyped[i]) != len(bTyped[i]) {
				return false
			}
			for j := range aTyped[i] {
				if aTyped[i][j] != bTyped[i][j] {
					return false
				}
			}
		}
		return true
	default:
		return false
	}
}
