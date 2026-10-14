#include <functional>
#include <queue>
#include <tuple>
#include <vector>

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

// find_kth_smallest_point finds the Kth smallest element in a matrix
int find_kth_smallest_point(const std::vector<std::vector<int>> &matrix, int k)
{
    // a min heap of (number, row, column); tuples compare field by field, so
    // the smallest number is on top
    using Entry = std::tuple<int, int, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<>> min_heap;

    // put the 1st element of each row in the min heap
    // we don't need to push more than 'k' elements in the heap
    for (int row = 0; row < std::ssize(matrix) && row < k; row++)
    {
        min_heap.push({matrix[row][0], row, 0});
    }

    // take the smallest (top) element form the min heap, if the running count
    // is equal to k return the number. if the row of the top element has more
    // elements, add the next element to the heap
    int number_count = 0;
    int result = 0;
    while (!min_heap.empty())
    {
        auto [num, row, col] = min_heap.top();
        min_heap.pop();
        result = num;
        number_count++;
        if (number_count == k)
        {
            break;
        }

        col++;
        if (col < std::ssize(matrix[row]))
        {
            min_heap.push({matrix[row][col], row, col});
        }
    }

    return result;
}
