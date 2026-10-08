namespace DsaPatterns.Subsets;

// Example 1:
// input: 2
// output: 2

// Example 2:
// input: 3
// output: 5

internal static class CountBst
{
    internal static int CountTrees(int n)
    {
        if (n <= 1)
        {
            return 1;
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            // making 'i' root of the tree
            int countOfLeftSubtrees = CountTrees(i - 1);
            int countOfRightSubtrees = CountTrees(n - i);
            count += countOfLeftSubtrees * countOfRightSubtrees;
        }

        return count;
    }
}
