#include "common/list.hpp"

#include <functional>
#include <queue>
#include <utility>
#include <vector>

// Given an array of ‘K’ sorted LinkedLists, merge them into one sorted list.
// Example 1:
// Input: L1=[2, 6, 8], L2=[3, 6, 7], L3=[1, 3, 4]
// Output: [1, 2, 3, 3, 4, 6, 6, 7, 8]
//
// Example 2:
// Input: L1=[5, 8, 9], L2=[1, 7]
// Output: [1, 5, 7, 8, 9]

// merge merges the given lists into one sorted list.
ListNode *merge(const std::vector<ListNode *> &lists)
{
    // a min heap of (value of a node, index of its list); the nodes are
    // looked up through 'heads', the first node not yet merged of each list
    std::vector<ListNode *> heads = lists;
    using Entry = std::pair<int, int>;
    std::priority_queue<Entry, std::vector<Entry>, std::greater<>> min_heap;

    // put the root of each list in the min heap
    for (int i = 0; i < std::ssize(heads); i++)
    {
        if (heads[i] != nullptr)
        {
            min_heap.push({heads[i]->value, i});
        }
    }

    // take the smallest (top) element form the min-heap and add it to the
    // result; if the top element has a next element add it to the heap
    ListNode *result_head = nullptr;
    ListNode *result_tail = nullptr;
    while (!min_heap.empty())
    {
        int i = min_heap.top().second;
        min_heap.pop();
        ListNode *node = heads[i];
        heads[i] = node->next;

        if (result_head == nullptr)
        {
            result_head = node;
        }
        else
        {
            result_tail->next = node;
        }
        result_tail = node;

        if (heads[i] != nullptr)
        {
            min_heap.push({heads[i]->value, i});
        }
    }

    return result_head;
}
