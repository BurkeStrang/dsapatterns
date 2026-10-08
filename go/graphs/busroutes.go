package graphs

// You are given an array routes where routes[i] is the list of bus stops that the ithe bus travels in a cyclic manner.
// For example, if routes[0] = [2, 3, 7],
// it means that bus 0 travels through the stops 2 -> 3 -> 7 -> 2 -> 3 -> 7 ...
// and then repeats this sequence indefinitely.
//
// You start at a bus stop called source and wish to travel to a bus stop called target using the bus routes.
// You can switch buses at any bus stop that is common to the routes of two buses.
// Return the minimum number of buses you need to take to travel from source to target. If it is not possible to reach the target, return -1.
//
// Example 1
// Input: routes = [[2, 3, 4], [5, 6, 7, 8], [4, 5, 9, 10], [10, 12]], source = 3, target = 12
// Expected Output: 3
// Justification: Start at stop 3, take bus 0 to stop 4, switch to bus 2 to reach stop 10,
// and then take bus 3 to reach to 12. You need 3 buses.
//
// Example 2
// Input: routes = [[1, 2, 3, 4, 5], [5, 6, 7, 8], [8, 9, 10, 11]], source = 1, target = 11
// Expected Output: 3
// Justification: Start at stop 1, take bus 0 to stop 5,
// switch to bus 1 to reach stop 8, then switch to bus 2 to reach stop 11. You need 3 buses.
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

// Method to find the minimum number of buses required to travel from source to target
func numBusesToDestination(routes [][]int, source int, target int) int {
	if source == target {
		return 0 // If source and target are the same, no bus is needed
	}

	// Map bus stops to buses that visit them
	stopToBuses := make(map[int][]int)
	for i, route := range routes {
		for _, stop := range route {
			stopToBuses[stop] = append(stopToBuses[stop], i)
		}
	}

	// BFS setup
	queue := make([][2]int, 0)
	visitedStops := make(map[int]bool)
	usedBuses := make(map[int]bool)

	queue = append(queue, [2]int{source, 0}) // Start BFS with the source stop and 0 buses taken
	visitedStops[source] = true              // Mark the source stop as visited

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]
		stop, buses := current[0], current[1]

		for _, bus := range stopToBuses[stop] {
			if usedBuses[bus] {
				continue // Skip buses that have already been used
			}
			usedBuses[bus] = true // Mark the current bus as used

			for _, nextStop := range routes[bus] {
				if nextStop == target {
					return buses + 1 // Found the target stop
				}
				if !visitedStops[nextStop] {
					visitedStops[nextStop] = true
					queue = append(queue, [2]int{nextStop, buses + 1}) // Enqueue the next stop with one more bus taken
				}
			}
		}
	}

	return -1 // If target is not reachable, return -1
}
