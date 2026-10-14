#include <compare>
#include <format>
#include <queue>
#include <string>
#include <utility>
#include <vector>

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

struct Point
{
    int x;
    int y;

    int dist_from_origin() const
    {
        // ignoring sqrt
        return (x * x) + (y * y);
    }

    // points compare by x, then y, so that they can go in a heap and be
    // sorted
    auto operator<=>(const Point &) const = default;
};

inline std::string to_string(const Point &point)
{
    return std::format("({}, {})", point.x, point.y);
}

std::vector<Point> find_closest_points(const std::vector<Point> &points, int k)
{
    // a max heap of (distance from the origin, point), so the point farthest
    // from the origin is on top
    std::priority_queue<std::pair<int, Point>> max_point_heap;

    // put first 'k' points in the max heap
    for (int i = 0; i < k; i++)
    {
        max_point_heap.push({points[i].dist_from_origin(), points[i]});
    }

    // go through the remaining points of the input array, if a point is
    // closer to the origin than the top point of the max-heap, remove the top
    // point from heap and add the point from the input array
    for (int i = k; i < std::ssize(points); i++)
    {
        if (points[i].dist_from_origin() < max_point_heap.top().first)
        {
            max_point_heap.pop();
            max_point_heap.push({points[i].dist_from_origin(), points[i]});
        }
    }

    // the heap has 'k' points closest to the origin, return them in a list
    std::vector<Point> result;
    while (!max_point_heap.empty())
    {
        result.push_back(max_point_heap.top().second);
        max_point_heap.pop();
    }
    return result;
}
