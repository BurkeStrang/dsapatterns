namespace DsaPatterns.MonotonicStack;

// Given an array of integers temperatures representing daily temperatures,
// calculate how many days you have to wait until a warmer temperature.
// If there is no future day for which this is possible, put 0 instead.
//
// Example 1
// Input: temperatures = [70, 73, 75, 71, 69, 72, 76, 73]
// Output: [1, 1, 4, 2, 1, 1, 0, 0]
// Explanation: The first day's temperature is 70 and the next day's temperature
// is 73 which is warmer. So for the first day, you only have to wait for 1 day
// to get a warmer temperature. Hence, the first element in the result array is
// 1. The same process is followed for the rest of the days.
//
// Example 2
// Input: temperatures = [73, 72, 71, 70]
// Output: [0, 0, 0, 0]
// Explanation: As we can see, the temperature is decreasing every day. So,
// there is no future day with a warmer temperature. Hence, all the elements in
// the result array are 0.
//
// Example 3
// Input: temperatures = [70, 71, 72, 73]
// Output: [1, 1, 1, 0]
// Explanation: For the first three days, the next day is warmer. But for the
// last day, there is no future day with a warmer temperature. Hence, the result
// array is [1, 1, 1, 0].
//
// Constraints:
// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100

internal static class DailyTemp
{
    internal static int[] DailyTemperatures(int[] temperatures)
    {
        // Initialize an empty stack to store indices of temperatures.
        Stack<int> stack = new();
        // Initialize a result array with zeros.
        int[] res = new int[temperatures.Length];

        for (int i = 0; i < temperatures.Length; i++)
        {
            int temp = temperatures[i];
            while (stack.Count > 0 && temp > temperatures[stack.Peek()])
            {
                // While the stack is not empty and the current temperature is
                // higher than the temperature at the index stored at the top
                // of the stack:
                int idx = stack.Pop(); // Pop the top index from the stack.
                // Calculate the number of days until warmer temperature.
                res[idx] = i - idx;
            }

            stack.Push(i); // Push the current index onto the stack.
        }

        return res;
    }
}
