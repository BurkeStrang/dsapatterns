#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

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
int num_buses_to_destination(const std::vector<std::vector<int>> &routes,
                             int source, int target)
{
    if (source == target)
    {
        return 0; // If source and target are the same, no bus is needed
    }

    // Map bus stops to buses that visit them
    std::unordered_map<int, std::vector<int>> stop_to_buses;
    for (int i = 0; i < std::ssize(routes); i++)
    {
        for (int stop : routes[i])
        {
            stop_to_buses[stop].push_back(i);
        }
    }

    // BFS setup
    std::queue<std::pair<int, int>> queue;
    std::unordered_set<int> visited_stops;
    std::unordered_set<int> used_buses;
    queue.push({source, 0});      // Start with the source stop and 0 buses
    visited_stops.insert(source); // Mark the source stop as visited

    while (!queue.empty())
    {
        auto [stop, buses] = queue.front();
        queue.pop();
        auto buses_at_stop = stop_to_buses.find(stop);
        if (buses_at_stop == stop_to_buses.end())
        {
            continue;
        }
        for (int bus : buses_at_stop->second)
        {
            // Mark the current bus as used; insert reports false for buses
            // that have already been used, which we skip
            if (!used_buses.insert(bus).second)
            {
                continue;
            }

            for (int next_stop : routes[bus])
            {
                if (next_stop == target)
                {
                    return buses + 1; // Found the target stop
                }
                if (visited_stops.insert(next_stop).second)
                {
                    // Enqueue the next stop with one more bus taken
                    queue.push({next_stop, buses + 1});
                }
            }
        }
    }

    return -1; // If target is not reachable, return -1
}
