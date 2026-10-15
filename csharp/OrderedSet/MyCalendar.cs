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
// Justification: All events are booked without any overlap,
// as each event starts exactly when the previous one ends.
// Constraints:
//
// 0 <= start < end <= 109
// At most 1000 calls will be made to book.

internal static class MyCalendar
{
    private class IntervalComparer : IComparer<(int Start, int End)>
    {
        public int Compare((int Start, int End) x, (int Start, int End) y)
        {
            return x.Start.CompareTo(y.Start);
        }
    }

    internal static List<bool> Book(int[][] nums)
    {
        SortedSet<(int Start, int End)> bookings = new(new IntervalComparer());
        List<bool> results = [];

        foreach (int[] interval in nums)
        {
            int curStart = interval[0];
            int curEnd = interval[1];

            (int Start, int End)? lower = null;
            (int Start, int End)? higher = null;

            foreach ((int Start, int End) prevBooking in bookings)
            {
                if (prevBooking.Start < curStart)
                {
                    lower = prevBooking;
                }
                else
                {
                    higher = prevBooking;
                    break;
                }
            }

            if (
                (lower is null || lower.Value.End <= curStart)
                && (higher is null || curEnd <= higher.Value.Start)
            )
            {
                bookings.Add((curStart, curEnd));
                results.Add(true);
            }
            else
            {
                results.Add(false);
            }
        }

        return results;
    }
}
