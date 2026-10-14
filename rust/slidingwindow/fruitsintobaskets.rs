use std::collections::HashMap;

// You are visiting a farm to collect fruits.
// The farm has a single row of fruit trees.
// You will be given two baskets, and your goal is to pick as many fruits as
// possible to be placed in the given baskets.
//
// You will be given an array of characters where each character represents a
// fruit tree.
// The farm has following restrictions:
//
// Each basket can have only one type of fruit. There is no limit to how many
// fruit a basket can hold.
// You can start with any tree, but you can’t skip a tree once you have started.
// You will pick exactly one fruit from every tree until you cannot, i.e.,
// you will stop when you have to pick from a third fruit type.
// Write a function to return the maximum number of fruits in both baskets.
//
// Example 1:
//
// Input: arr=['A', 'B', 'C', 'A', 'C']
// Output: 3
// Explanation: We can put 2 'C' in one basket and one 'A' in the other from the
// subarray ['C', 'A', 'C']
// Example 2:
//
// Input: arr = ['A', 'B', 'C', 'B', 'B', 'C']
// Output: 5
// Explanation: We can put 3 'B' in one basket and two 'C' in the other basket.
// This can be done if we start with the second letter: ['B', 'C', 'B', 'B',
// 'C']
// Constraints:
//
// 1 <= arr.length <=
// 0 <= arr[i] < arr.length

pub fn max_fruit(arr: &[char]) -> usize {
    let mut window_start = 0;
    let mut max_length = 0;
    let mut fruit_frequency_map: HashMap<char, usize> = HashMap::new();
    // try to extend the range [window_start, window_end]
    for window_end in 0..arr.len() {
        *fruit_frequency_map.entry(arr[window_end]).or_insert(0) += 1;
        // shrink the sliding window, until we're left with '2' fruits in the
        // frequency map
        while fruit_frequency_map.len() > 2 {
            let left_fruit = arr[window_start];
            let count = fruit_frequency_map.get_mut(&left_fruit).unwrap();
            *count -= 1;
            if *count == 0 {
                fruit_frequency_map.remove(&left_fruit);
            }
            window_start += 1; // shrink the window
        }
        max_length = max_length.max(window_end - window_start + 1);
    }
    max_length
}
