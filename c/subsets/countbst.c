// Example 1:
// input: 2
// output: 2

// Example 2:
// input: 3
// output: 5

int count_trees
(
    int n
)
{
    if (n <= 1)
    {
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        // making 'i' root of the tree
        int count_of_left_subtrees = count_trees(i - 1);
        int count_of_right_subtrees = count_trees(n - i);
        count += count_of_left_subtrees * count_of_right_subtrees;
    }
    return count;
}
