namespace DsaPatterns.Subsets;

// example1: [1,3] => [[], [1], [3], [1,3]]
// example2: [1,5,3] => [[], [1], [5], [3], [1,5], [1,3], [5,3], [1,5,3]]

internal static class DistinctSubsets
{
    internal static List<List<int>> FindSubsets(int[] nums)
    {
        List<List<int>> subsets = [];
        // start by adding the empty subset
        subsets.Add([]);
        // subsets = [[]]

        foreach (int currentNumber in nums)
        {
            // ===== Iteration 1 =====
            // currentNumber = 1

            // ===== Iteration 2 =====
            // currentNumber = 3

            // we will take all existing subsets and insert the current number
            // in them
            int n = subsets.Count;
            for (int i = 0; i < n; i++)
            {
                // -------- EXAMPLE WALKTHROUGH --------
                // INPUT: nums = [1,3]
                // Before any loops:
                // subsets = [[]]
                // ===============================
                // OUTER LOOP 1
                // currentNumber = 1
                // n = 1
                //
                // INNER LOOP:
                //
                // i = 0
                // subsets[i] = []
                // set (copy of subsets[i]) = []
                // after append currentNumber:
                // set = [1]
                //
                // subsets becomes:
                // [[], [1]]
                // ===============================
                // ===============================
                // OUTER LOOP 2
                // currentNumber = 3
                // n = 2  (because subsets now has 2 items)
                //
                // INNER LOOP:
                //
                // i = 0
                // subsets[0] = []
                // set = []
                // after append:
                // set = [3]
                //
                // subsets becomes:
                // [[], [1], [3]]
                //
                // i = 1
                // subsets[1] = [1]
                // set = [1]
                // after append:
                // set = [1,3]
                //
                // subsets becomes:
                // [[], [1], [3], [1,3]]
                // ===============================
                List<int> set = [.. subsets[i], currentNumber];
                subsets.Add(set);
            }
        }

        return subsets;
    }
}
