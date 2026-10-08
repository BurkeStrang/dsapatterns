namespace DsaPatterns.Subsets;

internal static class DupSubsets
{
    internal static List<List<int>> FindDupSubsets(int[] nums)
    {
        // sort the numbers to handle duplicates
        Array.Sort(nums);
        List<List<int>> subsets =
        [
            [],
        ];
        int endIndex = 0;
        for (int i = 0; i < nums.Length; i++)
        {
            int startIndex = 0;
            // if current and the previous elements are same, create new
            // subsets only from the subsets added in the previous step
            if (i > 0 && nums[i] == nums[i - 1])
            {
                startIndex = endIndex + 1;
            }

            endIndex = subsets.Count - 1;
            for (int j = startIndex; j <= endIndex; j++)
            {
                // create a new subset from the existing subset and add the
                // current element to it
                List<int> set = [.. subsets[j], nums[i]];
                subsets.Add(set);
            }
        }

        return subsets;
    }
}
