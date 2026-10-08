// Given a staircase with ‘n’ steps and an array of 'n' numbers representing
// the fee that you have to pay if you take the step.
// Implement a method to calculate the minimum fee required to reach the top of
// the staircase
// (beyond the top-most step).
// At every step, you have an option to take either 1 step, 2 steps, or 3 steps.
// You should assume that you are standing at the first step.
//
// Example 1:
// Number of stairs (n) : 6
// Fee: {1,2,5,2,1,2}
// Output: 3
// Explanation: Starting from index '0', we can reach the top through: 0->3->top
// The total fee we have to pay will be (1+2).
//
// Example 2:
// Number of stairs (n): 4
// Fee: {2,3,4,5}
// Output: 5
// Explanation: Starting from index '0', we can reach the top through: 0->1->top
// The total fee we have to pay will be (2+3).

int find_min_fee_recursive
(
    const int *fee,
    int fee_len,
    int current_index
)
{
    if (current_index > fee_len - 1)
    {
        return 0;
    }

    // if we take 1 step, we are left with 'n-1' steps;
    int take_1_step = find_min_fee_recursive(fee, fee_len, current_index + 1);
    // similarly, if we took 2 steps, we are left with 'n-2' steps;
    int take_2_step = find_min_fee_recursive(fee, fee_len, current_index + 2);
    // if we took 3 steps, we are left with 'n-3' steps;
    int take_3_step = find_min_fee_recursive(fee, fee_len, current_index + 3);

    int min = take_1_step;
    if (take_2_step < min)
    {
        min = take_2_step;
    }
    if (take_3_step < min)
    {
        min = take_3_step;
    }

    return min + fee[current_index];
}

int find_min_fee
(
    const int *fee,
    int fee_len
)
{
    return find_min_fee_recursive(fee, fee_len, 0);
}
