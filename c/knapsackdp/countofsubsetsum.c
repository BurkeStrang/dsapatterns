// Given a set of positive numbers,
// find the total number of subsets whose sum is equal to a given number ‘S’.
//
// Example 1:
// Input: {1, 1, 2, 3}, S=4
// Output: 3
// The given set has '3' subsets whose sum is '4': {1, 1, 2}, {1, 3}, {1, 3}
// Note that we have two similar sets {1, 3}, because we have two '1' in our
// input.
//
// Example 2:
// Input: {1, 2, 7, 1, 5}, S=9
// Output: 3
// The given set has '3' subsets whose sum is '9': {2, 7}, {1, 7, 1}, {1, 2, 1,
// 5}

int count_subsets_recursive
(
    const int *num,
    int num_len,
    int sum,
    int current_index
)
{
    // base checks
    if (sum == 0)
    {
        return 1;
    }

    if (num_len == 0 || current_index >= num_len)
    {
        return 0;
    }

    // recursive call after selecting the number at the current_index
    // if the number at current_index exceeds the sum, we shouldn't process
    // this
    int sum1 = 0;
    if (num[current_index] <= sum)
    {
        sum1 = count_subsets_recursive(num, num_len, sum - num[current_index],
                                       current_index + 1);
    }

    // recursive call after excluding the number at the current_index
    int sum2 = count_subsets_recursive(num, num_len, sum, current_index + 1);

    return sum1 + sum2;
}

int count_subsets
(
    const int *num,
    int num_len,
    int sum
)
{
    return count_subsets_recursive(num, num_len, sum, 0);
}
