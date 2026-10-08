#include <limits.h>

// Given an infinite sorted array (or an array with unknown size),
// find if a given number ‘key’ is present in the array.
// Write a function to return the index of the ‘key’ if it is present in the
// array, otherwise return -1.
// Since it is not possible to define an array with infinite (unknown) size,
// you will be provided with an interface ArrayReader to read elements of the
// array.
// ArrayReader.get(index) will return the number at index;
// if the array’s size is smaller than the index, it will return
// Integer.MAX_VALUE.
//
// Example 1:
// Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 16
// Output: 6
// Explanation: The key is present at index '6' in the array.
//
// Example 2:
// Input: [4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30], key = 11
// Output: -1
// Explanation: The key is not present in the array.
//
// Example 3:
// Input: [1, 3, 8, 10, 15], key = 15
// Output: 4
// Explanation: The key is present at index '4' in the array.
//
// Example 4:
// Input: [1, 3, 8, 10, 15], key = 200
// Output: -1
// Explanation: The key is not present in the array.

typedef struct
{
    const int *arr;
    int arr_len;
} ArrayReader;

int array_reader_get
(
    const ArrayReader *reader,
    int index
)
{
    if (index >= reader->arr_len)
    {
        return INT_MAX;
    }
    return reader->arr[index];
}

int binary_search
(
    const ArrayReader *reader,
    int key,
    int start,
    int end
)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (key < array_reader_get(reader, mid))
        {
            end = mid - 1;
        }
        else if (key > array_reader_get(reader, mid))
        {
            start = mid + 1;
        }
        else
        { // found the key
            return mid;
        }
    }
    return -1;
}

int search_infinite_sorted_array
(
    const ArrayReader *reader,
    int key
)
{
    // find the proper bounds first
    int start = 0;
    int end = 1;
    while (array_reader_get(reader, end) < key)
    {
        int new_start = end + 1;
        end += (end - start + 1) * 2; // increase to double the bounds size
        start = new_start;
    }
    return binary_search(reader, key, start, end);
}
