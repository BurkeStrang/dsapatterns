namespace DsaPatterns.TopKElements;

// You are given a list of tasks that need to be run, in any order, on a server.
// Each task will take one CPU interval to execute but once a task has finished,
// it has a cooling period during which it can’t be run again.
// If the cooling period for all tasks is ‘K’ intervals,
// find the minimum number of CPU intervals that the server needs to finish all
// tasks.
// If at any time the server can’t execute any task then it must stay idle.
//
// Example 1:
// Input: [a, a, a, b, c, c], K=2
// Output: 7
// Explanation: a -> c -> b -> a -> c -> idle -> a
//
// Example 2:
// Input: [a, b, a], K=3
// Output: 5
// Explanation: a -> b -> idle -> idle -> a

internal record struct TaskEntry(string Task, int Frequency);

internal static class ScheduelingTask
{
    internal static int ScheduleTasks(string[] tasks, int k)
    {
        int intervalCount = 0;
        Dictionary<string, int> taskFrequencyMap = [];
        foreach (string task in tasks)
        {
            taskFrequencyMap[task] =
                taskFrequencyMap.GetValueOrDefault(task) + 1;
        }

        // max heap of tasks, ordered by frequency
        PriorityQueue<TaskEntry, int> maxHeap = Shared.NewMaxHeap<TaskEntry>();
        foreach ((string task, int frequency) in taskFrequencyMap)
        {
            maxHeap.Enqueue(new TaskEntry(task, frequency), frequency);
        }

        while (maxHeap.Count > 0)
        {
            List<TaskEntry> waitList = [];
            int n = k + 1;
            while (n > 0 && maxHeap.Count > 0)
            {
                intervalCount++;
                TaskEntry task = maxHeap.Dequeue();
                if (task.Frequency > 1)
                {
                    task.Frequency--;
                    waitList.Add(task);
                }

                n--;
            }

            foreach (TaskEntry task in waitList)
            {
                maxHeap.Enqueue(task, task.Frequency);
            }

            if (maxHeap.Count > 0)
            {
                intervalCount += n;
            }
        }

        return intervalCount;
    }
}
