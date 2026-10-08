namespace DsaPatterns.Subsets;

internal static class Permutations
{
    internal static List<List<int>> FindPermutations(int[] nums)
    {
        List<List<int>> result = [];
        Queue<List<int>> permutations = new();
        permutations.Enqueue([]);
        foreach (int currentNumber in nums)
        {
            // we will take all existing permutations and add the current
            // number to create new permutations
            int n = permutations.Count;
            for (int p = 0; p < n; p++)
            {
                List<int> oldPermutation = permutations.Dequeue();
                // create a new permutation by adding the current number at
                // every position
                for (int j = 0; j <= oldPermutation.Count; j++)
                {
                    List<int> newPermutation = [.. oldPermutation];
                    newPermutation.Insert(j, currentNumber);
                    if (newPermutation.Count == nums.Length)
                    {
                        result.Add(newPermutation);
                    }
                    else
                    {
                        permutations.Enqueue(newPermutation);
                    }
                }
            }
        }

        return result;
    }
}
