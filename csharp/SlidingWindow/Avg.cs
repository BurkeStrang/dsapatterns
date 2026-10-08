namespace DsaPatterns.SlidingWindow;

// Given an array, find the average of each subarray of ‘K’ contiguous elements
// in it.

internal static class Avg
{
    internal static double[] FindAverages(int k, int[] arr)
    {
        double[] result = new double[arr.Length - k + 1];
        int windowSum = 0;
        int windowStart = 0;
        for (int windowEnd = 0; windowEnd < arr.Length; windowEnd++)
        {
            windowSum += arr[windowEnd]; // add the next element
            // slide the window, we don't need to slide if we've not hit the
            // required window size of 'k'
            if (windowEnd >= k - 1)
            {
                // calculate the average
                result[windowStart] = (double)windowSum / k;
                windowSum -= arr[windowStart]; // subtract the element going out
                windowStart++; // slide the window ahead
            }
        }

        return result;
    }
}
