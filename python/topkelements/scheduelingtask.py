"""
You are given a list of tasks that need to be run, in any order, on a server.
Each task will take one CPU interval to execute but once a task has finished,
it has a cooling period during which it can’t be run again.
If the cooling period for all tasks is ‘K’ intervals,
find the minimum number of CPU intervals that the server needs to finish all
tasks.
If at any time the server can’t execute any task then it must stay idle.

Example 1:
Input: [a, a, a, b, c, c], K=2
Output: 7
Explanation: a -> c -> b -> a -> c -> idle -> a

Example 2:
Input: [a, b, a], K=3
Output: 5
Explanation: a -> b -> idle -> idle -> a
"""

import heapq
from collections import Counter


def schedule_tasks(tasks: list[str], k: int) -> int:
    interval_count = 0
    task_frequency_map = Counter(tasks)

    # a max heap of (frequency, task), so the most frequent task is on top;
    # heapq only makes min-heaps, so the frequency is stored negated
    max_heap = [
        (-frequency, task) for task, frequency in task_frequency_map.items()
    ]
    heapq.heapify(max_heap)

    while max_heap:
        wait_list: list[tuple[int, str]] = []
        n = k + 1  # try to execute as many as 'k+1' tasks
        while n > 0 and max_heap:
            frequency, task = heapq.heappop(max_heap)
            interval_count += 1
            if frequency < -1:
                wait_list.append((frequency + 1, task))
            n -= 1

        # put all the waiting list back on the heap
        for entry in wait_list:
            heapq.heappush(max_heap, entry)

        if max_heap:
            # we'll be having 'n' idle intervals for the next iteration
            interval_count += n

    return interval_count
