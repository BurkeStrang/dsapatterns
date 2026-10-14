"""
Given an array, find the average of each subarray of ‘K’ contiguous elements
in it.
"""


def find_averages(k: int, arr: list[int]) -> list[float]:
    result: list[float] = []
    window_sum = 0
    window_start = 0
    for window_end in range(len(arr)):
        window_sum += arr[window_end]  # add the next element
        # slide the window, we don't need to slide if we've not hit the
        # required window size of 'k'
        if window_end >= k - 1:
            result.append(window_sum / k)  # calculate the average
            window_sum -= arr[window_start]  # subtract the element going out
            window_start += 1  # slide the window ahead
    return result
