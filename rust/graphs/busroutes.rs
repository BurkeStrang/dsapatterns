use std::collections::{HashMap, HashSet, VecDeque};

// You are given an array routes where routes[i] is the list of bus stops that
// the ithe bus travels in a cyclic manner.
// For example, if routes[0] = [2, 3, 7],
// it means that bus 0 travels through the stops 2 -> 3 -> 7 -> 2 -> 3 -> 7 ...
// and then repeats this sequence indefinitely.
//
// You start at a bus stop called source and wish to travel to a bus stop called
// target using the bus routes.
// You can switch buses at any bus stop that is common to the routes of two
// buses.
// Return the minimum number of buses you need to take to travel from source to
// target. If it is not possible to reach the target, return -1.
//
// Example 1
// Input: routes = [[2, 3, 4], [5, 6, 7, 8], [4, 5, 9, 10], [10, 12]], source =
// 3, target = 12
// Expected Output: 3
// Justification: Start at stop 3, take bus 0 to stop 4, switch to bus 2 to
// reach stop 10,
// and then take bus 3 to reach to 12. You need 3 buses.
//
// Example 2
// Input: routes = [[1, 2, 3, 4, 5], [5, 6, 7, 8], [8, 9, 10, 11]], source = 1,
// target = 11
// Expected Output: 3
// Justification: Start at stop 1, take bus 0 to stop 5,
// switch to bus 1 to reach stop 8, then switch to bus 2 to reach stop 11. You
// need 3 buses.
//
// Example 3
// Input: routes = [[1, 2, 5], [3, 6, 7], [7, 9, 10]], source = 2, target = 10
// Expected Output: -1
// Justification: It is not possible to reach from bus stop 2 to 10.
//
// Constraints:
// 1 <= routes.length <= 500.
// 1 <= routes[i].length <= 105
// All the values of routes[i] are unique.
// sum(routes[i].length) <= 105
// 0 <= routes[i][j] < 106
// 0 <= source, target < 106

// Method to find the minimum number of buses required to travel from source to
// target

pub fn num_buses_to_destination(
    routes: &[Vec<i32>],
    source: i32,
    target: i32,
) -> i32 {
    if source == target {
        return 0; // If source and target are the same, no bus is needed
    }

    // Map bus stops to buses that visit them
    let mut stop_to_buses: HashMap<i32, Vec<usize>> = HashMap::new();
    for (i, route) in routes.iter().enumerate() {
        for &stop in route {
            stop_to_buses.entry(stop).or_default().push(i);
        }
    }

    // BFS setup
    let mut queue = VecDeque::new();
    let mut visited_stops = HashSet::new();
    let mut used_buses = HashSet::new();
    queue.push_back((source, 0)); // Start with the source stop and 0 buses
    visited_stops.insert(source); // Mark the source stop as visited

    while let Some((stop, buses)) = queue.pop_front() {
        let Some(buses_at_stop) = stop_to_buses.get(&stop) else {
            continue;
        };
        for &bus in buses_at_stop {
            // Mark the current bus as used; insert returns false for buses
            // that have already been used, which we skip
            if !used_buses.insert(bus) {
                continue;
            }

            for &next_stop in &routes[bus] {
                if next_stop == target {
                    return buses + 1; // Found the target stop
                }
                if visited_stops.insert(next_stop) {
                    // Enqueue the next stop with one more bus taken
                    queue.push_back((next_stop, buses + 1));
                }
            }
        }
    }

    -1 // If target is not reachable, return -1
}
