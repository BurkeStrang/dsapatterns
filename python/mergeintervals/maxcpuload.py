"""
We are given a list of Jobs. Each job has a Start time, an End time, and a
CPU load when it is running. Our goal is to find the maximum CPU load at any
time if all the jobs are running on the same machine.

Example 1:
Jobs: [[1,4,3], [2,5,4], [7,9,6]]
Output: 7
Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load
(3+4=7) will be when both the jobs are running at the same time i.e., during
the time interval (2,4).

Example 2:
Jobs: [[6,7,10], [2,4,11], [8,12,15]]
Output: 15
Explanation: None of the jobs overlap, therefore we will take the maximum
load of any job which is 15.

Example 3:
Jobs: [[1,4,2], [2,4,1], [3,6,5]]
Output: 8
Explanation: Maximum CPU load will be 8 as all jobs overlap during the time
interval [3,4].
"""

import heapq
from dataclasses import dataclass


@dataclass
class Job:
    start: int
    end: int
    cpu_load: int


def find_max_cpu_load(jobs: list[Job]) -> int:
    jobs.sort(key=lambda job: job.start)
    max_cpu_load = 0
    current_cpu_load = 0
    # a min heap of (end time, cpu load) for the jobs that are running
    min_heap: list[tuple[int, int]] = []
    for job in jobs:
        # remove all jobs that have ended
        while min_heap and job.start > min_heap[0][0]:
            current_cpu_load -= heapq.heappop(min_heap)[1]
        # add the current job into the min_heap
        heapq.heappush(min_heap, (job.end, job.cpu_load))
        current_cpu_load += job.cpu_load
        max_cpu_load = max(max_cpu_load, current_cpu_load)
    return max_cpu_load
