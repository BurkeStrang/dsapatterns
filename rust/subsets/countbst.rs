// Example 1:
// input: 2
// output: 2

// Example 2:
// input: 3
// output: 5

pub fn count_trees(n: u32) -> u64 {
    if n <= 1 {
        return 1;
    }

    let mut count = 0;
    for i in 1..=n {
        // making 'i' root of the tree
        let count_of_left_subtrees = count_trees(i - 1);
        let count_of_right_subtrees = count_trees(n - i);
        count += count_of_left_subtrees * count_of_right_subtrees;
    }
    count
}
