use std::cmp::Reverse;
use std::collections::BinaryHeap;

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

#[derive(Debug, Clone, Copy, PartialEq, Eq)]
pub struct Job {
    pub start: i32,
    pub end: i32,
    pub cpu_load: i32,
}

pub fn find_max_cpu_load(jobs: &mut [Job]) -> i32 {
    jobs.sort_by_key(|job| job.start);

    let mut max_cpu_load = 0;
    let mut current_cpu_load = 0;
    // a min heap of (end time, cpu load) for the jobs that are running
    let mut min_heap: BinaryHeap<Reverse<(i32, i32)>> = BinaryHeap::new();

    for job in jobs {
        // remove all jobs that have ended
        while let Some(&Reverse((end, cpu_load))) = min_heap.peek() {
            if job.start <= end {
                break;
            }
            current_cpu_load -= cpu_load;
            min_heap.pop();
        }

        // add the current job into the min_heap
        min_heap.push(Reverse((job.end, job.cpu_load)));
        current_cpu_load += job.cpu_load;
        max_cpu_load = max_cpu_load.max(current_cpu_load);
    }
    max_cpu_load
}
