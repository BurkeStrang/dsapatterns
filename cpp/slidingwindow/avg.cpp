#include <cstddef>
#include <vector>

// Given an array, find the average of each subarray of ‘K’ contiguous elements
// in it.

std::vector<double> find_averages(int k, const std::vector<int> &arr)
{
    std::vector<double> result(arr.size() - k + 1);
    int window_sum = 0;
    std::size_t window_start = 0;
    for (std::size_t window_end = 0; window_end < arr.size(); window_end++)
    {
        window_sum += arr[window_end]; // add the next element
        // slide the window, we don't need to slide if we've not hit the
        // required window size of 'k'
        if (window_end + 1 >= static_cast<std::size_t>(k))
        {
            // calculate the average
            result[window_start] = static_cast<double>(window_sum) / k;
            window_sum -= arr[window_start]; // subtract the element going out
            window_start++;                  // slide the window ahead
        }
    }
    return result;
}
