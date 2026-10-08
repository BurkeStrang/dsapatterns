namespace DsaPatterns.TwoHeaps;

internal static class MaxCapital
{
    internal static int FindMaximumCapital(
        int[] capitalArr,
        int[] profitsArr,
        int numberOfProjects,
        int initialCapital
    )
    {
        int n = profitsArr.Length;
        // min-heap of project indices sorted by capital requirement
        PriorityQueue<int, int> minCapitalHeap = new();
        // max-heap of project indices sorted by profit
        PriorityQueue<int, int> maxProfitHeap = Shared.NewMaxHeap();

        // insert all project indices into the min-capital heap
        for (int i = 0; i < n; i++)
        {
            minCapitalHeap.Enqueue(i, capitalArr[i]);
        }

        // try to find a total of 'numberOfProjects' best projects
        int availableCapital = initialCapital;
        for (int p = 0; p < numberOfProjects; p++)
        {
            // move all affordable projects into the max-profit heap
            while (
                minCapitalHeap.Count > 0
                && capitalArr[minCapitalHeap.Peek()] <= availableCapital
            )
            {
                int project = minCapitalHeap.Dequeue();
                maxProfitHeap.Enqueue(project, profitsArr[project]);
            }

            // no affordable project found
            if (maxProfitHeap.Count == 0)
            {
                break;
            }

            // select the project with the maximum profit
            availableCapital += profitsArr[maxProfitHeap.Dequeue()];
        }

        return availableCapital;
    }
}
