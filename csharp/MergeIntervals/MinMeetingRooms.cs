namespace DsaPatterns.MergeIntervals;

// Given a list of intervals representing the start and end time of ‘N’
// meetings,
// find the minimum number of rooms required to hold all the meetings.
//
// Example 1:
// Meetings: [[1,4], [2,5], [7,9]]
// Output: 2
// Explanation: Since [1,4] and [2,5] overlap, we need two rooms to hold these
// two meetings.
// [7,9] can occur in any of the two rooms later.
//
// Example 2:
// Meetings: [[6,7], [2,4], [8,12]]
// Output: 1
// Explanation: None of the meetings overlap,
// therefore we only need one room to hold all meetings.
//
// Example 3:
// Meetings: [[1,4], [2,3], [3,6]]
// Output:2
// Explanation: Since [1,4] overlaps with the other two meetings [2,3] and
// [3,6],
// we need two rooms to hold all the meetings.
//
// Example 4:
// Meetings: [[4,5], [2,3], [2,4], [3,5]]
// Output: 2
// Explanation: We will need one room for [2,3] and [3,5],
// and another room for [2,4] and [4,5].
//
// Constraints:
// 1 <= meetings.length <= 104
// 0 <= starti < endi <= 106

internal record struct Meeting(int Start, int End);

internal static class MinMeetingRooms
{
    internal static int FindMinimumMeetingRooms(Meeting[] meetings)
    {
        if (meetings.Length == 0)
        {
            return 0;
        }

        // sort the meetings by start time
        Array.Sort(meetings, (a, b) => a.Start.CompareTo(b.Start));

        int minRooms = 0;
        // min heap ordered by meeting end time
        PriorityQueue<Meeting, int> minHeap = new();
        foreach (Meeting meeting in meetings)
        {
            // remove all meetings that have ended
            while (minHeap.Count > 0 && meeting.Start >= minHeap.Peek().End)
            {
                minHeap.Dequeue();
            }

            // add the current meeting into the minHeap
            minHeap.Enqueue(meeting, meeting.End);
            // all active meeting are in the minHeap, so we need rooms for all
            // of them.
            if (minHeap.Count > minRooms)
            {
                minRooms = minHeap.Count;
            }
        }

        return minRooms;
    }
}
