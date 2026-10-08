namespace DsaPatterns.MergeIntervals;

// For ‘K’ employees, we are given a list of intervals representing each
// employee’s working hours.
// Our goal is to determine if there is a free interval which is common to all
// employees.
//
// Example 1:
// Input: Employee Working Hours=[[[1,3], [5,6]], [[2,3], [6,8]]]
// Output: [3,5]
// Explanation: All the employees are free between [3,5].
//
// Example 2:
// Input: Employee Working Hours=[[[1,3], [9,12]], [[2,4]], [[6,8]]]
// Output: [4,6], [8,9]
// Explanation: All employees are free between [4,6] and [8,9].
//
// Example 3:
// Input: Employee Working Hours=[[[1,3]], [[2,4]], [[3,5], [7,9]]]
// Output: [5,7]
// Explanation: All employees are free between [5,7].

internal record struct EmployeeInterval(
    Interval Interval,
    int EmployeeIndex,
    int IntervalIndex
);

internal static class EmployeeFreeTime
{
    internal static List<Interval> FindEmployeeFreeTime(Interval[][] schedule)
    {
        List<Interval> result = [];
        // min heap ordered by interval start time
        PriorityQueue<EmployeeInterval, int> minHeap = new();

        // insert the first interval of each employee to the queue
        for (int i = 0; i < schedule.Length; i++)
        {
            minHeap.Enqueue(
                new EmployeeInterval(schedule[i][0], i, 0),
                schedule[i][0].Start
            );
        }

        Interval previousInterval = minHeap.Peek().Interval;
        while (minHeap.Count > 0)
        {
            EmployeeInterval queueTop = minHeap.Dequeue();
            // if previousInterval is not overlapping with the next interval,
            // insert a free interval
            if (previousInterval.End < queueTop.Interval.Start)
            {
                result.Add(
                    new Interval(previousInterval.End, queueTop.Interval.Start)
                );
                previousInterval = queueTop.Interval;
            }
            else if (previousInterval.End < queueTop.Interval.End)
            {
                // overlapping intervals, update the previousInterval if needed
                previousInterval = queueTop.Interval;
            }

            // if there are more intervals available for the same employee, add
            // their next interval
            Interval[] employeeSchedule = schedule[queueTop.EmployeeIndex];
            int nextIndex = queueTop.IntervalIndex + 1;
            if (employeeSchedule.Length > nextIndex)
            {
                minHeap.Enqueue(
                    new EmployeeInterval(
                        employeeSchedule[nextIndex],
                        queueTop.EmployeeIndex,
                        nextIndex
                    ),
                    employeeSchedule[nextIndex].Start
                );
            }
        }

        return result;
    }
}
