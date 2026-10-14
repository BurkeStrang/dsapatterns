// In a non-empty array of numbers,
// every number appears exactly twice except two numbers that appear only once.
// Find the two numbers that appear only once.
//
// Example 1:
// Input: [1, 4, 2, 1, 3, 5, 6, 2, 3, 5]
// Output: [4, 6]
//
// Example 2:
// Input: [2, 1, 3, 2]
// Output: [1, 3]

pub fn find_single_numbers(nums: &[i32]) -> [i32; 2] {
    // Get the XOR of all the numbers
    let mut n1xn2 = 0;
    for &num in nums {
        n1xn2 ^= num;
    }

    // Get the rightmost bit that is '1'
    let mut rightmost_set_bit = 1;
    while (rightmost_set_bit & n1xn2) == 0 {
        rightmost_set_bit <<= 1;
    }

    let mut num1 = 0;
    let mut num2 = 0;
    for &num in nums {
        if (num & rightmost_set_bit) != 0 {
            // the bit is set
            num1 ^= num;
        } else {
            // the bit is not set
            num2 ^= num;
        }
    }

    [num1, num2]
}
