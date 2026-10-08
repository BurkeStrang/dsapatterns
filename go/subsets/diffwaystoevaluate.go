package subsets

import (
	"strconv"
	"strings"
	"unicode"
)

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

func diffWaysToEvaluateExpression(input string) []int {
	result := []int{}
	// base case: if the input string is a number, parse and add it to output.
	if !strings.Contains(input, "+") && !strings.Contains(input, "-") && !strings.Contains(input, "*") {
		num, _ := strconv.Atoi(input)
		result = append(result, num)
	} else {
		for i := 0; i < len(input); i++ {
			chr := input[i]
			if !unicode.IsDigit(rune(chr)) {
				// break the equation here into two parts and make recursively calls
				leftParts := diffWaysToEvaluateExpression(input[:i])
				rightParts := diffWaysToEvaluateExpression(input[i+1:])
				for _, part1 := range leftParts {
					for _, part2 := range rightParts {
						switch chr {
						case '+':
							result = append(result, part1+part2)
						case '-':
							result = append(result, part1-part2)
						case '*':
							result = append(result, part1*part2)
						}
					}
				}
			}
		}
	}
	return result
}
