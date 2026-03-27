package knapsackdp

// Given the weights and profits of ‘N’ items,
// we are asked to put these items in a knapsack with a capacity ‘C.’
// The goal is to get the maximum profit out of the knapsack items.
// Each item can only be selected once,
// as we don’t have multiple quantities of any item.
// Let’s take Merry’s example,
// who wants to carry some fruits in the knapsack to get maximum profit.
// Here are the weights and profits of the fruits:
// Items: { Apple, Orange, Banana, Melon }
// Weights: { 2, 3, 1, 4 }
// Profits: { 4, 5, 3, 7 }
// Knapsack capacity: 5
// Let’s try to put various combinations of fruits in the knapsack, such that their total weight is not more than 5:
// Apple + Orange (total weight 5) => 9 profit
// Apple + Banana (total weight 3) => 7 profit
// Orange + Banana (total weight 4) => 8 profit
// Banana + Melon (total weight 5) => 10 profit
// This shows that Banana + Melon is the best combination as it gives us the maximum profit,
// and the total weight does not exceed the capacity.

// brute force solution
// func solveKnapsack(profits, weights []int, capacity int) int {
// 	return knapsackRecursive(profits, weights, capacity, 0)
// }
//
// func knapsackRecursive(profits, weights []int, capacity, currentIndex int) int {
// 	// base checks
// 	if capacity <= 0 || currentIndex >= len(profits) {
// 		return 0
// 	}
// 	// recursive call after choosing the element at the currentIndex
// 	// if the weight of the element at currentIndex exceeds the capacity, we shouldn't process this
// 	profit1 := 0
// 	if weights[currentIndex] <= capacity {
// 		profit1 = profits[currentIndex] + knapsackRecursive(
// 			profits, weights, capacity-weights[currentIndex], currentIndex+1)
// 	}
//
// 	// recursive call after excluding the element at the currentIndex
// 	profit2 := knapsackRecursive(profits, weights, capacity, currentIndex+1)
//
// 	return max(profit1, profit2)
// }

func solveKnapsack(profits, weights []int, capacity int) int {
	// basic checks
	if capacity <= 0 || len(profits) == 0 || len(weights) != len(profits) {
		return 0
	}

	n := len(profits)
	dp := make([]int, capacity+1)

	// if we have only one weight, we will take it if it is not more than the
	// capacity
	for c := 0; c <= capacity; c++ {
		if weights[0] <= c {
			dp[c] = profits[0]
		}
	}

	// process all sub-arrays for all the capacities
	for i := 1; i < n; i++ {
		for c := capacity; c >= 0; c-- {
			profit1, profit2 := 0, 0
			// include the item, if it is not more than the capacity
			if weights[i] <= c {
				profit1 = profits[i] + dp[c-weights[i]]
			}
			// exclude the item
			profit2 = dp[c]
			// take maximum
			dp[c] = max(profit1, profit2)
		}
	}

	return dp[capacity]
}
