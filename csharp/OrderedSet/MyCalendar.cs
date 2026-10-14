namespace DsaPatterns.OrderedSet;
// Given a 2D array nums of size N x 2.
// nums[i] = [starti, endi],
// where starti is the starting time of the event and end
// i is the ending time of the event.
// For each nums[i],
// determine if a requested booking time conflicts with any existing bookings.
// Return a boolean array of size N,
// representing whether the booking can be done in the given time interval.
//
// Example 1:
// Input: nums = [[10, 20], [15, 25], [20, 30]]
// Expected Output: [true, false, true]
// Justification: The first event is booked successfully.
// The second event overlaps with the first one and is rejected.
// The third event starts when the first event ends, so it's booked successfully.
//
// Example 2:
// Input: [[5, 10], [10, 15], [5, 15]]
// Expected Output: [true, true, false]
// Justification: The first and second events are booked without overlap.
// The third event overlaps with both the first and second, so it's rejected.
//
// Example 3:
// Input: [[8, 13],[13, 17], [17, 20]]
// Expected Output: [true, true, true]
// Justification: All events are booked without any overlap, as each event starts exactly when the previous one ends.
// Constraints:
//
// 0 <= start < end <= 109
// At most 1000 calls will be made to book.


internal static class MyCalendar
{
    // Custom comparer for SortedSet
    private class IntervalComparer : IComparer<int[]>
    {
        int IComparer<int[]>.Compare(int[]? x, int[]? y)
        {
            return x![0].CompareTo(y![0]);
        }
    }

    // Method to process booking requests and return results
    internal static List<bool> Book(int[][] nums)
    {
        // Initialize SortedSet with custom comparer
        SortedSet<int[]> bookings = new(new IntervalComparer());
        List<bool> results = []; // List to store the results of booking attempts

        foreach (int[] interval in nums)
        {
            int start = interval[0], end = interval[1]; // Extract start and end times

            // Find the closest event that starts before or at the same time
            int[]? lower = null, higher = null;
            foreach (int[] b in bookings)
            {
                if (b[0] < start) lower = b;
                if (b[0] >= start)
                {
                    higher = b;
                    break;
                }
            }

            // Check for overlap with neighboring events
            if ((lower == null || lower[1] <= start) && (higher == null || end <= higher[0]))
            {
                bookings.Add([start, end]); // Add booking if no overlap
                results.Add(true);
            }
            else
            {
                results.Add(false); // Booking overlaps, push false
            }
        }
        return results; // Return the list of results
    }
}


