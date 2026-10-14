use std::cmp::Reverse;
use std::collections::BinaryHeap;

// Given a set of investment projects with their respective profits, we need
// to find the most profitable projects. We are given an initial capital and
// are allowed to invest only in a fixed number of projects. Our goal is to
// choose projects that give us the maximum profit. We can start an investment
// project only when we have the required capital. Once a project is selected,
// we can assume that its profit has become our capital.

pub fn find_maximum_capital(
    capital_arr: &[i32],
    profits_arr: &[i32],
    number_of_projects: usize,
    initial_capital: i32,
) -> i32 {
    let n = profits_arr.len();
    // a min-heap of (capital, project index), so the cheapest project is on
    // top; BinaryHeap is a max-heap, hence the Reverse
    let mut min_capital_heap = BinaryHeap::new();
    // a max-heap of the profits of the projects we can afford
    let mut max_profit_heap = BinaryHeap::new();

    // insert all project indices into the min-capital heap
    for i in 0..n {
        min_capital_heap.push(Reverse((capital_arr[i], i)));
    }

    // try to find a total of 'number_of_projects' best projects
    let mut available_capital = initial_capital;
    for _ in 0..number_of_projects {
        // move all affordable projects into the max-profit heap
        while let Some(&Reverse((capital, i))) = min_capital_heap.peek() {
            if capital > available_capital {
                break;
            }
            min_capital_heap.pop();
            max_profit_heap.push(profits_arr[i]);
        }

        // select the project with the maximum profit
        let Some(profit) = max_profit_heap.pop() else {
            break; // no affordable project found
        };
        available_capital += profit;
    }

    available_capital
}
