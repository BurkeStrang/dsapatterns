use std::collections::{BinaryHeap, HashMap};

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

pub fn schedule_tasks(tasks: &[&str], k: usize) -> usize {
    let mut interval_count = 0;

    let mut task_frequency_map: HashMap<&str, usize> = HashMap::new();
    for &task in tasks {
        *task_frequency_map.entry(task).or_insert(0) += 1;
    }

    // a max heap of (frequency, task), so the most frequent task is on top
    let mut max_heap: BinaryHeap<(usize, &str)> = task_frequency_map
        .into_iter()
        .map(|(task, frequency)| (frequency, task))
        .collect();

    while !max_heap.is_empty() {
        let mut wait_list = Vec::new();
        let mut n = k + 1; // try to execute as many as 'k+1' tasks
        while n > 0 {
            let Some((frequency, task)) = max_heap.pop() else {
                break;
            };
            interval_count += 1;
            if frequency > 1 {
                wait_list.push((frequency - 1, task));
            }
            n -= 1;
        }

        // put all the waiting list back on the heap
        max_heap.extend(wait_list);

        if !max_heap.is_empty() {
            // we'll be having 'n' idle intervals for the next iteration
            interval_count += n;
        }
    }

    interval_count
}
