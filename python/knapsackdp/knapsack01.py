"""
Given the weights and profits of ‘N’ items,
we are asked to put these items in a knapsack with a capacity ‘C.’
The goal is to get the maximum profit out of the knapsack items.
Each item can only be selected once,
as we don’t have multiple quantities of any item.
Let’s take Merry’s example,
who wants to carry some fruits in the knapsack to get maximum profit.
Here are the weights and profits of the fruits:
Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5
Let’s try to put various combinations of fruits in the knapsack, such that
their total weight is not more than 5:
Apple + Orange (total weight 5) => 9 profit
Apple + Banana (total weight 3) => 7 profit
Orange + Banana (total weight 4) => 8 profit
Banana + Melon (total weight 5) => 10 profit
This shows that Banana + Melon is the best combination as it gives us the
maximum profit,
and the total weight does not exceed the capacity.
"""

# brute force solution
# def solve_knapsack(profits, weights, capacity):
#     return knapsack_recursive(profits, weights, capacity, 0)
#
# def knapsack_recursive(profits, weights, capacity, current_index):
#     # base checks
#     if capacity <= 0 or current_index >= len(profits):
#         return 0
#
#     # recursive call after choosing the element at the current_index
#     # if the weight of the element at current_index exceeds the capacity,
#     # we shouldn't process this
#     profit1 = 0
#     if weights[current_index] <= capacity:
#         profit1 = profits[current_index] + knapsack_recursive(
#             profits, weights, capacity - weights[current_index],
#             current_index + 1
#         )
#
#     # recursive call after excluding the element at the current_index
#     profit2 = knapsack_recursive(
#         profits, weights, capacity, current_index + 1
#     )
#
#     return max(profit1, profit2)


def solve_knapsack(
    profits: list[int], weights: list[int], capacity: int
) -> int:
    # basic checks
    if capacity <= 0 or not profits or len(weights) != len(profits):
        return 0

    n = len(profits)
    dp = [0] * (capacity + 1)

    # if we have only one weight, we will take it if it is not more than the
    # capacity
    for c in range(capacity + 1):
        if weights[0] <= c:
            dp[c] = profits[0]

    # process all sub-arrays for all the capacities
    for i in range(1, n):
        for c in range(capacity, -1, -1):
            profit1 = 0
            # include the item, if it is not more than the capacity
            if weights[i] <= c:
                profit1 = profits[i] + dp[c - weights[i]]
            # exclude the item
            profit2 = dp[c]
            # take maximum
            dp[c] = max(profit1, profit2)

    return dp[capacity]
