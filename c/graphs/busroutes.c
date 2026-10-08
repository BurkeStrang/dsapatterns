#include "common/list.h"
#include "common/map.h"
#include "common/queue.h"

#include <stdbool.h>

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

typedef struct
{
    int stop;
    int buses;
} StopVisit;

int num_buses_to_destination
(
    const IntMatrix *routes,
    int source,
    int target
)
{
    if (source == target)
    {
        return 0; // If source and target are the same, no bus is needed
    }

    // Map bus stops to buses that visit them: stop_index gives each stop a
    // row in stop_to_buses (stored as row + 1 so 0 can mean "not seen")
    IntMap stop_index = {0};
    IntMatrix stop_to_buses = {0};
    for (int i = 0; i < routes->len; i++)
    {
        for (int s = 0; s < routes->rows[i].len; s++)
        {
            int stop = routes->rows[i].items[s];
            int row = intmap_get(&stop_index, stop);
            if (row == 0)
            {
                intmatrix_push(&stop_to_buses, (IntList){0});
                row = stop_to_buses.len;
                intmap_set(&stop_index, stop, row);
            }
            intlist_push(&stop_to_buses.rows[row - 1], i);
        }
    }

    // BFS setup
    Queue queue = queue_new(sizeof(StopVisit));
    IntMap visited_stops = {0};
    bool *used_buses = calloc((size_t)routes->len + 1, sizeof(bool));
    // Start BFS with the source stop and 0 buses taken
    queue_push(&queue, &(StopVisit){source, 0});
    intmap_set(&visited_stops, source, 1); // Mark the source stop as visited

    int result = -1; // If target is not reachable, return -1
    while (queue.len > 0 && result == -1)
    {
        StopVisit current;
        queue_pop(&queue, &current);

        int row = intmap_get(&stop_index, current.stop);
        if (row == 0)
        {
            continue; // no bus visits this stop
        }
        const IntList *buses = &stop_to_buses.rows[row - 1];
        for (int b = 0; b < buses->len && result == -1; b++)
        {
            int bus = buses->items[b];
            if (used_buses[bus])
            {
                continue; // Skip buses that have already been used
            }
            used_buses[bus] = true; // Mark the current bus as used

            for (int s = 0; s < routes->rows[bus].len; s++)
            {
                int next_stop = routes->rows[bus].items[s];
                if (next_stop == target)
                {
                    result = current.buses + 1; // Found the target stop
                    break;
                }
                if (!intmap_has(&visited_stops, next_stop))
                {
                    intmap_set(&visited_stops, next_stop, 1);
                    // Enqueue the next stop with one more bus taken
                    queue_push(&queue,
                               &(StopVisit){next_stop, current.buses + 1});
                }
            }
        }
    }

    free(used_buses);
    intmap_free(&visited_stops);
    queue_free(&queue);
    intmatrix_free(&stop_to_buses);
    intmap_free(&stop_index);
    return result;
}
