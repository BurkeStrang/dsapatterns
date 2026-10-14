// Example 1:
// Input: ['a', 'c', 'f', 'h'], key = 'f'
// Output: 'h'

pub fn search_next_letter(letters: &[char], key: char) -> char {
    let n = letters.len();
    // search the half-open range [left, right), so 'right' never goes below 0
    let mut left = 0;
    let mut right = n;

    while left < right {
        let mid = left + (right - left) / 2;
        if key < letters[mid] {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    // at the end of the while loop 'left' is the first letter bigger than the
    // key; if there is none it is 'n', which wraps around to the first letter
    letters[left % n]
}
