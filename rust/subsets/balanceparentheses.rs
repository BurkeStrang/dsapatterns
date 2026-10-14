use std::collections::VecDeque;

// For a given number 'num', write a function to generate all combinations of
// 'num' pairs of balanced parentheses.
//
// Example 1:
// Input: num=2
// Output: (()), ()()
//
// Example 2:
// Input: num=3
// Output: ((())), (()()), (())(), ()(()), ()()()

struct ParenthesesString {
    s: String,
    open_count: usize,  // open parentheses count
    close_count: usize, // close parentheses count
}

pub fn generate_valid_parentheses(num: usize) -> Vec<String> {
    let mut result = Vec::new();
    let mut queue = VecDeque::new();
    queue.push_back(ParenthesesString {
        s: String::new(),
        open_count: 0,
        close_count: 0,
    });

    while let Some(ps) = queue.pop_front() {
        // if we've reached the maximum number of open and close parentheses,
        // add to result
        if ps.open_count == num && ps.close_count == num {
            result.push(ps.s);
        } else {
            // if we can add an open parentheses, add it
            if ps.open_count < num {
                queue.push_back(ParenthesesString {
                    s: format!("{}(", ps.s),
                    open_count: ps.open_count + 1,
                    close_count: ps.close_count,
                });
            }

            // if we can add a close parentheses, add it
            if ps.open_count > ps.close_count {
                queue.push_back(ParenthesesString {
                    s: format!("{})", ps.s),
                    open_count: ps.open_count,
                    close_count: ps.close_count + 1,
                });
            }
        }
    }

    result
}
