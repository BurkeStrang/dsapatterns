// How do we search in a sorted and rotated array that also has duplicates?
// The code above will fail in the following example!
//
// Example 1:
// Input: [3, 7, 3, 3, 3], key = 7
// Output: 1
// Explanation: '7' is present in the array at index '1'.

pub fn search_rotated_dups(arr: &[i32], key: i32) -> i32 {
    let mut start = 0;
    let mut end = arr.len() as i32 - 1;
    while start <= end {
        let mid = start + (end - start) / 2;
        let val = arr[mid as usize];
        let (first, last) = (arr[start as usize], arr[end as usize]);

        if val == key {
            return mid;
        }

        if first == val && last == val {
            // the only difference from the previous solution,
            // if numbers at indexes start, mid, and end are same, we can't
            // choose a side the best we can do, is to skip one number from
            // both ends as key != arr[mid]
            start += 1;
            end -= 1;
        } else if first <= val {
            // left side is sorted in ascending order
            if key >= first && key < val {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        } else {
            // right side is sorted in ascending order
            if key > val && key <= last {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
    }

    // we are not able to find the element in the given array
    -1
}
