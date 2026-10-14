#include <queue>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

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

int schedule_tasks(const std::vector<std::string> &tasks, int k)
{
    int interval_count = 0;

    std::unordered_map<std::string, int> task_frequency_map;
    for (const std::string &task : tasks)
    {
        task_frequency_map[task]++;
    }

    // a max heap of (frequency, task), so the most frequent task is on top
    std::priority_queue<std::pair<int, std::string>> max_heap;
    for (const auto &[task, frequency] : task_frequency_map)
    {
        max_heap.push({frequency, task});
    }

    while (!max_heap.empty())
    {
        std::vector<std::pair<int, std::string>> wait_list;
        int n = k + 1; // try to execute as many as 'k+1' tasks
        for (; n > 0 && !max_heap.empty(); n--)
        {
            auto [frequency, task] = max_heap.top();
            max_heap.pop();
            interval_count++;
            if (frequency > 1)
            {
                wait_list.push_back({frequency - 1, task});
            }
        }

        // put all the waiting list back on the heap
        for (const std::pair<int, std::string> &entry : wait_list)
        {
            max_heap.push(entry);
        }

        if (!max_heap.empty())
        {
            // we'll be having 'n' idle intervals for the next iteration
            interval_count += n;
        }
    }

    return interval_count;
}
