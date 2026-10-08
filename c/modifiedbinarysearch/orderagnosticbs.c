#include <stdbool.h>

int desc_or_asc_search
(
    const int *arr,
    int arr_len,
    int key
)
{
    int left = 0;
    int right = arr_len - 1;
    bool is_asc = arr[left] < arr[right];

    while (left <= right)
    {
        // calculate the middle of the current range
        int mid = left + (right - left) / 2;

        if (key == arr[mid])
        {
            return mid;
        }

        if (is_asc)
        { // ascending order
            if (key < arr[mid])
            {
                right = mid - 1; // the 'key' can be in the first half
            }
            else
            {                   // key > arr[mid]
                left = mid + 1; // the 'key' can be in the second half
            }
        }
        else
        { // descending order
            if (key > arr[mid])
            {
                right = mid - 1; // the 'key' can be in the first half
            }
            else
            {                   // key < arr[mid]
                left = mid + 1; // the 'key' can be in the second half
            }
        }
    }

    return -1; // element not found
}
