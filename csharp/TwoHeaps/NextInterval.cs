namespace DsaPatterns.TwoHeaps;

// Interval represents an interval with a start and an end.
internal record struct Interval(int Start, int End);

internal static class NextInterval
{
    internal static int[] FindNextInterval(Interval[] intervals)
    {
        int n = intervals.Length;
        // max-heaps of interval indexes, ordered by start and by end times
        PriorityQueue<int, int> maxStartHeap = Shared.NewMaxHeap();
        PriorityQueue<int, int> maxEndHeap = Shared.NewMaxHeap();
        int[] result = new int[n];

        // Initialize heaps
        for (int i = 0; i < n; i++)
        {
            maxStartHeap.Enqueue(i, intervals[i].Start);
            maxEndHeap.Enqueue(i, intervals[i].End);
        }

        // Iterate through intervals to find the next interval
        for (int k = 0; k < n; k++)
        {
            int topEnd = maxEndHeap.Dequeue();
            result[topEnd] = -1; // Default to -1
            if (intervals[maxStartHeap.Peek()].Start >= intervals[topEnd].End)
            {
                int topStart = maxStartHeap.Dequeue();
                while (
                    maxStartHeap.Count > 0
                    && intervals[maxStartHeap.Peek()].Start
                        >= intervals[topEnd].End
                )
                {
                    topStart = maxStartHeap.Dequeue();
                }

                result[topEnd] = topStart;
                // Put it back as it could be next for other intervals
                maxStartHeap.Enqueue(topStart, intervals[topStart].Start);
            }
        }

        return result;
    }
}
