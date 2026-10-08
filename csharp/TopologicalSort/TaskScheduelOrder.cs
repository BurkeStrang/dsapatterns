namespace DsaPatterns.TopologicalSort;

// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs,
// write a method to find the ordering of tasks we should pick to finish all
// tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: [0 1 4 3 2 5]
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: To execute task '1', task '0' needs to finish first.
// Similarly, task '1' needs to finish before '2' can be scheduled.
// A possible scheduling of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: []
// Explanation: The tasks have a cyclic dependency, therefore they cannot be
// scheduled.

internal static class TaskScheduelOrder
{
    internal static List<int> FindOrder(int tasks, int[][] prerequisites)
    {
        List<int> sortedOrder = [];
        if (tasks <= 0)
        {
            return sortedOrder;
        }

        // Initialize the graph
        Dictionary<int, int> inDegree = [];
        Dictionary<int, List<int>> graph = [];
        for (int i = 0; i < tasks; i++)
        {
            inDegree[i] = 0;
            graph[i] = [];
        }

        // Build the graph
        foreach (int[] prerequisite in prerequisites)
        {
            int parent = prerequisite[0];
            int child = prerequisite[1];
            graph[parent].Add(child);
            inDegree[child]++;
        }

        // Find all sources i.e., all vertices with 0 in-degrees
        Queue<int> sources = new();
        foreach ((int key, int value) in inDegree)
        {
            if (value == 0)
            {
                sources.Enqueue(key);
            }
        }

        // For each source, add it to the sortedOrder and subtract one from all
        // of its children's in-degrees. If a child's in-degree becomes zero,
        // add it to sources queue.
        while (sources.Count > 0)
        {
            int vertex = sources.Dequeue();
            sortedOrder.Add(vertex);
            foreach (int child in graph[vertex])
            {
                inDegree[child]--;
                if (inDegree[child] == 0)
                {
                    sources.Enqueue(child);
                }
            }
        }

        // If sortedOrder doesn't contain all tasks, there is a cyclic
        // dependency between tasks, therefore, we will not be able to schedule
        // all tasks
        if (sortedOrder.Count != tasks)
        {
            return [];
        }

        return sortedOrder;
    }
}
