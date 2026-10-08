namespace DsaPatterns.TopKElements;

// Given an array of points in a 2D plane, find ‘K’ closest points to the
// origin.
//
// Example 1:
// Input: points = [[1,2],[1,3]], K = 1
// Output: [[1,2]]
// Explanation: The Euclidean distance between (1, 2) and the origin is sqrt(5).
// The Euclidean distance between (1, 3) and the origin is sqrt(10).
// Since sqrt(5) < sqrt(10), therefore (1, 2) is closer to the origin.
//
// Example 2:
// Input: point = [[1, 3], [3, 4], [2, -1]], K = 2
// Output: [[1, 3], [2, -1]]

internal static class KColsestPointsToOrigin
{
    internal static Point[] FindClosestPoints(Point[] points, int k)
    {
        // max heap of points, ordered by distance from the origin
        PriorityQueue<Point, int> maxPointHeap = Shared.NewMaxHeap<Point>();

        // put first 'k' points in the max heap
        for (int i = 0; i < k; i++)
        {
            maxPointHeap.Enqueue(points[i], points[i].DistFromOrigin());
        }

        // go through the remaining points of the input array, if a point is
        // closer to the origin than the top point of the max-heap, remove the
        // top point from heap and add the point from the input array
        for (int i = k; i < points.Length; i++)
        {
            if (
                points[i].DistFromOrigin()
                < maxPointHeap.Peek().DistFromOrigin()
            )
            {
                maxPointHeap.Dequeue();
                maxPointHeap.Enqueue(points[i], points[i].DistFromOrigin());
            }
        }

        // the heap has 'k' points closest to the origin, return them in an
        // array
        Point[] result = new Point[k];
        for (int i = 0; i < k; i++)
        {
            result[i] = maxPointHeap.Dequeue();
        }

        return result;
    }
}
