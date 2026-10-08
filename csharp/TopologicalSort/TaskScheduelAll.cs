namespace DsaPatterns.TopologicalSort;

// There are N tasks, labeled from 0 to 'N-1'.
// Each task can have some prerequisite tasks which need to be completed before
// it can be scheduled.
//
// Given the number of tasks and a list of prerequisite pairs,
// write a method to print all possible ordering of tasks meeting all
// prerequisites.
//
// Example 1:
// Input: Tasks=4, Prerequisites=[3, 2], [3, 0], [2, 0], [2, 1]
// Output:
// 1) [3, 2, 0, 1]
// 2) [3, 2, 1, 0]
// Explanation: There are two possible orderings of the tasks meeting all
// prerequisites.
//
// Example 2:
// Input: Tasks=3, Prerequisites=[0, 1], [1, 2]
// Output: [0, 1, 2]
// Explanation: There is only possible ordering of the tasks.
//
// Example 3:
// Input: Tasks=6, Prerequisites=[2, 5], [0, 5], [0, 4], [1, 4], [3, 2], [1, 3]
// Output:
// 1) [0, 1, 4, 3, 2, 5]
// 2) [0, 1, 3, 4, 2, 5]
// 3) [0, 1, 3, 2, 4, 5]
// 4) [0, 1, 3, 2, 5, 4]
// 5) [1, 0, 3, 4, 2, 5]
// 6) [1, 0, 3, 2, 4, 5]
// 7) [1, 0, 3, 2, 5, 4]
// 8) [1, 0, 4, 3, 2, 5]
// 9) [1, 3, 0, 2, 4, 5]
// 10) [1, 3, 0, 2, 5, 4]
// 11) [1, 3, 0, 4, 2, 5]
// 12) [1, 3, 2, 0, 5, 4]
// 13) [1, 3, 2, 0, 4, 5]

internal static class TaskSchedulingAll
{
    internal static List<List<int>> PrintOrders(
        int tasks,
        int[][] prerequisites
    )
    {
        List<List<int>> orders = [];
        List<int> sortedOrder = [];
        if (tasks <= 0)
            return orders;

        // a. Initialize the graph
        Dictionary<int, int> inDegree = [];
        Dictionary<int, List<int>> graph = [];
        for (int i = 0; i < tasks; i++)
        {
            inDegree[i] = 0;
            graph[i] = [];
        }

        // b. Build the graph
        for (int i = 0; i < prerequisites.Length; i++)
        {
            int parent = prerequisites[i][0],
                child = prerequisites[i][1];
            graph[parent].Add(child);
            inDegree[child]++;
        }

        // c. Find all sources i.e., all vertices with 0 in-degrees
        Queue<int> sources = new();
        foreach (var entry in inDegree)
        {
            if (entry.Value == 0)
            {
                sources.Enqueue(entry.Key);
            }
        }

        PrintAllTopologicalSorts(graph, inDegree, sources, sortedOrder, orders);

        return orders;
    }

    internal static void PrintAllTopologicalSorts(
        Dictionary<int, List<int>> graph,
        Dictionary<int, int> inDegree,
        Queue<int> sources,
        List<int> sortedOrder,
        List<List<int>> orders
    )
    {
        if (sources.Count > 0)
        {
            foreach (int vertex in new List<int>(sources))
            {
                sortedOrder.Add(vertex);
                Queue<int> sourcesForNextCall = CloneQueue(sources);

                // Remove the current vertex
                List<int> sourcesForNextCallList = [.. sourcesForNextCall];
                sourcesForNextCallList.Remove(vertex);
                sourcesForNextCall = new Queue<int>(sourcesForNextCallList);

                List<int> children = graph[vertex];
                foreach (int child in children)
                {
                    inDegree[child]--;
                    if (inDegree[child] == 0)
                        sourcesForNextCall.Enqueue(child);
                }

                PrintAllTopologicalSorts(
                    graph,
                    inDegree,
                    sourcesForNextCall,
                    sortedOrder,
                    orders
                );

                sortedOrder.Remove(vertex);
                foreach (int child in children)
                    inDegree[child]++;
            }
        }

        if (sortedOrder.Count == inDegree.Count)
            orders.Add([.. sortedOrder]);
    }

    internal static Queue<int> CloneQueue(Queue<int> queue)
    {
        return new Queue<int>([.. queue]);
    }
}
