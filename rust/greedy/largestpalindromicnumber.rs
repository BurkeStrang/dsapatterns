// Given a string s containing 0 to 9 digits, create the largest possible
// palindromic number using the string characters.
// It should not contain leading zeroes.
// A palindromic number reads the same backward as forward.
// If it's not possible to form such a number using all digits of the given
// string, you can skip some of them.
//
// Example 1
// Input: s = "323211444"
// Expected Output: "432141234"
// Justification: This is the largest palindromic number that can be formed from
// the given digits.
//
// Example 2
// Input: s = "998877"
// Expected Output: "987789"
// Justification: "987789" is the largest palindrome that can be formed.
//
// Example 3
// Input: s = "54321"
// Expected Output: "5"
// Justification: Only "5" can form a valid palindromic number as other digits
// cannot be paired.

pub fn largest_palindromic(s: &str) -> String {
    let mut first_half = String::new(); // The first half of the palindrome
    let mut frequency = [0; 10]; // Frequency array for digits 0-9

    // Count the frequency of each digit in the input number
    for digit in s.bytes() {
        frequency[usize::from(digit - b'0')] += 1;
    }

    let mut middle = None; // The middle digit, if one is needed

    // Iterate from the highest digit (9) to the lowest (0)
    for digit in ('0'..='9').rev() {
        let mut count = frequency[digit as usize - '0' as usize];
        // a number can't start with 0, so skip the zeros until there is
        // something in front of them
        if count != 0 && (digit != '0' || !first_half.is_empty()) {
            while count > 1 {
                first_half.push(digit); // Append the digit to first_half
                count -= 2; // Use two of the digit for the two halves
            }
            if count == 1 && middle.is_none() {
                // The middle digit is the largest digit with an odd count
                middle = Some(digit);
            }
        }
    }

    // Create second_half as a reversed copy of first_half
    let second_half: String = first_half.chars().rev().collect();

    // Append the middle digit if it exists
    let mut result = first_half;
    result.extend(middle);
    result.push_str(&second_half); // Append the reversed first half

    if result.is_empty() {
        return "0".to_string();
    }
    result // Return the final palindrome
}
