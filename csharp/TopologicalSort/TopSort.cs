namespace DsaPatterns.TopologicalSort;

internal static class TopSort
{
    internal static List<int> Sort(int vertices, int[][] edges)
    {
        List<int> sortedOrder = [];
        if (vertices <= 0)
        {
            return sortedOrder;
        }

        // a. Initialize the graph
        // count of incoming edges for every vertex
        Dictionary<int, int> inDegree = [];
        Dictionary<int, List<int>> graph = []; // adjacency list graph
        for (int i = 0; i < vertices; i++)
        {
            inDegree[i] = 0;
            graph[i] = [];
        }

        // b. Build the graph
        foreach (int[] edge in edges)
        {
            int parent = edge[0];
            int child = edge[1];
            graph[parent].Add(child); // put the child into its parent's list
            inDegree[child]++; // increment child's inDegree
        }

        // c. Find all sources i.e., all vertices with 0 in-degrees
        Queue<int> sources = new();
        foreach ((int key, int value) in inDegree)
        {
            if (value == 0)
            {
                sources.Enqueue(key);
            }
        }

        // d. For each source, add it to the sortedOrder and subtract one from
        // all of its children's in-degrees if a child's in-degree becomes
        // zero, add it to sources queue
        while (sources.Count > 0)
        {
            int vertex = sources.Dequeue();
            sortedOrder.Add(vertex);

            // get the node's children to decrement their in-degrees
            foreach (int child in graph[vertex])
            {
                inDegree[child]--;
                if (inDegree[child] == 0)
                {
                    sources.Enqueue(child);
                }
            }
        }

        // if topological sort is not possible as the graph has a cycle
        if (sortedOrder.Count != vertices)
        {
            return [];
        }

        return sortedOrder;
    }
}
