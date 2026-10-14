// Numbers can be regarded as the product of their factors.
// For example, 8 = 2 x 2 x 2 = 2 x 4.
// Given an integer n,
// return all possible combinations of its factors.
// You may return the answer in any order.
//
// Example 1:
// Input: n = 8
// Output: [[2, 2, 2], [2, 4]]
//
// Example 2:
// Input: n = 20
// Output: [[2, 2, 5], [2, 10], [4, 5]]
//
// Constraints:
// 2 <= n <= 107

pub fn get_factors(n: i32) -> Vec<Vec<i32>> {
    let mut result = Vec::new();
    get_all_factors(n, 2, &mut Vec::new(), &mut result);
    result
}

fn get_all_factors(
    n: i32,
    start: i32,
    curr: &mut Vec<i32>,
    result: &mut Vec<Vec<i32>>,
) {
    // go up to the square root of 'n'
    let mut i = start;
    while i * i <= n {
        if n % i == 0 {
            curr.push(i);

            // 'i' and 'n / i' finish off a combination
            let mut curr_copy = curr.clone();
            curr_copy.push(n / i);
            result.push(curr_copy);

            // keep 'i' and break 'n / i' down further
            get_all_factors(n / i, i, curr, result);
            curr.pop();
        }
        i += 1;
    }
}
