/// Sorts each subset and then the list of subsets, so that two lists holding
/// the same subsets in a different order compare equal.
pub fn sorted_subsets(mut subsets: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    for subset in &mut subsets {
        subset.sort_unstable();
    }
    subsets.sort();
    subsets
}
