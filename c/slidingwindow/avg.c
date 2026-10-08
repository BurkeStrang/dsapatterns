#include <stdlib.h>

// Given an array, find the average of each subarray of ‘K’ contiguous elements
// in it.
//
// The averages are returned in a new array that the caller must free, and its
// length is stored in result_len.

double *find_averages
(
    int k,
    const int *arr,
    int arr_len,
    int *result_len
)
{
    *result_len = arr_len - k + 1;
    double *result = malloc((size_t)*result_len * sizeof(double));
    int window_sum = 0;
    int window_start = 0;
    for (int window_end = 0; window_end < arr_len; window_end++)
    {
        window_sum += arr[window_end]; // add the next element
        // slide the window, we don't need to slide if we've not hit the
        // required window size of 'k'
        if (window_end >= k - 1)
        {
            // calculate the average
            result[window_start] = (double)window_sum / k;
            window_sum -= arr[window_start]; // subtract the element going out
            window_start++;                  // slide the window ahead
        }
    }
    return result;
}
