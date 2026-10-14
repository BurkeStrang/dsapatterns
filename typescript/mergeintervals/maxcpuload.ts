// We are given a list of Jobs. Each job has a Start time, an End time, and a
// CPU load when it is running. Our goal is to find the maximum CPU load at any
// time if all the jobs are running on the same machine.
//
// Example 1:
// Jobs: [[1,4,3], [2,5,4], [7,9,6]]
// Output: 7
// Explanation: Since [1,4,3] and [2,5,4] overlap, their maximum CPU load
// (3+4=7) will be when both the jobs are running at the same time i.e., during
// the time interval (2,4).
//
// Example 2:
// Jobs: [[6,7,10], [2,4,11], [8,12,15]]
// Output: 15
// Explanation: None of the jobs overlap, therefore we will take the maximum
// load of any job which is 15.
//
// Example 3:
// Jobs: [[1,4,2], [2,4,1], [3,6,5]]
// Output: 8
// Explanation: Maximum CPU load will be 8 as all jobs overlap during the time
// interval [3,4].

import { Heap } from "../common/heap.ts";

export interface Job {
  start: number;
  end: number;
  cpuLoad: number;
}

export function findMaxCpuLoad(jobs: Job[]): number {
  jobs.sort((a, b) => a.start - b.start);
  let maxCpuLoad = 0;
  let currentCpuLoad = 0;
  // a min heap of the jobs that are running, ordered by end time
  const minHeap = new Heap<Job>((a, b) => a.end < b.end);
  for (const job of jobs) {
    // remove all jobs that have ended
    let running = minHeap.peek();
    while (running !== undefined && job.start > running.end) {
      currentCpuLoad -= running.cpuLoad;
      minHeap.pop();
      running = minHeap.peek();
    }
    // add the current job into the minHeap
    minHeap.push(job);
    currentCpuLoad += job.cpuLoad;
    maxCpuLoad = Math.max(maxCpuLoad, currentCpuLoad);
  }
  return maxCpuLoad;
}
