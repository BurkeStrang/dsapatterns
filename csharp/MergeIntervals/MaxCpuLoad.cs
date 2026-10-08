namespace DsaPatterns.MergeIntervals;

// We are given a list of Jobs. Each job has a Start time, an End time, and a
// CPU load when it is running. Our goal is to find the maximum CPU load at any
// time if all the jobs are running on the same machine.
//
// Example 1:
// Jobs: [[1,4,3], [2,5,4], [7,9,6]]
// Output: 7
// Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load
// (3+4=7) will be when both the jobs are running at the same time i.e., during
// the time interval (2,4).
//
// Example 2:
// Jobs: [[6,7,10], [2,4,11], [8,12,15]]
// Output: 15
// Explanation: None of the jobs overlap, therefore we will take the maximum
// load of any job which is 15.
//
// Example 3:
// Jobs: [[1,4,2], [2,4,1], [3,6,5]]
// Output: 8
// Explanation: Maximum CPU load will be 8 as all jobs overlap during the time
// interval [3,4].

internal record Job(int Start, int End, int CpuLoad);

internal static class MaxCpuLoad
{
    internal static int FindMaxCpuLoad(Job[] jobs)
    {
        Array.Sort(jobs, (a, b) => a.Start.CompareTo(b.Start));

        int maxCpuLoad = 0;
        int currentCpuLoad = 0;
        // min heap ordered by job end time
        PriorityQueue<Job, int> minHeap = new();

        foreach (Job job in jobs)
        {
            // remove all jobs that have ended
            while (minHeap.Count > 0 && job.Start > minHeap.Peek().End)
            {
                currentCpuLoad -= minHeap.Dequeue().CpuLoad;
            }

            // add the current job into the minHeap
            minHeap.Enqueue(job, job.End);
            currentCpuLoad += job.CpuLoad;
            maxCpuLoad = Math.Max(maxCpuLoad, currentCpuLoad);
        }

        return maxCpuLoad;
    }
}
