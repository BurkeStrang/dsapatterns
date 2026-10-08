namespace DsaPatterns.KWayMerge;

// Given an N * N matrix where each row and column is sorted in ascending order,
// find the Kth smallest element in the matrix.
// Example 1:
// Input: Matrix=[
//     [2, 6, 8],
//     [3, 7, 10],
//     [5, 8, 11]
//   ],
//   K=5
// Output: 7
// Explanation: The 5th smallest number in the matrix is 7.

internal record struct Point(int Row, int Col);

internal static class KSmallestSortedMatrix
{
    // FindKthSmallestPoint finds the Kth smallest element in a matrix
    internal static int FindKthSmallestPoint(int[][] matrix, int k)
    {
        // min-heap of positions, ordered by the number at that position
        PriorityQueue<Point, int> minHeap = new();

        // put the 1st element of each row in the min heap
        // we don't need to push more than 'k' elements in the heap
        for (int i = 0; i < matrix.Length && i < k; i++)
        {
            minHeap.Enqueue(new Point(i, 0), matrix[i][0]);
        }

        // take the smallest (top) element form the min heap, if the running
        // count is equal to k return the number. if the row of the top element
        // has more elements, add the next element to the heap
        int numberCount = 0;
        int result = 0;
        while (minHeap.Count > 0)
        {
            Point node = minHeap.Dequeue();
            result = matrix[node.Row][node.Col];
            numberCount++;
            if (numberCount == k)
            {
                break;
            }

            node.Col++;
            if (matrix[0].Length > node.Col)
            {
                minHeap.Enqueue(node, matrix[node.Row][node.Col]);
            }
        }

        return result;
    }
}
