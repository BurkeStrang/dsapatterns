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

import { Heap } from "../common/heap.ts";

export function scheduleTasks(tasks: string[], k: number): number {
  let intervalCount = 0;
  const taskFrequencyMap = new Map<string, number>();
  for (const task of tasks) {
    taskFrequencyMap.set(task, (taskFrequencyMap.get(task) ?? 0) + 1);
  }

  // a max heap of [frequency, task], so the most frequent task is on top
  const maxHeap = new Heap<[number, string]>(
    (a, b) => a[0] > b[0] || (a[0] === b[0] && a[1] > b[1]),
  );
  for (const [task, frequency] of taskFrequencyMap) {
    maxHeap.push([frequency, task]);
  }

  while (maxHeap.size > 0) {
    const waitList: [number, string][] = [];
    let n = k + 1; // try to execute as many as 'k+1' tasks
    for (; n > 0 && maxHeap.size > 0; n--) {
      const [frequency, task] = maxHeap.pop() ?? [0, ""];
      intervalCount++;
      if (frequency > 1) {
        waitList.push([frequency - 1, task]);
      }
    }

    // put all the waiting list back on the heap
    for (const entry of waitList) {
      maxHeap.push(entry);
    }

    if (maxHeap.size > 0) {
      // we'll be having 'n' idle intervals for the next iteration
      intervalCount += n;
    }
  }

  return intervalCount;
}
