namespace DsaPatterns.TopologicalSort;

// There are ‘N’ tasks, labeled from ‘0’ to ‘N-1’.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
// Given the number of tasks and a list of prerequisite pairs, find out if it is
// possible to schedule all the tasks.
//
// Example 1:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output: true
// Explanation: A possible scheduling of tasks is: [0 1 4 3 2 5]
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: true
// Explanation: To execute task '1', task '0' needs to finish first. Similarly,
// task '1' needs to finish before '2' can be scheduled. One possible scheduling
// of tasks is: [0, 1, 2]
//
// Example 3:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2], [2, 0]
// Output: false
// Explanation: The tasks have a cyclic dependency, therefore they cannot be
// scheduled.

internal static class TaskSchedueling
{
    internal static bool IsSchedulingPossible(int tasks, int[][] prerequisites)
    {
        List<int> sortedOrder = [];
        if (tasks <= 0)
        {
            return false;
        }

        // Initialize the graph
        // count of incoming edges for every vertex
        Dictionary<int, int> inDegree = [];
        Dictionary<int, List<int>> graph = []; // adjacency list graph
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
            graph[parent].Add(child); // put the child into its parent's list
            inDegree[child]++; // increment child's inDegree
        }

        // Find all sources i.e., all vertices with 0 in-degrees
        Queue<int> sources = new();
        foreach ((int vertex, int degree) in inDegree)
        {
            if (degree == 0)
            {
                sources.Enqueue(vertex);
            }
        }

        // For each source, add it to the sortedOrder and subtract one from all
        // of its children's in-degrees. If a child's in-degree becomes zero,
        // add it to sources queue.
        while (sources.Count > 0)
        {
            int vertex = sources.Dequeue();
            sortedOrder.Add(vertex);

            // Get the node's children to decrement their in-degrees
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
        return sortedOrder.Count == tasks;
    }
}
