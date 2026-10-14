// Given an expression containing digits and operations (+, -, *),
// find all possible ways in which the expression can be evaluated
// by grouping the numbers and operators using parentheses.
//
// Example 1:
// Input: "1+2*3"
// Output: 7, 9
// Explanation:
//   1+(2*3) => 7
//   (1+2)*3 => 9
//
// Example 2:
// Input: "2*3-4-5"
// Output: 8, -12, 7, -7, -3
// Explanation:
//   2*(3-(4-5)) => 8
//   2*(3-4-5) => -12
//   2*3-(4-5) => 7
//   2*(3-4)-5 => -7
//   (2*3)-4-5 => -3

pub fn diff_ways_to_evaluate_expression(input: &str) -> Vec<i32> {
    let mut result = Vec::new();

    // base case: if the input string is a number, parse and add it to output.
    if !input.contains(['+', '-', '*']) {
        result.push(input.parse().unwrap());
    } else {
        for (i, chr) in input.char_indices() {
            if !chr.is_ascii_digit() {
                // break the equation here into two parts and make recursively
                // calls
                let left_parts = diff_ways_to_evaluate_expression(&input[..i]);
                let right_parts =
                    diff_ways_to_evaluate_expression(&input[i + 1..]);
                for &part1 in &left_parts {
                    for &part2 in &right_parts {
                        match chr {
                            '+' => result.push(part1 + part2),
                            '-' => result.push(part1 - part2),
                            '*' => result.push(part1 * part2),
                            _ => {}
                        }
                    }
                }
            }
        }
    }

    result
}
